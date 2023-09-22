@model InApps.Models.EmpModel

<!DOCTYPE html>
<html>
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
            <input type="text" id="refcodeSearchBox" class="form-control" placeholder="Enter REFCODE" />
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
                                <td>@Html.TextBox("PYMTORDNUM", ViewBag.p2, new { @class = "form-control" })</td>
                                <td>@Html.Label("Invoice Date")</td>
                                <td>@Html.TextBoxFor(model => model.INVOICEDATE, new { @Value = ViewBag.p4, @class = "form-control" })</td>
                            </tr>
                            <!-- Add more form fields as needed -->

                            <tr>
                                <td>@Html.Label("Referenca e Teller:")</td>
                                <td>@Html.TextBox("REFCODE", ViewBag.p1, new { @class = "form-control" })</td>
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

                            <!-- Add more form fields as needed -->

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
</html>
