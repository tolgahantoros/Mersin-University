<?php
/**
 * insert.php
 *
 * @category   Ajax executed php script
 * @package    None
 * @author     Volkan
 * @copyright  2018 Volkan
 * @version    CVS: $Id:1.0
 * @deprecated None
 */


include("connect.php");
$_motorpwm=$_GET['motorpwm'];
$_ledpwm=$_GET['ledpwm'];

$motorpwm=$_motorpwm;
$ledpwm=$_ledpwm;
$ipAddress = $_SERVER['REMOTE_ADDR'];

$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
	die("Connection failed: " . mysqli_connect_error());
}

mysqli_query($conn, "SET NAMES utf8");
$basari_sayac = 0;


$sql = "INSERT INTO iot_pwm (motorpwm, ledpwm, zaman, ipaddr) VALUES ('$motorpwm','$ledpwm',NOW(),'$ipAddress')";

if (mysqli_query($conn, $sql)) {
	$basari_sayac++;
} else {
	echo "Hata Oluştu: " . $sql . "<br>" . mysqli_error($conn);
}

mysqli_close($conn);
//echo $basari_sayac;
echo $sql;