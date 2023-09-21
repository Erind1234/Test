@model List<InApps.Models.EmpModel>  <!-- Update the model type -->

@{
    ViewBag.Title = "Index";
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
            <!-- Existing search box -->
            <input type="text" name="searchBox" placeholder="Search by values separated by ;" />
            <input type="submit" value="Search" />
            <!-- New search box for REFCODE -->
            <input type="text" name="refCodeSearchBox" placeholder="Enter REFCODE" />
            <input type="submit" value="Search by REFCODE" />
        </form>
    </div>

    <div class="fixed-table">
        @if (Model != null && Model.Any())
        {
            <table>
                <tr>
                    <th>ID</th>
                    <th>User</th>
                    <th>Numri Urdhrit</th>
                    <th>Invoice Date</th>
                    <th>NIVF</th>
                    <th>NIPT Bleres</th>
                    <th>Emri Shites</th>
                    <th>Referenca e Teller</th>
                    <th>Tipi i Pageses</th>
                    <th>Statusi i Pageses</th>
                    <th>Monedha</th>
                    <th>Shuma e Paguar</th>
                    <th>IBAN</th>
                    <th>SWIFT</th>
                    <!-- Add more table headers as needed -->
                </tr>
                @foreach (var item in Model)
                {
                    <tr>
                        <td>@item.ID</td>
                        <td>@item.USR</td>
                        <td>@item.PYMTORDNUM</td>
                        <td>@item.INVOICEDATE</td>
                        <td>@item.NIVF</td>
                        <td>@item.PAYERNIPT</td>
                        <td>@item.TRANSACTIONCODE</td>
                        <td>@item.REFCODE</td>
                        <td>@item.PYMTTYPE</td>
                        <td>@item.PYMTSTATUS</td>
                        <td>@item.PAIDCUR</td>
                        <td>@item.PAIDAMT</td>
                        <td>@item.IBANNR</td>
                        <td>@item.SWIFTNR</td>
                        <!-- Add more table cells for other properties as needed -->
                    </tr>
                }
            </table>
        }
        else
        {
            <p>No records found.</p>
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

    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="~/Scripts/jquery-1.10.2.min.js"></script>
    <script src="~/Scripts/jquery.validate.min.js"></script>
    <script src="~/Scripts/jquery.validate.unobtrusive.min.js"></script>
</div>
