// Retrieve a list of EmpModel objects from the database
public List<EmpModel> GetEmpList()
{
    List<EmpModel> empList = new List<EmpModel>();

    try
    {
        con.Open();
        SqlCommand com = new SqlCommand("SELECT * FROM [dbo].[Fiscal]", con);

        SqlDataReader reader = com.ExecuteReader();
        while (reader.Read())
        {
            EmpModel emp = new EmpModel();
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

            empList.Add(emp);
        }
    }
    catch (Exception ex)
    {
        // Handle exceptions here or log them
        Console.WriteLine("Error: " + ex.Message);
    }
    finally
    {
        con.Close();
    }

    return empList;
}
