package ac.sict.test;

import ac.sict.utils.JPAUtils;
import org.junit.Test;

import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;
import javax.persistence.Query;
import java.util.List;

public class JPQLTest {
    @Test
    public void testFindAll(){
        EntityManager em = JPAUtils.getEntityManager();
        EntityTransaction tx = em.getTransaction();
        tx.begin();
        String jpql = "from XOX";
        Query query = em.createQuery(jpql);
        List list = query.getResultList();
        for(Object obj : list){
            System.out.println(obj);
        }
        tx.commit();
        em.close();
    }

    @Test
    public void testFindOrder(){
        EntityManager em = JPAUtils.getEntityManager();
        EntityTransaction tx = em.getTransaction();
        tx.begin();
        String jpql = "from XOX order by xoxID desc";
        Query query = em.createQuery(jpql);
        List list = query.getResultList();
        for(Object obj : list){
            System.out.println(obj);
        }
        tx.commit();
        em.close();
    }

    @Test
    public void testFindCount(){
        EntityManager em = JPAUtils.getEntityManager();
        EntityTransaction tx = em.getTransaction();
        tx.begin();
        String jpql = "select count(xoxName) from XOX";
        Query query = em.createQuery(jpql);
        System.out.println(query.getSingleResult());
        tx.commit();
        em.close();
    }

    @Test
    public void testFindPaged(){
        EntityManager em = JPAUtils.getEntityManager();
        EntityTransaction tx = em.getTransaction();
        tx.begin();
        String jpql = "from XOX";
        Query query = em.createQuery(jpql);
        query.setFirstResult(0);
        query.setMaxResults(2);
        List list = query.getResultList();
        for(Object obj : list){
            System.out.println(obj);
        }
        tx.commit();
        em.close();
    }

    @Test
    public void testFindCondition(){
        EntityManager em = JPAUtils.getEntityManager();
        EntityTransaction tx = em.getTransaction();
        tx.begin();
        String jpql = "from XOX where xoxName like ?";
        Query query = em.createQuery(jpql);
        query.setParameter(1,"张%");
        List list = query.getResultList();
        for(Object obj : list){
            System.out.println(obj);
        }
        tx.commit();
        em.close();
    }
}
