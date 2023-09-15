using System;
using System.Data;
using System.Data.SqlClient;

namespace InApps.Repository
{
    public class EmpRepository
    {
        private readonly string connectionString; // Set your database connection string here

        public EmpRepository()
        {
            connectionString = "Your_Connection_String_Here";
        }

        public bool SaveFiscalization(EmpModel emp)
        {
            // Implement the logic to save fiscalization data to the database
            // Return true if the data is successfully saved; otherwise, return false
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    SqlCommand cmd = new SqlCommand("INSERT INTO YourTableName (ID, QRCODEVAL, STPROFILE, NIVF, REFCODE, PYMTORDNUM, PAYERNIPT, EINFIC, PAIDAMT, PAIDCUR, TRANSACTIONCODE, PYMTTYPE, BANKNIPT, DATTIMSEND, PYMTDATTIM, OVERPAIDAMT, PYMTSTATUS, CODE, MESSAGE, USR, SELLERNIPT, INVOICEDATE, IBANNR, SWIFTNR, BANKNAME) VALUES (@ID, @QRCODEVAL, @STPROFILE, @NIVF, @REFCODE, @PYMTORDNUM, @PAYERNIPT, @EINFIC, @PAIDAMT, @PAIDCUR, @TRANSACTIONCODE, @PYMTTYPE, @BANKNIPT, @DATTIMSEND, @PYMTDATTIM, @OVERPAIDAMT, @PYMTSTATUS, @CODE, @MESSAGE, @USR, @SELLERNIPT, @INVOICEDATE, @IBANNR, @SWIFTNR, @BANKNAME)", connection);

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
            catch (Exception ex)
            {
                // Log the exception here for debugging purposes
                return false;
            }
        }
    }
}
