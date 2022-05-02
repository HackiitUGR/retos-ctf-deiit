<!DOCTYPE html>
<html>
	<head>
		<title>Cookie Monster</title>

		<link rel="stylesheet" href="styles/style.css">

	</head>
	<body>
    <header><h1>Can you feed the Cookie Monster?</h1></header>
    <main class="feed">
  
  
    <?php

      $name = "access";
      //value = md5(feed)
      $value = "09353387931db36c8af0e1b3658ddffe";


      if(!isset($_COOKIE[$name])) {
        echo "<p>Cookie Monster can't find your cookie...</p>";
        echo "<img src='images/angry-cookie-monster.png' >";

      } else {
        if($_COOKIE[$name] == $value){
          echo "<h1>Yummy!!</h1>";
	        echo "<p>Here it is your flag: ETSIIT_CTF{1n5p3ct1ng_c00k1e5}</p>";
          echo "<img src='images/happy-monster.png' >";}
        else{
          echo "<p>Cookie Monster doesn't like your cookie...</p>";
          echo "<img src='images/angry-cookie-monster.png' >";

        }
  
      }
    ?>

    </main>
  </body>
</html>

