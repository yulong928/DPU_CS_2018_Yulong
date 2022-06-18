<%@ page import="com.dlpu.cs.yulong.DAO.DAOImpl" %>
<%@ page import="com.dlpu.cs.yulong.POJO.ClassCourseMsg" %>
<%@ page import="java.util.List" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>考务管理安排</title>
    <link rel="stylesheet" href="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://cdn.staticfile.org/jquery/2.1.1/jquery.min.js"></script>
    <script src="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <meta name="description" content="data tables" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <link rel="shortcut icon" href="assets/img/favicon.png" type="image/x-icon">
    <link href="assets/css/bootstrap.min.css" rel="stylesheet" />
    <link id="bootstrap-rtl-link" href="" rel="stylesheet" />
    <link href="assets/css/font-awesome.min.css" rel="stylesheet" />
    <link href="assets/css/weather-icons.min.css" rel="stylesheet" />
    <link href="http://fonts.useso.com/css?family=Open+Sans:300italic,400italic,600italic,700italic,400,600,700,300" rel="stylesheet" type="text/css">
    <link id="beyond-link" href="assets/css/beyond.min.css" rel="stylesheet" />
    <link href="assets/css/demo.min.css" rel="stylesheet" />
    <link href="assets/css/typicons.min.css" rel="stylesheet" />
    <link href="assets/css/animate.min.css" rel="stylesheet" />
    <link id="skin-link" href="" rel="stylesheet" type="text/css" />
    <link href="assets/css/dataTables.bootstrap.css" rel="stylesheet" />
    <script src="assets/js/skins.min.js"></script>
</head>
<body style="padding: 20px">
<div class="main-container container-fluid">
    <div class="page-container">
        <div class="page-sidebar" id="sidebar">
            <ul class="nav sidebar-menu">
                <li>
                    <a href="manager.jsp">
                        <i class="menu-icon glyphicon glyphicon-home"></i>
                        <span class="menu-text"> 考务管理 </span>
                    </a>
                </li>
                <li>
                    <a href="newExam.jsp" class="menu-dropdown">
                        <i class="menu-icon fa fa-desktop"></i>
                        <span class="menu-text"> 新增考试 </span>
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
                                <span class="widget-caption">考务管理安排</span>
                            </div>
                            <div class="widget-body">
                                <div role="grid" id="simpledatatable_wrapper" class="dataTables_wrapper form-inline no-footer">
                                    <div class="table-responsive" style="padding-right: 50px">
                                        <table class="table table-striped table-hover table-bordered">
                                            <tr><th>班级</th><th>应报名人数</th><th>已报名人数</th><th>考场名称</th><th>考试日期</th><th>考试时间</th><th>修改考务</th><th>操作</th></tr>
                                            <%
                                                String id =request.getParameter("id");
                                                DAOImpl dao = new DAOImpl();
                                                List<ClassCourseMsg> msgList = dao.getClassCourseList(id);
                                                for (ClassCourseMsg msg : msgList){
                                                    out.print("<tr><td>"+msg.getClassName()+"</td><td>"+msg.getAllNum()
                                                            +"</td><td>"+msg.getCheckNum()+"</td><td><input style=\"width: 80px\" type=\"text\" name=\"\" value=\""+msg.getRoom()
                                                            +"\"></td><td><input style=\"width: 100px\" type=\"text\" name=\"\" value=\""
                                                            +msg.getDate()+"\"></td><td><input style=\"width: 100px\" type=\"text\" name=\"\" value=\""
                                                            +msg.getTime()+"\"></td><td><a>确认修改</a></td><td>" +
                                                            "<a href=\"stuMsg.jsp?class="+msg.getClassName()+"&id="+id+"\">详细信息</a></td></tr>");
                                                }
                                            %>
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
