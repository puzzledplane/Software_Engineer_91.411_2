<?php
echo'	<div id="navigation">
		<ul>';
			
			if (!empty($_SESSION['SE_User_Username']))
			{
				echo '<li><a href="index.php">Home</a></li>|
					  <li><a href="account.php">My Account</a></li>|
					  <li><a href="device.php">My Devices</a></li>|
					  <li><a href="logout.php">Logout</a></li>';
			}
			else
			{
				echo '<li><a href="login.php">Login</a></li>|
					  <li><a href="register.php">Register</a></li>';
			}
echo'
		</ul>
	</div>';
?>