using InApps.Models;
using System;
using System.Web.Mvc;
using System.Data.SqlClient;
using System.Configuration;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Collections;
using InApps.Repository;
using System.Web;

namespace InApps.Controllers
{


    public class FiscalizationController : Controller
    {

        private EmpRepository empRepo;

        public FiscalizationController()
        {
            empRepo = new EmpRepository();
        }


        public ActionResult Index()
        {
            EmpModel emp = new EmpModel();

            return View(emp);

        }


        private const string connectionString = "FacilegalConn";
        [HttpGet]
        public ActionResult AddFiscalization()
        {
            return View();
        }


        [HttpPost]
        public ActionResult Index(string searchBox)
        {
            try
            {
                string[] splitValues = searchBox.Split(';');

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
                ViewBag.p11 = splitValues.Length > 10 ? splitValues[10] : string.Empty;

                return View("");
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View();
            }
        }



        [HttpPost]
        public ActionResult SaveQRCodeValue(string QRCODEVAL)
        {
            try
            {
                var empModel = new EmpModel();
                empModel.QRCODEVAL = QRCODEVAL;
                empRepo.SaveQRCodeValue(empModel);
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



        [HttpPost]
        public ActionResult SaveFiscalization(EmpModel emp)
        {
            try
            {
                string qrcodeval = emp.QRCODEVAL;
                
                int newlyInsertedID = empRepo.SaveFiscalization(emp);

                if (newlyInsertedID > 0)
                { emp.ID = newlyInsertedID;
                    return View("Popup",emp);
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




        

        [HttpGet]
        public ActionResult EditFiscalization(int ID)
        {
            EmpModel emp = empRepo.GetFiscalizationById(ID);

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
                
                    bool isUpdated = empRepo.UpdateFiscalization(emp);

                    if (isUpdated)
                    {
                        return View("Popup",emp); 
                    }
                    else
                    {
                        ViewBag.Message = "Failed to update fiscalization details.";
                    }
                return View("Index");
                }


            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("Index", emp);
            }
       }

        [HttpPost]
        public ActionResult DeleteFiscalization(int ID)
        {
            try
            {
                bool isDeleted = empRepo.DeleteFiscalization(ID);

                if (isDeleted)
                {
                    return Json(new { success = true });
                }
                else
                {
                    return Json(new { success = false, message = "Failed to delete fiscalization record." });
                }
            }
            catch (Exception ex)
            {
                return Json(new { success = false, message = "An error occurred: " + ex.Message });
            }
        }
        [HttpPost]
        public ActionResult SearchByRefcode(string REFCODE)
        {
            try
            { 
                List<EmpModel> searchResults = empRepo.SearchByRefcode(REFCODE);
                return PartialView("_SearchResults", searchResults);
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("Index");
            }
        }






    }
}
