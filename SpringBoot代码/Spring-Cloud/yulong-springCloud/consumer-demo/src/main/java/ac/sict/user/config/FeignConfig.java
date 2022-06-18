package ac.sict.user.config;

import feign.Logger;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;


@Configuration
public class FeignConfig {

    @Bean
    Logger.Level feignLoggerLevel(){
        //记录所有请求相应明细
        return Logger.Level.BASIC;
    }
}
