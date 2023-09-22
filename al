Server Error in '/' Application.
Compilation Error
Description: An error occurred during the compilation of a resource required to service this request. Please review the following specific error details and modify your source code appropriately.

Compiler Error Message: CS1973: 'HtmlHelper<EmpModel>' has no applicable method named 'TextBox' but appears to have an extension method by that name. Extension methods cannot be dynamically dispatched. Consider casting the dynamic arguments or calling the extension method without the extension method syntax.

Source Error:


Line 62:                     <tr>
Line 63:                         <td>@Html.Label("Numri Urdhrit")</td>
Line 64:                         <td>@Html.TextBox("PYMTORDNUM", ViewBag.p2, new { @class = "form-control" })</td>
Line 65:                         <td>@Html.Label("Invoice Date")</td>
Line 66:                         <td>@Html.TextBoxFor(model => model.INVOICEDATE, new { @Value = ViewBag.p4, @class = "form-control" })</td>

Source File: C:\Users\B010\Desktop\InApps\InApps\Views\Fiscalization\Index.cshtml    Line: 64
