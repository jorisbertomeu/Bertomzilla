<?php include("session.php"); ?> ?>
<!DOCTYPE html>
<html lang="en">

<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="">

    <title>BertomZilla - Users Managment</title>

    <!-- Bootstrap Core CSS -->
    <link href="bower_components/bootstrap/dist/css/bootstrap.min.css" rel="stylesheet">

    <!-- MetisMenu CSS -->
    <link href="bower_components/metisMenu/dist/metisMenu.min.css" rel="stylesheet">

    <!-- DataTables CSS -->
    <link href="bower_components/datatables-plugins/integration/bootstrap/3/dataTables.bootstrap.css" rel="stylesheet">

    <!-- DataTables Responsive CSS -->
    <link href="bower_components/datatables-responsive/css/dataTables.responsive.css" rel="stylesheet">

    <!-- Custom CSS -->
    <link href="dist/css/sb-admin-2.css" rel="stylesheet">

    <!-- Custom Fonts -->
    <link href="bower_components/font-awesome/css/font-awesome.min.css" rel="stylesheet" type="text/css">

    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
        <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->

</head>

<body>

    <div id="wrapper">

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
                                        <div class="progress-bar progress-bar-info" role="progressbar" aria-valuenow="20" aria-valuemin="0" aria-valuemax="100" style="width: 20%">
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
                        <li><a href="login.html"><i class="fa fa-sign-out fa-fw"></i> Logout</a>
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
                            <a href="dashboard.php"><i class="fa fa-home fa-fw"></i> Dashboard</a>
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
                    <h1 class="page-header">Uploads Statistics</h1>
                </div>
                <!-- /.col-lg-12 -->
            </div>
            <div class="row">
                <div class="col-lg-12">
                    <div class="panel panel-default">
                        <div class="panel-heading">
                            <i class="fa fa-bar-chart-o fa-fw"></i> Uploads Statistics
                        </div>
                        <!-- /.panel-heading -->
                        <div class="panel-body">
                            <div id="container" style="min-width: 100%; height: 100%; margin: 0 auto"></div>
                        </div>
                        <!-- /.panel-body -->
                    </div>
                    <div class="panel panel-default">
                        <div class="panel-heading">
                            Uploads history
                        </div>
                        <!-- /.panel-heading -->
                        <?php
                            $db = mysql_connect('localhost', 'bertomzilla', 'password'); 
                            mysql_select_db('bertomzilla', $db);
                            $sql = "SELECT * FROM operations WHERE type = '1' AND username = '".$_SESSION['username']."' ORDER BY id desc"; 
                            $req = mysql_query($sql) or die('Erreur SQL !<br>'.$sql.'<br>'.mysql_error()); 
                        ?>
                        <div class="panel-body">
                            <div class="table-responsive">
                                <table class="table table-striped table-bordered table-hover">
                                    <thead>
                                        <tr>
                                            <th>#</th>
                                            <th>Filename</th>
                                            <th>Size</th>
                                            <th>Speed</th>
                                            <th>Date</th>
                                            <th>Type</th>
                                            <th>Actions</th>
                                        </tr>
                                    </thead>
                                    <tbody>
                                        <?php 
                                            $i = 1;
                                            $j = -1;
                                            $prev = "";
                                            for ($k = 0; $k < 7; $k++)
                                                $tab[$k] = 0;
                                            while ($data = mysql_fetch_assoc($req)) {
                                                $debit = $data['size'] / (1000000) / $data['time'];
                                                if ($debit == 0)
                                                    $debit = $data['size'] / 1000000;
                                                for ($incr = 0; $incr < 7; $incr++) {
                                                    if (!strncmp($data['date'], strftime("%Y-%m-%d", mktime(0, 0, 0, date('m'), date('d')-$incr, date('y'))), 10)) {
                                                        $tab[$incr] += 1;
                                                    }  
                                                }
                                            }
                                            if (!isset($_GET['page']))
                                                $offset = 0;
                                            else
                                                $offset = $_GET['page'] * 50;
                                            $sql = "SELECT * FROM operations WHERE type = '1' AND username = '".$_SESSION['username']."' ORDER BY id DESC LIMIT 50 OFFSET ".$offset; 
                                            $req = mysql_query($sql) or die('Erreur SQL !<br>'.$sql.'<br>'.mysql_error());
                                            $total_size = mysql_fetch_array(mysql_query("SELECT COUNT(*) FROM operations WHERE type = '1' AND username = '".$_SESSION['username']."'"))[0];
                                            $i = 1;
                                            while ($data = mysql_fetch_assoc($req)) {
                                                $debit = $data['size'] / (1000000) / $data['time'];
                                                if ($debit == 0)
                                                    $debit = $data['size'] / 1000000;
                                        ?>
                                        <tr>
                                            <td><?php echo $i; ?></td>
                                            <td><?php echo $data['filename']; ?></td>
                                            <td><?php echo ($data['size'] / 1000000)." Mb"; ?></td>
                                            <td><?php echo number_format($debit, 2)." Mb/s"; ?></td>
                                            <td><?php echo $data['date']; ?></td>
                                            <td><?php echo ($data['type'] == 0) ? "Download" : "Upload"; ?></td>
                                            <td><center>
                                                <button type="button" class="btn btn-warning btn-circle"><i class="fa fa-pencil"></i></button>
                                                <button type="button" class="btn btn-danger btn-circle"><i class="fa fa-times"></i></button>
                                                <button type="button" class="btn btn-info btn-circle"><i class="fa fa-info"></i></button>
                                            </center></td>
                                        </tr>
                                        <?php
                                            $i++;
                                            }
                                        ?>
                                    </tbody>
                                </table>
                            </div>
                            <!-- /.table-responsive -->
                        </div>
                        <center> <ul class="pagination">
                             <li><a href="uploads.php"> <b><</b></a></li>
                            <?php 
                                $n = ($offset / 50 - 10 >= 0 ? $offset / 50 - 10 : 0);
                                $j = 0;
                                for($i = $n * 50; $i < $total_size and $j <= 20; $i += 50) { ?>
                                 <li <?php if ($n == $offset / 50) { echo "class=\"active\""; } ?>><a href="uploads.php?page=<?php echo $n; ?>"><?php echo $n; ?></a></li>
                            <?php  
                                $n++; $j++;}
                            ?>
                            <li><a href="uploads.php?page=<?php echo floor($total_size / 50); ?>"> <b>></b></a></li>
                        </ul></center>
                        <!-- /.panel-body -->
                    </div>
                    <!-- /.panel -->
                </div>
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
    <script src="http://code.highcharts.com/highcharts.js"></script>
    <script src="http://code.highcharts.com/modules/exporting.js"></script>

    <!-- Custom Theme JavaScript -->
    <script src="dist/js/sb-admin-2.js"></script>

    <!-- Page-Level Demo Scripts - Tables - Use for reference -->
    
    <script>
    $(document).ready(function() {
       $(function () {
    $('#container').highcharts({
        chart: {
            type: 'areaspline'
        },
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
                text: 'Uploads'
            }
        },
        tooltip: {
            shared: true,
            valueSuffix: ' Uploads'
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
            name: 'Upload Number',
            data: [<?php echo $tab[6]; ?>, <?php echo $tab[5]; ?>, <?php echo $tab[4]; ?>, <?php echo $tab[3]; ?>, <?php echo $tab[2]; ?>, <?php echo $tab[1]; ?>, <?php echo $tab[0]; ?>]
        },],
    });
});
    });
    </script>

</body>

</html>
