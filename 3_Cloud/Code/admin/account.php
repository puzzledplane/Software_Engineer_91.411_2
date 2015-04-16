<?php
	session_start();
	include('../config.php');
	
	if(empty($_SESSION['SE_Admin_Username']) || empty($_SESSION['SE_Admin_ID']))
	{		
		$_SESSION['SE_Admin_Error'] = "You must sign in first.";
		header("location: login.php");
	}
	else
	{
		// Set ID from session.
		$id = $_SESSION['SE_Admin_ID'];
	
		if(!isset($_GET['action'])) 
		{	
			$_GET['action'] = "";
		}
		
		if(!isset($_GET['task'])) 
		{	
			$_GET['task'] = "";
		}
		
		// Salt Function -- Source: http://tinsology.net/2009/06/creating-a-secure-login-system-the-right-way/
		function createSalt()
		{
			$string = md5(uniqid(rand(), true));
			return substr($string, 0, 3);
		}
		
		if (mysqli_connect_errno())
		{
			die('Could not connect: ' . mysqli_connect_error());
		};
		
		echo '
			<!DOCTYPE html>
				<html>
				<head>
				<meta charset="UTF-8">
				<title>My Account</title>
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
											<!-- Begin Account Form -->';
											//Edit Account Information
											if ($_GET['action'] == 'edit')
											{
												//Submit Changes from Edit
												if ($_GET['task'] == 'submit')
												{
													//Post Variables
													$current = mysqli_real_escape_string($con, $_POST['password']);
													$name = mysqli_real_escape_string($con, $_POST['name']);
													$email = mysqli_real_escape_string($con, $_POST['email']);
													$hospitalname = mysqli_real_escape_string($con, $_POST['hospitalname']);
													$hospitalid = mysqli_real_escape_string($con, $_POST['hospitalid']);
													$dob = mysqli_real_escape_string($con, $_POST['dob']);
													$location = mysqli_real_escape_string($con, $_POST['location']);
													
													$sql="SELECT * FROM admins WHERE ID='$id'";
													$result=mysqli_query($con, $sql);
													
													while ($row = mysqli_fetch_array($result))
													{
														$currenthash = hash('sha256', $row['Salt'] . hash('sha256', $current));
														
														if ($currenthash == $row['Password'])
														{
															$query = "UPDATE admins SET Name = '$name', Email='$email', HospitalName = '$hospitalname', HospitalID = '$hospitalid', DOB = '$dob', Location = '$location' WHERE ID = '$id'";
															
															if(mysqli_query($con, $query))
																{
																	$_SESSION['SE_Admin_Error'] = "";
																	
																	echo '<div id="EditAccount" class="module">
																				<div class="frameheader"><h2>Account Edited</h2></div>
																				<ul>
																					<li class="box">
																						<p>Your account was edited successfully.
																						<br />
																						<br />
																						<a href="account.php">Click Here</a> to go back to My Account.</p>
																					</li>
																				</ul>
																		</div>';
																}
																else
																{
																	die('Error: ' . mysqli_error($con));
																}
															
														}
														else
														{
															$_SESSION['SE_Admin_Error'] = "Incorrect Current Password. Please try again";
															header('Location: account.php?action=edit');
															exit;
														}
													}
												}
												else
												{
													
													echo' 	<div id="EditAccount" class="module">
																<div class="frameheader"><h2>Edit Account</h2></div>
																<ul>
																	<li class="box">
																		<h2>Edit My Account</h2>
																			<br />';
																			
																			if(!empty($_SESSION['SE_Admin_Error']))
																			{
																				echo '<span class="error">'.$_SESSION['SE_Admin_Error'].'</span>
																				  <br />
																				  <br />';
																			}
																			
																			$query = "SELECT * FROM admins WHERE ID = '$id'";
								
																			if ($result = mysqli_query($con, $query))
																			{
																				$row = mysqli_fetch_array($result);
																				mysqli_free_result($result);
																			}
																			else
																			{
																				die('Error:' . mysqli_error($con));
																			}
													
																	echo'	<form method="post" action="account.php?action=edit&task=submit">
																				<table id="editAccount">
																					<tr>
																						<td>Username: <span class="required">*</span></td>
																						<td>'.$row['Username'].'</td>
																					</tr>
																					<tr>
																						<td>Current Password: <span class="required">*</span></td>
																						<td><input class="styled" type="password" name="password" required></td>
																					</tr>
																					<tr>
																						<td>Full Name: <span class="required">*</span></td>
																						<td><input class="styled" type="text" name="name" value="'.$row['Name'].'" required></td>
																					</tr>
																					<tr>
																						<td>Email: <span class="required">*</span></td>
																						<td><input class="styled" type="email" name="email" value="'.$row['Email'].'" required></td>
																					</tr>
																					<tr>
																						<td>Hospital/Clinic Name: <span class="required">*</span></td>
																						<td><input class="styled" type="text" name="hospitalname" value="'.$row['HospitalName'].'" required></td>
																					</tr>
																					<tr>
																						<td>Hospital/Clinic ID: <span class="required">*</span></td>
																						<td><input class="styled" type="text" name="hospitalid" value="'.$row['HospitalID'].'" required></td>
																					</tr>
																					<tr>
																						<td>Date of Birth 
																						<br />
																						(MM/DD/YYYY): <span class="required">*</span></td>
																						<td><input class="styled" type="text" name="dob" value="'.$row['DOB'].'" required pattern="^(0[1-9]|1[012])[/](0[1-9]|[12][0-9]|3[01])[/](19|20)\d\d"></td>
																					</tr>
																					<tr>
																						<td>Location (City, State): <span class="required">*</span></td>
																						<td><input class="styled" type="text" name="location" value="'.$row['Location'].'" required></td>
																					</tr>
																				</table>
																				<br />
																				<br />
																				<input type="submit" value="Submit">
																		</form>
																	</li>
																</ul>
															</div>';
												}
											}
											elseif ($_GET['action'] == 'changepassword')
											{
												if ($_GET['task'] == 'submit')
												{
													
													$sql="SELECT * FROM admins WHERE ID='$id'";
													$result=mysqli_query($con, $sql);
													
													$current = mysqli_real_escape_string($con, $_POST['current']);
													$password = mysqli_real_escape_string($con, $_POST['password']);
													$confirm = mysqli_real_escape_string($con, $_POST['confirm']);
													
													while ($row = mysqli_fetch_array($result))
													{
														$currenthash = hash('sha256', $row['Salt'] . hash('sha256', $current));
													
														if ($currenthash == $row['Password'])
														{
															if ($password == $confirm)
															{
																$hash = hash('sha256', $password);
																$salt = createSalt();
																$hash = hash('sha256', $salt . $hash);
																
																$query = "UPDATE admins SET Password='$hash', Salt='$salt' WHERE ID = '$id'";
																
																if(mysqli_query($con, $query))
																{
																	$_SESSION['SE_Admin_Error'] = "";
																	
																	echo '<div id="EditAccount" class="module">
																				<div class="frameheader"><h2>Password Changed</h2></div>
																				<ul>
																					<li class="box">
																						<p>Your Password was changed successfully.
																						<br />
																						<br />
																						<a href="account.php">Click Here</a> to go back to My Account.</p>
																					</li>
																				</ul>
																		</div>';
																}
																else
																{
																	die('Error: ' . mysqli_error($con));
																}
															}
															else
															{
																$_SESSION['SE_Admin_Error'] = "New Password and Confirmation do not match. Please try again";
																header('Location: account.php?action=changepassword');
																exit;
															}
															
														}
														else
														{
															$_SESSION['SE_Admin_Error'] = "Incorrect Current Password. Please try again";
															header('Location: account.php?action=changepassword');
															exit;
														}
													}
												}
												else
												{
													echo '<div id="EditAccount" class="module">
																<div class="frameheader"><h2>Change Password</h2></div>
																<ul>
																	<li class="box">
																		<h2>Change Password</h2>
																		<br />';
																		if(!empty($_SESSION['SE_Admin_Error']))
																		{
																			echo '<span class="error">'.$_SESSION['SE_Admin_Error'].'</span>
																				  <br />
																				  <br />';
																		}
																	echo'<form method="post" action="account.php?action=changepassword&task=submit">
																				<table id="changePassword">
																					<tr>
																						<td>Current Password: <span class="required">*</span></td>
																						<td><input class="styled" type="password" name="current" required></td>
																					</tr>
																					<tr>
																						<td>New Password: <span class="required">*</span></td>
																						<td><input class="styled" type="password" name="password" required></td>
																					</tr>
																					<tr>
																						<td>Confirm New Password: <span class="required">*</span></td>
																						<td><input class="styled" type="password" name="confirm" required></td>
																					</tr>
																				</table>
																				<br />
																				<br />
																				<input type="submit" value="Submit">
																		</form>
																	</li>
																</ul>
															</div>';
												}
											}
											else
											{
												$index = 0;
												
												//Title Array
												$titles_array = array("Username:", "Full Name:", "Email:", "Hospital/Clinic Name:", "Hospital/Clinic ID:", "Date of Birth:", "Location:", "Access Code:");
												$data_array = array("Username", "Name", "Email", "HospitalName", "HospitalID", "DOB", "Location", "AccessCode");
												
												$sql="SELECT * FROM admins WHERE ID = '$id'";
												
												if($result = mysqli_query($con, $sql))
												{
													echo' 	<div id="Account" class="module">
														<div class="frameheader"><h2>My Account</h2></div>
															<ul>
																<li class="box">
																	<h2>My Account Information:</h2>
																	<table id="myAccount">';
																		while($row = mysqli_fetch_array($result))
																		{
																		
																			foreach ($data_array as $val)
																			{
																				echo '	<tr>';
																				
																						// Check for last row of table (Headers) for styling reasons.
																						if (sizeof($data_array) == ($index + 1))
																						{
																							echo '<td class ="lastAccountHeader">'.$titles_array[$index].'</td>';
																						}
																						else
																						{
																							echo '<td class ="accountHeader">'.$titles_array[$index].'</td>';
																						}
																						
																						
																						// Also Check for DOB field to add age using php date_diff.
																						if ($val == 'DOB')
																						{
																							echo '<td class ="accountData">'.$row[$val].'</td> 
																									</tr>
																									<tr>
																										<td class ="accountHeader">Age:</td> 
																										<td class ="accountData">'.date_diff(date_create($row[$val]), date_create('today'))->y.'</td>
																									</tr>';
																						}
																						// Also Check for Weight field to add lbs at end.
																						elseif ($val == 'Weight')
																						{
																							echo '<td class = "accountData">'.$row[$val].' lbs</td>';
																							echo'</tr>';
																						}
																						// Check for last row of table (Data) for styling reasons.
																						elseif (sizeof($data_array) == ($index + 1))
																						{
																							echo '<td class = "lastAccountData">'.$row[$val].'</td>';
																							echo'</tr>';
																						}
																						else
																						{
																							echo '<td class = "accountData">'.$row[$val].'</td>';
																							echo'</tr>';
																						}
																							
																				$index++;
																			}
																		}
													echo'			</table>
																	<div class="buttonRow">
																		 <a href="account.php?action=edit"><button class="styled">Edit Account</button></a> <a href="account.php?action=changepassword"><button class="styled">Change Password</button></a>
																	</div>
																</li>
															</ul>
														</div>';
												}
												else
												{
													die('Error:' . mysqli_error($con));
												}
											}
		echo'						</td>';
								include('./includes/sidebar.right.php');
		echo'					</tr>
							</table>
						</div>';
						include('../templates/main/footer.php');
echo'				</body>
				</html>';
	}
mysqli_close($con);
?>