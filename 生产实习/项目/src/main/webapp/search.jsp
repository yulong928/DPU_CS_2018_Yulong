<%@ page import="java.util.List" %>
<%@ page import="com.dlpu.cs.yulong.POJO.ExamList" %>
<%@ page import="com.dlpu.cs.yulong.DAO.DAOImpl" %>
<%@ page import="com.dlpu.cs.yulong.POJO.ExamMsg" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>考务信息平台</title>
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
                        <a href="home.jsp?id=
                            <%
                            String id = request.getParameter("id");
                            out.print(id);
                            %>
                        ">
                            <i class="menu-icon glyphicon glyphicon-home"></i>
                            <span class="menu-text"> 考试报名 </span>
                        </a>
                    </li>
                    <li>
                        <a href="search.jsp?id=
                            <%
                            out.print(id);
                            %>
                        ">
                            <i class="menu-icon glyphicon glyphicon-tasks"></i>
                            <span class="menu-text"> 查询考试安排 </span>
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
                                    <span class="widget-caption">考试安排</span>
                                </div>
                                <div class="widget-body">
                                    <div role="grid" id="simpledatatable_wrapper" class="dataTables_wrapper form-inline no-footer">
                                        <div class="table-responsive" style="padding-right: 500px">
                                            <table class="table table-striped table-hover table-bordered">
                                                <tr><th>课程名称</th><th>考试时间</th><th>教室</th></tr>
                                                <%
                                                    DAOImpl dao = new DAOImpl();
                                                    List<ExamMsg> msgs = dao.getExamMsgs(id);
                                                    for (ExamMsg msg : msgs){
                                                        String date = msg.getDate() + " " +msg.getTime();
                                                        out.print("<tr><td>"+msg.getCou_name()+"</td><td>"+date+"</td><td>"+msg.getRoom()+"</td></tr>");
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
