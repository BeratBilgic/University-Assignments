<?php
session_start();
?>
<!DOCTYPE html>
<html>
<body>

<?php
echo session_id() . "<br>";
$_SESSION["favcolor"] = "yellow";
$_SESSION["favanimal"] = "bird";
print_r($_SESSION);
echo "<br>";

// remove all session variables
echo "<br>";
session_unset();
echo session_id() . "<br>";
echo "after session_unset(); <br>";
print_r($_SESSION);
echo "<br>";

// destroy the session
echo "<br>";
session_destroy();
echo session_id() . "<br>";
echo "after session_destroy(); <br>";
print_r($_SESSION);
?>

</body>
</html>