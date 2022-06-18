package com.dlpu.cs.yulong.Servlet;

import com.dlpu.cs.yulong.DAO.DAOImpl;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet(name = "ExamBaoMing", value = "/ExamBaoMing")
public class ExamBaoMing extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String id = request.getParameter("id");
        String cou_id = request.getParameter("cou_id");
        boolean statue = Boolean.parseBoolean(request.getParameter("statue"));
        DAOImpl dao = new DAOImpl();
        try {
            int update = dao.update(id, cou_id, statue);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        response.sendRedirect("home.jsp？id="+id);

    }
}
