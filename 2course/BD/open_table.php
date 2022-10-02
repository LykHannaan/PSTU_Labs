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
 <a class="btn btn-sm btn-outline-secondary" href="blocks/exit.php">Выйти</a>
</div>
<?php
  $id_table = $_GET['id_table'];
  ?>

  <?php
  $rs = mysqli_query($conn, "SELECT * FROM ".$_GET['id_table'].""); //запрос на выборку данных и выбраной таблицы
  $rs2 = mysqli_query($conn, "SELECT * FROM ".$_GET['id_table']."");
  $col = mysqli_num_fields($rs2);?>
   <table>
   <?php
    if($row_rs = mysqli_fetch_assoc($rs)){?>
     <tr>
     <?php
     foreach($row_rs as $k=>$v)
     { 
         echo "<th>".$k."</th>"; 
     }?>
      <th>&#9998;</th>
      <th>&#10006;</th>
     </tr>
     <?php
    }?>
    <?php
     $rows = mysqli_fetch_all($rs2); // массив с данными
     ?>
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
      <td><a href = "update.php?id=<?= $val[0] ?>&name_table=<?=$id_table?>&cols=<?=$col?>">Обновить</a></td>
      <td><a href = "vendor/delete.php?id=<?= $val[0] ?>&name_table=<?=$id_table?>">Удалить</a></td>
      </tr>
      <?php }?>
     
  </table>
<button type = "submit">
        <td><a href = "insert.php?row_main=<?=$rows_rs?>&cols=<?=$col?>">Добавить запись</a></button>


<?if ($id_table == 'employees'){?>   
  <h2>Создать представления :</h2>    
  <form action = "create_view.php">
  <input type="hidden" name="view1" >
  <button type = "submit">Номера </button>
  </form>
  <form action = "create_view.php" method = "post">
  <input type="hidden" name="view2">
  <button type = "submit">VIEW №2 - Adress</button>
  </form>
  <form action = "create_view.php" method = "post">
  <input type="hidden" name="view3">
  <button type = "submit">VIEW №3 - EXP </button>
  </form>
<?}?>
  </form>

</body> 
</html>