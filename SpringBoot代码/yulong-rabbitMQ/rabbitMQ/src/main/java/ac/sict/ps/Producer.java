package ac.sict.ps;

import ac.sict.utils.ConnectionUtil;
import com.rabbitmq.client.BuiltinExchangeType;
import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

/*
    work工作队列模式用来发送消息
* */
public class Producer {
    //交换机名称
    static final String FANOUT_EXCHANGE = "fanout_exchange";

    //队列名称
    static final String FANOUT_QUEUE_1 = "fanout_queue_1";
    static final String FANOUT_QUEUE_2 = "fanout_queue_2";

    public static void main(String[] args) throws IOException, TimeoutException {
        Connection connection = ConnectionUtil.getConnection();
        //创建频道
        Channel channel = connection.createChannel();
        //声明交换机(参数：交换机名称、交换机类型：fanout、direct、topic)
        channel.exchangeDeclare(FANOUT_EXCHANGE, BuiltinExchangeType.FANOUT);
        //声明队列(参数：队列名称、指定是否定义持久化队列、是否独占本连接、是否在不使用的时候将队列自动删除、其他参数)
        channel.queueDeclare(FANOUT_QUEUE_1,true,false,false,null);
        channel.queueDeclare(FANOUT_QUEUE_2,true,false,false,null);
        //队列绑定到交换机(参数：队列名称，交换机名称，路由key)
        channel.queueBind(FANOUT_QUEUE_1,FANOUT_EXCHANGE,"");
        channel.queueBind(FANOUT_QUEUE_2,FANOUT_EXCHANGE,"");
        //发送消息
        for (int i = 1; i<=10 ; i++){
            String message = "这是订阅模式下发给交换机的第 --" + i + "-- 条消息";
            //参数：
            // 1、交换机名称（没有指定空字符串），
            // 2、队列路由key，简单模式使用队列名称
            // 3、消息其他属性
            // 4、消息内容
            channel.basicPublish(FANOUT_EXCHANGE,"",null,message.getBytes());
            System.out.println("消息已经发送,内容为："+message);
        }
        //释放资源
        channel.close();
        connection.close();
    }
}
