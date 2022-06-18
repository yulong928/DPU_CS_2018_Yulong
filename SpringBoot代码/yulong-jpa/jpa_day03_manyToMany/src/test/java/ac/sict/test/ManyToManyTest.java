package ac.sict.test;


import ac.sict.dao.RoleDao;
import ac.sict.dao.UserDao;
import ac.sict.domain.Role;
import ac.sict.domain.User;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.annotation.Rollback;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.transaction.annotation.Transactional;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = "classpath:applicationContext.xml")
public class ManyToManyTest {

    @Autowired
    private RoleDao roleDao;
    @Autowired
    private UserDao userDao;

    @Test
    @Transactional
    @Rollback(value = false)
    public void testAdd(){
        User user = new User();
        user.setUserName("小李");
        Role role = new Role();
        role.setRoleName("Java程序员");
        user.getRoles().add(role);
        role.getUsers().add(user);
        userDao.save(user);
        roleDao.save(role);
    }

}
