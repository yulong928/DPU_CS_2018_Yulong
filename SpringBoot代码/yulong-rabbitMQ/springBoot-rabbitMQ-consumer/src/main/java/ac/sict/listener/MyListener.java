package ac.sict.listener;


import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.stereotype.Component;

@Component
public class MyListener {

    @RabbitListener(queues = {"item_queue"})
    public void myListener1(String message){
        System.out.println("消费者接收到消息：" + message);
    }

}
