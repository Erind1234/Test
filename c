<!DOCTYPE html>
<html>
<head>
    <title>Popup</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <style>
        .popup-container {
            position: fixed;
            top: 100;
            left: 100;
            width: 100%;
            height: 100%;
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: rgba(0, 0, 0, 0.5);
        }

        .popup-content {
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.3);
        }

        .close-button {
            position: absolute;
            top: 10px;
            right: 10px;
            cursor: pointer;
        }
    </style>
</head>

<body>
    <div class="popup-container">
        <div class="popup-content">
            <span class="close-button">&times;</span>
            <h2>Saved Fiscalization Details</h2>

            <table style="border-collapse: collapse;">
                <tr>
                    <th style="border: 1px solid black; padding: 8px;"></th>
                    <th style="border: 1px solid black; padding: 16px;">ID</th>
                    <th style="border: 1px solid black; padding: 8px;">User</th>
                    <th style="border: 1px solid black; padding: 8px;">Referenca</th>
                    <th style="border: 1px solid black; padding: 8px;">Nr urdher</th>
                    <th style="border: 1px solid black; padding: 8px;">NIPT Bleres</th>
                    <th style="border: 1px solid black; padding: 8px;">NIVF</th>
                    <th style="border: 1px solid black; padding: 8px;">Shuma</th>
                    <th style="border: 1px solid black; padding: 8px;">Monedha</th>
                    <th style="border: 1px solid black; padding: 8px;">Shitesi</th>
                    <th style="border: 1px solid black; padding: 8px;">Lloji</th>
                    <th style="border: 1px solid black; padding: 8px;">Nipt Shites</th>
                    <th style="border: 1px solid black; padding: 8px;">Edit</th> <!-- Add Edit column -->
                </tr>
                <tr>
                    <td style="border: 1px solid black; padding: 8px;"></td>
                    <td style="border: 1px solid black; padding: 16px;">@Model.ID</td>
                    <td style="border: 1px solid black; padding: 8px;">@Model.USR</td>
                    <td style="border: 1px solid black; padding: 8px;">@Model.REFCODE</td>
                    <td style="border: 1px solid black; padding: 8px;">@Model.PYMTORDNUM</td>
                    <td style="border: 1px solid black; padding: 8px;">@Model.PAYERNIPT</td>
                    <td style="border: 1px solid black; padding: 8px;">@Model.NIVF</td>
                    <td style="border: 1px solid black; padding: 8px;">@Model.PAIDAMT</td>
                    <td style="border: 1px solid black; padding: 8px;">@Model.PAIDCUR</td>
                    <td style="border: 1px solid black; padding: 8px;">@Model.TRANSACTIONCODE</td>
                    <td style="border: 1px solid black; padding: 8px;">@Model.PYMTTYPE</td>
                    <td style="border: 1px solid black; padding: 8px;">@Model.SELLERNIPT</td>
                    <td style="border: 1px solid black; padding: 8px;">
                        <a href="@Url.Action("EditFiscalization", "Fiscalization", new { ID = Model.ID })" class="btn btn-primary">Edit</a>
                    </td>
                </tr>
            </table>
        </div>
    </div>
</body>
</html>
