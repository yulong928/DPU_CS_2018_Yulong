<%@ page import="java.util.List" %>
<%@ page import="cs.dlpu.edu.JTA_project.massage" %>
<%@ page import="cs.dlpu.edu.JTA_project.dao" %>
<%@ page import="cs.dlpu.edu.JTA_project.student" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
        <link rel="stylesheet" href="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/css/bootstrap.min.css">
        <script src="https://cdn.staticfile.org/jquery/2.1.1/jquery.min.js"></script>
        <script src="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/js/bootstrap.min.js"></script>
        <title>考试信息查询</title>
    </head>
    <body style="padding: 20px">
        <form action="index.jsp" method="get">
            <p>
                <label>
                    学号
                    <input type="text" name="studentID">
                </label>
                <input type="submit" value="提交">
            </p>
        </form>
        <p>
            <%
                String studentID = request.getParameter("studentID");
                List<massage> msgList = new dao().select(studentID);
                student stu = new dao().getStuName(studentID);
//                if(studentName!=null)
//                {
                    int num = msgList.size();
                    out.print(stu.getName()+"同学您好，共查询到"+num+"条考试信息");
//                }
//                else{
//                    out.print("未查询到该学生信息");
//                }
            %>
        </p>
        <div class="table-responsive" style="padding-right: 500px">
            <table class="table table-striped table-hover table-bordered">
                <tr>
                    <th>课程名称</th><th>考试时间</th><th>考试地点</th>
                </tr>
                <%
                    for (massage msg : msgList) {
                        out.print("<tr><td>" + msg.getName() + "</td><td>" + msg.getDate() + "</td><td>" + msg.getRoom() + "</td></tr>");
                    }
                %>
            </table>
        </div>
    </body>
</html>