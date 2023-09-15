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

            SqlCommand com = new SqlCommand("AddNewFiscal", con);
            com.CommandType = CommandType.StoredProcedure;
           
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

            int i = com.ExecuteNonQuery();
            con.Close();
            if (i >= 1)
                //{

                //    return true;

                //}
                //else
                //{

                //    return false;
                //}
                if (i >= 1)
                {
                    // Data was successfully inserted, now retrieve the last inserted record
                    EmpModel lastInsertedEmp = GetLastInsertedEmp();

                    // Check if the lastInsertedEmp is not null or has a valid ID
                    if (lastInsertedEmp != null && lastInsertedEmp.ID>0)
                    {
                        return true;
                    }
                }

            // Data insertion failed or no valid lastInsertedEmp found
            return false;
        }



        internal bool AddFiscalization(EmpModel emp)
        {
            throw new NotImplementedException();
        }



        public EmpModel GetEmpModelById(int ID)
        {
            connection();
            con.Open();
            SqlCommand com = new SqlCommand("SELECT * FROM [dbo].[Fiscal] WHERE ID = @ID", con);
            com.Parameters.AddWithValue("@ID", ID);

            SqlDataReader reader = com.ExecuteReader();
            EmpModel emp = new EmpModel();
            if (reader.Read())
            {
                // Map the data from the database to the EmpModel object
                //emp.ID = reader["ID"].ToString();
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








        public bool Update(EmpModel emp)
        {
            
                connection();
            con.Open();
            SqlCommand com = new SqlCommand("Edit", con);
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
                // Add mappings for other fields here
               
                int i = com.ExecuteNonQuery();
                con.Close();
            return i >= 1;
                //if (i >= 1)
                //{

                //    return true;
                //}
                //else
                //{
                //    return false;
                //}
            }

        public EmpModel GetLastInsertedEmp()
        {
            connection();
            con.Open();

            SqlCommand com = new SqlCommand("SELECT TOP 1 * FROM [dbo].[Fiscal] ORDER BY ID DESC", con);

            SqlDataReader reader = com.ExecuteReader();
            EmpModel emp = new EmpModel();

            if (reader.Read())
            {
                // Map the data from the database to the EmpModel object
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



        // Retrieve a list of EmpModel objects from the database
        public List<EmpModel> GetEmpList()
        {
            List<EmpModel> empList = new List<EmpModel>();

            try
            {
                con.Open();
                SqlCommand com = new SqlCommand("SELECT * FROM [dbo].[Fiscal]", con);

                SqlDataReader reader = com.ExecuteReader();
                while (reader.Read())
                {
                    EmpModel emp = new EmpModel();
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
                    // Add other properties as needed

                    empList.Add(emp);
                }
            }
            catch (Exception ex)
            {
                // Handle exceptions here or log them
                Console.WriteLine("Error: " + ex.Message);
            }
            finally
            {
                con.Close();
            }

            return empList;
        }

    }
    }






    

***********************************

using InApps.Models;
using InApps.Repository;
using System;
using System.Web.Mvc;

public class FiscalizationController : Controller
{
    private EmpRepository empRepo;

    public FiscalizationController()
    {
        empRepo = new EmpRepository();
    }

    // GET: Fiscalization/Index
    public ActionResult Index()
    {
        // Retrieve a list of EmpModels from the database and pass it to the view
        var empList = empRepo.GetEmpList();
        return View(empList);
    }

    // GET: Fiscalization/Create
    public ActionResult Create()
    {
        return View();
    }

    // POST: Fiscalization/Create
    [HttpPost]
    public ActionResult Create(string QRCODEVAL, string IBANNR, string STPROFILE, string REFCODE, string PYMTORDNUM, string PAYERNIPT, string EINFIC, string PAIDAMT, string PAIDCUR, string TRANSACTIONCODE, string PYMTTYPE, string BANKNAME, string NIVF, string INVOICEDATE)
    {
        try
        {
            

            EmpModel emp = new EmpModel();
            
            emp.QRCODEVAL = QRCODEVAL;
            emp.STPROFILE = STPROFILE;
            emp.NIVF = NIVF;
            emp.REFCODE = REFCODE;
            emp.PYMTORDNUM = PYMTORDNUM;
            emp.PAYERNIPT = PAYERNIPT;
            emp.EINFIC = EINFIC;
            emp.PAIDAMT = PAIDAMT;
            emp.PAIDCUR = PAIDCUR;
            emp.TRANSACTIONCODE = TRANSACTIONCODE;
            emp.PYMTTYPE = PYMTTYPE;
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
                EmpModel lastInsertedEmp = empRepo.GetLastInsertedEmp();
                return View("Popup", lastInsertedEmp);
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

    // GET: Fiscalization/Edit/5
    public ActionResult Edit(int ID)
    {
        EmpModel emp = empRepo.GetEmpModelById(ID);
        return View(emp);
    }

    // POST: Fiscalization/Edit/5
    [HttpPost]
    public ActionResult Edit(EmpModel emp)
    {
        try
        {
            if (ModelState.IsValid)
            {
                // Update the data in the database
                bool updated = empRepo.Update(emp);

                if (updated)
                {
                    // Redirect to the Index or another appropriate view
                    return RedirectToAction("Index");
                }
                else
                {
                    ModelState.AddModelError("", "Update failed");
                    return View();
                }
            }
            return View(emp);
        }
        catch (Exception e)
        {
            return View();
        }
    }
}

**********
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
