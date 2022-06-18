package ac.sict.G8_AMS.domain;

public class NoticeMain {
    private String id;
    private String dateAndTime;
    private String actName;
    private String team;
    private String cap;
    private String album;
    private boolean capStatue;
    private String after;

    public NoticeMain(){}

    public NoticeMain(String id, String dateAndTime, String actName, String team, String cap, String album, boolean capStatue) {
        this.id = id;
        this.dateAndTime = dateAndTime;
        this.actName = actName;
        this.team = team;
        this.cap = cap;
        this.album = album;
        this.capStatue = capStatue;
    }

    @Override
    public String toString() {
        return "NoticeMain{" +
                "id='" + id + '\'' +
                ", dateAndTime='" + dateAndTime + '\'' +
                ", actName='" + actName + '\'' +
                ", team='" + team + '\'' +
                ", cap='" + cap + '\'' +
                ", album='" + album + '\'' +
                ", capStatue=" + capStatue +
                '}';
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getDateAndTime() {
        return dateAndTime;
    }

    public void setDateAndTime(String dateAndTime) {
        this.dateAndTime = dateAndTime;
    }

    public String getActName() {
        return actName;
    }

    public void setActName(String actName) {
        this.actName = actName;
    }

    public String getTeam() {
        return team;
    }

    public void setTeam(String team) {
        this.team = team;
    }

    public String getCap() {
        return cap;
    }

    public void setCap(String cap) {
        this.cap = cap;
    }

    public String getAlbum() {
        return album;
    }

    public void setAlbum(String album) {
        this.album = album;
    }

    public boolean isCapStatue() {
        return capStatue;
    }

    public void setCapStatue(boolean capStatue) {
        this.capStatue = capStatue;
    }

    public String getAfter() {
        return after;
    }

    public void setAfter(String after) {
        this.after = after;
    }
}
