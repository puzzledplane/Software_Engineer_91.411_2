<?php
session_start();

include("./config.php");

if (mysqli_connect_errno())
{
	die('Could not connect: ' . mysqli_connect_error());
};

################################
##      Login Action          ##
################################

if(!isset($_GET['action'])) 
{	
	$_GET['action'] = "";
}

if (!empty($_SESSION['SE_User_Username']))
{
	header("location: index.php");
}
			
if($_GET['action'] == 'login')
{
	
	// username and password sent from form
	//NEVER Remove the mysqli_real_escape_string. Else there could be an Sql-Injection!
	$username = mysqli_real_escape_string($con, $_POST['username']);
	$password = mysqli_real_escape_string($con, $_POST['password']);

	$sql="SELECT * FROM users WHERE Username='$username'";
	$result=mysqli_query($con, $sql);

	$count=mysqli_num_rows($result);

	if($count == 1)
	{
	  while ($row = mysqli_fetch_array($result))
	  {
		$hash = hash('sha256', $row['Salt'] . hash('sha256', $password));
		
		if($hash != $row['Password']) //incorrect password
		{
			$_SESSION['SE_User_Error'] = "You have entered an incorrect password. Please try again";
			header('Location: login.php');
			die();
		}
		else
		{
			$_SESSION['SE_User_ID'] = $row['ID'];
			$_SESSION['SE_User_Username'] = $row['Username'];
			$_SESSION['SE_User_Name'] = $row['Name'];
			$_SESSION['SE_User_Error'] = "";
		}
	  }
	  
	  header("location:index.php");
	  
	} 
	else 
	{
		$_SESSION['SE_User_Error'] = "You have entered an incorrect username. Please try again";
		header('Location: login.php');
		die();
	}
}

else
{
	
	echo '
			<!DOCTYPE html>
				<html>
				<head>
				<meta charset="UTF-8">
				<title>Login</title>
				<link rel="stylesheet" href="./templates/main/style.css">
				</head>
				
					<body>';
						include('./templates/main/header.php');
						include('./includes/navigation.php');
	echo'				<div id="content">
							<table id="mainframe">
								<tr>
									<td class="maincontent">
											<!-- Begin Login Form -->
											<div id="Login" class="module">
												<div class="frameheader"><h2>Login</h2></div>
													<ul>
														<li class="box">
														<form method="post" action="login.php?action=login">';
																if (isset($_SESSION['SE_User_Error'])) 
																{
																	echo '<br />
																	<span class="error">'.$_SESSION['SE_User_Error'].'</span>';
																}
														echo'	<br />
																<br />
																<div id="label">Username: 
																	<input class="styled" type="text" id="username" name="username" required>
																</div>		
																<div id="label">Password: 
																	<input class="styled" type="password" id="password" name="password" required>
																</div>
																<br />
																<br />
																<input type="submit" value="Submit">
														</form>
														</li>
													</ul>
											</div>
								</td>';
								include('./includes/sidebar.right.php');
echo'							</tr>
							</table>
						</div>';
						include('./templates/main/footer.php');
echo'				</body>
				</html>';
}
		
?>