package ac.sict.work;

import ac.sict.utils.ConnectionUtil;
import com.rabbitmq.client.*;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

/*
* 使用简单模式的消费者接受消息
* */
public class Consumer2 {
    public static void main(String[] args) throws IOException, TimeoutException {
        Connection connection = ConnectionUtil.getConnection();
        final Channel channel = connection.createChannel();
        channel.queueDeclare(Producer.QUEUE_NAME,true,false,false,null);

        //每次可以预取多少个消息
        channel.basicQos(1);

        //创建消费者
        DefaultConsumer defaultConsumer = new DefaultConsumer(channel){
            @Override
            public void handleDelivery(String consumerTag, Envelope envelope, AMQP.BasicProperties properties, byte[] body) throws IOException {
                //重写方法尝试输出相关信息（路由key、交换机、消息id、接受到的消息）
                try {
                    System.out.println("路由key："+envelope.getRoutingKey());
                    System.out.println("消息id："+envelope.getDeliveryTag());
                    System.out.println("消费者2接收的消息内容："+new String(body,"utf-8"));
                    System.out.println("------------------------------------------------");
                    Thread.sleep(1000);
                    /*确认消息
                    * 参数1：消息id
                    * 参数2：是否确认，false表示只有当前消息被处理了*/
                    channel.basicAck(envelope.getDeliveryTag(),false);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };
        //队列监听(参数：队列名称、是否自动确认：消息接收到后自动向MQ应答，MQ将队列中删除消息、消费者)
        channel.basicConsume(Producer.QUEUE_NAME,true,defaultConsumer);

    }
}
