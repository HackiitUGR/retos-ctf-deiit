<!DOCTYPE html>
<html>
	<head>
		<title>Employees only</title>
	</head>
	<body>
		<main>
			<!--
				This is a website for nasa employees only...
			-->
			<?php

				if(isset($_SERVER['HTTP_REFERER'])){
					$referer = $_SERVER['HTTP_REFERER'];
					if(preg_match('/nasa.gov/', $referer)){
						echo "<h2>Welcome back employee!</h2>";
						echo "<p>ETSIIT_CTF{N1c3_W3b_Kn0l3dg3}";
					}
					else{
						echo "<h2>You don't seem to work here...</h2>";
						echo "<p>We don't like your references</p>";
						echo "<p>You should check out our web page at www.nasa.gov</p>";
					}
				}
				else{
					echo "<h2>What!!</h2>";
					echo "<p>You don't even have references...</p>";
				}

			?>

</html>
