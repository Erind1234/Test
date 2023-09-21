using System;
using System.Collections.Generic;
using System.Web.Mvc;
using InApps.Models; // Update the namespace as needed for your model

namespace InApps.Controllers
{
    public class FiscalizationController : Controller
    {
        private readonly EmpRepository empRepo = new EmpRepository(); // Adjust repository name as needed

        // GET: Fiscalization
        public ActionResult Index()
        {
            return View();
        }

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
                    // ... (assign other ViewBag variables as needed)
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

        [HttpPost]
        public ActionResult SaveFiscalization(EmpModel model)
        {
            try
            {
                // Perform the saving logic here
                // ...

                ViewBag.savedData = "Data saved successfully.";
                return RedirectToAction("Index");
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return RedirectToAction("Index");
            }
        }

        // Add other controller actions as needed

        // Example of a repository method to retrieve all fiscalization records
        // Replace with your actual repository method
        private List<EmpModel> GetAllFiscalizations()
        {
            return empRepo.GetAllFiscalizations();
        }
    }
}
