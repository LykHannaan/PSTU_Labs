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

<?php
  $rs = mysqli_query($conn, "SELECT `Код_номера`, `Тип_номера`, `Статус` FROM rooms WHERE Статус = 'свободен'"); 
  $rs2 = mysqli_query($conn, "SELECT `Код_номера`, `Тип_номера`, `Статус` FROM rooms WHERE Статус = 'свободен'");
  $col = mysqli_num_fields($rs2);?>
<table class = "green">
   <?php
    if($row_rs = mysqli_fetch_assoc($rs)){?>
     <tr>
     <?php
     foreach($row_rs as $k=>$v)
     { 
         echo "<th>".$k."</th>"; 
     }?>
    
     </tr>
     <?php
    }?>
    <?php
     $rows = mysqli_fetch_all($rs2); // массив с данными
     ?>
     <tbody>
      <tr>
      <?php
      foreach($rows as $val) //перебор массива в цикле
      {
        $i = 0;
           do {?>
           <td><?= $val[$i] ?></td>
           <?php
            $i++;
           } while($i < $col);
           ?>

    </tr>
      <?php }?>
      <tbody>
  </table>
  </form>
  </div