import socket
import threading

def NLU(context):
    if context == "hello":
        return "hello"
    if context == "最近怎么样":
        return "还不错，隔离呢"
    if context == "老子吃火锅，你吃火锅底料":
        return "老子坐火车，你坐火车轨道"
    if context == "大连天气怎么样":
        return "你不是有Siri吗，问我干吗"
    if context == "我今天不想出门":
        return "你都快在寝室呆傻了"
    return "这个问题我不太懂"

def client_request(service_client_socket,ip_port):
    while True:
        recv_data = service_client_socket.recv(1024)
        if recv_data:
            context = recv_data.decode("gbk")
            print("接收到的消息是：",recv_data.decode("gbk"))
            send_context = NLU(context)
            service_client_socket.send(send_context.encode("gbk"))
        else:
            print("客户端已下线",ip_port)
            break
    service_client_socket.close()

if __name__ == '__main__':
    tcp_server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    tcp_server_socket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,True)
    tcp_server_socket.bind(("",9090))
    tcp_server_socket.listen(128)
    while True:
        service_client_socket,ip_port=tcp_server_socket.accept()
        print("客户端连接成功：",ip_port)
        sub_threading = threading.Thread(target=client_request,args=(service_client_socket,ip_port))
        sub_threading.setDaemon(True)
        sub_threading.start()