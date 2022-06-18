package ac.sict.G8_AMS.domain;

public class Album {
    private String albumID;
    private String albumName;

    @Override
    public String toString() {
        return "{" +
                "albumID='" + albumID + '\'' +
                ", albumName='" + albumName + '\'' +
                '}';
    }

    public Album(){}

    public Album(String albumID, String albumName) {
        this.albumID = albumID;
        this.albumName = albumName;
    }

    public String getAlbumID() {
        return albumID;
    }

    public void setAlbumID(String albumID) {
        this.albumID = albumID;
    }

    public String getAlbumName() {
        return albumName;
    }

    public void setAlbumName(String albumName) {
        this.albumName = albumName;
    }
}
