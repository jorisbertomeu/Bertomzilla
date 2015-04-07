<?php
	session_start();
	if (!isset($_SESSION['connected']) OR $_SESSION['connected'] != 1) {
		?>
			<script language="JavaScript">document.location.href="index.php?reason=Session%20Expired" </script>
		<?php
	}
?>