<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core_rt" %>
<html>
    <head>
        <title>新增通告发布</title>
        <link rel="stylesheet" href="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/css/bootstrap.min.css">
        <script src="https://cdn.staticfile.org/jquery/2.1.1/jquery.min.js"></script>
        <script src="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/js/bootstrap.min.js"></script>
        <meta name="description" content="data tables" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <link rel="shortcut icon" href="../assets/img/favicon.png" type="image/x-icon">
        <link href="../assets/css/bootstrap.min.css" rel="stylesheet" />
        <link href="../assets/css/font-awesome.min.css" rel="stylesheet" />
        <link href="../assets/css/weather-icons.min.css" rel="stylesheet" />
        <link href="http://fonts.useso.com/css?family=Open+Sans:300italic,400italic,600italic,700italic,400,600,700,300" rel="stylesheet" type="text/css">
        <link href="../assets/css/beyond.min.css" rel="stylesheet" />
        <link href="../assets/css/demo.min.css" rel="stylesheet" />
        <link href="../assets/css/typicons.min.css" rel="stylesheet" />
        <link href="../assets/css/animate.min.css" rel="stylesheet" />
        <link href="../assets/css/dataTables.bootstrap.css" rel="stylesheet" />
        <script src="../assets/js/skins.min.js"></script>
    </head>
    <body style="padding: 20px">
    <div class="main-container container-fluid">
        <div class="page-container">
            <div class="page-sidebar" id="sidebar">
                <ul class="nav sidebar-menu">
                    <li>
                        <a href="/G8_AMS/coo/home">
                            <i class="menu-icon glyphicon glyphicon-home"></i>
                            <span class="menu-text"> 通告状态查询 </span>
                        </a>
                    </li>
                    <li>
                        <a href="/G8_AMS/coo/manager" class="menu-dropdown">
                            <i class="menu-icon fa fa-desktop"></i>
                            <span class="menu-text"> 新增通告 </span>
                        </a>
                    </li>
                </ul>
            </div>
            <div class="page-content">
                <div class="page-body">
                    <div class="row">
                        <div class="col-lg-6 col-sm-6 col-xs-12">
                            <div class="widget radius-bordered">
                                <div class="widget-header">
                                    <span class="widget-caption">新增通告发布</span>
                                </div>
                                <div class="widget-body">
                                    <form class="form-horizontal bv-form" action="/G8_AMS/coo/addAct" method="post">
                                        <div class="form-group has-feedback">
                                            <label class="col-lg-4 control-label">演出时间</label>
                                            <div class="col-lg-8">
                                                <input type="datetime-local" name="datetime">
                                            </div>
                                        </div>
                                        <div class="form-group has-feedback">
                                            <label class="col-lg-4 control-label">参演队伍</label>
                                            <div class="col-lg-8">
                                                <select name="team">
                                                    <option>队伍</option>
                                                    <c:forEach items="${teams}" var="team">
                                                    <option value="${team}">${team}</option>
                                                    </c:forEach>
                                                </select>

                                            </div>
                                        </div>
                                        <div class="form-group has-feedback">
                                            <label class="col-lg-4 control-label">队长</label>
                                            <div class="col-lg-8">
                                                <select name="cap">
                                                    <option>负责人</option>
                                                    <c:forEach items="${caps}" var="cap">
                                                        <option value="${cap.xoxID}">${cap.team} ${cap.xoxName}</option>
                                                    </c:forEach>
                                                </select>
                                            </div>
                                        </div>
                                        <div class="form-group has-feedback">
                                            <label class="col-lg-4 control-label">演出主题</label>
                                            <div class="col-lg-8">
                                                <select name="album">
                                                    <option>请选择公演所用专辑</option>
                                                    <c:forEach items="${albums}" var="album">
                                                        <option value="${album.albumID}">${album.albumName}</option>
                                                    </c:forEach>
                                                </select>
                                            </div>
                                        </div>
                                        <div class="form-group">
                                            <div class="col-lg-offset-4 col-lg-8">
                                                <input class="btn btn-palegreen" type="submit" value="发布">
                                            </div>
                                        </div>
                                    </form>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    </body>
</html>