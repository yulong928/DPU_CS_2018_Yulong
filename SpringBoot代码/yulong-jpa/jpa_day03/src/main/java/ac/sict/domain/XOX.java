package ac.sict.domain;

import lombok.Data;

import javax.persistence.*;
import java.util.Date;

@Entity
@Table(name = "xox")
@Data
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

}