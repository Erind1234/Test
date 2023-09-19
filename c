public ActionResult SaveFiscalization(string QRCODEVAL, string IBANNR, string STPROFILE, string REFCODE, string PYMTORDNUM, string PAYERNIPT, string EINFIC, string PAIDAMT, string PAIDCUR, string TRANSACTIONCODE, string PYMTTYPE, string BANKNAME, string NIVF, string INVOICEDATE)
        {
            try
            {


                EmpModel emp = new EmpModel();
                
                emp.QRCODEVAL = "1";
                emp.STPROFILE = "1";
                emp.NIVF = NIVF;
                emp.REFCODE = REFCODE;
                emp.PYMTORDNUM = PYMTORDNUM;
                emp.PAYERNIPT = PAYERNIPT;
                emp.EINFIC = "1";
                emp.PAIDAMT = PAIDAMT;
                emp.PAIDCUR = PAIDCUR;
                emp.TRANSACTIONCODE = TRANSACTIONCODE;
                emp.PYMTTYPE = "1";
                emp.BANKNIPT = "1";
                emp.DATTIMSEND = "1";
                emp.PYMTDATTIM = "1";
                emp.OVERPAIDAMT = "1";
                emp.PYMTSTATUS = "1";
                emp.CODE = "1";
                emp.MESSAGE = "1";
                emp.USR = "1";
                emp.SELLERNIPT = "1";
                emp.INVOICEDATE = INVOICEDATE;
                emp.IBANNR = IBANNR;
                emp.SWIFTNR = "1";
                emp.BANKNAME = "BANKNAME";
                bool isAdded = empRepo.SaveFiscalization(emp);
