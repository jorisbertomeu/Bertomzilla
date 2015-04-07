<?php
	$db = mysql_connect('localhost', 'bertomzilla', 'password'); 
	mysql_select_db('bertomzilla', $db); 
	if($db)
	{
		$permissions = "0000";
		if (isset($_POST['read']))
			$permissions{0} = 1;
		if (isset($_POST['write']))
			$permissions{1} = 1;
		if (isset($_POST['dirCrea']))
			$permissions{2} = 1;
		if (isset($_POST['dirRem']))
			$permissions{3} = 1;
		$requete = "INSERT INTO users (`id`, `username`, `password`, `fullname`, `directory`, `rights`, `creation`, `permissions`) VALUES (NULL, '".$_POST['username']."', '".$_POST['password']."', '".$_POST['fullname']."', '".$_POST['directory']."', '".(isset($_POST['admin']) ? "1" : "0")."', '".date('d/m/Y h:i:s', time())."', '".$permissions."')";
		mysql_query($requete);
	}
?>
<script language="JavaScript">document.location.href="users.php" </script>