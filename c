[HttpPost]
public ActionResult SaveQRCodeValue(string QRCODEVAL)
{
    try
    {
        // Assuming you have an instance of EmpRepository, update the QRCODEVAL field in the database
        EmpRepository repo = new EmpRepository();
        var emp = new EmpModel();
        emp.QRCODEVAL = QRCODEVAL; // Set the QRCODEVAL property in the EmpModel
        int result = repo.SaveFiscalization(emp);

        if (result > 0)
        {
            // The value was successfully saved in the database
            return Json(new { success = true, message = "QR Code value saved successfully." });
        }
        else
        {
            // There was an issue saving the value
            return Json(new { success = false, message = "Failed to save QR Code value." });
        }
    }
    catch (Exception ex)
    {
        return Json(new { success = false, message = ex.Message });
    }
}
