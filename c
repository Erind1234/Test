[HttpPost]
public ActionResult SaveQRCodeValue(string QRCODEVAL)
{
    try
    {
        // Here, you can save the QRCODEVAL to your database or perform any other necessary operations
        // For example, you can call your repository method to save it
        // empRepo.SaveQRCodeValue(QRCODEVAL);

        // Optionally, you can return a response to the client if needed
        return Json(new { success = true, message = "QR Code value saved successfully" });
    }
    catch (Exception ex)
    {
        // Handle any errors that occur during the saving process
        return Json(new { success = false, message = "An error occurred while saving the QR Code value: " + ex.Message });
    }
}
