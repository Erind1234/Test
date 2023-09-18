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

                List<EmpModel> searchResults = empRepo.SearchEmpList(searchBox);

                return View("searchResults" +
                    "" +
                    "");
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View();
            }
        }

        public EmpModel GetLastSavedEmployee()
        {
            EmpModel emp = null;

            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // Define your SQL query to retrieve the last saved employee
                    string query = "SELECT TOP 1 * FROM [dbo].[Fiscal] ORDER BY ID DESC";

                    using (SqlCommand cmd = new SqlCommand(query, connection))
                    {
                        using (SqlDataReader reader = cmd.ExecuteReader())
                        {
                            if (reader.Read())
                            {

                                emp = new EmpModel
                                {
                                    // Map your columns here
                                    ID = Convert.ToInt32(reader["ID"]),
                                    REFCODE = reader["REFCODE"].ToString(),
                                    PYMTORDNUM = reader["PYMTORDNUM"].ToString(),
                                    DATTIMSEND = reader["DATTIMSEND"].ToString(),
                                    BANKNIPT = reader["BANKNIPT"].ToString(),
                                    PAYERNIPT = reader["PAYERNIPT"].ToString(),
                                    EINFIC = reader["EINFIC"].ToString(),
                                    PYMTDATTIM = reader["PYMTDATTIM"].ToString(),
                                    PAIDAMT = reader["PAIDAMT"].ToString(),
                                    OVERPAIDAMT = reader["OVERPAIDAMT"].ToString(),
                                    PAIDCUR = reader["PAIDCUR"].ToString(),
                                    TRANSACTIONCODE = reader["TRANSACTIONCODE"].ToString(),
                                    PYMTTYPE = reader["PYMTTYPE"].ToString(),
                                    PYMTSTATUS = reader["PYMTSTATUS"].ToString(),
                                    CODE = reader["CODE"].ToString(),
                                    MESSAGE = reader["MESSAGE"].ToString(),
                                    USR = reader["USR"].ToString(),
                                    SELLERNIPT = reader["SELLERNIPT"].ToString(),
                                    INVOICEDATE = reader["INVOICEDATE"].ToString(),
                                    IBANNR = reader["IBANNR"].ToString(),
                                    SWIFTNR = reader["SWIFTNR"].ToString(),
                                    BANKNAME = reader["BANKNAME"].ToString(),
                                    QRCODEVAL = reader["QRCODEVAL"].ToString(),
                                    NIVF = reader["NIVF"].ToString(),
                                    STPROFILE = reader["STPROFILE"].ToString()
                                };
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                // Handle exceptions here
                Console.WriteLine("An error occurred: " + ex.Message);
            }

            return emp;
        }

        // Other methods and repository code...




        [HttpPost]
        public ActionResult SaveFiscalization(string QRCODEVAL, string IBANNR, string STPROFILE, string REFCODE, string PYMTORDNUM, string PAYERNIPT, string EINFIC, string PAIDAMT, string PAIDCUR, string TRANSACTIONCODE, string PYMTTYPE, string BANKNAME, string NIVF, string INVOICEDATE)
        {
            try
            {



                EmpModel emp = new EmpModel();

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
                object empRepo = null;
                bool isAdded = empRepo.SaveFiscalization(emp);


                if (isAdded)
                {

                    //ViewBag.savedData = new HtmlString(tableHtml);
                    return View("Popup", emp);
                }
                else
                {
                    ViewBag.Message = "Failed to save fiscalization details";
                    return View("Popup");
                }


            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("Index");
            }
        }




    }



    }






using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using InApps.Models;
using System.Linq;
namespace InApps.Repository
    {
        public class EmpRepository
        {
            private readonly string connectionString; // Set your database connection string here

            public EmpRepository()
            {
                connectionString = "FacilegalConn";
            }

            public bool SaveFiscalization(EmpModel emp)
            {
            
                try
                {
                    using (SqlConnection connection = new SqlConnection(connectionString))
                    {
                        connection.Open();
                        SqlCommand cmd = new SqlCommand("INSERT INTO [dbo].[Fiscal] (ID, QRCODEVAL, STPROFILE, NIVF, REFCODE, PYMTORDNUM, PAYERNIPT, EINFIC, PAIDAMT, PAIDCUR, TRANSACTIONCODE, PYMTTYPE, BANKNIPT, DATTIMSEND, PYMTDATTIM, OVERPAIDAMT, PYMTSTATUS, CODE, MESSAGE, USR, SELLERNIPT, INVOICEDATE, IBANNR, SWIFTNR, BANKNAME) VALUES (@ID, @QRCODEVAL, @STPROFILE, @NIVF, @REFCODE, @PYMTORDNUM, @PAYERNIPT, @EINFIC, @PAIDAMT, @PAIDCUR, @TRANSACTIONCODE, @PYMTTYPE, @BANKNIPT, @DATTIMSEND, @PYMTDATTIM, @OVERPAIDAMT, @PYMTSTATUS, @CODE, @MESSAGE, @USR, @SELLERNIPT, @INVOICEDATE, @IBANNR, @SWIFTNR, @BANKNAME)", connection);

                        cmd.Parameters.AddWithValue("@ID", emp.ID);
                        cmd.Parameters.AddWithValue("@QRCODEVAL", emp.QRCODEVAL);
                        cmd.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);
                        cmd.Parameters.AddWithValue("@NIVF", emp.NIVF);
                        cmd.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
                        cmd.Parameters.AddWithValue("@PYMTORDNUM", emp.PYMTORDNUM);
                        cmd.Parameters.AddWithValue("@PAYERNIPT", emp.PAYERNIPT);
                        cmd.Parameters.AddWithValue("@EINFIC", emp.EINFIC);
                        cmd.Parameters.AddWithValue("@PAIDAMT", emp.PAIDAMT);
                        cmd.Parameters.AddWithValue("@PAIDCUR", emp.PAIDCUR);
                        cmd.Parameters.AddWithValue("@TRANSACTIONCODE", emp.TRANSACTIONCODE);
                        cmd.Parameters.AddWithValue("@PYMTTYPE", emp.PYMTTYPE);
                        cmd.Parameters.AddWithValue("@BANKNIPT", emp.BANKNIPT);
                        cmd.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
                        cmd.Parameters.AddWithValue("@PYMTDATTIM", emp.PYMTDATTIM);
                        cmd.Parameters.AddWithValue("@OVERPAIDAMT", emp.OVERPAIDAMT);
                        cmd.Parameters.AddWithValue("@PYMTSTATUS", emp.PYMTSTATUS);
                        cmd.Parameters.AddWithValue("@CODE", emp.CODE);
                        cmd.Parameters.AddWithValue("@MESSAGE", emp.MESSAGE);
                        cmd.Parameters.AddWithValue("@USR", emp.USR);
                        cmd.Parameters.AddWithValue("@SELLERNIPT", emp.SELLERNIPT);
                        cmd.Parameters.AddWithValue("@INVOICEDATE", emp.INVOICEDATE);
                        cmd.Parameters.AddWithValue("@IBANNR", emp.IBANNR);
                        cmd.Parameters.AddWithValue("@SWIFTNR", emp.SWIFTNR);
                        cmd.Parameters.AddWithValue("@BANKNAME", emp.BANKNAME);

                        int rowsAffected = cmd.ExecuteNonQuery();

                        return rowsAffected > 0;
                    }
                }
                catch (Exception ex)
                {
                    // Log the exception here for debugging purposes
                    return false;
                }
            }

        internal List<EmpModel> SearchEmpList(string searchBox)
        {
            throw new NotImplementedException();
        }
    }
    }


Severity	Code	Description	Project	File	Line	Suppression State
Error	CS1061	'object' does not contain a definition for 'SaveFiscalization' and no accessible extension method 'SaveFiscalization' accepting a first argument of type 'object' could be found (are you missing a using directive or an assembly reference?)	InApps	C:\Users\B010\Desktop\InApps\InApps\Controllers\FiscalizationController.cs	191	Active
