package ac.sict.G8_AMS.domain;

public class ArrangeMusicToAct {
    private String actID;
    private String musicID;
    private int pre;
    private String xoxID;
    private String musicName;

    public ArrangeMusicToAct(){}

    public ArrangeMusicToAct(String actID, String musicID, int pre, String xoxID) {
        this.actID = actID;
        this.musicID = musicID;
        this.pre = pre;
        this.xoxID = xoxID;
    }

    @Override
    public String toString() {
        return "ArrangeMusicToAct{" +
                "actID='" + actID + '\'' +
                ", musicID='" + musicID + '\'' +
                ", pre=" + pre +
                ", xoxID='" + xoxID + '\'' +
                '}';
    }

    public String getActID() {
        return actID;
    }

    public void setActID(String actID) {
        this.actID = actID;
    }

    public String getMusicID() {
        return musicID;
    }

    public void setMusicID(String musicID) {
        this.musicID = musicID;
    }

    public int getPre() {
        return pre;
    }

    public void setPre(int pre) {
        this.pre = pre;
    }

    public String getXoxID() {
        return xoxID;
    }

    public void setXoxID(String xoxID) {
        this.xoxID = xoxID;
    }

    public String getMusicName() {
        return musicName;
    }

    public void setMusicName(String musicName) {
        this.musicName = musicName;
    }
}
