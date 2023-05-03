<html>
<body>

<form action="<?php echo $_SERVER['PHP_SELF'];?>" method="POST" enctype="multipart/form-data">
    <input type="file" name="file">
    <input type ="submit" value="submit">
</form>

<?php
if ($_FILES["file"]["error"] == UPLOAD_ERR_OK) {

    $folderLocation = "/";

    if (!file_exists($folderLocation))
        mkdir($folderLocation);

    move_uploaded_file($_FILES["file"]["tmp_name"], "$folderLocation/" . basename($_FILES["file"]["name"]));

    echo "Filename: " . $_FILES['file']['name']."<br>";
    echo "Type : " . $_FILES['file']['type'] ."<br>";
    echo "Size : " . $_FILES['file']['size'] ."<br>";
    echo "Temp name: " . $_FILES['file']['tmp_name'] ."<br>";
    echo "Error : " . $_FILES['file']['error'] . "<br>";
}else{
    echo "Error : " . $_FILES['file']['error'] . "<br>";
}
?>

</body>
</html>