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


        public List<EmpModel> SearchByRefcode(string REFCODE)
        {
            List<EmpModel> searchResults = new List<EmpModel>();
            try { 
            connection();

                con.Open();
                using (SqlCommand cmd = new SqlCommand("GetFiscalDataByRefcode", con))
            {
                cmd.CommandType = CommandType.StoredProcedure;

                    // Add parameters to the stored procedure

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
        // Handle any exceptions here
        // You can log the exception, throw it, or handle it as needed
        // For example: throw new Exception("An error occurred: " + ex.Message);
    }

    return searchResults; // Return the list of results
}




}
}



@model InApps.Models.EmpModel


<head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Fiscalization</title>
    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet" />

    <style>
        /* Add CSS styles for freezing the table and the popup */
        .fixed-table {
            position: fixed;
            top: 150px; /* Adjust the top position as needed */
            left: 50%; /* Adjust the left position as needed */
            width: 90%;
            max-height: 500px; /* Adjust the max-height as needed */
            overflow-y: auto;
        }

        .popup {
            position: fixed;
            top: 50%; /* Adjust the top position as needed */
            left: 50%; /* Adjust the left position as needed */
            transform: translate(-50%, -50%);
            background-color: white;
            padding: 20px;
            border: 1px solid #ccc;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.2);
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Fiscalization</h1>

        @using (Html.BeginForm("Index", "Fiscalization", FormMethod.Post))
        {
            <div class="form-group">
                <input type="text" name="searchBox" class="form-control" placeholder="Enter search criteria" />
            </div>
            <button type="submit" class="btn btn-primary">Search</button>
        }

        <div class="form-group mt-4">
            <input type="text" id="REFCODE" class="form-control" placeholder="Enter REFCODE" />
            <button id="searchByRefcode" class="btn btn-success mt-2">Search by REFCODE</button>
        </div>

        <div id="resultTable" style="display: none;">
            <!-- Table content will be displayed here -->
        </div>

        <div class="fixed-table">
            @if (!string.IsNullOrEmpty(ViewBag.p1))
            {
                using (Html.BeginForm("SaveFiscalization", "Fiscalization", FormMethod.Post))
                {


                    <div style="display: flex; justify-content: center; align-items: center; height: 84444444440vh;">

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

                    <div class="popup" id="popupWindow" style="display: none;">
                        <h3>Saved Data</h3>
                        <p> @ViewBag.savedData</p>
                    </div>
                </div>

    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>

    <script>
        $(document).ready(function () {
            // Add an event listener for the "Search by REFCODE" button
            $("#searchByRefcode").click(function () {
                var refcode = $("#refcodeSearchBox").val();
                if (refcode !== "") {
                    $.post("/Fiscalization/SearchByRefcode", { searchBox2: refcode }, function (data) {
                        $("#resultTable").html(data);
                        $("#resultTable").show();
                    });
                }
            });
        });

        // Function to delete row
        function deleteRow() {
            if (confirm("Are you sure you want to delete this row?")) {
                // Add your delete logic here
            }
        }
    </script>
</body>

                        and store procedure
                        
CREATE PROCEDURE GetFiscalDataByRefcode
    @REFCODE NVARCHAR(50)
AS
BEGIN
    SELECT ID, USR, REFCODE,INVOICEDATE,PYMTORDNUM,PAYERNIPT,NIVF,PAIDAMT,PAIDCUR,TRANSACTIONCODE,PYMTTYPE,SELLERNIPT
    FROM Fiscal
    WHERE REFCODE = @REFCODE;
END
