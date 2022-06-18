package com.dlpu.cs.yulong.POJO;

public class StuMsg {
    String id;
    String stu_name;
    boolean statue;

    public StuMsg(String id, String stu_name, boolean statue) {
        this.id = id;
        this.stu_name = stu_name;
        this.statue = statue;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getStu_name() {
        return stu_name;
    }

    public void setStu_name(String stu_name) {
        this.stu_name = stu_name;
    }

    public boolean isStatue() {
        return statue;
    }

    public void setStatue(boolean statue) {
        this.statue = statue;
    }
}
