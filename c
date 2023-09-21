@model InApps.Models.EmpModel

@{
    ViewBag.Title = "Index";
}

<style>
    /* Add CSS styles for freezing the table and the popup */
    .fixed-table {
        position: fixed;
        top: 400px;
        left: 400px;
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
                    <li class="breadcrumb-item active"><a href="javascript:void(0)">Index</a></li>
                </ol>
            </div>
        </div>
    </div>

    <div class="form-group">
        <form method="post" id="fiscal">
            <div class="table-responsive" style="align-content:center"></div>
        </form>
    </div>

    <h1>Fiscalization</h1>

    @using (Html.BeginForm("Index", "Fiscalization", FormMethod.Post))
    {
        <input type="text" name="searchBox" />
        <input type="submit" value="Search" />
    }

    <div>
        <input type="text" id="refcodeSearchBox" />
        <button id="searchByRefcode">Search by REFCODE</button>
    </div>

    <div id="resultTable" style="display: none;">
        <!-- Table content will be displayed here -->
    </div>

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
                            <!-- Add more form fields as needed -->

                            <tr>
                                <td>@Html.Label("Referenca e Teller:")</td>
                                <td>@Html.TextBox("REFCODE")</td>
                            </tr>

                            <!-- Add more form fields as needed -->

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
        
        // Function to handle the click event of the "Search by REFCODE" button
        $(document).ready(function () {
            $("#searchByRefcode").click(function () {
                var refcode = $("#refcodeSearchBox").val();
                if (refcode) {
                    $.ajax({
                        url: "/Fiscalization/SearchByRefcode",
                        data: { refcode: refcode },
                        type: "GET",
                        dataType: "html",
                        success: function (data) {
                            $("#resultTable").html(data);
                            $("#resultTable").show();
                        },
                        error: function () {
                            alert("An error occurred while fetching data.");
                        }
                    });
                }
            });
        });
    </script>

    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="~/Scripts/jquery-1.10.2.min.js"></script>
    <script src="~/Scripts/jquery.validate.min.js"></script>
    <script src="~/Scripts/jquery.validate.unobtrusive.min.js"></script>
</div>
