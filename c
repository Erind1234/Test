public bool SaveFiscalization(EmpModel emp)
{
    connection();
    con.Open();

    SqlCommand com = new SqlCommand("AddNewFiscal", con);
    com.CommandType = CommandType.StoredProcedure;
    // ... (parameter setup)

    int i = com.ExecuteNonQuery();
    con.Close();

    if (i >= 1)
    {
        // Data was successfully inserted, now retrieve the last inserted record
        EmpModel lastInsertedEmp = GetLastInsertedEmp();

        // Check if the lastInsertedEmp is not null or has a valid ID
        if (lastInsertedEmp != null && !string.IsNullOrEmpty(lastInsertedEmp.ID))
        {
            return true;
        }
    }

    // Data insertion failed or no valid lastInsertedEmp found
    return false;
}
