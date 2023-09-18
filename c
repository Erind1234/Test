public EmpModel GetLastSavedEmployee()
{
    EmpModel emp = null;

    try
    {
        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            connection.Open();

            // Define your SQL query to retrieve the last saved employee
            string query = "SELECT TOP 1 * FROM [dbo].[Fiscal] ORDER BY ID DESC";

            using (SqlCommand cmd = new SqlCommand(query, connection))
            {
                using (SqlDataReader reader = cmd.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        emp = new EmpModel
                        {
                            // Map your columns here
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
                    }
                }
            }
        }
    }
    catch (Exception ex)
    {
        // Handle exceptions here
        Console.WriteLine("An error occurred: " + ex.Message);
    }

    return emp;
}
