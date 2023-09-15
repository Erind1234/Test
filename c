using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;
using InApps.Models;

namespace InApps.Repository
{
    public class EmpRepository
    {
        private SqlConnection con;

        public EmpRepository()
        {
            string constr = ConfigurationManager.ConnectionStrings["FacilegalConn"].ToString();
            con = new SqlConnection(constr);
        }

        // Save an EmpModel object to the database
        public bool SaveFiscalization(EmpModel emp)
        {
            try
            {
                con.Open();
                SqlCommand com = new SqlCommand("AddNewFiscal", con);
                com.CommandType = CommandType.StoredProcedure;

                com.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
                com.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
                com.Parameters.AddWithValue("@BANKNIPT", emp.BANKNIPT);
                com.Parameters.AddWithValue("@PYMTORDNUM", emp.PYMTORDNUM);
                com.Parameters.AddWithValue("@PAYERNIPT", emp.PAYERNIPT);
                com.Parameters.AddWithValue("@EINFIC", emp.EINFIC);
                com.Parameters.AddWithValue("@PYMTDATTIM", emp.PYMTDATTIM);
                com.Parameters.AddWithValue("@PAIDAMT", emp.PAIDAMT);
                com.Parameters.AddWithValue("@OVERPAIDAMT", emp.OVERPAIDAMT);
                com.Parameters.AddWithValue("@PAIDCUR", emp.PAIDCUR);
                com.Parameters.AddWithValue("@TRANSACTIONCODE", emp.TRANSACTIONCODE);
                com.Parameters.AddWithValue("@PYMTTYPE", emp.PYMTTYPE);
                com.Parameters.AddWithValue("@PYMTSTATUS", emp.PYMTSTATUS);
                com.Parameters.AddWithValue("@CODE", emp.CODE);
                com.Parameters.AddWithValue("@MESSAGE", emp.MESSAGE);
                com.Parameters.AddWithValue("@USR", emp.USR);
                com.Parameters.AddWithValue("@SELLERNIPT", emp.SELLERNIPT);
                com.Parameters.AddWithValue("@INVOICEDATE", emp.INVOICEDATE);
                com.Parameters.AddWithValue("@IBANNR", emp.IBANNR);
                com.Parameters.AddWithValue("@SWIFTNR", emp.SWIFTNR);
                com.Parameters.AddWithValue("@BANKNAME", emp.BANKNAME);
                com.Parameters.AddWithValue("@QRCODEVAL", emp.QRCODEVAL);
                com.Parameters.AddWithValue("@NIVF", emp.NIVF);
                com.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);

                int i = com.ExecuteNonQuery();
                con.Close();

                return i >= 1;
            }
            catch (Exception ex)
            {
                // Handle exceptions here or log them
                Console.WriteLine("Error: " + ex.Message);
                return false;
            }
        }

        // Retrieve an EmpModel object by ID
        public EmpModel GetEmpModelById(string ID)
        {
            try
            {
                con.Open();
                SqlCommand com = new SqlCommand("SELECT * FROM [dbo].[Fiscal] WHERE ID = @ID", con);
                com.Parameters.AddWithValue("@ID", ID);

                SqlDataReader reader = com.ExecuteReader();
                EmpModel emp = new EmpModel();
                if (reader.Read())
                {
                    emp.ID = reader["ID"].ToString();
                    emp.REFCODE = reader["REFCODE"].ToString();
                    emp.PYMTORDNUM = reader["PYMTORDNUM"].ToString();
                    emp.DATTIMSEND = reader["DATTIMSEND"].ToString();
                    emp.BANKNIPT = reader["BANKNIPT"].ToString();
                    emp.PAYERNIPT = reader["PAYERNIPT"].ToString();
                    emp.EINFIC = reader["EINFIC"].ToString();
                    emp.PYMTDATTIM = reader["PYMTDATTIM"].ToString();
                    emp.PAIDAMT = reader["PAIDAMT"].ToString();
                    emp.OVERPAIDAMT = reader["OVERPAIDAMT"].ToString();
                    emp.PAIDCUR = reader["PAIDCUR"].ToString();
                    emp.TRANSACTIONCODE = reader["TRANSACTIONCODE"].ToString();
                    emp.PYMTTYPE = reader["PYMTTYPE"].ToString();
                    emp.PYMTSTATUS = reader["PYMTSTATUS"].ToString();
                    emp.CODE = reader["CODE"].ToString();
                    emp.MESSAGE = reader["MESSAGE"].ToString();
                    emp.USR = reader["USR"].ToString();
                    emp.SELLERNIPT = reader["SELLERNIPT"].ToString();
                    emp.INVOICEDATE = reader["INVOICEDATE"].ToString();
                    emp.IBANNR = reader["IBANNR"].ToString();
                    emp.SWIFTNR = reader["SWIFTNR"].ToString();
                    emp.BANKNAME = reader["BANKNAME"].ToString();
                    emp.QRCODEVAL = reader["QRCODEVAL"].ToString();
                    emp.NIVF = reader["NIVF"].ToString();
                    emp.STPROFILE = reader["STPROFILE"].ToString();
                    // Add other properties as needed
                }

                con.Close();
                return emp;
            }
            catch (Exception ex)
            {
                // Handle exceptions here or log them
                Console.WriteLine("Error: " + ex.Message);
                return null;
            }
        }

        // Update an EmpModel object in the database
        public bool Update(EmpModel emp)
        {
            try
            {
                con.Open();
                SqlCommand com = new SqlCommand("Edit", con);
                com.CommandType = CommandType.StoredProcedure;
                com.Parameters.AddWithValue("@ID", emp.ID);
                com.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
                com.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
                // Add mappings for other fields here

                int i = com.ExecuteNonQuery();
                con.Close();

                return i >= 1;
            }
            catch (Exception ex)
            {
                // Handle exceptions here or log them
                Console.WriteLine("Error: " + ex.Message);
                return false;
            }
        }
    }
}
