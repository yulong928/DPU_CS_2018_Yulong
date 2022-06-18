package ac.sict.test;

import ac.sict.domain.XOX;
import ac.sict.utils.JPAUtils;
import org.junit.Test;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Persistence;
import java.util.Date;

public class JPATest {
    @Test
    public void testSave(){
//        EntityManagerFactory factory = Persistence.createEntityManagerFactory("myJpa");
//        EntityManager entityManager = factory.createEntityManager();
        EntityManager entityManager = JPAUtils.getEntityManager();
        EntityTransaction transaction = entityManager.getTransaction();
        transaction.begin();    //开启事务
        XOX xox = new XOX();
        xox.setXoxID("19001");
        xox.setXoxName("林佳怡");
        xox.setBirthday(new Date(2022-1-13));
        entityManager.persist(xox);
        transaction.commit();
        entityManager.close();
    }

    @Test
    public void testFind(){
        EntityManager manager = JPAUtils.getEntityManager();
        EntityTransaction transaction = manager.getTransaction();
        transaction.begin();
        XOX xox = manager.find(XOX.class, "10087");
        System.out.println(xox);
        transaction.commit();
        manager.close();
    }

    @Test
    public void testReference(){
        EntityManager manager = JPAUtils.getEntityManager();
        EntityTransaction transaction = manager.getTransaction();
        transaction.begin();
        XOX xox = manager.getReference(XOX.class, "10087");
        System.out.println(xox);
        transaction.commit();
        manager.close();
    }

    @Test
    public void testRemove(){
        EntityManager manager = JPAUtils.getEntityManager();
        EntityTransaction transaction = manager.getTransaction();
        transaction.begin();
        XOX xox = manager.find(XOX.class, "19001");
        manager.remove(xox);
        transaction.commit();
        manager.close();
    }

    @Test
    public void testUpdate(){
        EntityManager manager = JPAUtils.getEntityManager();
        EntityTransaction transaction = manager.getTransaction();
        transaction.begin();
        XOX xox = manager.find(XOX.class, "19001");
        xox.setBirthday(new Date(2000-1900,0,15));
        manager.merge(xox);
        transaction.commit();
        manager.close();
    }
}
