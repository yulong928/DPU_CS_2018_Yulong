package ac.sict.test;

import ac.sict.dao.XOXDao;
import ac.sict.domain.XOX;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = "classpath:applicationContext.xml")
public class XOXDaoTest {
    @Autowired
    private XOXDao dao;

    @Test
    public void testFindOne(){
        XOX xox = dao.findOne("10087");
        System.out.println(xox);
    }

    @Test
    public void testSave(){
        XOX xox = new XOX();
        xox.setXoxID("19001");
        xox.setXoxName("林佳怡");
        xox.setTeam("SNH48 Team X");
        dao.save(xox);
    }

    @Test
    public void testUpdate(){
        XOX xox = new XOX();
        xox.setXoxID("19001");
        xox.setXoxName("林佳怡");
        xox.setTeam("TEAM X");
        dao.save(xox);
    }

    @Test
    public void testDelete(){
        dao.delete("19001");
    }

    @Test
    public void testFindAll(){
        List<XOX> all = dao.findAll();
        for (XOX xox : all){
            System.out.println(xox);
        }
    }

    @Test
    public void testCount(){
        long count = dao.count();
        System.out.println(count);
    }

    @Test
    public void textExist(){
        boolean exists = dao.exists("10087");
        System.out.printf(exists+" ");
    }

    @Test
    @Transactional
    public void testGetOne(){
        XOX one = dao.getOne("10087");
        System.out.println(one);
    }

}
