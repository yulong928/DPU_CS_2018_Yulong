package ac.sict.test;


import ac.sict.dao.XOXDao;
import ac.sict.domain.XOX;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.annotation.Rollback;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.transaction.annotation.Transactional;

import java.util.Arrays;
import java.util.Date;
import java.util.List;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = "classpath:applicationContext.xml")
public class JPQLTest {

    @Autowired
    private XOXDao dao;

    @Test
    public void testFindJPQL(){
        XOX jpql = dao.findJpql("宋昕冉");
        System.out.println(jpql);
    }

    @Test
    public void testFindUseIdAndName(){
        System.out.println(dao.findXOXUseIdAndName("10087", "宋昕冉"));
    }

    @Test
    @Transactional
    @Rollback(value = false)
    public void testUpdate(){
        dao.updateXOX("10163",new Date(2000-1900,2,9));
    }

    @Test
    public void testFindSql(){
        List<Object[]> sql = dao.findSql();
        for (Object[] obj:sql){
            System.out.println(Arrays.toString(obj));
        }
    }

    @Test
    public void testFindSqlUseName(){
        List<Object[]> sql = dao.findSqlUseName("张%");
        for (Object[] obj:sql){
            System.out.println(Arrays.toString(obj));
        }
    }

    @Test
    public void testFindByNaming(){
        System.out.println(dao.findByXoxName("宋昕冉"));
    }

    @Test
    public void testFindByNamingLike(){
        List<XOX> byXoxNameLike = dao.findByXoxNameLike("张%");
        for(XOX xox : byXoxNameLike){
            System.out.println(xox);
        }
    }
}
