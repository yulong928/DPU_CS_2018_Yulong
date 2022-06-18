package com.dlpu.cs.yulong.POJO;

public class CourseMsg {
    String courseID;
    String courseName;
    int all_count;
    int check_count;

    public CourseMsg(String courseID, String courseName) {
        this.courseID = courseID;
        this.courseName = courseName;
    }

    public CourseMsg(String courseID, String courseName, int all_count, int check_count) {
        this.courseID = courseID;
        this.courseName = courseName;
        this.all_count = all_count;
        this.check_count = check_count;
    }

    public String getCourseID() {
        return courseID;
    }

    public void setCourseID(String courseID) {
        this.courseID = courseID;
    }

    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    public int getAll_count() {
        return all_count;
    }

    public void setAll_count(int all_count) {
        this.all_count = all_count;
    }

    public int getCheck_count() {
        return check_count;
    }

    public void setCheck_count(int check_count) {
        this.check_count = check_count;
    }
}
