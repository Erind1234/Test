public class EmpRepository
{
    private const string connectionString = "FacilegalConn";

    // Define a method to retrieve the last saved employee
    public EmpModel GetLastSavedEmployee()
    {
        EmpModel emp = null;

        try
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // Define your SQL query to retrieve the last saved employee
                string query = "SELECT TOP 1 * FROM YourEmployeeTable ORDER BY ID DESC";

                using (SqlCommand cmd = new SqlCommand(query, connection))
                {
                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            // Map the data from the database to your EmpModel class
                            emp = new EmpModel
                            {
                                // Map your columns here
                                // Example: ID = reader["ID"].ToString(),
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

    // Other methods and repository code...
}
