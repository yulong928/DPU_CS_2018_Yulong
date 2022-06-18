package ac.sict.ps;

import ac.sict.utils.ConnectionUtil;
import com.rabbitmq.client.*;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

/*
* 使用订阅模式的消费者接受消息
* */
public class Consumer1 {
    public static void main(String[] args) throws IOException, TimeoutException {
        Connection connection = ConnectionUtil.getConnection();
        Channel channel = connection.createChannel();
        //声明交换机
        channel.exchangeDeclare(Producer.FANOUT_EXCHANGE,BuiltinExchangeType.FANOUT);
        //声明队列
        channel.queueDeclare(Producer.FANOUT_QUEUE_1,true,false,false,null);

        //创建消费者
        DefaultConsumer defaultConsumer = new DefaultConsumer(channel){
            @Override
            public void handleDelivery(String consumerTag, Envelope envelope, AMQP.BasicProperties properties, byte[] body) throws IOException {
                //重写方法尝试输出相关信息（路由key、交换机、消息id、接受到的消息）
                    System.out.println("路由key："+envelope.getRoutingKey());
                    System.out.println("消息id："+envelope.getDeliveryTag());
                    System.out.println("消费者1接受到的消息内容："+new String(body,"utf-8"));
                    System.out.println("------------------------------------------------");
            }
        };
        //队列监听(参数：队列名称、是否自动确认：消息接收到后自动向MQ应答，MQ将队列中删除消息、消费者)
        channel.basicConsume(Producer.FANOUT_QUEUE_1,true,defaultConsumer);

    }
}
