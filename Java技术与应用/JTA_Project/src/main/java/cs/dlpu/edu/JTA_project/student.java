package cs.dlpu.edu.JTA_project;

public class student {
    private String id;
    private String name;

    public student(String id) {
        this.id = id;
    }

    public student(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
