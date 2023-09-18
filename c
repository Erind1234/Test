using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using InApps.Models;

namespace InApps.Repository
{
    public class EmpRepository
    {
        private readonly string connectionString;

        public EmpRepository()
        {
            connectionString = ConfigurationManager.ConnectionStrings["FacilegalConn"].ConnectionString;
        }

        // Get a list of all employees
        public List<EmpModel> GetAllEmployees()
        {
            List<EmpModel> empList = new List<EmpModel>();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                using (SqlCommand cmd = new SqlCommand("SELECT * FROM [dbo].[Fiscal]", connection))
                {
                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            EmpModel emp = new EmpModel
                            {
                                ID = Convert.ToInt32(reader["ID"]),
                                REFCODE = reader["REFCODE"].ToString(),
                                PYMTORDNUM = reader["PYMTORDNUM"].ToString(),
                                DATTIMSEND = reader["DATTIMSEND"].ToString(),
                                BANKNIPT = reader["BANKNIPT"].ToString(),
                                PAYERNIPT = reader["PAYERNIPT"].ToString(),
                                EINFIC = reader["EINFIC"].ToString(),
                                PYMTDATTIM = reader["PYMTDATTIM"].ToString(),
                                PAIDAMT = reader["PAIDAMT"].ToString(),
                                OVERPAIDAMT = reader["OVERPAIDAMT"].ToString(),
                                PAIDCUR = reader["PAIDCUR"].ToString(),
                                TRANSACTIONCODE = reader["TRANSACTIONCODE"].ToString(),
                                PYMTTYPE = reader["PYMTTYPE"].ToString(),
                                PYMTSTATUS = reader["PYMTSTATUS"].ToString(),
                                CODE = reader["CODE"].ToString(),
                                MESSAGE = reader["MESSAGE"].ToString(),
                                USR = reader["USR"].ToString(),
                                SELLERNIPT = reader["SELLERNIPT"].ToString(),
                                INVOICEDATE = reader["INVOICEDATE"].ToString(),
                                IBANNR = reader["IBANNR"].ToString(),
                                SWIFTNR = reader["SWIFTNR"].ToString(),
                                BANKNAME = reader["BANKNAME"].ToString(),
                                QRCODEVAL = reader["QRCODEVAL"].ToString(),
                                NIVF = reader["NIVF"].ToString(),
                                STPROFILE = reader["STPROFILE"].ToString()
                            };
                            empList.Add(emp);
                        }
                    }
                }
            }

            return empList;
        }

        // Save fiscalization data to the database
        public bool SaveFiscalization(EmpModel emp)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    using (SqlCommand cmd = new SqlCommand("INSERT INTO [dbo].[Fiscal] (REFCODE, PYMTORDNUM, DATTIMSEND, BANKNIPT, PAYERNIPT, EINFIC, PYMTDATTIM, PAIDAMT, OVERPAIDAMT, PAIDCUR, TRANSACTIONCODE, PYMTTYPE, PYMTSTATUS, CODE, MESSAGE, USR, SELLERNIPT, INVOICEDATE, IBANNR, SWIFTNR, BANKNAME, QRCODEVAL, NIVF, STPROFILE) VALUES (@REFCODE, @PYMTORDNUM, @DATTIMSEND, @BANKNIPT, @PAYERNIPT, @EINFIC, @PYMTDATTIM, @PAIDAMT, @OVERPAIDAMT, @PAIDCUR, @TRANSACTIONCODE, @PYMTTYPE, @PYMTSTATUS, @CODE, @MESSAGE, @USR, @SELLERNIPT, @INVOICEDATE, @IBANNR, @SWIFTNR, @BANKNAME, @QRCODEVAL, @NIVF, @STPROFILE)", connection))
                    {
                        cmd.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
                        cmd.Parameters.AddWithValue("@PYMTORDNUM", emp.PYMTORDNUM);
                        cmd.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
                        cmd.Parameters.AddWithValue("@BANKNIPT", emp.BANKNIPT);
                        cmd.Parameters.AddWithValue("@PAYERNIPT", emp.PAYERNIPT);
                        cmd.Parameters.AddWithValue("@EINFIC", emp.EINFIC);
                        cmd.Parameters.AddWithValue("@PYMTDATTIM", emp.PYMTDATTIM);
                        cmd.Parameters.AddWithValue("@PAIDAMT", emp.PAIDAMT);
                        cmd.Parameters.AddWithValue("@OVERPAIDAMT", emp.OVERPAIDAMT);
                        cmd.Parameters.AddWithValue("@PAIDCUR", emp.PAIDCUR);
                        cmd.Parameters.AddWithValue("@TRANSACTIONCODE", emp.TRANSACTIONCODE);
                        cmd.Parameters.AddWithValue("@PYMTTYPE", emp.PYMTTYPE);
                        cmd.Parameters.AddWithValue("@PYMTSTATUS", emp.PYMTSTATUS);
                        cmd.Parameters.AddWithValue("@CODE", emp.CODE);
                        cmd.Parameters.AddWithValue("@MESSAGE", emp.MESSAGE);
                        cmd.Parameters.AddWithValue("@USR", emp.USR);
                        cmd.Parameters.AddWithValue("@SELLERNIPT", emp.SELLERNIPT);
                        cmd.Parameters.AddWithValue("@INVOICEDATE", emp.INVOICEDATE);
                        cmd.Parameters.AddWithValue("@IBANNR", emp.IBANNR);
                        cmd.Parameters.AddWithValue("@SWIFTNR", emp.SWIFTNR);
                        cmd.Parameters.AddWithValue("@BANKNAME", emp.BANKNAME);
                        cmd.Parameters.AddWithValue("@QRCODEVAL", emp.QRCODEVAL);
                        cmd.Parameters.AddWithValue("@NIVF", emp.NIVF);
                        cmd.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);

                        int rowsAffected = cmd.ExecuteNonQuery();

                        return rowsAffected > 0; // Return true if data is saved successfully
                    }
                }
            }
            catch (Exception ex)
            {
                // Log the exception here for debugging purposes
                return false;
            }
        }

        // Other methods and repository code...

        internal List<EmpModel> SearchEmpList(string searchBox)
        {
            // Implement the search logic here
            throw new NotImplementedException();
        }
    }
}
