package ac.sict.service;

import ac.sict.mapper.UserMapper;
import ac.sict.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
public class UserService {

    @Autowired
    private UserMapper userMapper;

    public User queryById(Long id){
        return userMapper.selectByPrimaryKey(id);
    }

    @Transactional
    public void saveUser(User user){
        System.out.println("新增用户：" + user.toString());
        userMapper.insertSelective(user);
    }
}
