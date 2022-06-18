<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core_rt" %>
<html>
<head>
    <title>home</title>
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
                    <div class="col-lg-12 col-sm-12 col-xs-12">
                        <div class="widget">
                            <div class="widget-header">
                                <span class="widget-caption">公告进度</span>
                            </div>
                            <div class="widget-body">
                                <div role="grid" id="simpledatatable_wrapper" class="dataTables_wrapper form-inline no-footer">
                                    <div class="table-responsive" style="padding-right: 50px">
                                        <table class="table table-striped table-hover table-bordered">
                                            <tr><th>公演</th><th>负责人</th><th>状态</th></tr>
                                            <c:forEach items="${list}" var="noticeMain">
                                                <tr>
                                                    <td>${noticeMain.dateAndTime} ${noticeMain.actName}</td>
                                                    <td>${noticeMain.after}</td>
                                                    <td>
                                                        <c:if test="${noticeMain.capStatue==true}">
                                                            <text style="color: green">队长已完成布置</text>
                                                        </c:if>
                                                        <c:if test="${noticeMain.capStatue==false}">
                                                            <text style="color: red">队长未完成布置</text>
                                                        </c:if>
                                                    </td>
                                                </tr>
                                            </c:forEach>
                                        </table>
                                    </div>
                                </div>
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
