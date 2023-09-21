while (reader.Read())
{
    EmpModel emp = new EmpModel
    {
        Property1 = reader["Column1"] != DBNull.Value ? reader["Column1"].ToString() : string.Empty,
        Property2 = reader["Column2"] != DBNull.Value ? reader["Column2"].ToString() : string.Empty,
        // Map other properties similarly...
    };
    results.Add(emp);
}




CREATE PROCEDURE YourStoredProcedureName
    @Refcode NVARCHAR(255)
AS
BEGIN
    SELECT Column1, Column2, Column3
    FROM YourTable
    WHERE Refcode = @Refcode;
END
