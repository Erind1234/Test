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

        public bool SaveFiscalization(EmpModel emp)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    string query = @"INSERT INTO [dbo].[Fiscal] (QRCODEVAL, STPROFILE, NIVF, REFCODE, PYMTORDNUM, PAYERNIPT, EINFIC, PAIDAMT, PAIDCUR, TRANSACTIONCODE, PYMTTYPE, BANKNIPT, DATTIMSEND, PYMTDATTIM, OVERPAIDAMT, PYMTSTATUS, CODE, MESSAGE, USR, SELLERNIPT, INVOICEDATE, IBANNR, SWIFTNR, BANKNAME)
                                     VALUES (@QRCODEVAL, @STPROFILE, @NIVF, @REFCODE, @PYMTORDNUM, @PAYERNIPT, @EINFIC, @PAIDAMT, @PAIDCUR, @TRANSACTIONCODE, @PYMTTYPE, @BANKNIPT, @DATTIMSEND, @PYMTDATTIM, @OVERPAIDAMT, @PYMTSTATUS, @CODE, @MESSAGE, @USR, @SELLERNIPT, @INVOICEDATE, @IBANNR, @SWIFTNR, @BANKNAME)";

                    using (SqlCommand cmd = new SqlCommand(query, connection))
                    {
                        cmd.Parameters.AddWithValue("@QRCODEVAL", emp.QRCODEVAL);
                        cmd.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);
                        cmd.Parameters.AddWithValue("@NIVF", emp.NIVF);
                        cmd.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
                        cmd.Parameters.AddWithValue("@PYMTORDNUM", emp.PYMTORDNUM);
                        cmd.Parameters.AddWithValue("@PAYERNIPT", emp.PAYERNIPT);
                        cmd.Parameters.AddWithValue("@EINFIC", emp.EINFIC);
                        cmd.Parameters.AddWithValue("@PAIDAMT", emp.PAIDAMT);
                        cmd.Parameters.AddWithValue("@PAIDCUR", emp.PAIDCUR);
                        cmd.Parameters.AddWithValue("@TRANSACTIONCODE", emp.TRANSACTIONCODE);
                        cmd.Parameters.AddWithValue("@PYMTTYPE", emp.PYMTTYPE);
                        cmd.Parameters.AddWithValue("@BANKNIPT", emp.BANKNIPT);
                        cmd.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
                        cmd.Parameters.AddWithValue("@PYMTDATTIM", emp.PYMTDATTIM);
                        cmd.Parameters.AddWithValue("@OVERPAIDAMT", emp.OVERPAIDAMT);
                        cmd.Parameters.AddWithValue("@PYMTSTATUS", emp.PYMTSTATUS);
                        cmd.Parameters.AddWithValue("@CODE", emp.CODE);
                        cmd.Parameters.AddWithValue("@MESSAGE", emp.MESSAGE);
                        cmd.Parameters.AddWithValue("@USR", emp.USR);
                        cmd.Parameters.AddWithValue("@SELLERNIPT", emp.SELLERNIPT);
                        cmd.Parameters.AddWithValue("@INVOICEDATE", emp.INVOICEDATE);
                        cmd.Parameters.AddWithValue("@IBANNR", emp.IBANNR);
                        cmd.Parameters.AddWithValue("@SWIFTNR", emp.SWIFTNR);
                        cmd.Parameters.AddWithValue("@BANKNAME", emp.BANKNAME);

                        int rowsAffected = cmd.ExecuteNonQuery();
                        return rowsAffected > 0;
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("An error occurred: " + ex.Message);
                return false;
            }
        }

        internal EmpModel GetEmployeeById(int id)
        {
            throw new NotImplementedException();
        }

        public bool UpdateFiscalization(EmpModel emp)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    string query = @"UPDATE [dbo].[Fiscal] SET QRCODEVAL = @QRCODEVAL, STPROFILE = @STPROFILE, /* Update other fields here */
                                     WHERE ID = @ID";

                    using (SqlCommand cmd = new SqlCommand(query, connection))
                    {
                        cmd.Parameters.AddWithValue("@ID", emp.ID);
                        cmd.Parameters.AddWithValue("@QRCODEVAL", emp.QRCODEVAL);
                        cmd.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);
                        cmd.Parameters.AddWithValue("@NIVF", emp.NIVF);
                        cmd.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
                        cmd.Parameters.AddWithValue("@PYMTORDNUM", emp.PYMTORDNUM);
                        cmd.Parameters.AddWithValue("@PAYERNIPT", emp.PAYERNIPT);
                        cmd.Parameters.AddWithValue("@EINFIC", emp.EINFIC);
                        cmd.Parameters.AddWithValue("@PAIDAMT", emp.PAIDAMT);
                        cmd.Parameters.AddWithValue("@PAIDCUR", emp.PAIDCUR);
                        cmd.Parameters.AddWithValue("@TRANSACTIONCODE", emp.TRANSACTIONCODE);
                        cmd.Parameters.AddWithValue("@PYMTTYPE", emp.PYMTTYPE);
                        cmd.Parameters.AddWithValue("@BANKNIPT", emp.BANKNIPT);
                        cmd.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
                        cmd.Parameters.AddWithValue("@PYMTDATTIM", emp.PYMTDATTIM);
                        cmd.Parameters.AddWithValue("@OVERPAIDAMT", emp.OVERPAIDAMT);
                        cmd.Parameters.AddWithValue("@PYMTSTATUS", emp.PYMTSTATUS);
                        cmd.Parameters.AddWithValue("@CODE", emp.CODE);
                        cmd.Parameters.AddWithValue("@MESSAGE", emp.MESSAGE);
                        cmd.Parameters.AddWithValue("@USR", emp.USR);
                        cmd.Parameters.AddWithValue("@SELLERNIPT", emp.SELLERNIPT);
                        cmd.Parameters.AddWithValue("@INVOICEDATE", emp.INVOICEDATE);
                        cmd.Parameters.AddWithValue("@IBANNR", emp.IBANNR);
                        cmd.Parameters.AddWithValue("@SWIFTNR", emp.SWIFTNR);
                        cmd.Parameters.AddWithValue("@BANKNAME", emp.BANKNAME);

                        int rowsAffected = cmd.ExecuteNonQuery();
                        return rowsAffected > 0;
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("An error occurred: " + ex.Message);
                return false;
            }
        }

        public EmpModel GetFiscalizationById(int id)
        {
            EmpModel emp = null;
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    string query = "SELECT * FROM [dbo].[Fiscal] WHERE ID = @ID";

                    using (SqlCommand cmd = new SqlCommand(query, connection))
                    {
                        cmd.Parameters.AddWithValue("@ID", id);
                        using (SqlDataReader reader = cmd.ExecuteReader())
                        {
                            if (reader.Read())
                            {
                                emp = new EmpModel
                                {
                                    ID = Convert.ToInt32(reader["ID"]),
                                    QRCODEVAL = reader["QRCODEVAL"].ToString(),
                                    STPROFILE = reader["STPROFILE"].ToString(),
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
                                    NIVF = reader["NIVF"].ToString()
                                    
                                };
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("An error occurred: " + ex.Message);
            }
            return emp;
        }

        public List<EmpModel> SearchFiscalizations(string searchBox)
        {
            List<EmpModel> fiscalizations = new List<EmpModel>();
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    // Define your SQL query to search fiscalizations based on searchBox
                    string query = "SELECT * FROM [dbo].[Fiscal] WHERE /* Your search criteria here */";

                    using (SqlCommand cmd = new SqlCommand(query, connection))
                    {
                        using (SqlDataReader reader = cmd.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                EmpModel emp = new EmpModel
                                {
                                    ID = Convert.ToInt32(reader["ID"]),
                                   
                                    QRCODEVAL = reader["QRCODEVAL"].ToString(),
                                    STPROFILE = reader["STPROFILE"].ToString(),
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
                                    NIVF = reader["NIVF"].ToString()
                                };
                                fiscalizations.Add(emp);
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("An error occurred: " + ex.Message);
            }
            return fiscalizations;
        }

       


    }
}
