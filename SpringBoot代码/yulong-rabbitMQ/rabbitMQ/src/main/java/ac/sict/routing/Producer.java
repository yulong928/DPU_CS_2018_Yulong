package ac.sict.routing;

import ac.sict.utils.ConnectionUtil;
import com.rabbitmq.client.BuiltinExchangeType;
import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

/*
    路由模式用来发送消息
* */
public class Producer {
    //交换机名称
    static final String DIRECT_EXCHANGE = "direct_exchange";

    //队列名称
    static final String DIRECT_QUEUE_INSERT = "direct_queue_insert";
    static final String DIRECT_QUEUE_UPDATE = "direct_queue_update";

    public static void main(String[] args) throws IOException, TimeoutException {
        Connection connection = ConnectionUtil.getConnection();
        //创建频道
        Channel channel = connection.createChannel();
        //声明交换机(参数：交换机名称、交换机类型：fanout、direct、topic)
        channel.exchangeDeclare(DIRECT_EXCHANGE, BuiltinExchangeType.DIRECT);
        //声明队列(参数：队列名称、指定是否定义持久化队列、是否独占本连接、是否在不使用的时候将队列自动删除、其他参数)
        channel.queueDeclare(DIRECT_QUEUE_INSERT,true,false,false,null);
        channel.queueDeclare(DIRECT_QUEUE_UPDATE,true,false,false,null);
        //队列绑定到交换机(参数：队列名称，交换机名称，路由key)
        channel.queueBind(DIRECT_QUEUE_INSERT, DIRECT_EXCHANGE,"insert");
        channel.queueBind(DIRECT_QUEUE_UPDATE, DIRECT_EXCHANGE,"update");
        //发送消息
        for (int i = 1; i<=10 ; i++){
            String KEY;
            if(i%3==0){
                KEY = "insert";
            }
            else {
                KEY = "update";
            }
            String message = "路由模式下发给交换机,key为 "+KEY+" 的第 --" + i + "-- 条消息";
            //参数：
            // 1、交换机名称（没有指定空字符串），
            // 2、队列路由key，简单模式使用队列名称
            // 3、消息其他属性
            // 4、消息内容
            channel.basicPublish(DIRECT_EXCHANGE,KEY,null,message.getBytes());
            System.out.println("消息已经发送,内容为："+message);
        }
        //释放资源
        channel.close();
        connection.close();
    }
}
