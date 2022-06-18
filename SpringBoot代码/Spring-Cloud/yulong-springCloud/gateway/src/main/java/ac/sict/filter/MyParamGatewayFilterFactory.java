package ac.sict.filter;

import lombok.Data;
import org.springframework.cloud.gateway.filter.GatewayFilter;
import org.springframework.cloud.gateway.filter.factory.AbstractGatewayFilterFactory;
import org.springframework.http.server.reactive.ServerHttpRequest;
import org.springframework.stereotype.Component;

import java.util.Arrays;
import java.util.List;

@Component
public class MyParamGatewayFilterFactory extends AbstractGatewayFilterFactory<MyParamGatewayFilterFactory.Config>{

    static final String PARAM_NAME="param";

    public MyParamGatewayFilterFactory() {
        super(Config.class);
    }

    public List<String> shortcutFieldOrder(){
        return Arrays.asList(PARAM_NAME);
    }

    @Override
    public GatewayFilter apply(Config config) {
        return (exchange, chain) -> {
            //获取请求参数中param对应参数名的参数值
            ServerHttpRequest request = exchange.getRequest();
            if (request.getQueryParams().containsKey(config.param)){
                request.getQueryParams().get(config.param).forEach(value -> System.out.printf("----局部过滤器----,%s=%s",config.param,value));
            }
            return chain.filter(exchange);
        };
    }

    @Data
    public static class Config{
        //对应在配置过滤器的时候指定的参数名
        private String param;
    }

}
