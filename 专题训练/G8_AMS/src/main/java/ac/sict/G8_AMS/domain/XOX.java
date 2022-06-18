package ac.sict.G8_AMS.domain;

import java.util.Date;

public class XOX {
    private String xoxID;
    private String xoxName;
    private Date birthday;
    private String classType;
    private String team;
    private String img;

    public XOX(){

    }

    public XOX(String xoxID, String xoxName, Date birthday, String classType, String team, String img) {
        this.xoxID = xoxID;
        this.xoxName = xoxName;
        this.birthday = birthday;
        this.classType = classType;
        this.team = team;
        this.img = img;
    }

    @Override
    public String toString() {
        return "{" +
                "xoxID='" + xoxID + '\'' +
                ", xoxName='" + xoxName + '\'' +
                ", birthday=" + birthday +
                ", classType='" + classType + '\'' +
                ", team='" + team + '\'' +
                ", img='" + img + '\'' +
                '}';
    }

    public String getXoxID() {
        return xoxID;
    }

    public void setXoxID(String xoxID) {
        this.xoxID = xoxID;
    }

    public String getXoxName() {
        return xoxName;
    }

    public void setXoxName(String xoxName) {
        this.xoxName = xoxName;
    }

    public Date getBirthday() {
        return birthday;
    }

    public void setBirthday(Date birthday) {
        this.birthday = birthday;
    }

    public String getClassType() {
        return classType;
    }

    public void setClassType(String classType) {
        this.classType = classType;
    }

    public String getTeam() {
        return team;
    }

    public void setTeam(String team) {
        this.team = team;
    }

    public String getImg() {
        return img;
    }

    public void setImg(String img) {
        this.img = img;
    }
}
