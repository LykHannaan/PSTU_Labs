<?php
require_once 'config/connect.php';
?>

<!DOCTYPE html>
<html lang="en">
<head>     
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content = "IE=edge">
  <meta name="viewport" content = "width=device-width, initial-scale=1.0">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" >   
  <link rel = "stylesheet" type="text/css" href = "css/stylee.css">
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
</div>

<?php
  $rs = mysqli_query($conn, "SELECT * FROM `room_type` ORDER BY `Стоимость (за сутки)` ASC"); 
  $rs2 = mysqli_query($conn, "SELECT * FROM `room_type` ORDER BY `Стоимость (за сутки)` ASC");
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
     <?php if(isset($_COOKIE['user']) == true):?>
       <th>&#9998;</th>
      <th>&#10006;</th>
      <?php endif; ?>
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
<?php if(isset($_COOKIE['user']) == true):?>
      <td><a href = "update.php?id=<?= $val[0] ?>&name_table=<?=$id_table?>&cols=<?=$col?>">Обновить</a></td>
      <td><a href = "vendor/delete.php?id=<?= $val[0] ?>&name_table=<?=$id_table?>">Удалить</a></td>
      <?php endif; ?>
    </tr>
      <?php }?>
      <tbody>
  </table>

  </body> 
</html>