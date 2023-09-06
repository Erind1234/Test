FiscalizationController
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





        public ActionResult EditFiscalization(string ID)
        {
            // Use the EmpRepository to fetch the last saved row by id
            EmpModel existingEmp = empRepo.GetEmpModelById(ID);
            if(existingEmp == null)
            {
                return HttpNotFound();
            }
            // Return the Details view with the retrieved data
            return View("EditFiscalization",existingEmp);
        }

        [HttpPost]
        public ActionResult UpdateFiscalization(EmpModel updatedEmp)
        {
            try
            {
                // Use the EmpRepository to update the row in the database
                bool isUpdated = empRepo.UpdateFiscalization(updatedEmp);

                if (isUpdated)
                {
                    // Redirect back to the Index view after successful update
                    return RedirectToAction("Index");
                }
                else
                {
                    ViewBag.Message = "Failed to update fiscalization details";
                    return View("Details", updatedEmp);
                }
            }
            catch (Exception ex)
            {
                ViewBag.Error = "An error occurred: " + ex.Message;
                return View("Details", updatedEmp);
            }
        }





    }
}







Popup.html

<!DOCTYPE html>
<html>
<head>
    <title>Popup</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <style>
        .popup-container {
            position: fixed;
            top: 100;
            left: 100;
            width: 100%;
            height: 100%;
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: rgba(0, 0, 0, 0.5);
        }

        .popup-content {
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.3);
        }

        .close-button {
            position: absolute;
            top: 10px;
            right: 10px;
            cursor: pointer;
        }
    </style>
</head>

<div class="popup-content">
    <span class="close-button">&times;</span>
    <h2>Edit Fiscalization Details</h2>

</div>

<body>
    <div class="popup-container">
        <div class="popup-content">
            <span class="close-button">&times;</span>
            <h2>Saved Fiscalization Details</h2>
            
                <table style="border-collapse: collapse;">

                    <tr>
                        <th style="border: 1px solid black; padding: 8px;"></th>
                        <th style="border: 1px solid black; padding: 16px;">ID</th>
                        <th style="border: 1px solid black; padding: 8px;">User</th>
                        <th style="border: 1px solid black; padding: 8px;">Referenca</th>
                        <th style="border: 1px solid black; padding: 8px;">Nr urdher</th>
                        <th style="border: 1px solid black; padding: 8px;">NIPT Bleres</th>
                        <th style="border: 1px solid black; padding: 8px;">NIVF</th>
                        <th style="border: 1px solid black; padding: 8px;">Shuma</th>
                        <th style="border: 1px solid black; padding: 8px;">Monedha</th>
                        <th style="border: 1px solid black; padding: 8px;">Shitesi</th>
                        <th style="border: 1px solid black; padding: 8px;">Lloji</th>
                        <th style="border: 1px solid black; padding: 8px;">Nipt Shites</th>
                    </tr>
                    <tr>

                        <td style="border: 1px solid black; padding: 8px;"></td>
                        <td style="border: 1px solid black; padding: 16px;">@Model.ID</td>

                        <td style="border: 1px solid black; padding: 8px;">@Model.USR</td>
                        <td style="border: 1px solid black; padding: 8px;">@Model.REFCODE</td>
                        <td style="border: 1px solid black; padding: 8px;">@Model.PYMTORDNUM</td>
                        <td style="border: 1px solid black; padding: 8px;">@Model.PAYERNIPT</td>
                        <td style="border: 1px solid black; padding: 8px;">@Model.NIVF</td>
                        <td style="border: 1px solid black; padding: 8px;">@Model.PAIDAMT</td>
                        <td style="border: 1px solid black; padding: 8px;">@Model.PAIDCUR</td>
                        <td style="border: 1px solid black; padding: 8px;">@Model.TRANSACTIONCODE</td>
                        <td style="border: 1px solid black; padding: 8px;">@Model.PYMTTYPE</td>
                        <td style="border: 1px solid black; padding: 8px;">@Model.SELLERNIPT</td>
                        @*<td><a href="@Url.Action("Details", "Fiscalization", new { ID = Model.ID })">Edit</a></td>*@
                       <td>@Html.ActionLink("Details", "EditFiscalization", new { ID = Model.ID }) Edit</td>
                    </tr>
                </table>







            </div>
</body>
</html>



EmpRepository
------------------------------------------------------
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

        public bool SaveFiscalization(EmpModel emp)
        {
            connection();
            con.Open();

            SqlCommand com = new SqlCommand("AddNewFiscalizimDetails1", con);
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

            int i = com.ExecuteNonQuery();
            con.Close();
            if (i >= 1)
            {

                return true;

            }
            else
            {

                return false;
            }


        }


     
        internal bool AddFiscalization(EmpModel emp)
        {
            throw new NotImplementedException();
        }
        //To Update Employee details    
       
       
     

        internal EmpModel GetEmpModelById(int id)
        {
            throw new NotImplementedException();
        }
        public EmpModel GetEmpModelById(String ID)
        {
            connection();
            con.Open();
            SqlCommand com = new SqlCommand("SELECT * FROM [dbo].[Fiscalizimi] WHERE ID = @ID", con);
            com.Parameters.AddWithValue("@ID", ID);

            SqlDataReader reader = com.ExecuteReader();
            EmpModel emp = new EmpModel();
            if (reader.Read())
            {
                // Map the data from the database to the EmpModel object
                emp.ID = reader["ID"].ToString();
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


                // Add other properties as needed
            }

            con.Close();
            return emp;
        }

        public bool UpdateFiscalization(EmpModel emp)
        {
            connection();
            con.Open();

            SqlCommand com = new SqlCommand("UPDATE [dbo].[Fiscalizimi] SET REFCODE=@REFCODE,  DATTIMSEND = @DATTIMSEND,BANKNIPT = @BANKNIPT,PYMTORDNUM = @PYMTORDNUM,PAYERNIPT = @PAYERNIPT,EINFIC = @EINFIC,PYMTDATTIM = @PYMTDATTIM,PAIDAMT = @PAIDAMT,OVERPAIDAMT = @OVERPAIDAMT,PAIDCUR = @PAIDCUR,TRANSACTIONCODE = @TRANSACTIONCODE,PYMTTYPE = @PYMTTYPE,PYMTSTATUS = @PYMTSTATUS,CODE = @CODE,MESSAGE = @MESSAGE,USR = @USR,SELLERNIPT = @SELLERNIPT,INVOICEDATE = @INVOICEDATE,IBANNR = @IBANNR,SWIFTNR = @SWIFTNR,BANKNAME = @BANKNAME,QRCODEVAL = @QRCODEVAL,NIVF = @NIVF,STPROFILE = @STPROFILE WHERE ID = @ID", con);
            // Set the parameters for the UPDATE query
            com.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
            com.Parameters.AddWithValue("@PYMTORDNUM", emp.PYMTORDNUM);
            // Add other parameters as needed
            com.Parameters.AddWithValue("@ID", emp.ID);
          
            com.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
            com.Parameters.AddWithValue("@BANKNIPT", emp.BANKNIPT);
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

            int i = com.ExecuteNonQuery();
            con.Close();
            if (i >= 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


    }



}





Details.cshtml
---------------------
@model InApps.Models.EmpModel

<h1>Fiscalization Details</h1>


<body>
    <h1>Fiscalization</h1>


    @using (Html.BeginForm("UpdateFiscalization", "Fiscalization", FormMethod.Post))
    {
        @Html.HiddenFor(model => model.ID)

        <div class="form-group">
            @Html.LabelFor(model=>model.PYMTORDNUM)
            @Htmll.TextBoxFor(model=>model.PYMTORDNUM,new{@class = "form-control")

        </div>




        <div class="fixed-table">


            <div style="display: flex; justify-content: center; align-items: center; height: 50vh;">

                <div style="text-align: center; background-color: #e7e7ff;">


                    <table>


                        <tr>
                            <td>@Html.Label("Numri Urdhrit")</td>
                            <td>@Html.TextBox("PYMTORDNUM")</td>
                            <td>@Html.Label("Invoice Date:")</td>
                            <td>@Html.TextBoxFor(model => model.INVOICEDATE, new { @Value = Model.INVOICEDATE })</td>
                        </tr>

                        <tr>
                            <td>@Html.LabelFor(model => model.NIVF)</td>
                            <td>@Html.TextBoxFor(model => model.NIVF, new { @Value = Model.NIVF, style = "width:400px;" })</td>

                        </tr>


                        <tr>
                            <td>@Html.Label("NIPT Bleres:")</td>
                            <td>@Html.TextBox("PAYERNIPT")</td>
                            <td>@Html.LabelFor(model => model.SELLERNIPT)</td>
                            <td>@Html.TextBoxFor(model => model.SELLERNIPT, new { @Value = Model.SELLERNIPT })</td>
                        </tr>
                        <tr>
                            <td>@Html.Label("Emri Shites")</td>
                            <td>@Html.TextBoxFor(model => model.TRANSACTIONCODE, new { @Value = Model.TRANSACTIONCODE, style = "width:400px;" })</td>
                        </tr>


                        <tr>
                            <td>@Html.Label("Referenca e Teller:")</td>
                            <td>@Html.TextBoxFor(model => model.REFCODE, new { @Value = Model.REFCODE })</td>

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
                            <td>@Html.TextBoxFor(model => model.PAIDCUR)</td>
                        </tr>

                        <tr>
                            <td>@Html.Label("Shuma e Paguar:")</td>
                            <td>@Html.TextBoxFor(model => model.PAIDAMT)</td>
                        </tr>


                        <tr>
                            <td>@Html.Label("IBAN & SWIFT:")</td>
                            <td>@Html.TextBoxFor(model => model.IBANNR)</td>
                            <td>@Html.TextBoxFor(model => model.BANKNAME)</td>
                        </tr>


                        <tr>
                            <td>&nbsp;</td>

                        </tr>
                        <tr>
                            <td>&nbsp;</td>

                        </tr>

                    </table>




                    @*<div class="form-group">
                            <div class="col-md-offset-2 col-md-10">


                                <input type="submit" value="Ruaj" class="btn btn-default" />




                            </div>
                        </div>*@
                </div>
            </div>

            </div>

            <!-- Add the "Update" button -->

                <input type="submit" value="Update" class="btn btn-primary" />


    }

index.cshtml
--------------------------
@model InApps.Models.EmpModel

@{
    ViewBag.Title = "Index";
    //Layout = "~/Views/Shared/_Layout.cshtml";
    //string[] tableHeaders = new string[] { "Branch", "Account" };
    //var ContentVersion = InApps.Models.Tools.ContentVersion;

}



<style>
    /* Add CSS styles for freezing the table and the popup */
    .fixed-table {
        position: fixed;
        top: 400;
        left: 400;
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
                    <li class="breadcrumb-item active"><a href="javascript:void(0)"></a>Index</li>
                </ol>
            </div>
        </div>
    </div>

    <div class="form-group">
        <form method="post" id="fiscal">
            <div class="table-responsive" style="align-content:center">

            </div>
        </form>
    </div>


    <body>
        <h1>Fiscalization</h1>



        @using (Html.BeginForm("Index", "Fiscalization", FormMethod.Post))
        {
            <input type="text" name="searchBox" />
            <input type="submit" value="Search" />
        }



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

                                <tr>
                                    <td>@Html.LabelFor(model => model.NIVF)</td>
                                    <td>@Html.TextBoxFor(model => model.NIVF, new { @Value = ViewBag.p3, style = "width:400px;" })</td>

                                </tr>


                                <tr>
                                    <td>@Html.Label("NIPT Bleres:")</td>
                                    <td>@Html.TextBox("PAYERNIPT")</td>
                                    <td>@Html.LabelFor(model => model.SELLERNIPT)</td>
                                    <td>@Html.TextBoxFor(model => model.SELLERNIPT, new { @Value = ViewBag.p1 })</td>
                                </tr>
                                <tr>
                                    <td>@Html.Label("Emri Shites")</td>
                                    <td>@Html.TextBoxFor(model => model.TRANSACTIONCODE, new { @Value = ViewBag.p2, style = "width:400px;" })</td>
                                </tr>


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

    

