package ac.sict.user.controller;

import com.netflix.hystrix.contrib.javanica.annotation.DefaultProperties;
import com.netflix.hystrix.contrib.javanica.annotation.HystrixCommand;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.discovery.DiscoveryClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

@RestController
@RequestMapping("/consumer")
@Slf4j
@DefaultProperties(defaultFallback = "defaultFallback")
public class ConsumerController {

    @Autowired
    private RestTemplate restTemplate;

    @Autowired
    private DiscoveryClient discoveryClient;

    @GetMapping("/{id}")
//    @HystrixCommand(fallbackMethod = "queryByIdFallback")
    @HystrixCommand
    public String queryById(@PathVariable Long id){

        if(id==1){
            throw new RuntimeException("系统正忙！");
        }
        //获取Eureka中注册的user-service实例
//        String url;
//        List<ServiceInstance> instances = discoveryClient.getInstances("user-service");
//        ServiceInstance serviceInstance = instances.get(0);
//        url = "http://"+serviceInstance.getHost()+":"+serviceInstance.getPort() + "/user/" + id;
//        User forObject = restTemplate.getForObject(url, User.class);

        //使用负载均衡获取服务地址
        String url = "http://user-service/user/" + id;
        return restTemplate.getForObject(url,String.class);
    }

    public String queryByIdFallback(Long id){
        log.error("查询用户信息失败！id:{}",id);
        return "对不起，网络拥挤";
    }

    public String defaultFallback(){
        log.error("默认提示：查询用户信息失败！");
        return "默认提示：对不起，网络拥挤";
    }
}
