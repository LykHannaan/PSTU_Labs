<?php
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
<p style="font-size:18px; color: green;">Пользователь: <?= $_COOKIE['user'] ?>.</p>
  <?php endif; ?>
  
  <div class="col-md-7 col-lg-8">
        <h4 class="mb-3">Заполнение данных о клиенте</h4>

        <?php if(isset($_COOKIE['success']) == false):?>
        <form class="needs-validation" action = "vendor/insert.php" method = "post">
          <div class="row g-3">
            <div class="col-sm-6">
              <label for="firstName" class="form-label">Фамилия</label>
              <input type="text" class="form-control input-words" name="firstname" required>
              <script>
              $('body').on('input', '.input-words', function(){
                this.value = this.value.replace(/[^a-zа-яё\s]/gi, '')
                });
                </script>
              <div class="invalid-feedback">
                Valid first name is required.
              </div>
            </div>

            <div class="col-sm-6">
              <label for="lastName" class="form-label">Имя</label>
              <input type="text" class="form-control input-words" name="lastname" required>
              <script>
              $('body').on('input', '.input-words', function(){
                this.value = this.value.replace(/[^a-zа-яё\s]/gi, '')
                });
                </script>
              <div class="invalid-feedback">
                Valid last name is required.
              </div>
            </div>
            <div class="col-sm-6">
              <label for="threeName" class="form-label">Отчество</label>
              <input type="text" class="form-control input-words" name="threename" required>
              <script>
              $('body').on('input', '.input-words', function(){
                this.value = this.value.replace(/[^a-zа-яё\s]/gi, '')
                });
                </script>
              <div class="invalid-feedback">
                Valid last name is required.
              </div>
            </div>
            <div class="col-sm-6">
              <label for="Date1" class="form-label">Дата заезда</label>
              <input type="text" class="form-control input-number" maxlength="10" placeholder="____-__-__" name="Date1" required>
              <script>
              $('body').on('input', '.input-number', function(){
                this.value = this.value.replace(/[^0-9\-]/g, '');});
              </script>
              <div class="invalid-feedback">
                Valid last name is required.
              </div>
            </div>
            <div class="col-sm-6">
              <label for="Date2" class="form-label">Дата выезда</label>
              <input type="text" class="form-control input-number" maxlength="10" placeholder="____-__-__" name="Date2" required>
              <script>
              $('body').on('input', '.input-number', function(){
                this.value = this.value.replace(/[^0-9\-]/g, '');});
              </script>
              <div class="invalid-feedback">
                Valid last name is required.
              </div>
            </div>
            <div class="col-md-6">
              <label for="cc-number" class="form-label">Паспорт</label>
              <input type="text" class="form-control input-number" placeholder="" maxlength="10" name="pasport" required>
              <script>
              $('body').on('input', '.input-number', function(){
                this.value = this.value.replace(/[^0-9]/g, '');});
              </script>
              <div class="invalid-feedback">
                Credit card number is required
              </div>
            </div>

            <div class="col-md-6">
              <label for="cc-number" class="form-label">Телефон</label>
              <input type="text" placeholder="" 
               maxlength="11" class="form-control input-number" name="tel-number" required>
               <script>
              $('body').on('input', '.input-number', function(){
                this.value = this.value.replace(/[^0-9]/g, '');});
              </script>
              <div class="invalid-feedback">
                Credit card number is required
              </div>
            </div>

            <div class="col-md-3">
              <label for="cc-cvv" class="form-label">Кол-во гостей</label>
              <input type="number" class="form-control" name="cc-cvv" placeholder="1" required>
              <div class="invalid-feedback">
                Security code required
              </div>
            </div>
          </div>

          <hr class="my-4">

          <button class="w-100 btn btn-primary btn-lg" type="submit">Зарегистрировать</button>
        </form>
        <?php else: 
    header('Location: /insert.php'); 
    $_COOKIE['success'];
    ?>
  <?php endif; ?>
  
</body> 
</html>

