using System;
using System.Web.Mvc;
using InApps.Models; // Make sure to import your model namespace

namespace InApps.Controllers
{
    public class FiscalizationController : Controller
    {
        private readonly EmpRepository _repository; // Replace with your repository class

        public FiscalizationController()
        {
            // Initialize your repository here
            _repository = new EmpRepository();
        }

        // Your other action methods here

        [HttpPost]
        public ActionResult SaveQRCodeValue(string QRCODEVAL)
        {
            try
            {
                // Assuming you have an instance of your model class (e.g., EmpModel)
                EmpModel empModel = new EmpModel();
                
                // Set the QRCODEVAL property of the model
                empModel.QRCODEVAL = QRCODEVAL;
                
                // Call a method in your repository to save the model to the database
                _repository.SaveEmpModel(empModel); // Replace with your actual repository method

                ViewBag.Message = "QR Code value saved successfully.";
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred while saving the QR Code value: " + ex.Message;
            }

            return View("Index"); // You can redirect to the appropriate view
        }

        // Your other controller actions here
    }
}
