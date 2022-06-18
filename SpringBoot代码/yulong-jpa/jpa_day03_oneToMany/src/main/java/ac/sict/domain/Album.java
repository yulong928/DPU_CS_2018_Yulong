package ac.sict.domain;
import lombok.Data;

import javax.persistence.*;
import java.util.HashSet;
import java.util.Set;

@Data
@Entity
@Table(name = "album")
public class Album {

    @Id
    private String albumID;
    private String albumName;


    @OneToMany(mappedBy = "album",cascade = CascadeType.ALL)
    private Set<Music> musicSet = new HashSet<>();

    public Album(String albumID, String albumName) {
        this.albumID = albumID;
        this.albumName = albumName;
    }

    public Album() {

    }
}
