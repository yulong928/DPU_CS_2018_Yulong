package ac.sict.utils;

import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

public class ConnectionUtil {

    public static Connection getConnection() throws IOException, TimeoutException {
        //创建连接工厂
        ConnectionFactory connectionFactory = new ConnectionFactory();
        //设置主机、连接端口、虚拟主机、用户名、密码（默认为localhost:5672/guest/guest）
        connectionFactory.setHost("localhost");
        connectionFactory.setPort(5672);
        connectionFactory.setVirtualHost("/yulong");
        connectionFactory.setUsername("yulong");
        connectionFactory.setPassword("wangyanlei306");
        //创建链接
        Connection connection = connectionFactory.newConnection();
        return connection;
    }
}
