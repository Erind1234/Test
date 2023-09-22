@model List<EmpModel> <!-- Make sure the model matches your EmpModel class -->

@if (Model != null && Model.Count > 0)
{
    <table class="table">
        <thead>
            <tr>
                <th>ID</th>
                <th>USR</th>
                <th>REFCODE</th>
                <th>INVOICEDATE</th>
                <!-- Add other table header columns for your properties -->
            </tr>
        </thead>
        <tbody>
            @foreach (var emp in Model)
            {
                <tr>
                    <td>@emp.ID</td>
                    <td>@emp.USR</td>
                    <td>@emp.REFCODE</td>
                    <td>@emp.INVOICEDATE.ToString("yyyy-MM-dd")</td>
                    <!-- Add other table data columns for your properties -->
                </tr>
            }
        </tbody>
    </table>
}
else
{
    <p>No results found.</p>
}
