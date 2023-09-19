SqlCommand getIdCommand = new SqlCommand("SELECT SCOPE_IDENTITY() AS NewID", con);
            SqlDataReader reader = getIdCommand.ExecuteReader();

            if (reader.Read() && reader["NewID"] != DBNull.Value)
            {
                emp.ID = Convert.ToInt32(reader["NewID"]);
            }

            reader.Close();
