package com.dlpu.cs.yulong.Servlet;

import com.dlpu.cs.yulong.DAO.DAOImpl;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet(name = "adminLogin", value = "/adminLogin")
public class AdminLogin extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String id = request.getParameter("id");
        String name = request.getParameter("name");
        if(id.equals("306928")&&name.equals("admin")){
            response.sendRedirect("manager.jsp");
        }
    }
}
