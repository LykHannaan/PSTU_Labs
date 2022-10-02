<?php
 // Подключение к MySQL
  require_once 'config/connect.php';

if (isset($_REQUEST ['view1']))
{
$view = "CREATE VIEW VIEW_salary
as SELECT `ID`, `Фамилия`, `Имя`, `Номер телефона`, `ЗП`
FROM employees
WHERE ЗП > (SELECT AVG(ЗП)
                FROM employees)";
}

if (isset($_REQUEST ['view2']))
{
$view = "CREATE VIEW VIEW_Adress
as SELECT `ID`, `Фамилия`, `Имя`, `Адрес`
FROM employees
ORDER by Адрес";
}

if (isset($_REQUEST ['view3']))
{
$view = "CREATE VIEW VIEW_experience
as SELECT `ID`, `Фамилия`, `Имя`, `Опыт_работы`
FROM employees
WHERE Опыт_работы = (SELECT MAX(Опыт_работы)
                FROM employees)";
}

if (mysqli_query($conn, $view))
{
     echo "success!";
}
else {
    echo "Ошибка создания таблицы: " . mysqli_error($conn);
}