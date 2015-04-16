<?php
	session_start();
	
	include('../config.php');
	
	if(empty($_SESSION['SE_User_Username']) || empty($_SESSION['SE_User_ID']))
	{		
		$_SESSION['SE_User_Error'] = "You must sign in first.";
		header("location: login.php");
	}
	else
	{
		if (!empty($_REQUEST["code"]))
		{
			$accesscode = mysqli_real_escape_string($con, $_REQUEST["code"]);
		}
		else
		{
			$accesscode = "";
		}
		
		if (!$con) 
		{
		die('Could not connect: ' . mysqli_error($con));
		}
		
		# Query Admins Database where AccessCode is equal to 
		# GET from external page.
		
		$query = "SELECT * FROM admins WHERE AccessCode = '$accesscode'";
		$result = mysqli_query($con, $query);
		
		$count = mysqli_num_rows($result);
		
		if ($count == 1)
		{
		
			$index = 0;
			$titles_array = array("Full Name:", "Email:", "Hospital/Clinic Name:", "Hospital/Clinic ID:", "Location:", "Access Code:");
			$data_array = array("Name", "Email", "HospitalName", "HospitalID", "Location", "AccessCode");
			
			
			echo '<h3>Providers Information:</h3>
					<br />
					<table class="myProvider">';
					while($row = mysqli_fetch_array($result))
					{
						foreach ($data_array as $val)
						{
							echo '<tr>';
							
							// Check for last row of table (Headers) for styling reasons.
							if (sizeof($data_array) == ($index + 1))
							{
								echo '<td class ="lastProviderHeader">'.$titles_array[$index].'</td>';
							}
							else
							{
								echo '<td class ="providerHeader">'.$titles_array[$index].'</td>';
							}
							
							if (sizeof($data_array) == ($index + 1))
							{
								echo '<td class = "lastProviderData">'.$row[$val].'</td>';
								echo'</tr>';
							}
							else
							{
								echo '<td class = "providerData">'.$row[$val].'</td>';
								echo'</tr>';
							}
							
							$index++;
						}
					}
		}
		else
		{
			echo 'Please enter a valid access code.';
		}
			  
	}

mysqli_close($con);

?>