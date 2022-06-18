import socket
import threading
import sys

class HttpWebServer():
    def __init__(self,port):
        tcp_server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        tcp_server_socket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,True)
        tcp_server_socket.bind(("",port))
        tcp_server_socket.listen(128)
        self.tcp_server_socket = tcp_server_socket

    #处理客户端的请求
    @staticmethod
    def handle_client_request(new_socket):
        recv_client_data = new_socket.recv(4096)
        if len(recv_client_data) == 0:
            print("客户端连接失败")
            new_socket.close()
            return
        recv_client_context = recv_client_data.decode("utf-8")
        request_list = recv_client_context.split(" ", maxsplit=2)
        request_path = request_list[1]
        if request_path == "/":
            request_path = "index.html"
        else:
            request_path_list = request_path.split("/", maxsplit=1)
            request_path = request_path_list[1]
        try:
            with open(request_path, "rb") as file:
                file_data = file.read()
        except Exception as e:
            responce_line = "HTTP/1.1 404 Not Found\r\n"
            responce_header = "Server:PWS1.0\r\n"
            with open("error.html", "rb") as file:
                file_data = file.read()
            responce_body = file_data
            responce_data = (responce_line + responce_header + "\r\n").encode("utf-8") + responce_body
            new_socket.send(responce_data)
        else:
            responce_line = "HTTP/1.1 200 OK\r\n"
            responce_header = "Server:PWS1.0\r\n"
            responce_body = file_data
            responce_data = (responce_line + responce_header + "\r\n").encode("utf-8") + responce_body
            new_socket.send(responce_data)
        finally:
            new_socket.close()

    def start(self):
        while True:
            new_socket, ip_port = self.tcp_server_socket.accept()
            print(ip_port)
            sub_thread = threading.Thread(target=self.handle_client_request, args=(new_socket,))
            sub_thread.setDaemon(True)
            sub_thread.start()

def main():
    print(sys.argv)
    if len(sys.argv) != 2:
        print("执行如下命令：python3 xxx.py 8000")
        return
    if not sys.argv[1].isdigit():
        print("执行如下命令：python3 xxx.py 8000")
        return
    port = int(sys.argv[1])
    web_server = HttpWebServer(port)
    web_server.start()

if __name__ == '__main__':
    main()