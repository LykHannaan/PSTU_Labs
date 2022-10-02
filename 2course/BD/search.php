<?php
 // Подключение к MySQL
  require_once 'config/connect.php';
  $table_name = $_GET['name_table'];
  $sql = mysqli_query($conn, "SELECT * FROM `$table_name` WHERE `id` = '$id'");
  $sql = mysqli_fetch_assoc($sql);
?>
<!DOCTYPE html>
<html lang="en">
<head>     
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content = "IE=edge">
  <meta name="viewport" content = "width=device-width, initial-scale=1.0">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet">
  <link rel = "stylesheet" href = "css/stylee.css">  
  <script src="https://snipp.ru/cdn/jquery/2.1.1/jquery.min.js"></script>
<script src="https://snipp.ru/cdn/maskedinput/jquery.maskedinput.min.js"></script>
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

<div class="col-md-7 col-lg-8">
<p class = "p-2 text-dark">По дате: </p>
  <form action="blocks/requests.php" class="needs-validation">
  <div class="row g-3">
    <div class="col-sm-6">
    <label for="date"><b>Дата выезда</b></label>
    <input class="form-control input-number" type="text" maxlength="10" placeholder="____-__-__" name="date" required>
    <script>
              $('body').on('input', '.input-number', function(){
                this.value = this.value.replace(/[^0-9\-]/g, '');});
              </script>
    <button type="submit" class="w-100 btn btn-primary btn-lg">Поиск</button>
  </form>
</div>

<div class="col-md-7 col-lg-8">
<p class = "p-2 text-dark">По фамилии: </p>
  <form action="blocks/requests.php" class="needs-validation">
  <div class="row g-3">
  <div class="col-sm-6">
    <input class="form-control input-words" type="text" name="name" required>
    <script>
              $('body').on('input', '.input-words', function(){
                this.value = this.value.replace(/[^a-zа-яё\s]/gi, '')
                });
              </script>
    <button type="submit" class="w-100 btn btn-primary btn-lg">Поиск</button>
  </form>
  </div>

<div class="col-md-7 col-lg-8">
<p class = "p-2 text-dark">По номеру: </p>
  <form action="blocks/reg2.php" class="needs-validation">
  <div class="row g-3">
  <div class="col-sm-6">
    <input class="form-control input-number" type="text" maxlength="3" name="room" required>
    <script>
              $('body').on('input', '.input-number', function(){
                this.value = this.value.replace(/[^0-9]/g, '');});
              </script>
    <button type="submit" class="w-100 btn btn-primary btn-lg">Поиск</button>

  </form>
  </div>