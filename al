public class FiscalizationController : Controller
{
    // ... (your existing code)

    [HttpPost]
    public ActionResult Index(string searchBox, string refCodeSearchBox)
    {
        try
        {
            List<EmpModel> matchingRows = null;

            if (!string.IsNullOrEmpty(refCodeSearchBox))
            {
                // Perform a search by REFCODE and return matching rows
                matchingRows = empRepo.GetFiscalizationByREFCODE(refCodeSearchBox);
            }
            else if (!string.IsNullOrEmpty(searchBox))
            {
                string[] splitValues = searchBox.Split(';');
                // Assign split values to ViewBag variables
                ViewBag.p1 = splitValues.Length > 0 ? splitValues[0] : string.Empty;
                ViewBag.p2 = splitValues.Length > 1 ? splitValues[1] : string.Empty;
                // ... (other ViewBag assignments)
            }
            else
            {
                // Handle other cases or return all rows
                matchingRows = empRepo.GetAllFiscalizations();
            }

            return View(matchingRows); // Return the matching rows to the view
        }
        catch (Exception ex)
        {
            ViewBag.Error = "An error occurred: " + ex.Message;
            return View();
        }
    }

    // ... (your existing code)

    public List<EmpModel> GetFiscalizationByREFCODE(string refCode)
    {
        // Implement the logic to retrieve fiscalization records by REFCODE from the database
        // Example: return dbContext.Fiscalizations.Where(f => f.REFCODE == refCode).ToList();
    }

    public List<EmpModel> GetAllFiscalizations()
    {
        // Implement the logic to retrieve all fiscalization records from the database
        // Example: return dbContext.Fiscalizations.ToList();
    }
    
    // ... (your existing code)
}
