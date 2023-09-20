<script>
    $(document).ready(function () {
        $("#deleteButton").on("click", function () {
            if (confirm("Are you sure you want to delete this record?")) {
                $.ajax({
                    url: "@Url.Action("DeleteFiscalization", "Fiscalization")",
                    type: "POST",
                    data: { id: @Model.ID },
                    success: function (result) {
                        // Handle success (e.g., close the popup or show a message)
                        // You can choose to close the popup or update the UI as needed.
                        alert("Record deleted successfully.");
                    },
                    error: function (error) {
                        alert("An error occurred while deleting the record.");
                    }
                });
            }
        });
    });
</script>
///////////////////
    [HttpPost]
public ActionResult DeleteFiscalization(int id)
{
    try
    {
        bool isDeleted = empRepo.DeleteFiscalization(id);

        if (isDeleted)
        {
            // Return a success response
            return Json(new { success = true });
        }
        else
        {
            // Return an error response
            return Json(new { success = false, message = "Failed to delete fiscalization record." });
        }
    }
    catch (Exception ex)
    {
        // Return an error response in case of exceptions
        return Json(new { success = false, message = "An error occurred: " + ex.Message });
    }
}
////////////////
public bool DeleteFiscalization(int id)
{
    using (var con = new SqlConnection(connectionString))
    {
        con.Open();
        SqlCommand com = new SqlCommand("DeleteFiscalization", con);
        com.CommandType = CommandType.StoredProcedure;
        com.Parameters.AddWithValue("@ID", id);

        int rowsAffected = com.ExecuteNonQuery();
        return rowsAffected > 0;
    }
}

//////////
