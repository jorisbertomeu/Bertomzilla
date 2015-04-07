<?php include("session.php"); 
if ($_SESSION['rights'] == 0)
    {   
       echo "ACCES DENIED";
       exit;
    }
?>
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
                        <li>
                            <a href="users.php"><i class="fa fa-users fa-fw active"></i> Users Managment</a>
                        </li>
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
                    <h1 class="page-header">Users Managment</h1>
                </div>
                <!-- /.col-lg-12 -->
            </div>
            <div class="row">
                <div class="col-lg-12">
                    <div class="panel panel-default">
                        <div class="panel-heading">
                            Add user
                        </div>
                        <div class="panel-body">
                            <form role="form" action="add_user.php" method="POST">
                                <div class="form-group">
                                    <table width="100%">
                                        <tr>
                                            <td width="50%">
                                                <label>Username</label>
                                                <input name="username" class="form-control"><br>
                                                <label>Password</label>
                                                <input name="password" type="password" class="form-control"><br>
                                                <label>Fullname</label>
                                                <input name="fullname" class="form-control"><br>
                                                <label>Home Directory</label>
                                                <input name="directory" class="form-control"><br>
                                            </td>
                                            <td>
                                                <label>&nbsp;&nbsp;Rights</label>
                                                <div class="checkbox">
                                                    <label>
                                                        &nbsp;&nbsp;&nbsp;<input name="user" type="checkbox" value="" checked>Simple User
                                                    </label>
                                                </div>
                                                <div class="checkbox">
                                                    <label>
                                                        &nbsp;&nbsp;&nbsp;<input name="admin" type="checkbox" value="">Admin
                                                    </label>
                                                </div>
                                            <label>&nbsp;&nbsp;Permissions</label>
                                                <div class="checkbox">
                                                    <label>
                                                        &nbsp;&nbsp;&nbsp;<input name="read" type="checkbox" value="" checked>Read
                                                    </label>
                                                </div>
                                                <div class="checkbox">
                                                    <label>
                                                        &nbsp;&nbsp;&nbsp;<input name="write" type="checkbox" value="" checked>Write
                                                    </label>
                                                </div>
                                                <div class="checkbox">
                                                    <label>
                                                        &nbsp;&nbsp;&nbsp;<input name="dirCrea" type="checkbox" value="" checked>Directory cration
                                                    </label>
                                                </div>
                                                <div class="checkbox">
                                                    <label>
                                                        &nbsp;&nbsp;&nbsp;<input name="dirRem" type="checkbox" value="" checked>Directory removing
                                                    </label>
                                                </div><br>
                                            </td>
                                        </tr>
                                    </table>
                                    <input type="submit" class="btn btn-outline btn-success btn-md btn-block" value="Add !">
                                </div>
                            </form>
                        </div>
                    </div>
                </div>
            </div>
            <div class="row">
                <div class="col-lg-12">
                    <div class="panel panel-default">
                        <div class="panel-heading">
                            Users Accounts
                        </div>
                        <!-- /.panel-heading -->
                        <?php
                            $db = mysql_connect('localhost', 'bertomzilla', 'password'); 
                            mysql_select_db('bertomzilla', $db); 
                            $sql = "SELECT * FROM users"; 
                            $req = mysql_query($sql) or die('Erreur SQL !<br>'.$sql.'<br>'.mysql_error()); 
                        ?>
                        <div class="panel-body">
                            <div class="table-responsive">
                                <table class="table table-striped table-bordered table-hover">
                                    <thead>
                                        <tr>
                                            <th>#</th>
                                            <th>Username</th>
                                            <th>Fullname</th>
                                            <th>Home Directory</th>
                                            <th>Creation date</th>
                                            <th>Rights</th>
                                            <th>Permissions</th>
                                            <th>Actions</th>
                                        </tr>
                                    </thead>
                                    <tbody>
                                        <?php 
                                            $i = 1;
                                            while ($data = mysql_fetch_assoc($req)) {
                                        ?>
                                        <tr>
                                            <td><?php echo $i; ?></td>
                                            <td><?php echo $data['username']; ?></td>
                                            <td><?php echo $data['fullname']; ?></td>
                                            <td><?php echo $data['directory']; ?></td>
                                            <td><?php echo $data['creation']; ?></td>
                                            <td><?php echo ($data['rights'] == 1) ? "Admin" : "User"; ?></td>
                                            <td>R,W,C,D</td>
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

    <!-- DataTables JavaScript -->
    <script src="bower_components/DataTables/media/js/jquery.dataTables.min.js"></script>
    <script src="bower_components/datatables-plugins/integration/bootstrap/3/dataTables.bootstrap.min.js"></script>

    <!-- Custom Theme JavaScript -->
    <script src="dist/js/sb-admin-2.js"></script>

    <!-- Page-Level Demo Scripts - Tables - Use for reference -->
    <script>
    $(document).ready(function() {
        $('#dataTables-example').DataTable({
                responsive: true
        });
    });
    </script>

</body>

</html>
