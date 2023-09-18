public List<EmpModel> SearchEmpList(string[] splitValues)
{
    try
    {
        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            connection.Open();

            // Define your SQL query to retrieve search results based on splitValues
            // For example, you can use splitValues to filter your query
            string query = "SELECT * FROM [dbo].[Fiscal] WHERE SomeColumn = @Value1 OR AnotherColumn = @Value2";

            using (SqlCommand cmd = new SqlCommand(query, connection))
            {
                // Set parameter values based on splitValues (customize this part based on your requirements)
                cmd.Parameters.AddWithValue("@Value1", splitValues[0]);
                cmd.Parameters.AddWithValue("@Value2", splitValues[1]);

                List<EmpModel> searchResults = new List<EmpModel>();

                using (SqlDataReader reader = cmd.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        // Map your columns to EmpModel and add to the searchResults list
                        EmpModel emp = new EmpModel
                        {
                            ID = Convert.ToInt32(reader["ID"]),
                            // Map other properties here
                        };

                        searchResults.Add(emp);
                    }
                }

                return searchResults;
            }
        }
    }
    catch (Exception ex)
    {
        // Handle exceptions here
        Console.WriteLine("An error occurred: " + ex.Message);
        return null; // Return an appropriate value in case of an error
    }
}
