package ac.sict.user.service;

import ac.sict.user.mapper.UserMapper;
import ac.sict.user.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserService {

    @Autowired
    private UserMapper userMapper;

    public User queryId(Long id){
        return userMapper.selectByPrimaryKey(id);
    }

}
