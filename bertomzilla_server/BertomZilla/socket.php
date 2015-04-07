<?php
 $socket_client = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
 $err = socket_bind($socket_client, "127.0.0.1", 3884);
 $err = socket_connect($socket_client, "127.0.0.1", 3884);
 $msg = $_POST['cmd']."\r\n";
 $taille = strlen($msg);
 socket_send($socket_client, $msg, $taille, 0x100);
 $buf = socket_read($socket_client, 4096);
 echo '<div class="shout_msg"><time>'.date('h:i A M d', time()).'</time><span class="username">'.$_POST['cmd'].'</span> <span class="message">'.$buf.'</span></div>';
 socket_close($socket_client);
?>