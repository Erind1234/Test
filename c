 SqlCommand getIdCommand = new SqlCommand("SELECT SCOPE_IDENTITY()", con);
    emp.ID = Convert.ToInt32(getIdCommand.ExecuteScalar());

    con.Close();
