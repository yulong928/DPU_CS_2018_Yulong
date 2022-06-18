<%--
  Created by IntelliJ IDEA.
  User: liangyulong
  Date: 2021/10/12
  Time: 07:11
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>公演通告确认</title>
</head>
<body>
    <h1>公演确认通知单</h1>
    <form action="/G8_AMS/coo/addAct" method="post">
        演出时间
        <input class="form-control js-datetimepicker" type="text" id="example-datetimepicker" name="datetime" placeholder="选择" value="" data-side-by-side="true" data-locale="zh-cn" data-format="YYYY-MM-DD HH:mm" />
        <br/>
        参演队伍<select name="team">
        <option>负责人</option>
        <c:forEach items="${teams}" var="team">
            <option value="${team}">${team}</option>
        </c:forEach>
    </select><br/>
        队长<select name="cap">
        <option>负责人</option>
        <c:forEach items="${caps}" var="cap">
            <option value="${cap.xoxID}">${cap.team} ${cap.xoxName}</option>
        </c:forEach>
    </select><br/>
        演出主题
        <select name="album">
            <option>请选择公演所用专辑</option>
            <c:forEach items="${albums}" var="album">
                <option value="${album.albumID}">${album.albumName}</option>
            </c:forEach>
        </select><br/>
        <input type="submit" value="提交">
    </form>
</body>
</html>
