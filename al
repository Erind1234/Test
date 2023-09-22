<script>
    // Function to handle the click event of the "Search by REFCODE" button
    $(document).ready(function () {
        $("#searchByRefcode").click(function () {
            var refcode = $("#refcodeSearchBox").val();
            $.ajax({
                url: "@Url.Action("SearchByRefcode", "Fiscalization")",
                type: "POST",
                data: { searchBox: refcode },
                success: function (result) {
                    $("#resultTable").html(result);
                    $("#resultTable").show();
                },
                error: function (error) {
                    console.error(error);
                }
            });
        });
    });
</script>
