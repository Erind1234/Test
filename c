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










    }
}




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

      







    }
}

store procedure 
CREATE PROCEDURE AddNewFiscal

    @REFCODE NVARCHAR(50),
    @DATTIMSEND NVARCHAR(50),
    @BANKNIPT NVARCHAR(50),
    @PYMTORDNUM NVARCHAR(50),
    @PAYERNIPT NVARCHAR(50),
    @EINFIC NVARCHAR(50),
    @PYMTDATTIM NVARCHAR(50),
    @PAIDAMT NVARCHAR(50),
    @OVERPAIDAMT NVARCHAR(50),
    @PAIDCUR NVARCHAR(50),
    @TRANSACTIONCODE NVARCHAR(50),
    @PYMTTYPE NVARCHAR(50),
    @PYMTSTATUS NVARCHAR(50),
    @CODE NVARCHAR(50),
    @MESSAGE NVARCHAR(50),
    @USR NVARCHAR(50),
    @SELLERNIPT NVARCHAR(50),
    @INVOICEDATE NVARCHAR(50),
    @IBANNR NVARCHAR(50),
    @SWIFTNR NVARCHAR(50),
    @BANKNAME NVARCHAR(50),
    @QRCODEVAL NVARCHAR(50),
    @NIVF NVARCHAR(50),
    @STPROFILE NVARCHAR(50)
AS
BEGIN
    INSERT INTO [dbo].[Fiscal] (
        REFCODE, DATTIMSEND, BANKNIPT, PYMTORDNUM, PAYERNIPT,
        EINFIC, PYMTDATTIM, PAIDAMT, OVERPAIDAMT, PAIDCUR,
        TRANSACTIONCODE, PYMTTYPE, PYMTSTATUS, CODE, MESSAGE,
        USR, SELLERNIPT, INVOICEDATE, IBANNR, SWIFTNR,
        BANKNAME, QRCODEVAL, NIVF, STPROFILE
    )
    VALUES (
       @REFCODE, @DATTIMSEND, @BANKNIPT, @PYMTORDNUM, @PAYERNIPT,
        @EINFIC, @PYMTDATTIM, @PAIDAMT, @OVERPAIDAMT, @PAIDCUR,
        @TRANSACTIONCODE, @PYMTTYPE, @PYMTSTATUS, @CODE, @MESSAGE,
        @USR, @SELLERNIPT, @INVOICEDATE, @IBANNR, @SWIFTNR,
        @BANKNAME, @QRCODEVAL, @NIVF, @STPROFILE
    );

    ---- Return the newly inserted ID
    --SELECT SCOPE_IDENTITY();
END
-------------------
 and table
CREATE TABLE [dbo].[Fiscal] (
    [ID]              INT           IDENTITY (1, 1) NOT NULL,
    [REFCODE]         NVARCHAR (50) NULL,
    [DATTIMSEND]      NVARCHAR (50) NULL,
    [BANKNIPT]        NVARCHAR (50) NULL,
    [PYMTORDNUM]      NVARCHAR (50) NULL,
    [PAYERNIPT]       NVARCHAR (50) NULL,
    [EINFIC]          NVARCHAR (50) NULL,
    [PYMTDATTIM]      NVARCHAR (50) NULL,
    [PAIDAMT]         NVARCHAR (50) NULL,
    [OVERPAIDAMT]     NVARCHAR (50) NULL,
    [PAIDCUR]         NVARCHAR (50) NULL,
    [TRANSACTIONCODE] NVARCHAR (50) NULL,
    [PYMTTYPE]        NVARCHAR (50) NULL,
    [PYMTSTATUS]      NVARCHAR (50) NULL,
    [CODE]            NVARCHAR (50) NULL,
    [MESSAGE]         NVARCHAR (50) NULL,
    [USR]             NVARCHAR (50) NULL,
    [SELLERNIPT]      NVARCHAR (50) NULL,
    [INVOICEDATE]     NVARCHAR (50) NULL,
    [IBANNR]          NVARCHAR (50) NULL,
    [SWIFTNR]         NVARCHAR (50) NULL,
    [BANKNAME]        NVARCHAR (50) NULL,
    [QRCODEVAL]       NVARCHAR (50) NULL,
    [NIVF]            NVARCHAR (50) NULL,
    [STPROFILE]       NVARCHAR (50) NULL,
    PRIMARY KEY CLUSTERED ([ID] ASC)
);


