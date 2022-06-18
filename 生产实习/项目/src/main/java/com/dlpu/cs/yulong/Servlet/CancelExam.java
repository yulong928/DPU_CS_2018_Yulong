package com.dlpu.cs.yulong.Servlet;

import com.dlpu.cs.yulong.DAO.DAOImpl;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet(name = "CancelExam", value = "/CancelExam")
public class CancelExam extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String stu_id = request.getParameter("stu_id");
        String cou_id = request.getParameter("cou_id");
        DAOImpl dao = new DAOImpl();
        try {
            dao.CancelExam(stu_id,cou_id);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        response.sendRedirect("setting.jsp?id="+cou_id);

    }
}
