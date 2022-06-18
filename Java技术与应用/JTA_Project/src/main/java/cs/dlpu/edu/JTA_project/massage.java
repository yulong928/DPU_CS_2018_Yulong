package cs.dlpu.edu.JTA_project;

public class massage {
    private String name;
    private String date;
    private String room;
    private String course_name;

    public massage(String name, String date, String room, String course_name) {
        this.name = name;
        this.date = date;
        this.room = room;
        this.course_name = course_name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDate() {
        return date;
    }

    public String getRoom() {
        return room;
    }

    public String getCourse_name() {
        return course_name;
    }
}
