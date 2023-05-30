<?php

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>login</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    
</head>
<body>
    <div class="container">
        <div class="row vh-100 align-items-center justify-content-center">
            <div class="col-sm-8 col-md-6 col-lg-4 bg-white rounded border border-success  p-4 shadow">
                <div class="row justify-content-center mb-4">
                    <h1 class="heading text-center">Login</h1>
                </div>
                <form>
                    <div class="mb-4">
                        <label for="email" class="form-label">Email </label>
                        <input type="email" class="form-control" id="email" aria-describedby="emailHelp">
                    </div>
                    <div class="mb-4">
                        <label for="password" class="form-label">Password</label>
                        <input type="password" class="form-control" id="password" aria-describedby="emailHelp">
                    </div>
                    <button type="login" class="btn btn-success w-100">Login</button>
                </form>
                <p class = "mb-0 text-center">Not registered yet? <a href="#" class="text-decoration-none">Signup here</a></p>
            </div>
        </div>
    </div>
    
</body>
</html>
