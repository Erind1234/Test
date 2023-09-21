@model List<InApps.Models.EmpModel>

@{
    ViewBag.Title = "Index";
    // Layout = "~/Views/Shared/_Layout.cshtml";
}

<style>
    /* Add CSS styles for freezing the table and the popup */
    .fixed-table {
        /* ... (your existing styles) */
    }

    .popup {
        /* ... (your existing styles) */
    }
</style>

<div class="content-body">
    <div class="container-fluid">
        <div class="row page-titles mx-0">
            <!-- ... (your existing HTML) -->
        </div>
    </div>

    <div class="form-group">
        <form method="post" id="fiscal">
            <input type="text" name="searchBox" />
            <input type="submit" value="Search" />
            <input type="text" name="refCodeSearchBox" placeholder="Enter REFCODE" />
            <input type="submit" value="Search by REFCODE" />
        </form>
    </div>

    <h1>Fiscalization</h1>

    @using (Html.BeginForm("Index", "Fiscalization", FormMethod.Post))
    {
        <input type="text" name="searchBox" />
        <input type="submit" value="Search" />
    }

    <div class="fixed-table">
        @if (Model != null && Model.Any())
        {
            <table>
                <!-- Your table header row here -->
                <tr>
                    <th>ID</th>
                    <th>User</th>
                    <th>Referenca</th>
                    <!-- Add more table headers as needed -->
                </tr>
                @foreach (var item in Model)
                {
                    <tr>
                        <td>@item.ID</td>
                        <td>@item.USR</td>
                        <td>@item.REFCODE</td>
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

    <div class="popup" id="popupWindow" style="display: none;">
        <h3>Saved Data</h3>
        <p>@ViewBag.savedData</p>
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
</div>
