using InApps.Models;
using System;
using System.Web.Mvc;
using System.Data.SqlClient;
using System.Configuration;
using System.Collections.Generic;
using System.Data;
using InApps.Repository;

namespace InApps.Controllers
{
    public class FiscalizationController : Controller
    {
        private EmpRepository empRepo;

        public FiscalizationController()
        {
            empRepo = new EmpRepository();
        }
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


                return View("");
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View();
            }
        }
    
        // GET: Display the index view
        public ActionResult Index()
        {
            EmpModel emp = new EmpModel();
            return View(emp);
        }

        // GET: Display the AddFiscalization view
        [HttpGet]
        public ActionResult AddFiscalization()
        {
            return View();
        }

        // POST: Handle the form submission for saving fiscalization data
        [HttpPost]
        public ActionResult SaveFiscalization(EmpModel emp)
        {
            try
            {
                // Assuming your EmpModel has properties matching the form fields
                bool isAdded = empRepo.SaveFiscalization(emp);

                if (isAdded)
                {
                    // Redirect to a view that shows the saved data or a success message
                    return RedirectToAction("FiscalizationDetails", new { id = emp.ID });
                }
                else
                {
                    ViewBag.Message = "Failed to save fiscalization details";
                    return View("AddFiscalization");
                }
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("AddFiscalization");
            }
        }

        // GET: Display the details of a fiscalization record
        public ActionResult FiscalizationDetails(int id)
        {
            EmpModel emp = empRepo.GetEmployeeById(id);

            if (emp != null)
            {
                return View(emp);
            }
            else
            {
                ViewBag.Message = "Fiscalization record not found";
                return RedirectToAction("Index");
            }
        }

        // GET: Display the edit view for a fiscalization record
        public ActionResult EditFiscalization(int id)
        {
            EmpModel emp = empRepo.GetEmployeeById(id);

            if (emp != null)
            {
                return View(emp);
            }
            else
            {
                ViewBag.Message = "Fiscalization record not found";
                return RedirectToAction("Index");
            }
        }
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
    }
}
