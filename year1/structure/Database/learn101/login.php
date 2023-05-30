<?php
session_start();
// Include the database connection file

if (isset($_SESSION['email'])) {
  // Unset all session variables
  $_SESSION = array();

  // Destroy the session
  session_destroy();
}

require_once "../components/connect.php";

if(isset($_POST['submit'])) {
  $email = $_POST['email'];
  $password = $_POST['password'];

  $query = "SELECT * FROM customer WHERE cus_email = :email AND cus_password = :password";
  $stmt = $pdo->prepare($query);
  $stmt->bindParam(':email', $email);
  $stmt->bindParam(':password', $password);
  $stmt->execute();

  $row_count = $stmt->rowCount();

  $stne = $pdo->prepare("SELECT * FROM `customer` WHERE cus_email = ?");
  $stne->execute([$email]);
  $row = $stne->fetch(PDO::FETCH_ASSOC);
  if($row){
    $_SESSION['fname'] = $row['cus_fname'];
  }

  if($row_count == 1) {
    $_SESSION['email'] = $email;
    header("Location: home.php");
  } else {
    $query = "SELECT * FROM employee WHERE emp_email = :email AND emp_password = :password";
    $stmt = $pdo->prepare($query);
    $stmt->bindParam(':email', $email);
    $stmt->bindParam(':password', $password);
    $stmt->execute();

    $row_count = $stmt->rowCount();

    if($row_count == 1) {
      $stne = $pdo->prepare("SELECT * FROM `employee` WHERE emp_email = ?");
      $stne->execute([$email]);
      $row = $stne->fetch(PDO::FETCH_ASSOC);
      if($row){
        $_SESSION['fname'] = $row['emp_name'];
      }

      $_SESSION['email'] = $email;
      header("Location: /pizza-database-project/admin/admin.php"); 
    } else {
      echo "Invalid login credentials";
    }

  }
}
?>

<!DOCTYPE html>
<html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Login Page</title>


  <!-- custom css file link  -->
  <link rel="stylesheet" type="text/css" href="../css/style.css">
	<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous"></head>
</head>
<body>
    <!-- <form method="post" action="">
      <input type="email" name="email" required placeholder="Enter your email"><br><br>
      <input type="password" name="password" required placeholder="Enter your password"><br><br>
      <input type="submit" name="submit" value="Login">
      <a href="signup.php" class="btn btn-primary">Register</a>
    </form> -->
  </body>
</html>
