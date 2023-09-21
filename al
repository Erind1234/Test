using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using InApps.Models;

namespace InApps.Repository
{
    public class EmpRepository
    {
        private readonly string connectionString = "YourConnectionString";

        public List<EmpModel> SearchByRefcode(string refcode)
        {
            List<EmpModel> results = new List<EmpModel>();

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

            return results;
        }

        // Other repository methods for CRUD operations...
    }
}
