@model InApps.Models.EmpModel

@{
    ViewBag.Title = "Edit Fiscalization";
}

<h2>Edit Fiscalization</h2>

@using (Html.BeginForm("UpdateFiscalization", "Fiscalization", FormMethod.Post))
{
    @Html.HiddenFor(model => model.ID)

    <div class="form-group">
        @Html.LabelFor(model => model.REFCODE)
        @Html.TextBoxFor(model => model.REFCODE, new { @class = "form-control" })
    </div>

    <div class="form-group">
        @Html.LabelFor(model => model.PYMTORDNUM)
        @Html.TextBoxFor(model => model.PYMTORDNUM, new { @class = "form-control" })
    </div>

    <div class="form-group">
        @Html.LabelFor(model => model.DATTIMSEND)
        @Html.TextBoxFor(model => model.DATTIMSEND, new { @class = "form-control" })
    </div>

    <div class="form-group">
        @Html.LabelFor(model => model.BANKNIPT)
        @Html.TextBoxFor(model => model.BANKNIPT, new { @class = "form-control" })
    </div>

    <div class="form-group">
        @Html.LabelFor(model => model.PAYERNIPT)
        @Html.TextBoxFor(model => model.PAYERNIPT, new { @class = "form-control" })
    </div>

    <!-- Add more fields for editing here -->

    <div class="form-group">
        <input type="submit" value="Update" class="btn btn-primary" />
    </div>
}
