<?php include("session.php"); ?>
<!DOCTYPE html>
<html lang="en">

<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="">

    <title>BertomZilla - Dashboard</title>

    <!-- Bootstrap Core CSS -->
    <link href="bower_components/bootstrap/dist/css/bootstrap.min.css" rel="stylesheet">

    <!-- MetisMenu CSS -->
    <link href="bower_components/metisMenu/dist/metisMenu.min.css" rel="stylesheet">

    <!-- Timeline CSS -->
    <link href="dist/css/timeline.css" rel="stylesheet">

    <!-- Custom CSS -->
    <link href="dist/css/sb-admin-2.css" rel="stylesheet">

    <!-- Morris Charts CSS -->
    <link href="bower_components/morrisjs/morris.css" rel="stylesheet">

    <!-- Custom Fonts -->
    <link href="bower_components/font-awesome/css/font-awesome.min.css" rel="stylesheet" type="text/css">

    <link href="shootbox.css" rel="stylesheet" type="text/css">

    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
        <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->

</head>

<body>

    <div id="wrapper">
        <!-- shoutbox -->
        <div class="shout_box">
            <div class="header">Monitoring Console <div class="close_btn">&nbsp;</div></div>
            <div class="toggle_chat">
                <div class="message_box">
                </div>
                <div class="user_info">
                    <input name="shout_message" id="shout_message" type="text" placeholder="Type Command Hit Enter" maxlength="100" /> 
                </div>
            </div>
        </div>
        <!-- shoutbox end -->
        <!-- Navigation -->
        <nav class="navbar navbar-default navbar-static-top" role="navigation" style="margin-bottom: 0">
            <div class="navbar-header">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <a class="navbar-brand" href="index.html">BertomZilla V1</a>
            </div>
            <!-- /.navbar-header -->

            <ul class="nav navbar-top-links navbar-right">
                <li class="dropdown">
                    <a class="dropdown-toggle" data-toggle="dropdown" href="#">
                        <i class="fa fa-tasks fa-fw"></i>  <i class="fa fa-caret-down"></i>
                    </a>
                    <ul class="dropdown-menu dropdown-tasks">
                        <li>
                            <a href="#">
                                <div>
                                    <p>
                                        <strong>The.Expandables.3.mkv</strong>
                                        <span class="pull-right text-muted">40% Complete</span>
                                    </p>
                                    <div class="progress progress-striped active">
                                        <div class="progress-bar progress-bar-success" role="progressbar" aria-valuenow="40" aria-valuemin="0" aria-valuemax="100" style="width: 40%">
                                            <span class="sr-only">40% Complete (success)</span>
                                        </div>
                                    </div>
                                </div>
                            </a>
                        </li>
                        <li class="divider"></li>
                        <li>
                            <a href="#">
                                <div>
                                    <p>
                                        <strong>Boogie.mp3</strong>
                                        <span class="pull-right text-muted">20% Complete</span>
                                    </p>
                                    <div class="progress progress-striped active">
                                        <div class="progress-bar progress-bar-primary" role="progressbar" aria-valuenow="20" aria-valuemin="0" aria-valuemax="100" style="width: 20%">
                                            <span class="sr-only">20% Complete</span>
                                        </div>
                                    </div>
                                </div>
                            </a>
                        </li>
                    </ul>
                    <!-- /.dropdown-tasks -->
                </li>
                <li class="dropdown">
                    <a class="dropdown-toggle" data-toggle="dropdown" href="#">
                        <i class="fa fa-user fa-fw"></i>  <i class="fa fa-caret-down"></i>
                    </a>
                    <ul class="dropdown-menu dropdown-user">
                        <li><a href="#"><i class="fa fa-gear fa-fw"></i> Settings</a>
                        </li>
                        <li class="divider"></li>
                        <li><a href="logout.php"><i class="fa fa-sign-out fa-fw"></i> Logout</a>
                        </li>
                    </ul>
                    <!-- /.dropdown-user -->
                </li>
                <!-- /.dropdown -->
            </ul>
            <!-- /.navbar-top-links -->

            <div class="navbar-default sidebar" role="navigation">
                <div class="sidebar-nav navbar-collapse">
                    <ul class="nav" id="side-menu">

                        <li>
                            <a href="dashboard.php"><i class="fa fa-home fa-fw active"></i> Dashboard</a>
                        </li>
                        <li>
                            <a href="downloads.php"><i class="fa fa-download fa-fw"></i> Download Statistics</a>
                        </li>
                        <li>
                            <a href="uploads.php"><i class="fa fa-upload fa-fw"></i> Upload Statistics</a>
                        </li>
                        <li>
                            <a href="speed.php"><i class="fa fa-dashboard fa-fw"></i> Speed Statistics</a>
                        </li>
                        <li>
                            <a href="space.php"><i class="fa fa-cloud fa-fw"></i> Space usage</a>
                        </li>
                        <?php if ($_SESSION['rights'] == 1) { ?>
                        <li>
                            <a href="users.php"><i class="fa fa-users fa-fw"></i> Users Managment</a>
                        </li>
                        <?php } ?>
                        <li>
                            <a href="about.php"><i class="fa fa-magic fa-fw"></i> About</a>
                        </li>
                    </ul>
                </div>
                <!-- /.sidebar-collapse -->
            </div>
            <!-- /.navbar-static-side -->
        </nav>

        <div id="page-wrapper">
            <div class="row">
                <div class="col-lg-12">
                    <h1 class="page-header">Dashboard</h1>
                </div>
                <!-- /.col-lg-12 -->
            </div>
            <!-- /.row -->
            <?php
                $db = mysql_connect('localhost', 'bertomzilla', 'password'); 
                mysql_select_db('bertomzilla', $db); 
                $download = mysql_fetch_array(mysql_query("SELECT COUNT(*) FROM operations WHERE type = '0' AND username = '".$_SESSION['username']."'"));
                $upload = mysql_fetch_array(mysql_query("SELECT COUNT(*) FROM operations WHERE type = '1' AND username = '".$_SESSION['username']."'"));
                $i = 0;
                $n = 0;

                $sql = "SELECT * FROM operations WHERE username = '".$_SESSION['username']."' ORDER BY id DESC"; 
                $req = mysql_query($sql) or die('Erreur SQL !<br>'.$sql.'<br>'.mysql_error()); 
               
                $j = -1;
                $prev = "";
                for ($k = 0; $k < 7; $k++)
                    $tab[$k] = 0;

                $jd = -1;
                $prevd = "";
                for ($kd = 0; $kd < 7; $kd++)
                    $tabd[$kd] = 0;
                while ($data = mysql_fetch_assoc($req)) {

                    if ($data['type'] == 1) {
                        for ($incr = 0; $incr < 7; $incr++) {
                            if (!strncmp($data['date'], strftime("%Y-%m-%d", mktime(0, 0, 0, date('m'), date('d')-$incr, date('y'))), 10)) {
                                $tab[$incr] += 1;
                            }  
                        }
                    } else {
                         for ($incr = 0; $incr < 7; $incr++) {
                            if (!strncmp($data['date'], strftime("%Y-%m-%d", mktime(0, 0, 0, date('m'), date('d')-$incr, date('y'))), 10)) {
                                $tabd[$incr] += 1;
                            }  
                        }
                    }

                    $n += ($data['size'] / (1000000) / $data['time'] == 0 ? $data['size'] / (1000000) : $data['size'] / (1000000) / $data['time'] );
                    //$n += ($data['size'] / (1000000) / $data['time']);
                    $i++;
                }
                $result = $n / $i;
                function foldersize($path) {
                    $f = $path;
                    $io = popen ( '/usr/bin/du -sk ' . $f, 'r' );
                    $size = fgets ( $io, 4096);
                    $size = substr ( $size, 0, strpos ( $size, "\t" ) );
                    pclose ( $io );
                    return ($size / 1000000);
            }
            ?>
            <div class="row">
                <div class="col-lg-3 col-md-6">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <div class="row">
                                <div class="col-xs-3">
                                    <i class="fa fa-download fa-5x"></i>
                                </div>
                                <div class="col-xs-9 text-right">
                                    <div class="huge"><?php echo $upload[0]; ?></div>
                                    <div>Uploads</div>
                                </div>
                            </div>
                        </div>
                        <a href="downloads.php">
                            <div class="panel-footer">
                                <span class="pull-left">View Details</span>
                                <span class="pull-right"><i class="fa fa-arrow-circle-right"></i></span>
                                <div class="clearfix"></div>
                            </div>
                        </a>
                    </div>
                </div>
                <div class="col-lg-3 col-md-6">
                    <div class="panel panel-green">
                        <div class="panel-heading">
                            <div class="row">
                                <div class="col-xs-3">
                                    <i class="fa fa-upload fa-5x"></i>
                                </div>
                                <div class="col-xs-9 text-right">
                                    <div class="huge"><?php echo $download[0]; ?></div>
                                    <div>Downloads</div>
                                </div>
                            </div>
                        </div>
                        <a href="uploads.php">
                            <div class="panel-footer">
                                <span class="pull-left">View Details</span>
                                <span class="pull-right"><i class="fa fa-arrow-circle-right"></i></span>
                                <div class="clearfix"></div>
                            </div>
                        </a>
                    </div>
                </div>
                <div class="col-lg-3 col-md-6">
                    <div class="panel panel-yellow">
                        <div class="panel-heading">
                            <div class="row">
                                <div class="col-xs-3">
                                    <i class="fa fa-tachometer fa-5x"></i>
                                </div>
                                <div class="col-xs-9 text-right">
                                    <div class="huge"><?php echo number_format($result, 2); ?></div>
                                    <div>Speed (Mb/s)</div>
                                </div>
                            </div>
                        </div>
                        <a href="speed.php">
                            <div class="panel-footer">
                                <span class="pull-left">View Details</span>
                                <span class="pull-right"><i class="fa fa-arrow-circle-right"></i></span>
                                <div class="clearfix"></div>
                            </div>
                        </a>
                    </div>
                </div>
                <div class="col-lg-3 col-md-6">
                    <div class="panel panel-red">
                        <div class="panel-heading">
                            <div class="row">
                                <div class="col-xs-3">
                                    <i class="fa fa-cloud fa-5x"></i>
                                </div>
                                <div class="col-xs-9 text-right">
                                    <div class="huge"><?php echo number_format(foldersize($_SESSION['directory']), 2); ?></div>
                                    <div>Space used (Mb)</div>
                                </div>
                            </div>
                        </div>
                        <a href="space.php">
                            <div class="panel-footer">
                                <span class="pull-left">View Details</span>
                                <span class="pull-right"><i class="fa fa-arrow-circle-right"></i></span>
                                <div class="clearfix"></div>
                            </div>
                        </a>
                    </div>
                </div>
            </div>
            <!-- /.row -->
            <div class="row">
                <div class="col-lg-8">
                    <div class="panel panel-default">
                        <div class="panel-heading">
                            <i class="fa fa-bar-chart-o fa-fw"></i> File transfert
                            <div class="pull-right">
                                <div class="btn-group">
                                    <button type="button" class="btn btn-default btn-xs dropdown-toggle" data-toggle="dropdown">
                                        Actions
                                        <span class="caret"></span>
                                    </button>
                                    <ul class="dropdown-menu pull-right" role="menu">
                                        <li><a href="#">Action</a>
                                        </li>
                                        <li><a href="#">Another action</a>
                                        </li>
                                        <li><a href="#">Something else here</a>
                                        </li>
                                        <li class="divider"></li>
                                        <li><a href="#">Separated link</a>
                                        </li>
                                    </ul>
                                </div>
                            </div>
                        </div>
                        <!-- /.panel-heading -->
                        <div class="panel-body">
                             <div id="container" style="min-width: 100%; height: 100%; margin: 0 auto"></div>
                        </div>
                        <!-- /.panel-body -->
                    </div>
                    <div class="panel panel-default ">
                        <div class="panel-heading">
                            <i class="fa fa-clock-o fa-fw"></i> File Transfert History
                        </div>
                        <!-- /.panel-heading -->
                        <?php
                            $db = mysql_connect('localhost', 'bertomzilla', 'password'); 
                            mysql_select_db('bertomzilla', $db); 
                            $sql = "SELECT * FROM operations WHERE username = '".$_SESSION['username']."' ORDER BY id desc LIMIT 20"; 
                            $req = mysql_query($sql) or die('Erreur SQL !<br>'.$sql.'<br>'.mysql_error()); 
                        ?>
                        <div class="panel-body">
                            <ul class="timeline">
                                <?php 
                                    while ($data = mysql_fetch_assoc($req)) {
                                ?>
                                <li class="<?php echo ($data['type'] == 0 ? "timeline-inverted" : ""); ?>">
                                    <div class="timeline-badge <?php echo ($data['type'] == 1 ? "primary" : "success"); ?>"><i class="fa fa-<?php echo ($data['type'] == 0 ? "upload" : "download"); ?>"></i>
                                    </div>
                                    <div class="timeline-panel">
                                        <div class="timeline-heading">
                                            <h4 class="timeline-title"><?php echo $data['filename']; ?></h4>
                                            <p><small class="text-muted"><i class="fa fa-clock-o"></i> <?php echo $data['date']; ?> via Unknown</small>
                                            </p>
                                        </div>
                                    </div>
                                </li>
                                <?php
                                    }
                                ?>
                            </ul>
                        </div>
                        <!-- /.panel-body -->
                    </div>
                    <!-- /.panel -->
                </div>
                <!-- /.col-lg-8 -->
                <div class="col-lg-4">
                    <div class="panel panel-default">
                        <div class="panel-heading">
                            <i class="fa fa-bell fa-fw"></i> Notifications Panel
                        </div>
                        <!-- /.panel-heading -->
                        <?php
                            $db = mysql_connect('localhost', 'bertomzilla', 'password'); 
                            mysql_select_db('bertomzilla', $db); 
                            $sql = "SELECT * FROM notifications WHERE username = '".$_SESSION['username']."' ORDER BY id desc LIMIT 20"; 
                            $req = mysql_query($sql) or die('Erreur SQL !<br>'.$sql.'<br>'.mysql_error()); 
                        ?>
                        <div class="panel-body">
                            <div class="list-group">
                                <?php 
                                    while ($data = mysql_fetch_assoc($req)) {
                                ?>
                                <a href="#" class="list-group-item">
                                    <i class="fa fa-<?php echo $data['icon']; ?> fa-fw"></i> <?php echo $data['label']; ?>
                                    <span class="pull-right text-muted small"><em><?php echo $data['date'] ?></em>
                                    </span>
                                </a>
                                <?php
                                    }
                                ?>
                            </div>
                            <!-- /.list-group -->
                            <a href="notifs.php" class="btn btn-default btn-block">View All Alerts</a>
                        </div>
                        <!-- /.panel-body -->
                    </div>
                </div>
                <!-- /.col-lg-4 -->
            </div>
            <!-- /.row -->
        </div>
        <!-- /#page-wrapper -->

    </div>
    <!-- /#wrapper -->

    <!-- jQuery -->
    <script src="bower_components/jquery/dist/jquery.min.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="bower_components/bootstrap/dist/js/bootstrap.min.js"></script>

    <!-- Metis Menu Plugin JavaScript -->
    <script src="bower_components/metisMenu/dist/metisMenu.min.js"></script>

    <!-- Custom Theme JavaScript -->
    <script src="dist/js/sb-admin-2.js"></script>
    <script src="http://code.highcharts.com/highcharts.js"></script>
    <script src="http://code.highcharts.com/modules/exporting.js"></script>
     <script>
    $(document).ready(function() {
       $(function () {

         //toggle hide/show shout box
        $(".close_btn").click(function (e) {
            //get CSS display state of .toggle_chat element
            var toggleState = $('.toggle_chat').css('display');

            //toggle show/hide chat box
            $('.toggle_chat').slideToggle();
            
            //use toggleState var to change close/open icon image
            if(toggleState == 'block')
            {
                $(".header div").attr('class', 'open_btn');
            }else{
                $(".header div").attr('class', 'close_btn');
            }
        });

        $("#shout_message").keypress(function(evt) {
            if(evt.which == 13) {
                    var imessage = $('#shout_message').val();
                    post_data = {'cmd':imessage};
                    
                    //send data to "shout.php" using jQuery $.post()
                    $.post('socket.php', post_data, function(data) {
                        
                        //append data into messagebox with jQuery fade effect!
                        $(data).hide().appendTo('.message_box').fadeIn();

                        //keep scrolled to bottom of chat!
                        var scrolltoh = $('.message_box')[0].scrollHeight;
                        $('.message_box').scrollTop(scrolltoh);
                        
                        //reset value of message box
                        $('#shout_message').val('');
                        
                    }).fail(function(err) { 
                    
                    //alert HTTP server error
                    alert(err.statusText); 
                    });
                }
        });
    $('#container').highcharts({
        chart: {
            type: 'areaspline'
        },
        colors: ['#2980b9', '#2ecc71'],
        legend: {
            layout: 'vertical',
            align: 'left',
            verticalAlign: 'top',
            x: 150,
            y: 100,
            floating: true,
            borderWidth: 1,
            backgroundColor: (Highcharts.theme && Highcharts.theme.legendBackgroundColor) || '#FFFFFF'
        },
        xAxis: {
            categories: [
                'J - 6',
                'J - 5',
                'J - 4',
                'J - 3',
                'J - 2',
                'J - 1',
                'J'
            ],
        },
        yAxis: {
            title: {
                text: 'Transferts'
            }
        },
        tooltip: {
            shared: true,
            valueSuffix: ' Transferts'
        },
        credits: {
            enabled: false
        },
        plotOptions: {
            areaspline: {
                fillOpacity: 0.5
            }
        },
        series: [{
            name: 'Upload',
            data: [<?php echo $tab[6]; ?>, <?php echo $tab[5]; ?>, <?php echo $tab[4]; ?>, <?php echo $tab[3]; ?>, <?php echo $tab[2]; ?>, <?php echo $tab[1]; ?>, <?php echo $tab[0]; ?>]
        },
        {
            name: 'Download',
            data: [<?php echo $tabd[6]; ?>, <?php echo $tabd[5]; ?>, <?php echo $tabd[4]; ?>, <?php echo $tabd[3]; ?>, <?php echo $tabd[2]; ?>, <?php echo $tabd[1]; ?>, <?php echo $tabd[0]; ?>]
        },],
    });
});
    });
    </script>

</body>

</html>
