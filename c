@model InApps.Models.EmpModel

<head>
    <style>

        .container {
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: flex-start;
            height: 160vh;
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
            width: 400px;
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
            width: 60%;
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
        <h2>Edit Fiscalization</h2>

        <div class="fixed-table" id="tab1">
            @using (Html.BeginForm("UpdateFiscalization", "Fiscalization", FormMethod.Post))
            {
                @Html.HiddenFor(model => model.ID)
         

                @*<tr>
                    <td> @Html.LabelFor(model => model.REFCODE)</td>
                    <td>@Html.TextBoxFor(model => model.REFCODE)</td>
                </tr>*@
                <table>

                    <tr>
                        <td>@Html.Label("Numri Urdhrit")</td>
                        <td>@Html.TextBoxFor(model => model.PYMTORDNUM)</td>
                    </tr>
                    <tr>
                        <td>@Html.Label("Invoice Date:")</td>
                        <td>@Html.TextBoxFor(model => model.INVOICEDATE, new { @disabled = "disabled" })</td>
                    </tr>

                    <tr>
                        <td>@Html.Label("NIVF")</td>
                        <td>@Html.TextBoxFor(model => model.EINFIC, new { @disabled = "disabled"})</td>

                    </tr>
                               <tr>
                        <td>@Html.Label("NIPT Bleres:")</td>
                        <td>@Html.TextBoxFor(model => model.PAYERNIPT)</td>
                    </tr>
                    <tr>
                        <td>@Html.Label("Shites")</td>
                        <td>@Html.TextBoxFor(model => model.SELLERNIPT,new { @disabled = "disabled" })</td>
                    </tr>
                    <tr>
                        <td>@Html.Label("Emri Shites")</td>
                        <td>@Html.TextBoxFor(model => model.TRANSACTIONCODE, new {@disabled = "disabled", style = "width:400px;" })</td>
                    </tr>
                    <tr>
                        <td>@Html.Label("Referenca e Teller:")</td>
                        <td>@Html.TextBoxFor(model => model.REFCODE)</td>
                    </tr>
                    <tr>
                        <td>@Html.Label("Tipi i Pageses:")</td>
                        <td>
                            @Html.TextBoxFor(model => model.PYMTTYPE)
                        </td>

                    </tr>
                    <tr>
                        <td>@Html.Label("Statusi i Pageses:")</td>

                        <td>
                            @Html.TextBoxFor(model => model.STPROFILE)
                        </td>
                    </tr>
                    <tr>
                        <td>@Html.Label("Monedha:")</td>
                        <td>@Html.TextBoxFor(model => model.PAIDCUR, new { @disabled = "disabled" })</td>
                    </tr>

                    <tr>
                        <td>@Html.Label("Shuma e Paguar:")</td>
                        <td>@Html.TextBoxFor(model => model.PAIDAMT)</td>
                    </tr>


                    <tr>
                        <td>@Html.Label("IBAN & SWIFT:")</td>
                        <td>
                            @Html.TextBoxFor(model => model.IBANNR, new {@disabled = "disabled" })

                            @Html.TextBoxFor(model => model.BANKNAME, new {@disabled = "disabled" })
                        </td>
                    </tr>

                   

                    <tr>
                        <td></td>
                        <button type="submit" class="btn btn-primary">Update</button>
                    </tr>
                </table>


                }

</div>
   
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>
