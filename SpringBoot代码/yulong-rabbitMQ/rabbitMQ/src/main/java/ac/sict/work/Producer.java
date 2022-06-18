package ac.sict.work;

import ac.sict.utils.ConnectionUtil;
import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

/*
    work工作队列模式用来发送消息
* */
public class Producer {
    static final String QUEUE_NAME = "simple_queue";

    public static void main(String[] args) throws IOException, TimeoutException {
        Connection connection = ConnectionUtil.getConnection();
        //创建频道
        Channel channel = connection.createChannel();
        //声明队列(参数：队列名称、指定是否定义持久化队列、是否独占本连接、是否在不使用的时候将队列自动删除、其他参数)
        channel.queueDeclare(QUEUE_NAME,true,false,false,null);
        //发送消息
        for (int i = 1; i<=30 ; i++){
            String message = "这是工作模式下的第" + i + "条消息";
            //参数：
            // 1、交换机名称（没有指定空字符串），
            // 2、队列路由key，简单模式使用队列名称
            // 3、消息其他属性
            // 4、消息内容
            channel.basicPublish("",QUEUE_NAME,null,message.getBytes());
            System.out.println("消息已经发送,内容为："+message);
        }
        //释放资源
        channel.close();
        connection.close();
    }
}
