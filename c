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
                SqlCommand com = new SqlCommand("AddNewFiscalization", con);
                com.CommandType = CommandType.StoredProcedure;

                SqlParameter outputParameter = new SqlParameter("@NewlyInsertedID", SqlDbType.Int);
                outputParameter.Direction = ParameterDirection.Output;
                com.Parameters.Add(outputParameter);

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
                //com.Parameters.AddWithValue("@NIVF", emp.NIVF);
                com.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);

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

        internal void SaveQRCodeValue(EmpModel empModel)
        {
            throw new NotImplementedException();
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
                //emp.NIVF = reader["NIVF"].ToString();
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
            //com.Parameters.AddWithValue("@NIVF", emp.NIVF);
            com.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);


            int rowsAffected = com.ExecuteNonQuery();
            con.Close();

            return rowsAffected > 0;
        }




        internal bool AddFiscalization(EmpModel emp)
        {
            throw new NotImplementedException();
        }
        
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


        public List<EmpModel> SearchByRefcode(string REFCODE)
        {
            List<EmpModel> searchResults = new List<EmpModel>();
            try { 
            connection();

                con.Open();
                using (SqlCommand cmd = new SqlCommand("GetFiscalDataByRefcode", con))
            {
                cmd.CommandType = CommandType.StoredProcedure;


                    cmd.Parameters.AddWithValue("@REFCODE", REFCODE);
                    

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            EmpModel emp = new EmpModel
                            {
                                ID = (int)reader["ID"],
                                USR = reader["USR"].ToString(),
                                REFCODE = reader["REFCODE"].ToString(),
                                INVOICEDATE = reader["INVOICEDATE"].ToString(),
                                PYMTORDNUM = reader["PYMTORDNUM"].ToString(),
                                PAYERNIPT = reader["PAYERNIPT"].ToString(),
                                NIVF = reader["NIVF"].ToString(),
                                PAIDAMT = reader["PAIDAMT"].ToString(),
                                PAIDCUR = reader["PAIDCUR"].ToString(),
                                TRANSACTIONCODE = reader["TRANSACTIONCODE"].ToString(),
                                PYMTTYPE = reader["PYMTTYPE"].ToString(),
                                SELLERNIPT = reader["SELLERNIPT"].ToString(),
                            };
                            searchResults.Add(emp);
                        }
                    }
                }
            }
        
       catch (Exception ex)
    {
    }

    return searchResults; 
}




}
}

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
                emp.QRCODEVAL = Request.Form["QRCODEVAL"];
                
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
                SqlCommand com = new SqlCommand("AddNewFiscalization", con);
                com.CommandType = CommandType.StoredProcedure;

                SqlParameter outputParameter = new SqlParameter("@NewlyInsertedID", SqlDbType.Int);
                outputParameter.Direction = ParameterDirection.Output;
                com.Parameters.Add(outputParameter);

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
                //com.Parameters.AddWithValue("@NIVF", emp.NIVF);
                com.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);

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

        internal void SaveQRCodeValue(EmpModel empModel)
        {
            throw new NotImplementedException();
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
                //emp.NIVF = reader["NIVF"].ToString();
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
            //com.Parameters.AddWithValue("@NIVF", emp.NIVF);
            com.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);


            int rowsAffected = com.ExecuteNonQuery();
            con.Close();

            return rowsAffected > 0;
        }




        internal bool AddFiscalization(EmpModel emp)
        {
            throw new NotImplementedException();
        }
        
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


        public List<EmpModel> SearchByRefcode(string REFCODE)
        {
            List<EmpModel> searchResults = new List<EmpModel>();
            try { 
            connection();

                con.Open();
                using (SqlCommand cmd = new SqlCommand("GetFiscalDataByRefcode", con))
            {
                cmd.CommandType = CommandType.StoredProcedure;


                    cmd.Parameters.AddWithValue("@REFCODE", REFCODE);
                    

                    using (SqlDataReader reader = cmd.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            EmpModel emp = new EmpModel
                            {
                                ID = (int)reader["ID"],
                                USR = reader["USR"].ToString(),
                                REFCODE = reader["REFCODE"].ToString(),
                                INVOICEDATE = reader["INVOICEDATE"].ToString(),
                                PYMTORDNUM = reader["PYMTORDNUM"].ToString(),
                                PAYERNIPT = reader["PAYERNIPT"].ToString(),
                                NIVF = reader["NIVF"].ToString(),
                                PAIDAMT = reader["PAIDAMT"].ToString(),
                                PAIDCUR = reader["PAIDCUR"].ToString(),
                                TRANSACTIONCODE = reader["TRANSACTIONCODE"].ToString(),
                                PYMTTYPE = reader["PYMTTYPE"].ToString(),
                                SELLERNIPT = reader["SELLERNIPT"].ToString(),
                            };
                            searchResults.Add(emp);
                        }
                    }
                }
            }
        
       catch (Exception ex)
    {
    }

    return searchResults; 
}




}
}
@model InApps.Models.EmpModel

<head>
   <style>
        
        .container {
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: flex-start;
            height: 120vh;
        }

        .form-group {
            display: flex;
            align-items: center;
            
        }

        .search-group {
            display: flex;
            align-items: center;
        }
        .search-box {
            width: 300px;
        }

        .freeze-search-box {
            position: absolute;
            top: 0;
            left: 0;
            background-color: white;
            z-index: 1;
        }

        .table-container {
            margin-top: 20px;
            /*margin-left: 350px;*/
            width: auto;
        }
        .fixed-table {
            position: absolute;
            top: 250px; 
            width: 40%; 
            border: 1px solid white; 
          
        }
        table {
            border-collapse: collapse;
            width: 70%;
        }

        tr, td {
            border: 1px solid #ccc;
            padding: 1px;
        }
        .popup {
            
            z-index: 2;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="search-group">
            @using (Html.BeginForm("Index", "Fiscalization", FormMethod.Post))
            {
                <br />
                <br />
                <div class="form-group">
                    @Html.TextBox("searchBox", null, new { @class = "form-control search-box", placeholder = "Klikoni per te skanuar:", id = "searchBox" })
                    <button type="submit" class="btn btn-primary ml-2" id="scan">Scan</button>
                </div>

            }
            <div class="freeze-search-box" id="freezeSearchBox" style="display: none;"></div>
        </div>

        <div class="form-group mt-4">
            <input type="text" id="REFCODE" class="form-control search-box" placeholder="Enter REFCODE" />
            <button id="searchByRefcode" class="btn btn-success ml-2">Kerko me Teller Reference</button>
        </div>

        <div id="resultTable" class="table-container" style="display: none;">
      
        </div>

        <div class="fixed-table" id="tab1">
            @if (!string.IsNullOrEmpty(ViewBag.p1))
            {
                using (Html.BeginForm("SaveFiscalization", "Fiscalization", FormMethod.Post))
                {

            <table>
                
                <tr>
                    <td>@Html.Label("Numri Urdhrit")</td>
                    <td>@Html.TextBox("PYMTORDNUM")</td>
                </tr>
                <tr>
                    <td>@Html.Label("Invoice Date:")</td>
                    <td>@Html.TextBoxFor(model => model.INVOICEDATE, new { @Value = ViewBag.p4 })</td>
                </tr>

                <tr>
                    <td>@Html.LabelFor(model => model.NIVF)</td>
                    <td>@Html.TextBoxFor(model => model.EINFIC, new { @Value = ViewBag.p3, style = "width:400px;" })</td>

                </tr>


                <tr>
                    <td>@Html.Label("NIPT Bleres:")</td>
                    <td>@Html.TextBox("PAYERNIPT")</td>
                </tr>
                <tr>
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
                                    }, "Value", "Text"), "")
                    </td>

                </tr>
                <tr>
                    <td>@Html.Label("Statusi i Pageses:")</td>

                    <td>
                        @Html.DropDownListFor(model => model.STPROFILE, new SelectList(new[]
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
                    <td>
                        @Html.TextBoxFor(model => model.IBANNR, new { @Value = ViewBag.p8 })
                        @Html.TextBoxFor(model => model.BANKNAME, new { @Value = ViewBag.p10 })
                    </td>
                </tr>
                <input type="hidden" id="QRCODEVAL" name="QRCODEVAL" />
                
                @*@Html.HiddenFor(model => model.STPROFILE, new { Value = "1" })*@

                @Html.HiddenFor(model => model.PYMTDATTIM, new { Value = " " })
                @*@Html.HiddenFor(model => model.EINFIC, new { Value = "1" })*@
                @Html.HiddenFor(model => model.BANKNIPT, new { Value = ViewBag.p1 })
                @Html.HiddenFor(model => model.DATTIMSEND, new { Value = " " })
                @Html.HiddenFor(model => model.OVERPAIDAMT, new { Value = "0.00" })

                @Html.HiddenFor(model => model.CODE, new { Value = " " })
                @Html.HiddenFor(model => model.MESSAGE, new { Value = " " })
                @Html.HiddenFor(model => model.USR, new { Value = "usr" })
                @Html.HiddenFor(model => model.PYMTSTATUS, new { Value = "PAYMENT" })
                @*@Html.HiddenFor(model => model.SELLERNIPT, new { Value = "1" })*@
                @Html.HiddenFor(model => model.SWIFTNR, new { Value = ViewBag.p10 ?? " " })

                <tr>
                    <td></td>
                    <td>
                        <button type="submit" id="ruajButton" class="btn btn-primary ml-2">Ruaj</button>
                        <button type="reset" id="resetButton" class="btn btn-primary ml-2">Skanim i Ri</button>
                    </td>
                </tr>
            </table>


            }
        }


            <div class="popup" id="popupWindow" style="display: none;">
                <h3>Saved Data</h3>
                <p> @ViewBag.savedData</p>
            </div>


            <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
            <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>


            <script>

                $(document).ready(function () {
                    $("#searchByRefcode").click(function () {
                        var refcode = $("#REFCODE").val();
                        if (refcode !== "") {
                            $("#tab1").hide();
                            $.post("/Fiscalization/SearchByRefcode", { REFCODE: refcode }, function (data) {
                                $("#tab1").hide();

                                $("#resultTable").html(data).show();
                            });
                        }
                    });

                  
                    $("#scan").click(function () {
                        var searchBoxValue = $("#searchBox").val();
                        $("#QRCODEVAL").val(searchBoxValue);
                        // Save the value in the database by making an AJAX POST request
                        $.post("/Fiscalization/SaveQRCodeValue", { QRCODEVAL: searchBoxValue }, function (data) {
                            // Handle the response from the server if needed

                            console.log("QR Code value saved: " + searchBoxValue);
                            $("#QRCODEVAL").val(searchBoxValue);
                        });
                    });

                        $("#searchBy").click(function () {
                        var searchBox = $("#searchBox").val();
                        if (searchBox !== "") {
                            $("#reftab").hide();
                        $.post("/Fiscalization/SearchBy", {searchBox: searchBox }, function (data) {
                            $("#resultTable").hide();
                        $("#tab1").html(data).show();
                            });
                        }
                    });
                            
            

                function deleteRow() {
                    if (confirm("Are you sure you want to delete this row?")) {

                    }
                }

                $("#resetButton").click(function () {
                    window.location.href = "/Fiscalization/Index";
                });



                $(document).ready(function () {
                    function updateDATTIMSEND() {
                        var currentDate = new Date();
                        var formattedDate = formatDate(currentDate);
                        $("#DATTIMSEND").val(formattedDate);
                        $("#PYMTDATTIM").val(formattedDate);
                    }

                    function formatDate(date) {
                        var year = date.getFullYear();
                        var month = String(date.getMonth() + 1).padStart(2, "0");
                        var day = String(date.getDate()).padStart(2, "0");
                        var hours = String(date.getHours()).padStart(2, "0");
                        var minutes = String(date.getMinutes()).padStart(2, "0");
                        var seconds = String(date.getSeconds()).padStart(2, "0");
                        return year + "-" + month + "-" + day + " " + hours + ":" + minutes + ":" + seconds;
                    }

                  

                    $("button[type='submit']").click(function (e) {
                        e.preventDefault();

                        if ($(this).hasClass("btn-primary")) {
                            updateDATTIMSEND();
                        }
                        $("form").submit();
                    });
                });

 

               

            </script>



         

</body>
</html>
