using InApps.Models;
using InApps.Repository;
using System;
using System.Collections.Generic;
using System.Web.Mvc;

namespace InApps.Controllers
{
    public class FiscalizationController : Controller
    {
        private EmpRepository empRepo;

        public FiscalizationController()
        {
            empRepo = new EmpRepository();
        }

        // Display the main page with a list of employees
        public ActionResult Index()
        {
            List<EmpModel> empList = empRepo.GetAllEmployees();
            return View(empList);
        }

        // Display the page for adding fiscalization
        [HttpGet]
        public ActionResult AddFiscalization()
        {
            return View();
        }

        // Save fiscalization data to the database
        [HttpPost]
        public ActionResult SaveFiscalization(EmpModel emp)
        {
            try
            {
                // Save the data to the database
                bool isAdded = empRepo.SaveFiscalization(emp);

                if (isAdded)
                {
                    // Get the last saved employee
                    EmpModel lastSavedEmployee = empRepo.GetLastSavedEmployee();

                    return View("Popup", lastSavedEmployee);
                }
                else
                {
                    ViewBag.Message = "Failed to save fiscalization details";
                    return View("Popup");
                }
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("Index");
            }
        }

        // Update fiscalization data in the database
        [HttpPost]
        public ActionResult UpdateFiscalization(EmpModel emp)
        {
            try
            {
                // Update the data in the database
                bool isUpdated = empRepo.UpdateFiscalization(emp);

                if (isUpdated)
                {
                    // Get the updated employee data
                    EmpModel updatedEmployee = empRepo.GetEmployeeById(emp.ID);

                    return View("Popup", updatedEmployee);
                }
                else
                {
                    ViewBag.Message = "Failed to update fiscalization details";
                    return View("Popup");
                }
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("Index");
            }
        }
    }
}



*******************
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using InApps.Models;

namespace InApps.Repository
{
    public class EmpRepository
    {
        private readonly string connectionString;

        public EmpRepository()
        {
            connectionString = ConfigurationManager.ConnectionStrings["FacilegalConn"].ConnectionString;
        }

        // Get a list of all employees
        public List<EmpModel> GetAllEmployees()
        {
            List<EmpModel> empList = new List<EmpModel>();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                // Implement SQL query to retrieve all employees
                // Example: SELECT * FROM [dbo].[Fiscal]
                using (SqlCommand cmd = new SqlCommand("SELECT * FROM [dbo].[Fiscal]", connection))
                {
                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            // Map database columns to EmpModel properties
                            EmpModel emp = new EmpModel
                            {
                                ID = Convert.ToInt32(reader["ID"]),
                                // Map other properties here
                            };
                            empList.Add(emp);
                        }
                    }
                }
            }

            return empList;
        }

        // Save fiscalization data to the database
        public bool SaveFiscalization(EmpModel emp)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    // Implement SQL query to insert fiscalization data
                    // Example: INSERT INTO [dbo].[Fiscal] (column1, column2, ...) VALUES (@value1, @value2, ...)
                    using (SqlCommand cmd = new SqlCommand("INSERT INTO [dbo].[Fiscal] (column1, column2, ...) VALUES (@value1, @value2, ...)", connection))
                    {
                        // Set SQL parameters with values from the emp object
                        // Example: cmd.Parameters.AddWithValue("@value1", emp.Property1);
                        int rowsAffected = cmd.ExecuteNonQuery();

                        return rowsAffected > 0; // Return true if data is saved successfully
                    }
                }
            }
            catch (Exception ex)
            {
                // Log the exception here for debugging purposes
                return false;
            }
        }

        // Get the last saved employee
        public EmpModel GetLastSavedEmployee()
        {
            EmpModel lastSavedEmployee = new EmpModel();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                // Implement SQL query to get the last saved employee
                // Example: SELECT TOP 1 * FROM [dbo].[Fiscal] ORDER BY ID DESC
                using (SqlCommand cmd = new SqlCommand("SELECT TOP 1 * FROM [dbo].[Fiscal] ORDER BY ID DESC", connection))
                {
                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            // Map database columns to EmpModel properties
                            lastSavedEmployee.ID = Convert.ToInt32(reader["ID"]);
                            // Map other properties here
                        }
                    }
                }
            }

            return lastSavedEmployee;
        }

        // Update fiscalization data in the database
        public bool UpdateFiscalization(EmpModel emp)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    // Implement SQL query to update fiscalization data
                    // Example: UPDATE [dbo].[Fiscal] SET column1 = @value1, column2 = @value2 WHERE ID = @ID
                    using (SqlCommand cmd = new SqlCommand("UPDATE [dbo].[Fiscal] SET column1 = @value1, column2 = @value2 WHERE ID = @ID", connection))
                    {
                        // Set SQL parameters with values from the emp object
                        // Example: cmd.Parameters.AddWithValue("@value1", emp.Property1);
                        int rowsAffected = cmd.ExecuteNonQuery();

                        return rowsAffected > 0; // Return true if data is updated successfully
                    }
                }
            }
            catch (Exception ex)
            {
                // Log the exception here for debugging purposes
                return false;
            }
        }

        // Get an employee by ID
        public EmpModel GetEmployeeById(int id)
        {
            EmpModel emp = new EmpModel();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                // Implement SQL query to get an employee by ID
                // Example: SELECT * FROM [dbo].[Fiscal] WHERE ID = @ID
                using (SqlCommand cmd = new SqlCommand("SELECT * FROM [dbo].[Fiscal] WHERE ID = @ID", connection))
                {
                    // Set SQL parameter for ID
                    cmd.Parameters.AddWithValue("@ID", id);

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            // Map database columns to EmpModel properties
                            emp.ID = Convert.ToInt32(reader["ID"]);
                            // Map other properties here
                        }
                    }
                }
            }

            return emp;
        }
    }
}
*******

CREATE PROCEDURE InsertFiscalization
    @Column1 VARCHAR(50),
    @Column2 VARCHAR(50),
    -- Add other columns here
AS
BEGIN
    INSERT INTO [dbo].[Fiscal] (Column1, Column2, ...) -- Specify all columns
    VALUES (@Column1, @Column2, ...) -- Specify all parameter values
END
****************

using (SqlCommand cmd = new SqlCommand("InsertFiscalization", connection))
{
    cmd.CommandType = CommandType.StoredProcedure;
    // Set SQL parameters with values from the emp object
    // Example: cmd.Parameters.AddWithValue("@Column1", emp.Property1);
    int rowsAffected = cmd.ExecuteNonQuery();

    return rowsAffected > 0; // Return true if data is saved successfully
}
****************************


