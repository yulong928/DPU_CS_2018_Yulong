package com.dlpu.cs.yulong.Servlet;

import com.dlpu.cs.yulong.DAO.DAOImpl;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet(name = "InsertExam", value = "/InsertExam")
public class InsertExam extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String cou_id = request.getParameter("cou_id");
        String cou_name = request.getParameter("cou_name");
        String className = request.getParameter("class");
        DAOImpl dao = new DAOImpl();
        try {
            dao.InsertExam(cou_id,cou_name,className);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        response.sendRedirect("manager.jsp");
    }
}
