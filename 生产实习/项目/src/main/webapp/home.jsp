<%@ page import="java.util.List" %>
<%@ page import="com.dlpu.cs.yulong.POJO.ExamList" %>
<%@ page import="com.dlpu.cs.yulong.DAO.DAOImpl" %>
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
                                    <span class="widget-caption">考试报名</span>
                                </div>
                                <div class="widget-body">
                                    <div role="grid" id="simpledatatable_wrapper" class="dataTables_wrapper form-inline no-footer">
                                        <div class="table-responsive" style="padding-right: 500px">
                                            <%
                                                DAOImpl dao = new DAOImpl();
                                                List<ExamList> lists = dao.search(id);
                                                out.print("<h5>您共需参加"+lists.size()+"门考试，请抓紧报名<h5>");
                                            %>
                                            <br/>
                                            <table class="table table-striped table-hover table-bordered">
                                                <tr><th>课程号</th><th>课程名称</th><th>当前报名状态</th><th>操作</th></tr>
                                                <%
                                                    for (ExamList list : lists){
                                                        String cou_id = list.getCou_id();
                                                        String cou_name = list.getCou_name();
                                                        out.print("<tr><td>"+cou_id+"</td><td>"+cou_name+"</td>");
                                                        if(list.isStatue()){
                                                            out.print("<td style=\"color: 27A836\">已经报名</td><td><a href=\"ExamBaoMing?id="+id+"&cou_id="+cou_id+"&statue=true\">取消报名</a></td></tr>");
                                                        }else{
                                                            out.print("<td style=\"color: red\">未报名</td><td><a href=\"ExamBaoMing?id="+id+"&cou_id="+cou_id+"&statue=false\">报名</a></td></tr>");
                                                        }
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
