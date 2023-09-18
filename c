public ActionResult Index(string searchBox)
{
    try
    {
        string[] splitValues = searchBox.Split(';');

        // Assign split values to ViewBag variables
        ViewBag.p1 = splitValues.Length > 0 ? splitValues[0] : string.Empty;
        ViewBag.p2 = splitValues.Length > 1 ? splitValues[1] : string.Empty;
        ViewBag.p3 = splitValues.Length > 2 ? splitValues[2] : string.Empty;
        ViewBag.p4 = splitValues.Length > 3 ? splitValues[3] : string.Empty;
        ViewBag.p5 = splitValues.Length > 4 ? splitValues[4] : string.Empty;
        ViewBag.p6 = splitValues.Length > 5 ? splitValues[5] : string.Empty;
        ViewBag.p7 = splitValues.Length > 6 ? splitValues[6] : string.Empty;
        ViewBag.p8 = splitValues.Length > 7 ? splitValues[7] : string.Empty;
        ViewBag.p9 = splitValues.Length > 8 ? splitValues[8] : string.Empty;
        ViewBag.p10 = splitValues.Length > 9 ? splitValues[9] : string.Empty;

        List<EmpModel> searchResults = empRepo.SearchEmpList(searchBox);

        return View("searchResults", searchResults);
    }
    catch (Exception ex)
    {
        ViewBag.Error = "An error occurred: " + ex.Message;
        return View();
    }
}
