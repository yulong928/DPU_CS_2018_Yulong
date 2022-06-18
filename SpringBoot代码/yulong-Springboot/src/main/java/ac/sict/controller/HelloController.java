package ac.sict.controller;

import ac.sict.pojo.User;
import ac.sict.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import javax.sql.DataSource;

@RestController
public class HelloController {
    @Autowired
    private DataSource dataSource;

    @Autowired
    private UserService userService;

    @GetMapping("/user/{id}")
    public User queryById(@PathVariable Long id){
        return userService.queryById(id);
    }

    @GetMapping("hello")
    public String hello(){
        System.out.println("dataSource:" + dataSource);
        return "hello,spring boot!";
    }
}
