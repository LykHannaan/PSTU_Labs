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

<?php if(isset($_COOKIE['user']) == true):?>
  <p><font color = "green"> Пользователь: <?= $_COOKIE['user']?>.</font></p>
  <?php endif; ?>
<h4>Данные о гостях</h4>
<h5><a href="blocks/guests.php">Полный список гостей</a><h5>
  
.....
<h4><a href="search.php">Поиск гостей</a></h4>
.....
<h4>Отчеты по состоянию номеров:</h4>
<h5><a href="otchet.php">Занятые номера:</a></h5>
<h5><a href="otchet2.php">Номера на ремонте:</a></h5>
<h5><a href="otchet3.php">Свободные номера:</a></h5>

</body> 
</html>

