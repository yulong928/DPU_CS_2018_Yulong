package com.dlpu.cs.yulong.JDBC;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
public class DataSource {
    public Connection getConnection() throws SQLException, ClassNotFoundException {
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/exam_data","root","12345678");
        connection.setAutoCommit(false);
        return connection;
    }
}
