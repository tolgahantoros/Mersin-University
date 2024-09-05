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

$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
	die("Connection failed: " . mysqli_connect_error());
}

mysqli_query($conn, "SET NAMES utf8");

$sql = "SELECT * from iot_pwm ORDER BY id DESC";

$result = mysqli_query($conn, $sql);

if($result!=null)
{
	/*while ($data = mysqli_fetch_row($result)) {
		echo($data[0] . ".......... ");
		echo("motor: " . $data[1] . " .......... ");
		echo("led: " . $data[2] . " .......... ");
		echo("zaman: " . $data[3] . " .......... ");
		echo("ipadres: " . $data[4]); echo("<br>");
		
	}*/

	echo "<table border=\"1\" cellspacing=\"0\" cellpadding=\"3\"> ";
	echo "<tr align= \"center\">";
	echo "<td><strong>id</td>";
	echo "<td><strong>motorpwm</td>";
	echo "<td><strong>ledpwm</td>";
	echo "<td><strong>zaman</td>";
	echo "<td><strong>ipadres</td>";
	echo "</tr>";
	while ($data = mysqli_fetch_row($result)) {
		echo "<tr>";
		echo "<td>".$data[0]."</td>";
		echo "<td>".$data[1]."</td>";
		echo "<td>".$data[2]."</td>";
		echo "<td>".$data[3]."</td>";
		echo "<td>".$data[4]."</td>";
		echo "</tr>";
		
	}
	echo "</table>";
}
mysqli_close($conn);