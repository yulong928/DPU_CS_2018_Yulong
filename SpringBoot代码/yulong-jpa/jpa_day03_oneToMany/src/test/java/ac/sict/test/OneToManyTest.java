package ac.sict.test;

import ac.sict.dao.AlbumDao;
import ac.sict.dao.MusicDao;
import ac.sict.domain.Album;
import ac.sict.domain.Music;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.annotation.Rollback;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.transaction.annotation.Transactional;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = "classpath:applicationContext.xml")
public class OneToManyTest {
    @Autowired
    private AlbumDao albumDao;
    @Autowired
    private MusicDao musicDao;

    @Test
    @Transactional
    @Rollback(value = false)
    public void testAdd(){
        Album album = new Album("11210","幻境");
        Music music = new Music("112102701","迷(Secret)",2,7);
        music.setAlbum(album);
        albumDao.save(album);
        musicDao.save(music);
    }

    @Test
    @Transactional
    @Rollback(value = false)
    public void testCascadeAdd(){
        Album album = new Album("12107","三角函数");
        Music music = new Music("121071201","结伴",1,2);
        music.setAlbum(album);
        album.getMusicSet().add(music);
        albumDao.save(album);
        musicDao.save(music);
    }

}
