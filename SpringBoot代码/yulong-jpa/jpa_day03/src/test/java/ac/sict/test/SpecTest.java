package ac.sict.test;


import ac.sict.dao.XOXDao;
import ac.sict.domain.XOX;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.data.jpa.domain.Specification;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import javax.persistence.criteria.*;
import java.util.List;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = "classpath:applicationContext.xml")
public class SpecTest {

    @Autowired
    private XOXDao dao;

    @Test
    public void testSpec1(){
        Specification<XOX> spec = new Specification<XOX>() {
            public Predicate toPredicate(Root<XOX> root, CriteriaQuery<?> criteriaQuery, CriteriaBuilder criteriaBuilder) {
                Path<Object> xoxName = root.get("xoxName");
                Predicate equal = criteriaBuilder.equal(xoxName, "宋昕冉");
                return equal;
            }
        };
        XOX one = dao.findOne(spec);
        System.out.println(one);
    }

    @Test
    public void testSpec2(){
        Specification<XOX> spec = new Specification<XOX>() {
            public Predicate toPredicate(Root<XOX> root, CriteriaQuery<?> criteriaQuery, CriteriaBuilder criteriaBuilder) {
                Path<Object> className = root.get("className");
                Path<Object> team = root.get("team");
                Predicate value1 = criteriaBuilder.equal(className, "SNH48 四期生");
                Predicate team_x = criteriaBuilder.equal(team, "TEAM X");
                //条件的组合
                Predicate or = criteriaBuilder.or(value1, team_x);
                return or;
            }
        };
        List<XOX> all = dao.findAll(spec);
        for (XOX xox : all){
            System.out.println(xox);
        }
    }

    @Test
    public void testSpec3(){
        Specification<XOX> spec = new Specification<XOX>() {
            public Predicate toPredicate(Root<XOX> root, CriteriaQuery<?> criteriaQuery, CriteriaBuilder criteriaBuilder) {
                Path<Object> className = root.get("className");
                Path<Object> team = root.get("team");
                Predicate value1 = criteriaBuilder.like(className.as(String.class),"BEJ48%");
                Predicate team_x = criteriaBuilder.equal(team, "TEAM NII");
                //条件的组合
                Predicate or = criteriaBuilder.and(value1, team_x);
                return or;
            }
        };
        List<XOX> all = dao.findAll(spec);
        for (XOX xox : all){
            System.out.println(xox);
        }
    }

    @Test
    public void testSpec4(){
        Specification<XOX> spec = new Specification<XOX>() {
            public Predicate toPredicate(Root<XOX> root, CriteriaQuery<?> criteriaQuery, CriteriaBuilder criteriaBuilder) {
                Path<Object> className = root.get("className");
                Path<Object> team = root.get("team");
                Predicate value1 = criteriaBuilder.like(className.as(String.class),"BEJ48%");
                Predicate team_x = criteriaBuilder.equal(team, "TEAM NII");
                //条件的组合
                Predicate or = criteriaBuilder.and(value1, team_x);
                return or;
            }
        };
        Sort sort = new Sort(Sort.Direction.DESC,"xoxID");
        List<XOX> all = dao.findAll(spec,sort);
        for (XOX xox : all){
            System.out.println(xox);
        }
    }

    @Test
    public void testSpec5(){
        Pageable pageable = new PageRequest(0,10);
        Page<XOX> all = dao.findAll(null, pageable);
        System.out.println(all.getTotalElements());
        System.out.println(all.getTotalPages());
    }
}
