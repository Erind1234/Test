using InApps.Models;
using System;
using System.Web.Mvc;
using System.Data.SqlClient;
using System.Configuration;
using System.Collections.Generic;
using System.Data;

using static InApps.Models.Fiscal;
using static InApps.Models.FiscalLog;

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


        //public ActionResult Index()
        //{
        //    return View();

        //}


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


        [HttpPost]
        public ActionResult SaveFiscalization(string QRCODEVAL, string IBANNR, string STPROFILE, string REFCODE, string PYMTORDNUM, string PAYERNIPT, string EINFIC, string PAIDAMT, string PAIDCUR, string TRANSACTIONCODE, string PYMTTYPE, string BANKNAME, string NIVF, string INVOICEDATE)
        {
            try
            {
                Guid myuuid = Guid.NewGuid();
                string myuuidAsString = myuuid.ToString();


                EmpModel emp = new EmpModel();
                emp.ID = myuuidAsString;
                emp.QRCODEVAL = "Null";
                emp.STPROFILE = "Null";
                emp.NIVF = NIVF;
                emp.REFCODE = REFCODE;
                emp.PYMTORDNUM = PYMTORDNUM;
                emp.PAYERNIPT = PAYERNIPT;
                emp.EINFIC = "Null";
                emp.PAIDAMT = PAIDAMT;
                emp.PAIDCUR = PAIDCUR;
                emp.TRANSACTIONCODE = TRANSACTIONCODE;
                emp.PYMTTYPE = "Null";
                emp.BANKNIPT = "Null";
                emp.DATTIMSEND = "Null";
                emp.PYMTDATTIM = "Null";
                emp.OVERPAIDAMT = "Null";
                emp.PYMTSTATUS = "Null";
                emp.CODE = "Null";
                emp.MESSAGE = "Null";
                emp.USR = "Null";
                emp.SELLERNIPT = "Null";
                emp.INVOICEDATE = INVOICEDATE;
                emp.IBANNR = IBANNR;
                emp.SWIFTNR = "Null";
                emp.BANKNAME = "BANKNAME";
                bool isAdded = empRepo.SaveFiscalization(emp);


                if (isAdded)
                {

                    //ViewBag.savedData = new HtmlString(tableHtml);
                    return View("Popup", emp);
                }
                else
                {
                    ViewBag.Message = "Failed to save fiscalization details";
                }

                return View("Popup");
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("Index");
            }
        }

        // GET: Employee/EditEmpDetails/5    
        public ActionResult EditEmpDetails(string Id)
        {
            EmpRepository EmpRepo = new EmpRepository();
            EmpModel emp = empRepo.GetEmpModelById(Id);
            return View(emp);

        }

        // POST: Employee/EditEmpDetails/5    
        [HttpPost]

        public ActionResult EditEmpDetails(EmpModel emp)

        {
            try
            {
                EmpRepository EmpRepo = new EmpRepository();
                bool updated = EmpRepo.Update(emp);
                if (updated)
                {
                    return RedirectToAction("Index");
                }
                else
                {
                    ModelState.AddModelError("", "Update failed");
                    return View();
                }
            }
            catch (Exception e)
            {
                return View();
            }
            }







        }
    }
