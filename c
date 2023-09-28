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
