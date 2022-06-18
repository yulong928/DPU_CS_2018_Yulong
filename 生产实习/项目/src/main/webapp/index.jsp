<%@ page import="com.dlpu.cs.yulong.DAO.DAOImpl" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>login</title>
    <link rel="stylesheet" href="https://cdn.bootcss.com/bootstrap/4.1.0/css/bootstrap.min.css">
    <script src="https://cdn.bootcss.com/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://cdn.bootcss.com/popper.js/1.12.5/umd/popper.min.js"></script>
    <script src="https://cdn.bootcss.com/bootstrap/4.1.0/js/bootstrap.min.js"></script>
    <meta name="description" content="login page" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <link rel="shortcut icon" href="assets/img/favicon.png" type="image/x-icon">
    <link href="assets/css/bootstrap.min.css" rel="stylesheet" />
    <link id="bootstrap-rtl-link" href="" rel="stylesheet" />
    <link href="assets/css/font-awesome.min.css" rel="stylesheet" />
    <link href="http://fonts.useso.com/css?family=Open+Sans:300italic,400italic,600italic,700italic,400,600,700,300" rel="stylesheet" type="text/css">
    <link id="beyond-link" href="assets/css/beyond.min.css" rel="stylesheet" />
    <link href="assets/css/demo.min.css" rel="stylesheet" />
    <link href="assets/css/animate.min.css" rel="stylesheet" />
    <link id="skin-link" href="" rel="stylesheet" type="text/css" />
    <script src="assets/js/skins.min.js"></script>
</head>
    <body>
        <div class="login-container animated fadeInDown">
            <div class="loginbox bg-white">
                <br><br><br><br><br>
                <div class="loginbox-title">学生考试系统</div>
                <div class="loginbox-social">
                </div>
                <form action="index.jsp">
                    <div class="loginbox-textbox">
                        <input type="text" class="form-control" placeholder="学号" name="id">
                    </div>
                    <div class="loginbox-textbox">
                        <input type="text" class="form-control" placeholder="姓名" name="name">
                    </div>
                    <div class="loginbox-textbox" style="margin: 0 auto">
                        <input type="submit" value="登录" class='btn btn-primary'>
                    </div>
                </form>
            </div>
        </div>
            <%
                String id = request.getParameter("id");
                String name = request.getParameter("name");
                DAOImpl dao = new DAOImpl();
                Boolean checkstu = dao.checkStudent(id,name);
                if(checkstu){
                    response.sendRedirect("home.jsp？id="+id);
                }
            %>
    </body>
</html>