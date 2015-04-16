<?php
			
	if (empty($_SESSION['SE_User_Username']))
	{
		echo '	<td class="sidebar" id="right">
				<!-- nav Information.-->
						<div id="nav" class="module">
							<div class="frameheader"><h2>Navigation</h2></div>
							<ul>
								<li class="box">
									<ul>
										<li class="box">
											<h3>Account</h3>
											<br />
											<a href="login.php">Login</a>
											<br />
											<a href="register.php">Register</a>
										</li>
									</ul>
								</li>
							</ul>
						</div>
			</td>';
	}
	else
	{
		echo '	<td class="sidebar" id="right">
				<!-- nav Information.-->
						<div id="nav" class="module">
							<div class="frameheader"><h2>Navigation</h2></div>
							<ul>
								<li class="box">
									<ul>
										<li class="box">
											<h3>My Account</h3>
											<br />
											<a href="account.php">View My Account</a>
											<br />
											<a href="account.php?action=edit">Edit My Information</a>
											<br />
											<a href="account.php?action=changepassword">Change Password</a>
										</li>
										<li class="box">
											<h3>My Devices</h3>
											<br />
											<a href="device.php">View My Devices</a>
											<br />
											<a href="device.php?action=add">Add a Device</a>
										</li>
										<li class="box">
											<h3>Authorized Users</h3>
											<br />
											<a href="authorize.php">View Authorized Users</a>
											<br />
											<a href="authorize.php?action=add">Authorize User</a>
										</li>
									</ul>
								</li>
							</ul>
						</div>
			</td>';
	}

?>