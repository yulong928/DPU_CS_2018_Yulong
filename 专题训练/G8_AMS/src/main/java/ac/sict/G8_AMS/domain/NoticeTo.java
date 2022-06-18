package ac.sict.G8_AMS.domain;

public class NoticeTo {
    private String acceptXoxId;
    private int type;
    private String content;
    private int statue;
    private String noticeID;
    private String sendXoxId = null;

    public NoticeTo(){}

    public NoticeTo(String noticeID,String acceptXoxId, int type, String content, int statue) {
        this.acceptXoxId = acceptXoxId;
        this.type = type;
        this.content = content;
        this.statue = statue;
        this.noticeID=noticeID;
    }

    public NoticeTo(String acceptXoxId, int type, String content, int statue, String noticeID, String sendXoxId) {
        this.acceptXoxId = acceptXoxId;
        this.type = type;
        this.content = content;
        this.statue = statue;
        this.noticeID = noticeID;
        this.sendXoxId = sendXoxId;
    }

    @Override
    public String toString() {
        return "NoticeTo{" +
                "acceptXoxId='" + acceptXoxId + '\'' +
                ", type=" + type +
                ", content='" + content + '\'' +
                ", statue=" + statue +
                ", noticeID='" + noticeID + '\'' +
                '}';
    }

    public String getAcceptXoxId() {
        return acceptXoxId;
    }

    public void setAcceptXoxId(String acceptXoxId) {
        this.acceptXoxId = acceptXoxId;
    }

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public int getStatue() {
        return statue;
    }

    public void setStatue(int statue) {
        this.statue = statue;
    }

    public String getNoticeID() {
        return noticeID;
    }

    public void setNoticeID(String noticeID) {
        this.noticeID = noticeID;
    }

    public String getSendXoxId() {
        return sendXoxId;
    }

    public void setSendXoxId(String sendXoxId) {
        this.sendXoxId = sendXoxId;
    }
}
