<?php
$host = 'localhost';
$port = '3306';
$database = 'php_lab_app';
$username = 'root';
$password = '';

$conn = new mysqli($host, $username, $password, $database);

if ($conn->connect_error) {
    die("Database connection failed: " . $conn->connect_error);
}

$sql = "CREATE TABLE IF NOT EXISTS students (
    id INT(11) AUTO_INCREMENT PRIMARY KEY,
    full_name VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
    gender ENUM('Male', 'Female') NOT NULL
)";

if ($conn->query($sql) === TRUE) {
    echo "Table created/Existing table used";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
