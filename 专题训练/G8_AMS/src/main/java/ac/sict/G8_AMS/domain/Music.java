package ac.sict.G8_AMS.domain;

public class Music {
    private String musicID;
    private String musicName;
    private int type;
    private String albumID;
    private int number;

    @Override
    public String toString() {
        return "{" +
                "musicID='" + musicID + '\'' +
                ", musicName='" + musicName + '\'' +
                ", type=" + type +
                ", albumID='" + albumID + '\'' +
                ", number=" + number +
                '}';
    }

    public Music(){}

    public Music(String musicID, String musicName, int type, String albumID, int number) {
        this.musicID = musicID;
        this.musicName = musicName;
        this.type = type;
        this.albumID = albumID;
        this.number = number;
    }

    public String getMusicID() {
        return musicID;
    }

    public void setMusicID(String musicID) {
        this.musicID = musicID;
    }

    public String getMusicName() {
        return musicName;
    }

    public void setMusicName(String musicName) {
        this.musicName = musicName;
    }

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }

    public String getAlbumID() {
        return albumID;
    }

    public void setAlbumID(String albumID) {
        this.albumID = albumID;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }
}
