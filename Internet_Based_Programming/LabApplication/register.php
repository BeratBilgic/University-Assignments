<?php
$host = 'localhost';
$port = '3306';
$database = 'php_lab_app';
$username = 'root';
$password = '';

$errors = [];

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $full_name = $_POST['full_name'];
    $email = $_POST['email'];
    $gender = $_POST['gender'];

    if (empty($full_name)) {
        $errors[] = "Full name field cannot be empty";
    }

    if (empty($email)) {
        $errors[] = "Email address field cannot be empty";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $errors[] = "Please enter a valid email address";
    }

    if (empty($errors)) {
        $conn = new mysqli($host, $username, $password, $database);

        if ($conn->connect_error) {
            die("Database connection failed:" . $conn->connect_error);
        }

        $sql = "INSERT INTO students (full_name, email, gender) VALUES ('$full_name', '$email', '$gender')";

        if ($conn->query($sql) === TRUE) {
            echo "Record successfully added.";

            $lastInsertedId = $conn->insert_id;
            $selectSql = "SELECT * FROM students WHERE id = $lastInsertedId";
            $result = $conn->query($selectSql);

            if ($result->num_rows > 0) {
                while ($row = $result->fetch_assoc()) {
                    echo "<br><br>Values of the added record:<br>";
                    echo "ID: " . $row["id"] . "<br>";
                    echo "Full Name: " . $row["full_name"] . "<br>";
                    echo "Email: " . $row["email"] . "<br>";
                    echo "Gender: " . $row["gender"] . "<br>";
                }
            }
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();
    } else {
        foreach ($errors as $error) {
            echo $error . "<br>";
        }
    }
}
?>
