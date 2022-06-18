package ac.sict.domain;

import lombok.Data;

import javax.persistence.*;

@Data
@Entity
@Table(name = "music")
public class Music {
    @Id
    private String musicID;
    private String musicName;
    private int type;
    private int number;

    @ManyToOne(targetEntity = Album.class)
    @JoinColumn(name = "albumID",referencedColumnName = "albumID")
    private Album album;

    public Music(String musicID, String musicName, int type, int number) {
        this.musicID = musicID;
        this.musicName = musicName;
        this.type = type;
        this.number = number;
    }

    public Music() {

    }
}
