using System;
using System.Collections.Generic;
using System.Web.Mvc;
using InApps.Models;
using InApps.Repository;

public class FiscalizationController : Controller
{
    private EmpRepository empRepo;

    public FiscalizationController()
    {
        empRepo = new EmpRepository();
    }

    // GET: Fiscalization/Index
    public ActionResult Index(string searchBox)
    {
        // Retrieve a list of EmpModels based on the search query or all records if no search query
        List<EmpModel> empList = string.IsNullOrEmpty(searchBox) ? empRepo.GetEmpList() : empRepo.SearchEmpList(searchBox);
        return View(empList);
    }

    // GET: Fiscalization/Create
    public ActionResult Create()
    {
        return View();
    }

    // POST: Fiscalization/Create
    [HttpPost]
    public ActionResult Create(EmpModel emp)
    {
        try
        {
            bool isAdded = empRepo.SaveFiscalization(emp);

            if (isAdded)
            {
                EmpModel lastInsertedEmp = empRepo.GetLastInsertedEmp();
                ViewBag.savedData = "Data has been saved successfully.";
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
                bool updated = empRepo.Update(emp);

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
            return View(emp);
        }
        catch (Exception e)
        {
            return View();
        }
    }
}




***********************


