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
        public ActionResult SaveFiscalization(EmpModel emp)
        {
            try
            {
                int newlyInsertedID = empRepo.SaveFiscalization(emp);

                if (newlyInsertedID > 0)
                {


                    // Redirect to an edit view for the newly inserted row
                    emp.ID = newlyInsertedID;
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
            // Fetch the fiscalization record by ID from the database
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
                        return View("Popup",emp); // Redirect to the list of fiscalizations
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
                    // Return a success response
                    return Json(new { success = true });
                }
                else
                {
                    // Return an error response
                    return Json(new { success = false, message = "Failed to delete fiscalization record." });
                }
            }
            catch (Exception ex)
            {
                // Return an error response in case of exceptions
                return Json(new { success = false, message = "An error occurred: " + ex.Message });
            }
        }
        [HttpPost]
        public ActionResult SearchByRefcode(string searchBox)
        {
            try
            {
                // Call the stored procedure to search by REFCODE
                List<EmpModel> searchResults = empRepo.SearchByRefcode(searchBox);

                // Pass the search results to a view
                return View("SearchResults", searchResults);
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("Index");
            }
        }







    }
}


//////////////////////////////
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

        private SqlConnection con;


        //To Handle connection related activities    
        private void connection()
        {
            string constr = ConfigurationManager.ConnectionStrings["FacilegalConn"].ToString();
            con = new SqlConnection(constr);

        }

        public int SaveFiscalization(EmpModel emp)
        {
            connection();
            con.Open();
            try
            {
                SqlCommand com = new SqlCommand("AddNewFiscal2", con);
                com.CommandType = CommandType.StoredProcedure;

                SqlParameter outputParameter = new SqlParameter("@NewlyInsertedID", SqlDbType.Int);
                outputParameter.Direction = ParameterDirection.Output;
                com.Parameters.Add(outputParameter);


                //com.Parameters.AddWithValue("@ID", emp.ID);
                com.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
                com.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
                com.Parameters.AddWithValue("@BANKNIPT", emp.BANKNIPT);
                com.Parameters.AddWithValue("@PYMTORDNUM", emp.PYMTORDNUM);
                com.Parameters.AddWithValue("@PAYERNIPT", emp.PAYERNIPT);
                com.Parameters.AddWithValue("@EINFIC", emp.EINFIC);
                com.Parameters.AddWithValue("@PYMTDATTIM", emp.PYMTDATTIM);
                com.Parameters.AddWithValue("@PAIDAMT", emp.PAIDAMT);
                com.Parameters.AddWithValue("@OVERPAIDAMT", emp.OVERPAIDAMT);
                com.Parameters.AddWithValue("@PAIDCUR", emp.PAIDCUR);
                com.Parameters.AddWithValue("@TRANSACTIONCODE", emp.TRANSACTIONCODE);
                com.Parameters.AddWithValue("@PYMTTYPE", emp.PYMTTYPE);
                com.Parameters.AddWithValue("@PYMTSTATUS", emp.PYMTSTATUS);
                com.Parameters.AddWithValue("@CODE", emp.CODE);
                com.Parameters.AddWithValue("@MESSAGE", emp.MESSAGE);
                com.Parameters.AddWithValue("@USR", emp.USR);
                com.Parameters.AddWithValue("@SELLERNIPT", emp.SELLERNIPT);
                com.Parameters.AddWithValue("@INVOICEDATE", emp.INVOICEDATE);
                com.Parameters.AddWithValue("@IBANNR", emp.IBANNR);
                com.Parameters.AddWithValue("@SWIFTNR", emp.SWIFTNR);
                com.Parameters.AddWithValue("@BANKNAME", emp.BANKNAME);
                com.Parameters.AddWithValue("@QRCODEVAL", emp.QRCODEVAL);
                com.Parameters.AddWithValue("@NIVF", emp.NIVF);
                com.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);

                //int i = com.ExecuteNonQuery();



                // con.Close();
                // if (i >= 1)

                // {



                //     return true;

                // }
                // else
                // {

                //     return false;
                // }
                int rowAffected = com.ExecuteNonQuery();
                if (rowAffected > 0)
                {
                    return Convert.ToInt32(outputParameter.Value);
                }
                else
                {
                    return -1;
                }
            }
            catch (Exception ex)
            {
                throw;
            }

            finally
            {
                con.Close();
            }

        }

        public EmpModel GetFiscalizationById(int ID)
        {
            connection();
            con.Open();

            SqlCommand com = new SqlCommand("GetFiscalizationById", con);
            com.CommandType = CommandType.StoredProcedure;
            com.Parameters.AddWithValue("@ID", ID);

            SqlDataReader reader = com.ExecuteReader();
            EmpModel emp = new EmpModel();

            while (reader.Read())
            {
                // Populate emp object with data from the database
                emp.ID = Convert.ToInt32(reader["ID"]);
                emp.REFCODE = reader["REFCODE"].ToString();
                emp.PYMTORDNUM = reader["PYMTORDNUM"].ToString();
                emp.DATTIMSEND = reader["DATTIMSEND"].ToString();
                emp.BANKNIPT = reader["BANKNIPT"].ToString();
                emp.PAYERNIPT = reader["PAYERNIPT"].ToString();
                emp.EINFIC = reader["EINFIC"].ToString();
                emp.PYMTDATTIM = reader["PYMTDATTIM"].ToString();
                emp.PAIDAMT = reader["PAIDAMT"].ToString();
                emp.OVERPAIDAMT = reader["OVERPAIDAMT"].ToString();
                emp.PAIDCUR = reader["PAIDCUR"].ToString();
                emp.TRANSACTIONCODE = reader["TRANSACTIONCODE"].ToString();
                emp.PYMTTYPE = reader["PYMTTYPE"].ToString();
                emp.PYMTSTATUS = reader["PYMTSTATUS"].ToString();
                emp.CODE = reader["CODE"].ToString();
                emp.MESSAGE = reader["MESSAGE"].ToString();
                emp.USR = reader["USR"].ToString();
                emp.SELLERNIPT = reader["SELLERNIPT"].ToString();
                emp.INVOICEDATE = reader["INVOICEDATE"].ToString();
                emp.IBANNR = reader["IBANNR"].ToString();
                emp.SWIFTNR = reader["SWIFTNR"].ToString();
                emp.BANKNAME = reader["BANKNAME"].ToString();
                emp.QRCODEVAL = reader["QRCODEVAL"].ToString();
                emp.NIVF = reader["NIVF"].ToString();
                emp.STPROFILE = reader["STPROFILE"].ToString();
            }

            con.Close();
            return emp;
        }

        public bool UpdateFiscalization(EmpModel emp)
        {
            connection();
            con.Open();

            SqlCommand com = new SqlCommand("UpdateFiscalization", con);
            com.CommandType = CommandType.StoredProcedure;
            com.Parameters.AddWithValue("@ID", emp.ID);
            com.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
            com.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
            com.Parameters.AddWithValue("@BANKNIPT", emp.BANKNIPT);
            com.Parameters.AddWithValue("@PYMTORDNUM", emp.PYMTORDNUM);
            com.Parameters.AddWithValue("@PAYERNIPT", emp.PAYERNIPT);
            com.Parameters.AddWithValue("@EINFIC", emp.EINFIC);
            com.Parameters.AddWithValue("@PYMTDATTIM", emp.PYMTDATTIM);
            com.Parameters.AddWithValue("@PAIDAMT", emp.PAIDAMT);
            com.Parameters.AddWithValue("@OVERPAIDAMT", emp.OVERPAIDAMT);
            com.Parameters.AddWithValue("@PAIDCUR", emp.PAIDCUR);
            com.Parameters.AddWithValue("@TRANSACTIONCODE", emp.TRANSACTIONCODE);
            com.Parameters.AddWithValue("@PYMTTYPE", emp.PYMTTYPE);
            com.Parameters.AddWithValue("@PYMTSTATUS", emp.PYMTSTATUS);
            com.Parameters.AddWithValue("@CODE", emp.CODE);
            com.Parameters.AddWithValue("@MESSAGE", emp.MESSAGE);
            com.Parameters.AddWithValue("@USR", emp.USR);
            com.Parameters.AddWithValue("@SELLERNIPT", emp.SELLERNIPT);
            com.Parameters.AddWithValue("@INVOICEDATE", emp.INVOICEDATE);
            com.Parameters.AddWithValue("@IBANNR", emp.IBANNR);
            com.Parameters.AddWithValue("@SWIFTNR", emp.SWIFTNR);
            com.Parameters.AddWithValue("@BANKNAME", emp.BANKNAME);
            com.Parameters.AddWithValue("@QRCODEVAL", emp.QRCODEVAL);
            com.Parameters.AddWithValue("@NIVF", emp.NIVF);
            com.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);


            int rowsAffected = com.ExecuteNonQuery();
            con.Close();

            return rowsAffected > 0;
        }




        internal bool AddFiscalization(EmpModel emp)
        {
            throw new NotImplementedException();
        }
        //To Update Employee details    

        public bool DeleteFiscalization(int ID)
        {
            connection();
            
            
                con.Open();
                SqlCommand com = new SqlCommand("DeleteFiscalization", con);
                com.CommandType = CommandType.StoredProcedure;
                com.Parameters.AddWithValue("@ID", ID);

                int rowsAffected = com.ExecuteNonQuery();
                return rowsAffected > 0;
            
        }


        public List<EmpModel> SearchByRefcode(string refcode)
        {
            List<EmpModel> results = new List<EmpModel>();
            try { 
            connection();
            using (SqlCommand cmd = new SqlCommand("REF", con))
            {
                cmd.CommandType = CommandType.StoredProcedure;

                // Add parameters to the stored procedure
                cmd.Parameters.Add(new SqlParameter("@Refcode", refcode));

                con.Open();

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            EmpModel emp = new EmpModel
                            {
                                ID = reader["ID"] != DBNull.Value ?(int) reader["ID"]:0,
                                USR = reader["USR"] != DBNull.Value ? reader["USR"].ToString() : string.Empty,
                                REFCODE = reader["REFCODE"] != DBNull.Value ? reader["REFCODE"].ToString() : string.Empty,
                                INVOICEDATE = reader["INVOICEDATE"] != DBNull.Value ? reader["INVOICEDATE"].ToString() : string.Empty,
                                PYMTORDNUM = reader["PYMTORDNUM"] != DBNull.Value ? reader["PYMTORDNUM"].ToString() : string.Empty,
                                PAYERNIPT = reader["PAYERNIPT"] != DBNull.Value ? reader["PAYERNIPT"].ToString() : string.Empty,
                                NIVF = reader["NIVF"] != DBNull.Value ? reader["NIVF"].ToString() : string.Empty,
                                PAIDAMT = reader["PAIDAMT"] != DBNull.Value ? reader["PAIDAMT"].ToString() : string.Empty,
                                PAIDCUR = reader["PAIDCUR"] != DBNull.Value ? reader["PAIDCUR"].ToString() : string.Empty,
                                TRANSACTIONCODE = reader["TRANSACTIONCODE"] != DBNull.Value ? reader["TRANSACTIONCODE"].ToString() : string.Empty,
                                PYMTTYPE = reader["PYMTTYPE"] != DBNull.Value ? reader["PYMTTYPE"].ToString() : string.Empty,
                                SELLERNIPT = reader["USR"] != DBNull.Value ? reader["SELLERNIPT"].ToString() : string.Empty,
                            };
                            results.Add(emp);
                        }
                    }
                }
            }
        
       catch (Exception ex)
    {
        // Handle any exceptions here
        // You can log the exception, throw it, or handle it as needed
        // For example: throw new Exception("An error occurred: " + ex.Message);
    }

    return results; // Return the list of results
}




}
}
/////////////////////////////
@model InApps.Models.EmpModel

@{
    ViewBag.Title = "Index";
}

<style>
    /* Add CSS styles for freezing the table and the popup */
    .fixed-table {
        position: fixed;
        top: 400px;
        left: 400px;
        width: 100%;
        height: 600px; /* Adjust the height as per your needs */
        overflow-y: auto;
    }

    .popup {
        position: fixed;
        bottom: 500px; /* Adjust the position as per your needs */
        left: 600px; /* Adjust the position as per your needs */
        background-color: white;
        padding: 40px;
        border: 1px solid black;
    }
</style>

<div class="content-body">
    <div class="container-fluid">
        <div class="row page-titles mx-0">
            <div class="col-sm-6 p-md-0">
                <div class="welcome-text">
                    <h4>Register Fiscal Data</h4>
                    <p class="mb-0"></p>
                </div>
            </div>
            <div class="col-sm-6 p-md-0 justify-content-sm-end mt-2 mt-sm-0 d-flex">
                <ol class="breadcrumb">
                    <li class="breadcrumb-item"><a href="javascript:void(0)">Register Fiscal Data</a></li>
                    <li class="breadcrumb-item active"><a href="javascript:void(0)">Index</a></li>
                </ol>
            </div>
        </div>
    </div>

    <div class="form-group">
        <form method="post" id="fiscal">
            <div class="table-responsive" style="align-content:center"></div>
        </form>
    </div>

    <h1>Fiscalization</h1>

    @using (Html.BeginForm("Index", "Fiscalization", FormMethod.Post))
    {
        <input type="text" name="searchBox" />
        <input type="submit" value="Search" />
    }

    <div>
        <input type="text" id="refcodeSearchBox" />
        <button id="searchByRefcode">Search by REFCODE</button>
    </div>

    <div id="resultTable" style="display: none;">
        <!-- Table content will be displayed here -->
    </div>

    <div class="fixed-table">
        @if (!string.IsNullOrEmpty(ViewBag.p1))
        {
            using (Html.BeginForm("SaveFiscalization", "Fiscalization", FormMethod.Post))
            {
                <div style="display: flex; justify-content: center; align-items: center; height: 50vh;">
                    <div style="text-align: center; background-color: #e7e7ff;">
                        <table>
                            <tr>
                                <td>&nbsp;</td>
                            </tr>
                            <tr>
                                <td>&nbsp;</td>
                            </tr>
                            <tr>
                                <td>@Html.Label("Numri Urdhrit")</td>
                                <td>@Html.TextBox("PYMTORDNUM")</td>
                                <td>@Html.Label("Invoice Date:")</td>
                                <td>@Html.TextBoxFor(model => model.INVOICEDATE, new { @Value = ViewBag.p4 })</td>
                            </tr>
                            <!-- Add more form fields as needed -->

                            <tr>
                                <td>@Html.Label("Referenca e Teller:")</td>
                                <td>@Html.TextBox("REFCODE")</td>
                            </tr>






                            <tr>
                                <td>@Html.Label("Tipi i Pageses:")</td>
                                <td>
                                    @Html.DropDownListFor(model => model.PYMTTYPE, new SelectList(new[]
                     {
                                        new { Value = "CASH", Text = "CASH" },
                                        new { Value = "NON_CASH", Text = "NON_CASH" }
                                    }, "Value", "Text"), "CASH")
                                </td>

                            </tr>
                            <tr>
                                <td>@Html.Label("Statusi i Pageses:")</td>

                                <td>
                                    @Html.DropDownListFor(model => model.PYMTSTATUS, new SelectList(new[]
                     {
                                        new { Value = "P1 Faturimi i dergesave te mallrave dhe sherbimeve kundrejt porosive te blerjes,bazuar ne  kontrate", Text = "P1 Faturimi i dergesave te mallrave dhe sherbimeve kundrejt porosive te blerjes,bazuar ne  kontrate" },
                                        new { Value = "P2 Faturimi i dergesave te mallrave dhe sherbimeve bazuar ne nje kontrate", Text = "P2 Faturimi i dergesave te mallrave dhe sherbimeve bazuar ne nje kontrate" },
                                        new { Value = "P3 Faturimi i dorezimit te porosise se blerjes se  rastesishme", Text = "P3 Faturimi i dorezimit te porosise se blerjes se  rastesishme" },
                                        new { Value = "P4 Pagesa paraprake", Text = "P4 Pagesa paraprake" },
                                        new { Value = "P5 Pagesa ne vend", Text = "P5 Pagesa ne vend" },
                                        new { Value = "P6 Pagesa para dorezimit", Text = "P6 Pagesa para dorezimit" },
                                        new { Value = "P7 Faturat me referenca ne shenimin e dergimit", Text = "P7 Faturat me referenca ne shenimin e dergimit" },
                                        new { Value = "P8 Faturat me referenca ne shenimin e dergimit dhe shenimin e marrjes", Text = "P8 Faturat me referenca ne shenimin e dergimit dhe shenimin e marrjes" },
                                        new { Value = "P9 Note kredie ose fatura me shuma negative, te leshuara per nje sere arsyesh,perfshire kthimin e", Text = "P9 Note kredie ose fatura me shuma negative, te leshuara per nje sere arsyesh,perfshire kthimin e" },

                                        new { Value = "P10 Faturimi korrigjues(anullimi/korrigjimi i nje  fature)", Text = "P10 Faturimi korrigjues(anullimi/korrigjimi i nje  fature)" },
                                        new { Value = "P11 Faturimi i pjesshem dhe perfundimtar", Text = "P11 Faturimi i pjesshem dhe perfundimtar" },

                                    }, "Value", "Text"), "P1 Faturimi i dergesave te mallrave dhe sherbimeve kundrejt porosive te blerjes,bazuar ne  kontrate")
                                </td>
                            </tr>



                            <tr>
                                <td>@Html.Label("Monedha:")</td>
                                <td>@Html.TextBoxFor(model => model.PAIDCUR, new { @Value = ViewBag.p7 })</td>
                            </tr>

                            <tr>
                                <td>@Html.Label("Shuma e Paguar:")</td>
                                <td>@Html.TextBoxFor(model => model.PAIDAMT, new { @Value = ViewBag.p6 })</td>
                            </tr>


                            <tr>
                                <td>@Html.Label("IBAN & SWIFT:")</td>
                                <td>@Html.TextBoxFor(model => model.IBANNR, new { @Value = ViewBag.p8 })</td>
                                <td>@Html.TextBoxFor(model => model.BANKNAME, new { @Value = ViewBag.p10 })</td>
                            </tr>
                            <!-- Hidden input fields for properties not on the form -->
                            @Html.HiddenFor(model => model.QRCODEVAL, new { Value = "1" })
                            @Html.HiddenFor(model => model.STPROFILE, new { Value = "1" })
                            @Html.HiddenFor(model => model.PYMTDATTIM, new { Value = "1" })
                            @Html.HiddenFor(model => model.EINFIC, new { Value = "1" })
                            @Html.HiddenFor(model => model.BANKNIPT, new { Value = "1" })
                            @Html.HiddenFor(model => model.DATTIMSEND, new { Value = "1" })
                            @Html.HiddenFor(model => model.OVERPAIDAMT, new { Value = "1" })
                            @Html.HiddenFor(model => model.PYMTSTATUS, new { Value = "1" })
                            @Html.HiddenFor(model => model.CODE, new { Value = "1" })
                            @Html.HiddenFor(model => model.MESSAGE, new { Value = "1" })
                            @Html.HiddenFor(model => model.USR, new { Value = "1" })
                            @Html.HiddenFor(model => model.PYMTSTATUS, new { Value = "1" })
                            @Html.HiddenFor(model => model.SELLERNIPT, new { Value = "1" })
                            @Html.HiddenFor(model => model.SWIFTNR, new { Value = "1" })

                            <!-- Add more hidd666664446en fields for other properties as needed -->

                            <tr>
                                <td>&nbsp;</td>

                            </tr>
                            <tr>
                                <td>&nbsp;</td>

                            </tr>

                        </table>




                        <div class="form-group">
                            <div class="col-md-offset-2 col-md-10">


                                <input type="submit" value="Ruaj" class="btn btn-default" />

                                <button type="button" onclick="deleteRow()" class="btn btn-default">Delete</button>

                                <input type="reset" value="Skanim i Ri" class="btn btn-default" />


                            </div>
                        </div>
                    </div>
                </div>


            }

        }






    </div>

    <div class="popup" id="popupWindow" style="display: none; ">
        <h3>Saved Data</h3>



        <p> @ViewBag.savedData</p>

    </div>

    <script>
    // Function to handle the click event of the "Save" button
    function showPopup() {
        document.getElementById("popupWindow").style.display = "block";
    }

    // Function to handle the click event of the "Edit" button
    function editTable() {
        history.back();
    }

    // Show the popup window when the page loads if the savedData exists
    window.onload = function () {
        var savedData = "@ViewBag.savedData";
        if (savedData) {
            showPopup();
        }
    }
    </script>


    @*<script>
                // Function to handle the click event of the "Delete" button


            //function editTable(id) {
            //    history.back();
            //}





            // Function to handle the click event of the "Data" button
            $(document).ready(function () {
                $("#dataButton").click(function () {
                    // Show the popup window
                    document.getElementById("popupWindow").style.display = "block";
                });
            });







        // Show the popup window when the page loads if the savedData exists
        window.onload = function () {
            var savedData = "@ViewBag.savedData";
            if (savedData) {
                document.getElementById("popupWindow").style.display = "block";
            }
            }
        </script>*@



    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="~/Scripts/jquery-1.10.2.min.js"></script>
    <script src="~/Scripts/jquery.validate.min.js"></script>
    <script src="~/Scripts/jquery.validate.unobtrusive.min.js"></script>


</div>
/////////////////////////////////
