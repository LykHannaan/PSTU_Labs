<?php
 // Подключение к MySQL
  require_once 'config/connect.php';
?>

<!DOCTYPE html>
<html lang="en">
<head>     
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content = "IE=edge">
  <meta name="viewport" content = "width=device-width, initial-scale=1.0">
  <link rel = "stylesheet" href = "https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css">  
  <link rel = "stylesheet" href = "css/stylee.css">
  <title>Пансионат "Overlook"</title> 
</head> 
<body>  
<div class="d-flex flex-column flex-md-row align-items-center p-3 
px-md-4 mb-3 bg-white border-bottom shadow-sm">
<h5 class="my-0 mr-md-auto font-weight-normal"><a href="index.php">Overlook</a</font></h5>
 <nav class ="my-2 my-md-0 mr-md-3">
 <a class="p-2 text-dark" href="rooms.php">Номерной фонд</a>
    <a class="p-2 text-dark" href="services.php">Дополнительные услуги</a>
 </nav>
</div>

  <div class = "container mt-4">
    <?php if(isset($_COOKIE['user']) == false):?>
   <h2>Авторизация</h2>
   <form action="blocks/auth.php" method="post">
     <input type="text" class="form-control" name="login" 
     id="login" placeholder="Введите логин"><br>
     <input type="password" class="form-control" name="pass" 
     id="pass" placeholder="Введите пароль"><br>
     <button class="btn btn-success"
     type="submit">Войти в систему</button>
    </form>
  </div>
  <?php else: 
    header('Location: /main.php'); ?>
  <?php endif; ?>

</body> 
</html>