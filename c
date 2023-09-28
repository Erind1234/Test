<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>

<script>
    $(document).ready(function () {
        // Function to save the QR code value
        $("#scan").click(function () {
            var searchBoxValue = $("#searchBox").val();
            $.post("/Fiscalization/SaveQRCodeValue", { QRCODEVAL: searchBoxValue }, function (data) {
                if (data.success) {
                    console.log("QR Code value saved: " + searchBoxValue);
                    $("#QRCODEVAL").val(searchBoxValue); // Set the value in the hidden field
                } else {
                    console.error("Failed to save QR Code value: " + data.message);
                }
            });
        });

        // Function to submit the main form
        $("button[type='submit']").click(function (e) {
            e.preventDefault();

            // Additional logic if needed

            $("form").submit();
        });

        // Function to reset the form
        $("#resetButton").click(function () {
            window.location.href = "/Fiscalization/Index";
        });
    });
</script>
