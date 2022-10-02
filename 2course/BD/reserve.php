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
  <link rel = "stylesheet" type="text/css" href = "css/stylee.css">
  <title>Бронирование номеров</title> 
</head> 
<body>  
<div class="d-flex flex-column flex-md-row align-items-center p-3 
px-md-4 mb-3 bg-white border-bottom shadow-sm">
 <h5 class="my-0 mr-md-auto font-weight-normal"><a href="index.php">Overlook</a></h5>
 <nav class ="my-2 my-md-0 mr-md-3">
    <a class="p-2 text-dark" href="rooms.php">Номерной фонд</a>
    <a class="p-2 text-dark" href="services.php">Дополнительные услуги</a>
    <a class="p-2 text-dark" href="#">Бронирование</a>
 </nav>
 
</div>

<!-- главная картинка --> <div class="heroimage"></div>
 
<div class="col-md-7 col-lg-8">
        <h4 class="mb-3">Контактные данные</h4>
        <form class="needs-validation" novalidate>
          <div class="row g-3">
            <div class="col-sm-6">
              <label for="firstName" class="form-label">Фамилия</label>
              <input type="text" class="form-control" id="firstName" placeholder="" value="" required>
              <div class="invalid-feedback">
                Valid first name is required.
              </div>
            </div>

            <div class="col-sm-6">
              <label for="lastName" class="form-label">Имя</label>
              <input type="text" class="form-control" id="lastName" placeholder="" value="" required>
              <div class="invalid-feedback">
                Valid last name is required.
              </div>
            </div>
            <div class="col-sm-6">
              <label for="lastName" class="form-label">Отчество</label>
              <input type="text" class="form-control" id="lastName" placeholder="" value="" required>
              <div class="invalid-feedback">
                Valid last name is required.
              </div>
            </div>

            <div class="col-12">
              <label for="email" class="form-label">Email <span class="text-muted">(Optional)</span></label>
              <input type="email" class="form-control" id="email" placeholder="you@example.com">
              <div class="invalid-feedback">
                Please enter a valid email address for shipping updates.
              </div>
            </div>

            <div class="col-md-6">
              <label for="cc-number" class="form-label">Телефон</label>
              <input type="text" class="form-control" id="cc-number" placeholder="" required>
              <div class="invalid-feedback">
                Credit card number is required
              </div>
            </div>

            <div class="col-md-3">
              <label for="cc-cvv" class="form-label">Кол-во гостей</label>
              <input type="text" class="form-control" id="cc-cvv" placeholder="" required>
              <div class="invalid-feedback">
                Security code required
              </div>
            </div>
          </div>

          <hr class="my-4">

          <button class="w-100 btn btn-primary btn-lg" type="submit">Найти номер</button>
</body> 
</html>