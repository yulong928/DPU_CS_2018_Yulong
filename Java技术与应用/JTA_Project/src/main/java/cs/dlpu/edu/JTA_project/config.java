package cs.dlpu.edu.JTA_project;

public class config {
    private String url = "jdbc:mysql://localhost:3306/JTA_projects";
    private String user = "root";
    private String password = "12345678";

    public String getUrl() {
        return url;
    }

    public String getUser() {
        return user;
    }

    public String getPassword() {
        return password;
    }
}
