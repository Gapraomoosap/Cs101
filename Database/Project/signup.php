<?php

session_start();

require_once "../components/connect.php";

if(isset($_SESSION['user_id'])){
    $user_id = $_SESSION['user_id'];
}else{
    $user_id = '';
};


if(isset($_POST['submit'])){

    $fname = $_POST['fname'];
    $fname = filter_var($fname, FILTER_SANITIZE_STRING);
    $lname = $_POST['lname'];
    $lname = filter_var($lname, FILTER_SANITIZE_STRING);
    $phone = $_POST['phone'];
    $phone = filter_var($phone, FILTER_SANITIZE_STRING);
    $birthdate = $_POST['birthdate'];
    $birthdate = filter_var($birthdate, FILTER_SANITIZE_STRING);
    $gender = $_POST['gender'];
    $email = $_POST['email'];
    $email = filter_var($email, FILTER_SANITIZE_STRING);
    $password = ($_POST['password']);
    $password = filter_var($password, FILTER_SANITIZE_STRING);
    $confirm_password = ($_POST['confirm_password']);
    $confirm_password = filter_var($confirm_password, FILTER_SANITIZE_STRING);

    $select_user = $pdo->prepare("SELECT * FROM `customer` WHERE cus_email = ? OR cus_phone = ?");
    $select_user->execute([$email, $phone]);
    $row = $select_user->fetch(PDO::FETCH_ASSOC);

    if($select_user->rowCount() > 0){
        $message[] = 'email or number already exists!';
    }else{
        if($password != $confirm_password){
            $message[] = 'confirm password not matched!';
        }else{
            $insert_user = $pdo->prepare("INSERT INTO `customer` (cus_fname, cus_lname, cus_phone, cus_birthdate, cus_gender, cus_email, cus_password) VALUES (?, ?, ?, ?, ?, ?, ?)");
            $insert_user->execute([$fname, $lname, $phone, $birthdate, $gender, $email, $password]);
            // $select_user = $pdo->prepare("SELECT * FROM `customer` WHERE cus_email = ? AND cus_password = ?");
            // $select_user->execute([$email, $password]);
            // $row = $select_user->fetch(PDO::FETCH_ASSOC);
            header('Location: home.php');
        }
    }
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sign Up</title>

    <!-- font awesome cdn link  -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.1.1/css/all.min.css">

    <!-- custom css file link  -->
    <link rel="stylesheet" href="css/style.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous"></head>

    <!-- bootstrap  -->

</head>
<body>

<!-- header section starts  
php include 'components/user_header.php'; ?> -->
<!-- header section ends -->

<section class="form-container ">
    <div style="display: flex; justify-content: center; align-items: center; min-height: 100vh; ">
        <form method="post" action="" style="border:1px solid black; padding: 3rem; border-radius : 1rem ; border-color: green" class="p-4 shadow">
            <fieldset name="register">
            <h2 class="text-center">Register</h2>
            <hr>

            <!-- F/L name -->
            
            <div class="row g-3">
                <div class="form-icon" style="display: flex; align-items: start; justify-content: space-between;" >
                        <img src="https://1112.com/images/form/name_form.svg" style="padding: .75em; ">
                        <div style="width: 25em;">
                            <input type="text" name="fname" class="form-control" style="margin-bottom :1rem" placeholder="First name" aria-label="First name" maxlength="50" required >
                            <input type="text" name="lname"class="form-control" style="margin-bottom :1rem" placeholder="Last name" aria-label="Last name" maxlength="50" required >
                        </div>
                        
                    </div>
                    
                </div>
                
                <div class="mb-3"> <!-- Phone number -->
                <div class="form-icon" style="display: flex; align-items: center; justify-content: space-between;" >
                    <img src="https://1112.com/images/form/phone_form.svg" style ="padding: .75em; margin:auto;">
                    <div style="width: 25em;">
                        <input type="text" class="form-control" stlye =  name="phone" placeholder="+66" maxlength="10" required >
                    </div>
                </div>
            </div>
            
            <div class="mb-3"> <!-- Date of birth -->
                <div class="form-icon" style="display: flex; align-items: center; justify-content: center;" >
                    <img src="https://1112.com/images/form/birthday_form.svg" style ="padding: .5em; " >
                    <div style="width: 25em;">
                        <input id="startDate" name="birthdate" class="form-control" type="date" required />
                    </div>
                </div>
            </div>

            <!-- Gender -->
            <div class="form-gender" style="display: flex; align-items: start; justify-content: start; padding-top :">
                <div class="form-icon">
                    <img class="gender_form" src="https://1112.com/images/form/gender_form.svg" style = "padding-left: .5em;  margin:auto;">
                </div>

                <div class="form-check form-check-inline">
                    <input class="" type="radio" name="gender" id="inlineRadio1" value="male" required>
                    <label class="form-check-label" for="inlineRadio1">Male</label>
                    
                </div>
                <div class="form-check form-check-inline">
                    <input class="" type="radio" name="gender" id="inlineRadio2" value="female" required>
                    <label class="form-check-label" for="inlineRadio1">Female</label>
                </div>
                <div class="form-check form-check-inline">
                    <input class="" type="radio" name="gender" id="inlineRadio3" value="none" required checked>
                    <label class="form-check-label" for="inlineRadio1">None</label>
                </div>
            </div>
        <!-- Email -->
            <div class="mb-3" style="display: flex; align-items: center; justify-content: space-between; padding-top:1rem;"> 
                <div class="form-icon">
                    <img src="https://1112.com/images/form/mail_form.svg" style = "padding: .75em; margin:auto;">
                </div>
                <div class="form-email" >
                <div style="width: 25em;">
                    <input type="email" class="form-control" name="email" aria-describedby="email" placeholder="Email" maxlength="50" required >
                </div>
                </div>
            </div>

        <!-- Password -->
            <div class="mb-3"> 
                <div class="form-icon" style="display: flex; align-items: start; justify-content: space-between;" >
                    <img src="https://1112.com/images/form/password_form.svg" style="padding: .75em; ">
                    <div style="width: 25em;">
                        <input type="password" class="form-control" style="margin-bottom :1rem" placeholder="Password" name="password" maxlength="20" required >
                        <input type="password" class="form-control" style="margin-bottom :1rem" placeholder="Confirm password" name="confirm_password" maxlength="20" required >
                    </div>
                    
                </div>
            </div>
            
            <div class="form-group" style="text-align:center;" style="display: flex; justify-content: center;">
                <!-- <button type="submit" name="submit" class="btn btn-primary">Register</button> -->
                <input type="submit" class="btn btn-success " style="padding: 10px 50px;" name="submit" value="Register" >
            </div>
            
            </fieldset>
        </form>
    </div>
</section>


<!-- custom js file link  -->
<script src="js/script.js"></script>

</body>
</html>