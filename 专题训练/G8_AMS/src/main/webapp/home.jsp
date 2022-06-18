<%@ page language="java" contentType="text/html; charset=GB18030" pageEncoding="GB18030" isELIgnored="false"%>
<%response.setCharacterEncoding("UTF-8");%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
    <head>
        <title>��������</title>
        <link rel="stylesheet" href="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/css/bootstrap.min.css">
        <script src="https://cdn.staticfile.org/jquery/2.1.1/jquery.min.js"></script>
        <script src="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/js/bootstrap.min.js"></script>
        <meta name="description" content="data tables" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <link rel="shortcut icon" href="assets/img/favicon.png" type="image/x-icon">
        <link href="assets/css/bootstrap.min.css" rel="stylesheet" />
        <link href="assets/css/font-awesome.min.css" rel="stylesheet" />
        <link href="assets/css/weather-icons.min.css" rel="stylesheet" />
        <link href="http://fonts.useso.com/css?family=Open+Sans:300italic,400italic,600italic,700italic,400,600,700,300" rel="stylesheet" type="text/css">
        <link href="assets/css/beyond.min.css" rel="stylesheet" />
        <link href="assets/css/demo.min.css" rel="stylesheet" />
        <link href="assets/css/typicons.min.css" rel="stylesheet" />
        <link href="assets/css/animate.min.css" rel="stylesheet" />
        <link href="assets/css/dataTables.bootstrap.css" rel="stylesheet" />
        <script src="assets/js/skins.min.js"></script>
    </head>
    <body style="padding: 20px">
    <div class="main-container container-fluid">
        <div class="page-container">
            <div class="page-sidebar" id="sidebar">
                <ul class="nav sidebar-menu">
                    <li>
                        <a href="/G8_AMS/login?xoxID=${xox.xoxID}&xoxName=${xox.xoxName}">
                            <i class="menu-icon glyphicon glyphicon-home"></i>
                            <span class="menu-text"> �������� </span>
                        </a>
                    </li>
                    <li>
                        <a href="/G8_AMS/searchMsg?xoxID=${param.xoxID}">
                            <i class="menu-icon glyphicon glyphicon-tasks"></i>
                            <span class="menu-text"> ֪ͨ���� </span>
                        </a>
                    </li>
                    <li>
                        <a href="/G8_AMS/applyForLeave?xoxID=${param.xoxID}">
                            <i class="menu-icon glyphicon glyphicon-tasks"></i>
                            <span class="menu-text"> ������� </span>
                        </a>
                    </li>
                </ul>
            </div>
            <div class="page-content">
                <div class="page-body">
                    <div class="row">
                        <div class="col-xs-12 col-md-12">
                            <div class="widget">
                                <div class="widget-header ">
                                    <span class="widget-caption">��������</span>
                                </div>
                                <div class="widget-body">
                                    <div role="grid" id="simpledatatable_wrapper" class="dataTables_wrapper form-inline no-footer">
                                        <div class="table-responsive" style="padding-right: 100px">
                                            <div class="widget-body">
                                                <form class="form-horizontal bv-form">
                                                    <div class="form-group has-feedback">
                                                        <label class="col-lg-4 control-label">����</label>
                                                        <div class="col-lg-8">
                                                            ${xox.xoxName}
                                                        </div>
                                                    </div>
                                                    <div class="form-group has-feedback">
                                                        <label class="col-lg-4 control-label">����</label>
                                                        <div class="col-lg-8">
                                                            ${xox.team}
                                                        </div>
                                                    </div>
                                                    <div class="form-group has-feedback">
                                                        <label class="col-lg-4 control-label">����</label>
                                                        <div class="col-lg-8">
                                                            ${xox.birthday}
                                                        </div>
                                                    </div>
                                                    <img src="${xox.img}">
                                                </form>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <c:if test="${count!=0}">
                                <div class="widget">
                                    <div class="widget-header ">
                                        <span class="widget-caption">��Ϣ����</span>
                                    </div>
                                    <div class="widget-body">
                                        <div role="grid" id="simpledatatable_wrapper2" class="dataTables_wrapper form-inline no-footer">
                                            <div class="table-responsive" style="padding-right: 100px">
                                                    <table class="table table-striped table-hover table-bordered">
                                                            <tr>
                                                                <td>����${count}��δ����ͨ�棬��ע����ա�</td>
                                                                <td><a href="/G8_AMS/searchMsg?xoxID=${param.xoxID}">ǰ���鿴</a></td>
                                                            </tr>
                                                    </table>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </c:if>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    </body>
</html>
