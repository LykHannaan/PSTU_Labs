<?php
  require_once 'config/connect.php';
  $table_name = $_GET['name_table'];
  $id = $_GET['id'];
  $cols = $_GET['cols'];
  $sql = mysqli_query($conn, "SELECT * FROM `$table_name` WHERE `id` = '$id'");
  $sql = mysqli_fetch_assoc($sql);
  print_r($sql);
?>

<!DOCTYPE html>
<html lang="en">
<head>     
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content = "IE=edge">
  <meta name="viewport" content = "width=device-width, initial-scale=1.0">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet">
  <link rel = "stylesheet" href = "css/stylee.css">  
  <title>Пансионат "Overlook"</title> 
</head> 
<body> 

<div class="d-flex flex-column flex-md-row align-items-center p-3 
px-md-4 mb-3 bg-white border-bottom shadow-sm">
<h5 class="my-0 mr-md-auto font-weight-normal"><a href="index.php">Overlook</a></h5>
 <nav class ="my-2 my-md-0 mr-md-3">
 <a class="p-2 text-dark" href="rooms.php">Номерной фонд</a>
    <a class="p-2 text-dark" href="services.php">Дополнительные услуги</a>
 </nav>
 <a class="btn btn-sm btn-outline-secondary" href="blocks/exit.php">Выйти</a>
</div>

  <h2>Обновить запись</h2>
  <form action = "vendor/update.php" method = "post">
    <p>Тип номера</p>
    <input type = "text" name = "tip" value= "<?= $sql[1] ?>">
    <p>Вместимость</p>
    <input type = "text" name = "kolvm" value= "<?= $sql[2] ?>">
    <p>Описание</p>
    <input type = "text" name = "opisanie" value= "<?= $sql['group'] ?>">
    <p>Стоимость</p>
    <input type = "text" name = "stoimost" value= "<?= $sql['group'] ?>">
    <button type = "submit">Обновить</button>
    </form>
</body> 
</html>