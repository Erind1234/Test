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


            .nu766


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

/////////////////////////////////////////////////

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

        <div class="fixed-table mt-5">
            @if (!string.IsNullOrEmpty(ViewBag.p1))
            {
                using (Html.BeginForm("SaveFiscalization", "Fiscalization", FormMethod.Post))
                {
            <div style="text-align: center; background-color: #e7e7ff;">
                <table class="table table-bordered">
                    <tr>
                        <td>@Html.Label("Numri Urdhrit")</td>
                        <td>@Html.TextBoxFor(model => model.PYMTORDNUM, new { @class = "form-control" })</td>
                        <td>@Html.Label("Invoice Date")</td>
                        <td>@Html.TextBoxFor(model => model.INVOICEDATE, new { @class = "form-control" })</td>
                    </tr>



                    <!-- Add more form fields as needed -->

                    <tr>
                        <td>@Html.Label("Referenca e Teller:")</td>
                        <td>@Html.TextBoxFor(model => model.REFCODE, new { @class = "form-control" })</td>
                    </tr>

                    <tr>
                        <td>@Html.Label("Tipi i Pageses:")</td>
                        <td>
                            @Html.DropDownListFor(model => model.PYMTTYPE, new SelectList(new[]
                            {
                                new { Value = "CASH", Text = "CASH" },
                                new { Value = "NON_CASH", Text = "NON_CASH" }
                            }, "Value", "Text"), new { @class = "form-control" })
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
                    <tr>
                        <td>&nbsp;</td>
                        <td colspan="3" style="text-align: center;">
                            <input type="submit" value="Save" class="btn btn-primary" />
                            <button type="button" onclick="deleteRow()" class="btn btn-danger">Delete</button>
                            <input type="reset" value="New Scan" class="btn btn-secondary" />
                        </td>
                    </tr>
                </table>


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
