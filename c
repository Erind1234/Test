@model List<InApps.Models.EmpModel>  <!-- Update the model type -->

<!-- ... (existing code) -->

<div class="form-group">
    <form method="post" id="fiscal">
        <!-- Existing search box -->
        <input type="text" name="searchBox" />
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
