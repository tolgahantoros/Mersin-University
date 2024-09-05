<?php
/**
 * select histroy data.php
 *
 * @category   Ajax executed php script
 * @package    None
 * @author     Volkan
 * @copyright  2018 Volkan
 * @version    CVS: $Id:1.0
 * @deprecated None
 */

include("connect.php");
$param=$_GET['param'];

$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
	die("Connection failed: " . mysqli_connect_error());
}

mysqli_query($conn, "SET NAMES utf8");

if ($param=="motor"){
	$sql = "SELECT motorpwm from iot_pwm ORDER BY id DESC LIMIT 1";
}

if ($param=="led"){
	$sql = "SELECT ledpwm from iot_pwm ORDER BY id DESC LIMIT 1";
}

$result = mysqli_query($conn, $sql);

if($result!=null)
{
	while ($data = mysqli_fetch_row($result)) {
		echo $data[0];
	}
}
mysqli_close($conn);