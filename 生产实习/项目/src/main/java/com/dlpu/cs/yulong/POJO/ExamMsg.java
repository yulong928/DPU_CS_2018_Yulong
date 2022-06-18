package com.dlpu.cs.yulong.POJO;

public class ExamMsg {
    String cou_name;
    String date;
    String time;
    String room;

    public ExamMsg(String cou_name, String date, String time, String room) {
        this.cou_name = cou_name;
        this.date = date;
        this.time = time;
        this.room = room;
    }

    public String getCou_name() {
        return cou_name;
    }

    public void setCou_name(String cou_name) {
        this.cou_name = cou_name;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }

    public String getRoom() {
        return room;
    }

    public void setRoom(String room) {
        this.room = room;
    }
}
