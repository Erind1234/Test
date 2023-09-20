public class FiscalizationController : Controller
{
    private EmpRepository empRepo;

    public FiscalizationController()
    {
        empRepo = new EmpRepository();
    }

    // ... Other controller methods

    [HttpPost]
    public ActionResult SaveFiscalization(EmpModel emp)
    {
        try
        {
            int newlyInsertedID = empRepo.SaveFiscalization(emp);

            if (newlyInsertedID > 0)
            {
                // Redirect to an edit view for the newly inserted row
                return RedirectToAction("EditFiscalization", new { id = newlyInsertedID });
            }
            else
            {
                ViewBag.Message = "Failed to save fiscalization details.";
            }

            return View("Popup");
        }
        catch (Exception ex)
        {
            ViewBag.Error = "An error occurred: " + ex.Message;
            return View("Index");
        }
    }

    public ActionResult EditFiscalization(int id)
    {
        // Load the data for editing based on the retrieved ID
        // Here, you should retrieve the row from the database using the 'id'
        // and pass it to the edit view
        EmpModel emp = empRepo.GetFiscalizationById(id);

        if (emp == null)
        {
            return HttpNotFound();
        }

        return View(emp);
    }

    [HttpPost]
    public ActionResult UpdateFiscalization(EmpModel emp)
    {
        try
        {
            // Update the row based on the 'emp.ID'
            bool isUpdated = empRepo.UpdateFiscalization(emp);

            if (isUpdated)
            {
                // Redirect to a view that displays the updated row
                return RedirectToAction("ShowFiscalization", new { id = emp.ID });
            }
            else
            {
                ViewBag.Message = "Failed to update fiscalization details.";
            }

            return View("EditFiscalization", emp);
        }
        catch (Exception ex)
        {
            ViewBag.Error = "An error occurred: " + ex.Message;
            return View("EditFiscalization", emp);
        }
    }
}
