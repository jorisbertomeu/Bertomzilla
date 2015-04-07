<?php
	session_start();
	$username = $_POST['username'];
	$password = $_POST['password'];
	
	$db = mysql_connect('localhost', 'bertomzilla', 'password'); 
	echo "after connect";
	mysql_select_db('bertomzilla', $db); 
	echo "select";
	$sql = "SELECT * FROM users WHERE username = '".$username."'"; 
	$req = mysql_query($sql) or die('Erreur SQL !<br>'.$sql.'<br>'.mysql_error()); 
	$data = mysql_fetch_assoc($req);
	echo "after recup";
	if (strlen($username) > 0 AND strlen($password) > 0 AND $data['password'] == $password) {
		$_SESSION['username'] = $username;
		$_SESSION['fullname'] = $data['fullname'];
		$_SESSION['directory'] = $data['directory'];
		$_SESSION['rights'] = $data['rights'];
		$_SESSION['connected'] = 1;
		mysql_close();
		?> SALUUUUT <script language="JavaScript">document.location.href="dashboard.php" </script> <?php
	}
	mysql_close(); 
	?> 
<script language="JavaScript">document.location.href="index.php" </script>