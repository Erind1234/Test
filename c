using System;
using System.Data;
using System.Data.SqlClient;

public class EmpRepository
{
    private SqlConnection con;

    // Constructor to initialize the SqlConnection
    public EmpRepository()
    {
        // Initialize the connection string or retrieve it from your configuration
        string connectionString = "Your_Connection_String_Here";
        con = new SqlConnection(connectionString);
    }

    // Get an employee by ID
    public EmpModel GetEmpModelById(string ID)
    {
        connection();
        con.Open();
        SqlCommand com = new SqlCommand("SELECT * FROM [dbo].[Fiscalizimi] WHERE ID = @ID", con);
        com.Parameters.AddWithValue("@ID", ID);

        SqlDataReader reader = com.ExecuteReader();
        EmpModel emp = new EmpModel();
        if (reader.Read())
        {
            // Map the data from the database to the EmpModel object
            emp.ID = reader["ID"].ToString();
            emp.REFCODE = reader["REFCODE"].ToString();
            // Add mappings for other fields here

            // Close the database connection
            con.Close();

            return emp;
        }

        // If no employee is found, return null
        con.Close();
        return null;
    }

    // Update an employee's details
    public bool Update(EmpModel emp)
    {
        connection();
        SqlCommand com = new SqlCommand("Your_Update_Stored_Procedure_Name", con);
        com.CommandType = CommandType.StoredProcedure;

        com.Parameters.AddWithValue("@ID", emp.ID);
        com.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
        // Add mappings for other fields here

        con.Open();
        int i = com.ExecuteNonQuery();
        con.Close();

        // Check if the update was successful
        return i >= 1;
    }

    // Helper method to initialize the SqlConnection
    private void connection()
    {
        if (con.State == ConnectionState.Closed)
        {
            con.Open();
        }
    }
}





//////////////////////////


@model EmpModel
@{
    ViewBag.Title = "Edit Employee Details";
}

<h2>Edit Employee Details</h2>

@using (Html.BeginForm())
{
    @Html.AntiForgeryToken()

    <div class="form-horizontal">
        @Html.HiddenFor(model => model.ID)

        <div class="form-group">
            @Html.LabelFor(model => model.REFCODE, new { @class = "control-label col-md-2" })
            <div class="col-md-10">
                @Html.EditorFor(model => model.REFCODE)
                @Html.ValidationMessageFor(model => model.REFCODE)
            </div>
        </div>

        <!-- Add similar fields for other properties here -->

        <div class="form-group">
            <div class="col-md-offset-2 col-md-10">
                <input type="submit" value="Save" class="btn btn-default" />
            </div>
        </div>
    </div>
}

<div>
    @Html.ActionLink("Back to List", "Index")
</div>



---------------------------------------

using System;
using System.Web.Mvc;
using YourNamespace.Models; // Make sure to include the appropriate namespace for your models.
using YourNamespace.Repositories; // Include the appropriate namespace for your repository.

public class EmployeeController : Controller
{
    // GET: Employee/EditEmpDetails/5    
    public ActionResult EditEmpDetails(string id)
    {
        if (id == null)
        {
            return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
        }

        EmpRepository empRepo = new EmpRepository();
        EmpModel emp = empRepo.GetEmpModelById(id);

        if (emp == null)
        {
            return HttpNotFound();
        }

        return View(emp);
    }

    // POST: Employee/EditEmpDetails/5    
    [HttpPost]
    [ValidateAntiForgeryToken]
    public ActionResult EditEmpDetails(EmpModel emp)
    {
        try
        {
            if (ModelState.IsValid)
            {
                EmpRepository empRepo = new EmpRepository();
                bool updated = empRepo.Update(emp);

                if (updated)
                {
                    return RedirectToAction("Index"); // Redirect to the appropriate action after successful update.
                }
                else
                {
                    ModelState.AddModelError("", "Update failed");
                }
            }

            return View(emp);
        }
        catch (Exception e)
        {
            // Handle exceptions, log errors, or display an error message as needed.
            ModelState.AddModelError("", "An error occurred while updating.");
            return View(emp);
        }
    }
}
