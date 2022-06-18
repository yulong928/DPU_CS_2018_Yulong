package com.dlpu.cs.yulong.POJO;

public class ExamList {
    String cou_id;
    String cou_name;
    boolean statue;

    public ExamList(String cou_id, String cou_name, boolean statue) {
        this.cou_id = cou_id;
        this.cou_name = cou_name;
        this.statue = statue;
    }

    public ExamList(String cou_id, String cou_name) {
        this.cou_id = cou_id;
        this.cou_name = cou_name;
    }

    public String getCou_id() {
        return cou_id;
    }

    public void setCou_id(String cou_id) {
        this.cou_id = cou_id;
    }

    public String getCou_name() {
        return cou_name;
    }

    public void setCou_name(String cou_name) {
        this.cou_name = cou_name;
    }

    public boolean isStatue() {
        return statue;
    }

    public void setStatue(boolean statue) {
        this.statue = statue;
    }
}
