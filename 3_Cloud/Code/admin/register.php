<?php
session_start();

require_once '../includes/securimage/securimage.php';
include("../config.php");

$options = array();
$options['input_name'] = 'captcha';

if (mysqli_connect_errno())
{
	die('Could not connect: ' . mysqli_connect_error());
};

################################
##      Register Action       ##
################################

if(!isset($_GET['action'])) 
{	
	$_GET['action'] = "";
}

if (!empty($_SESSION['SE_Admin_Username']))
{
	header("location: index.php");
}

if($_GET['action'] == 'register')
{	
	//Post Variables
	$username = mysqli_real_escape_string($con, $_POST['username']);
	$pwd = mysqli_real_escape_string($con, $_POST['password']);
	$confirm = mysqli_real_escape_string($con, $_POST['confirm']);
	$name = mysqli_real_escape_string($con, $_POST['name']);
	$email = mysqli_real_escape_string($con, $_POST['email']);
	$hospitalname = mysqli_real_escape_string($con, $_POST['hospitalname']);
	$hospitalID = mysqli_real_escape_string($con, $_POST['hospitalid']);
	$dob = mysqli_real_escape_string($con, $_POST['dob']);
	$location = mysqli_real_escape_string($con, $_POST['location']);
	
	
	$sql="SELECT * FROM admins WHERE Username = '$username' OR Email = '$email'";
	$result = mysqli_query($con, $sql);
	
	$count=mysqli_num_rows($result);
	mysqli_free_result($result);
	
	echo '
			<!DOCTYPE html>
				<html>
				<head>
				<meta charset="UTF-8">
				<title>Admin Registration</title>
					<link rel="stylesheet" href="../templates/main/style.css">
					<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js"></script>
					<link rel="stylesheet" href="https://ajax.googleapis.com/ajax/libs/jqueryui/1.11.3/themes/smoothness/jquery-ui.css" />
					<script src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.11.3/jquery-ui.min.js"></script>
				</head>
				
					<body>';
						include('../templates/main/header.php');
						include('./includes/navigation.php');
	echo'				<div id="content">
							<table id="mainframe">
								<tr>
									<td class="maincontent">
											<!-- Begin Error Form -->
											<div id="Error" class="module">
												<div class="frameheader"><h2>Admin Registration</h2></div>
													<ul>
														<li class="box">';
	
	if ($pwd != $confirm)
	{
		echo'		<p>
					Password and Confirm do not match. Please try again.
					<br />
					<br />
					<a href="javascript:history.go(-1)">Click Here</a> to go back.
				</p>';

	}
	elseif ($count >= 1)
	{
		echo'	<p>
					Username or Email has already been used. Please try again.
					<br />
					<br />
					<a href="javascript:history.go(-1)">Click Here</a> to go back.
				</p>';
	}
	else
	{
		$securimage = new Securimage();
		
		if ($securimage->check($_POST['captcha']) == false) 
		{
			echo'	<p>
					Captcha was entered incorrectly. Please try again.
					<br />
					<br />
					<a href="javascript:history.go(-1)">Click Here</a> to go back.
				</p>';
			exit;
		}
		
			// Salt Function -- Source: http://tinsology.net/2009/06/creating-a-secure-login-system-the-right-way/
		function createSalt()
		{
			$string = md5(uniqid(rand(), true));
			return substr($string, 0, 3);
		}
		
		$valid_chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

		/*********************************************************************************************
		*                             createAccessCode function                                      *
		*                                   By: Chad Birch                                           *
		* Source: http://stackoverflow.com/questions/853813/how-to-create-a-random-string-using-php  *
		**********************************************************************************************/

		function createAccessCode($valid_chars, $length)
		{
			include("../config.php");
			
			// start with an empty random string
			$random_string = "";

			// count the number of chars in the valid chars string so we know how many choices we have
			$num_valid_chars = strlen($valid_chars);

			// repeat the steps until we've created a string of the right length
			for ($i = 0; $i < $length; $i++)
			{
				// pick a random number from 1 up to the number of valid chars
				$random_pick = mt_rand(1, $num_valid_chars);

				// take the random character out of the string of valid chars
				// subtract 1 from $random_pick because strings are indexed starting at 0, and we started picking at 1
				$random_char = $valid_chars[$random_pick-1];

				// add the randomly-chosen char onto the end of our string so far
				$random_string .= $random_char;
			}
			
			$query = "SELECT AccessCode FROM admins WHERE AccessCode = '$random_string'";
			$result = mysqli_query($con, $query);
	
			$count=mysqli_num_rows($result);
			mysqli_free_result($result);
			
			//Check if code already exists.
			if ($count != 0)
			{
				$called++;
				createAccessCode($valid_chars, $length);
			}
			elseif($called == 5)
			{
				die('Error Code 100: An Error Occurred. Please Contact an Administrator.');
			}
			else
			{
				// return our finished random string
				return $random_string;
			}
		}
		
		$hash = hash('sha256', $pwd);
		$salt = createSalt();
		$accesscode = createAccessCode($valid_chars, 10);
		$hash = hash('sha256', $salt . $hash);
		
		$query = "INSERT INTO admins (Username, Password, Salt, Name, Email, HospitalName, HospitalID, DOB, Location, AccessCode) 
		VALUES ('$username', '$hash', '$salt', '$name', '$email', '$hospitalname', '$hospitalID', '$dob', '$location', '$accesscode')";
		
		if (mysqli_query($con, $query))
		{
			echo'	<p>
					Account was successfully created.
					<br />
					<br />
					<a href="login.php">Click Here</a> to go login.
				</p>';
		}
		else
		{
			die('Error: ' . mysqli_error($con));
		}
	}
	
echo'													</li>
													</ul>
											</div>
								</td>';
								include('./includes/sidebar.right.php');
echo'							</tr>
							</table>
						</div>';
						include('../templates/main/footer.php');
echo'				</body>
				</html>';

}
else
{
	echo '
			<!DOCTYPE html>
				<html>
				<head>
				<meta charset="UTF-8">
				<title>Admin Registration</title>
					<link rel="stylesheet" href="../templates/main/style.css">
					<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js"></script>
					<link rel="stylesheet" href="https://ajax.googleapis.com/ajax/libs/jqueryui/1.11.3/themes/smoothness/jquery-ui.css" />
					<script src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.11.3/jquery-ui.min.js"></script>
				</head>
				
					<body>';
						include('../templates/main/header.php');
						include('./includes/navigation.php');
	echo'				<div id="content">
							<table id="mainframe">
								<tr>
									<td class="maincontent">
											<!-- Begin Registration Form -->
											<div id="Registration" class="module">
												<div class="frameheader"><h2>Admin Registration</h2></div>
													<ul>
														<li class="box">
														<p>Please fill out this form to create an admin account. 
														All fields marked with a <span class="required">*</span> are required.</p>
														<br />
														<h3>Personal Information:</h3>
														<br />
														<form method="post" action="register.php?action=register">
																<table id="register">
																	<tr>
																		<td>Username: <span class="required">*</span></td>
																		<td><input class="styled" type="text" name="username" required></td>
																	</tr>
																	<tr>
																		<td>Password: <span class="required">*</span></td>
																		<td><input class="styled" type="password" name="password" required></td>
																	</tr>
																	<tr>
																		<td>Confirm Password: <span class="required">*</span>
																		<td><input class="styled" type="password" name="confirm" required></td>
																	</tr>
																	<tr>
																		<td>Full Name: <span class="required">*</span></td>
																		<td><input class="styled" type="text" name="name" required></td>
																	</tr>
																	<tr>
																		<td>Email: <span class="required">*</span></td>
																		<td><input class="styled" type="email" name="email" required></td>
																	</tr>
																	<tr>
																		<td>Hospital/Clinic Name: <span class="required">*</span></td>
																		<td><input class="styled" type="text" name="hospitalname" required></td>
																	</tr>
																	<tr>
																		<td>Hospital ID: <span class="required">*</span></td>
																		<td><input class="styled" type="text" name="hospitalid" required></td>
																	</tr>
																	<tr>
																		<td>Date of Birth 
																		<br />
																		(MM/DD/YYYY): <span class="required">*</span></td>
																		<td><input class="styled" type="text" name="dob" required pattern="^(0[1-9]|1[012])[/](0[1-9]|[12][0-9]|3[01])[/](19|20)\d\d"></td>
																	</tr>
																	<tr>
																		<td>Location (City, State): <span class="required">*</span></td>
																		<td><input class="styled" type="text" name="location" required></td>
																	</tr>';
																	if (!empty($_SESSION['ctform']['captcha_error'])) 
																	{
																		$options['error_html'] = $_SESSION['ctform']['captcha_error'];
																	}
																	
													echo'			<tr>
																		<td>Captcha: <span class="required">*</span></td>
																		<td>';echo Securimage::getCaptchaHtml($options); echo'</td>
																	</tr>';
																	

													echo'		</table>
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
						include('../templates/main/footer.php');
echo'				</body>
				</html>';
}

mysqli_close($con);
?>