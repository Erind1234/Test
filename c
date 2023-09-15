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
            Guid myuuid = Guid.NewGuid();
            string myuuidAsString = myuuid.ToString();

            EmpModel emp = new EmpModel();
            emp.ID = myuuidAsString;
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
    public ActionResult Edit(string id)
    {
        EmpModel emp = empRepo.GetEmpModelById(id);
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
*******************************


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
        // Map other properties as needed
    }

    con.Close();
    return emp;
}
********************




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

        internal object GetEmpModelById()
        {
            throw new NotImplementedException();
        }

        //public bool Update(EmpModel emp)
        //{

        //        connection();
        //    SqlCommand com = new SqlCommand("Update", con);

        //            com.CommandType = CommandType.StoredProcedure;

        //    com.Parameters.AddWithValue("@ID", emp.ID);
        //    com.Parameters.AddWithValue("@NR", emp.NR);
        //    com.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
        //            com.Parameters.AddWithValue("@PYMTORDNUM", emp.PYMTORDNUM);
        //            com.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
        //            com.Parameters.AddWithValue("@BANKNIPT", emp.BANKNIPT);
        //            com.Parameters.AddWithValue("@PAYERNIPT", emp.PAYERNIPT);
        //            com.Parameters.AddWithValue("@EINFIC", emp.EINFIC);
        //            com.Parameters.AddWithValue("@PYMTDATTIM", emp.PYMTDATTIM);
        //            com.Parameters.AddWithValue("@PAIDAMT", emp.PAIDAMT);
        //            com.Parameters.AddWithValue("@OVERPAIDAMT", emp.OVERPAIDAMT);
        //            com.Parameters.AddWithValue("@PAIDCUR", emp.PAIDCUR);
        //            com.Parameters.AddWithValue("@TRANSACTIONCODE", emp.TRANSACTIONCODE);
        //            com.Parameters.AddWithValue("@PYMTTYPE", emp.PYMTTYPE);
        //            com.Parameters.AddWithValue("@PYMTSTATUS", emp.PYMTSTATUS);
        //            com.Parameters.AddWithValue("@CODE", emp.CODE);
        //            com.Parameters.AddWithValue("@MESSAGE", emp.MESSAGE);
        //            com.Parameters.AddWithValue("@USR", emp.USR);
        //            com.Parameters.AddWithValue("@SELLERNIPT", emp.SELLERNIPT);
        //            com.Parameters.AddWithValue("@INVOICEDATE", emp.INVOICEDATE);
        //            com.Parameters.AddWithValue("@IBANNR", emp.IBANNR);
        //            com.Parameters.AddWithValue("@SWIFTNR", emp.SWIFTNR);
        //            com.Parameters.AddWithValue("@BANKNAME", emp.BANKNAME);
        //            com.Parameters.AddWithValue("@QRCODEVAL", emp.QRCODEVAL);
        //            com.Parameters.AddWithValue("@NIVF", emp.NIVF);
        //            com.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);

        //            con.Open();
        //            int i = com.ExecuteNonQuery();
        //            con.Close();
        //            if (i >= 1)
        //            {

        //                return true;
        //            }
        //            else
        //            {
        //                return false;
        //            }
        //        }


        //public bool Edit(EmpModel emp)
        //{

        //    connection();
        //    SqlCommand com = new SqlCommand("Edit", con);

        //    com.CommandType = CommandType.StoredProcedure;

        //    com.Parameters.AddWithValue("@ID", emp.ID);
        //    com.Parameters.AddWithValue("@REFCODE", emp.REFCODE);
        //    com.Parameters.AddWithValue("@PYMTORDNUM", emp.PYMTORDNUM);
        //    com.Parameters.AddWithValue("@DATTIMSEND", emp.DATTIMSEND);
        //    com.Parameters.AddWithValue("@BANKNIPT", emp.BANKNIPT);
        //    com.Parameters.AddWithValue("@PAYERNIPT", emp.PAYERNIPT);
        //    com.Parameters.AddWithValue("@EINFIC", emp.EINFIC);
        //    com.Parameters.AddWithValue("@PYMTDATTIM", emp.PYMTDATTIM);
        //    com.Parameters.AddWithValue("@PAIDAMT", emp.PAIDAMT);
        //    com.Parameters.AddWithValue("@OVERPAIDAMT", emp.OVERPAIDAMT);
        //    com.Parameters.AddWithValue("@PAIDCUR", emp.PAIDCUR);
        //    com.Parameters.AddWithValue("@TRANSACTIONCODE", emp.TRANSACTIONCODE);
        //    com.Parameters.AddWithValue("@PYMTTYPE", emp.PYMTTYPE);
        //    com.Parameters.AddWithValue("@PYMTSTATUS", emp.PYMTSTATUS);
        //    com.Parameters.AddWithValue("@CODE", emp.CODE);
        //    com.Parameters.AddWithValue("@MESSAGE", emp.MESSAGE);
        //    com.Parameters.AddWithValue("@USR", emp.USR);
        //    com.Parameters.AddWithValue("@SELLERNIPT", emp.SELLERNIPT);
        //    com.Parameters.AddWithValue("@INVOICEDATE", emp.INVOICEDATE);
        //    com.Parameters.AddWithValue("@IBANNR", emp.IBANNR);
        //    com.Parameters.AddWithValue("@SWIFTNR", emp.SWIFTNR);
        //    com.Parameters.AddWithValue("@BANKNAME", emp.BANKNAME);
        //    com.Parameters.AddWithValue("@QRCODEVAL", emp.QRCODEVAL);
        //    com.Parameters.AddWithValue("@NIVF", emp.NIVF);
        //    com.Parameters.AddWithValue("@STPROFILE", emp.STPROFILE);

        //    con.Open();
        //    int i = com.ExecuteNonQuery();
        //    con.Close();
        //    if (i >= 1)
        //    {

        //        return true;
        //    }
        //    else
        //    {
        //        return false;
        //    }
        //}



        // Update an employee's details
        public bool Update(EmpModel emp)
        {
            
                connection();
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
                con.Open();
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






    

