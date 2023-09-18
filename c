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

        // POST: Handle the form submission for updating fiscalization data
        [HttpPost]
        public ActionResult UpdateFiscalization(EmpModel emp)
        {
            try
            {
                bool isUpdated = empRepo.UpdateFiscalization(emp);

                if (isUpdated)
                {
                    // Redirect to a view that shows the updated data or a success message
                    return RedirectToAction("FiscalizationDetails", new { id = emp.ID });
                }
                else
                {
                    ViewBag.Message = "Failed to update fiscalization details";
                    return View("EditFiscalization", emp);
                }
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("EditFiscalization", emp);
            }
        }
    }
}
