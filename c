[HttpPost]
public ActionResult UpdateFiscalization(EmpModel emp)
{
    try
    {
        if (ModelState.IsValid)
        {
            bool isUpdated = empRepo.UpdateFiscalization(emp);

            if (isUpdated)
            {
                return RedirectToAction("Index"); // Redirect to the index page after successful update
            }
            else
            {
                ViewBag.Message = "Failed to update fiscalization details";
                return View("Edit", emp); // Return to the edit view with an error message
            }
        }

        return View("Edit", emp); // If ModelState is not valid, return to the edit view
    }
    catch (Exception ex)
    {
        ViewBag.Error = "An error occurred: " + ex.Message;
        return View("Edit", emp); // Return to the edit view with an error message
    }
}


*****
REP
public bool UpdateFiscalization(EmpModel emp)
{
    try
    {
        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            connection.Open();
            SqlCommand cmd = new SqlCommand("UPDATE [dbo].[Fiscal] SET REFCODE = @REFCODE, PYMTORDNUM = @PYMTORDNUM, DATTIMSEND = @DATTIMSEND, BANKNIPT = @BANKNIPT, PAYERNIPT = @PAYERNIPT, /* Add more columns here */ WHERE ID = @ID", connection);

            cmd.Parameters.AddWithValue("@ID", emp.ID);
            cmd.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
            cmd.Parameters.AddWithValue("@PYMTORDNUM", emp.PYMTORDNUM);
            cmd.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
            cmd.Parameters.AddWithValue("@BANKNIPT", emp.BANKNIPT);
            cmd.Parameters.AddWithValue("@PAYERNIPT", emp.PAYERNIPT);
            /* Add more parameters for other columns */

            int rowsAffected = cmd.ExecuteNonQuery();

            return rowsAffected > 0;
        }
    }
    catch (Exception ex)
    {
        // Log the exception here for debugging purposes
        return false;
    }
}
