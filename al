@model List<InApps.Models.EmpModel>

<table class="table">
    <thead>
        <tr>
            <th>ID</th>
            <th>USR</th>
            <th>REFCODE</th>
            <th>INVOICEDATE</th>
            <!-- Add other table headers as needed -->
        </tr>
    </thead>
    <tbody>
        @foreach (var item in Model)
        {
            <tr>
                <td>@item.ID</td>
                <td>@item.USR</td>
                <td>@item.REFCODE</td>
                <td>@item.INVOICEDATE</td>
                <!-- Add other table cells based on your EmpModel properties -->
            </tr>
        }
    </tbody>
</table>
