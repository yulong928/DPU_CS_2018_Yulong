<%@ page language="java" contentType="text/html; charset=GB18030" pageEncoding="GB18030" isELIgnored="false"%>
<%response.setCharacterEncoding("UTF-8");%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>个人中心</title>
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
                    <a href="/G8_AMS/searchMsg?xoxID=${param.xoxID}">
                        <i class="menu-icon glyphicon glyphicon-tasks"></i>
                        <span class="menu-text"> 通知中心 </span>
                    </a>
                </li>
                <li>
                    <a href="/G8_AMS/applyForLeave?xoxID=${param.xoxID}">
                        <i class="menu-icon glyphicon glyphicon-tasks"></i>
                        <span class="menu-text"> 请假申请 </span>
                    </a>
                </li>
            </ul>
        </div>
        <div class="page-content">
            <div class="page-body">
                <div class="row">
                        <c:if test="${count!=0}">
                            <div class="widget">
                                <div class="widget-header ">
                                    <span class="widget-caption">${act.actName}歌曲安排</span>
                                </div>
                                <div class="widget-body">
                                    <div role="grid" id="simpledatatable_wrapper2" class="dataTables_wrapper form-inline no-footer">
                                        <div class="table-responsive" style="padding-right: 100px">
                                            <form method="get" action="/G8_AMS/cap/setActMenu">
                                                <input type="text" style="display: none" name="actId" value="${act.id}">
                                                <input type="text" style="display: none" name="xoxID" value="${xox}">
                                                <table class="table table-striped table-hover table-bordered">
                                                    <tr><th style="width: 200px">歌曲</th><th>参演成员</th></tr>
                                                    <tr>
                                                        <c:forEach items="${musics}" var="music">
                                                        <td>《${music.musicName}》</td>
                                                        <td>
                                                            <c:forEach begin="1" end="${music.number}" var="index">
                                                                <select name="${music.musicID}.${index}">
                                                                    <option value=null>选择参演成员</option>
                                                                    <c:forEach items="${xoxes}" var="xox">
                                                                        <option value="${xox.xoxID}">${xox.team} ${xox.xoxName}</option>
                                                                    </c:forEach>
                                                                </select>
                                                            </c:forEach>
                                                        </td>
                                                    </tr>
                                                    </c:forEach>
                                                </table>
                                                <text style="color: red">表格中存在顺位间断的情况，请进行修改</text><br/>
                                                <input type="submit" value="提交">
                                            </form>
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