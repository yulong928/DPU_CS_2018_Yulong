package ac.sict.yulong;

import java.sql.*;

public class Main {

    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://47.94.226.222:3306/mysql";
    static final String USER = "root";
    static final String PASS = "12345678";

    public static void main(String[] args) {
        Connection connection;
        Statement statement;
        try {
            Class.forName(JDBC_DRIVER);
            connection = DriverManager.getConnection(DB_URL,USER,PASS);
            statement = connection.createStatement();
            String sql;
            sql = "SELECT Host, User, Password FROM user";
            ResultSet rs = statement.executeQuery(sql);
            while (rs.next()){
                String host = rs.getString("Host");
                String name = rs.getString("User");
                String password = rs.getString("Password");
                System.out.println(host + " " +name+ " " +password);
            }
            rs.close();
            statement.close();
            connection.close();
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }
}
