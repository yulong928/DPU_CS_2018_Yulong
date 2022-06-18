package ac.sict.domain;

import javax.persistence.*;
import java.util.Date;

@Entity
@Table(name = "xox")
public class XOX {

    @Id
    @Column(name = "xoxID")
    private String xoxID;
    @Column(name = "xoxName")
    private String xoxName;
    @Column(name="birthday")
    private Date birthday;
    @Column(name="className")
    private String className;
    @Column(name="team")
    private String team;
    @Column(name="img")
    private String img;
    @Column(name="caption")
    private boolean caption;


    @Override
    public String toString() {
        return "XOX{" +
                "xoxID='" + xoxID + '\'' +
                ", xoxName='" + xoxName + '\'' +
                ", birthday=" + birthday +
                ", className='" + className + '\'' +
                ", team='" + team + '\'' +
                ", img='" + img + '\'' +
                ", caption=" + caption +
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

    public String getClassName() {
        return className;
    }

    public void setClassName(String className) {
        this.className = className;
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

    public boolean isCaption() {
        return caption;
    }

    public void setCaption(boolean caption) {
        this.caption = caption;
    }

}
