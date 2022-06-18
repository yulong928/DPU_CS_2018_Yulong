package cs.dlpu.edu.JTA_project;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class dao {
    public List<massage> select(String studentID) {
        List<massage> msgList = new ArrayList<>();
        Connection connection;
        Statement statement;
        try {
            config cf = new config();
            Class.forName("com.mysql.jdbc.Driver");
            connection = DriverManager.getConnection(cf.getUrl(), cf.getUser(), cf.getPassword());
            statement = connection.createStatement();
            String sql = "select student_name,course_name,date,room from JTA_data where student_id = " + studentID;
            ResultSet rs = statement.executeQuery(sql);
            while (rs.next()) {
                String student_name = rs.getString("student_name");
                String course_name = rs.getString("course_name");
                String date = rs.getString("date");
                String room = rs.getString("room");
                msgList.add(new massage(student_name,date, room, course_name));
            }
            rs.close();
            statement.close();
            connection.close();
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
        return msgList;
    }
//    public student getStuName(String studentID)
//    {
//        student stu = new student(studentID);
//        config cf = new config();
//        try {
//            Class.forName("com.mysql.jdbc.Driver");
//            Connection connection = DriverManager.getConnection(cf.getUrl(), cf.getUser(), cf.getPassword());
//            Statement statement = connection.createStatement();
//            String sql = "SELECT student_name FROM JTA_data WHERE student_id = " + studentID;
//            ResultSet rs = statement.executeQuery(sql);
//            while (rs.next()) {
//                String name = rs.getString("student_name");
//                stu.setName(name);
//            }
//            rs.close();
//            statement.close();
//            connection.close();
//        } catch (SQLException | ClassNotFoundException throwable) {
//            throwable.printStackTrace();
//        }
//        return stu;
//    }
}
