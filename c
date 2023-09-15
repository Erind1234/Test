using System;
using System.ComponentModel.DataAnnotations;

namespace InApps.Models
{
    public class EmpModel
    {
        public int ID { get; set; }
        public string REFCODE { get; set; }
        public string DATTIMSEND { get; set; }
        public string BANKNIPT { get; set; }
        public string PYMTORDNUM { get; set; }
        public string PAYERNIPT { get; set; }
        public string EINFIC { get; set; }
        public string PYMTDATTIM { get; set; }
        public string PAIDAMT { get; set; }
        public string OVERPAIDAMT { get; set; }
        public string PAIDCUR { get; set; }
        public string TRANSACTIONCODE { get; set; }
        public string PYMTTYPE { get; set; }
        public string PYMTSTATUS { get; set; }
        public string CODE { get; set; }
        public string MESSAGE { get; set; }
        public string USR { get; set; }
        public string SELLERNIPT { get; set; }
        public string INVOICEDATE { get; set; }
        public string IBANNR { get; set; }
        public string SWIFTNR { get; set; }
        public string BANKNAME { get; set; }
        public string QRCODEVAL { get; set; }
        public string NIVF { get; set; }
        public string STPROFILE { get; set; }
    }
}
************************
using System;
using System.Collections.Generic;
using System.Linq;

namespace InApps.Repository
{
    public class EmpRepository
    {
        // Your other repository methods

        // Implement a search method
        public List<EmpModel> SearchEmpList(string searchTerm)
        {
            // Assuming you have a list of employees named empList, replace this with your actual data source
            List<EmpModel> empList = GetEmpList(); // You should replace this with your actual data retrieval method

            // Perform a case-insensitive search based on a property, e.g., Name
            var filteredEmployees = empList
                .Where(emp => emp.Name != null && emp.Name.IndexOf(searchTerm, StringComparison.OrdinalIgnoreCase) >= 0)
                .ToList();

            return filteredEmployees;
        }
    }
}
