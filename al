public List<EmpModel> SearchByRefcode(string refcode)
{
    List<EmpModel> results = new List<EmpModel>();

    try
    {
        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            using (SqlCommand cmd = new SqlCommand("YourStoredProcedureName", connection))
            {
                cmd.CommandType = CommandType.StoredProcedure;

                // Add parameters to the stored procedure
                cmd.Parameters.Add(new SqlParameter("@Refcode", refcode));

                connection.Open();

                using (SqlDataReader reader = cmd.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        EmpModel emp = new EmpModel
                        {
                            // Map the data from the reader to your EmpModel properties
                            // For example: Property1 = reader["ColumnName1"].ToString()
                        };
                        results.Add(emp);
                    }
                }
            }
        }
    }
    catch (Exception ex)
    {
        // Handle any exceptions here
        // You can log the exception, throw it, or handle it as needed
        // For example: throw new Exception("An error occurred: " + ex.Message);
    }

    return results; // Return the list of results
}
