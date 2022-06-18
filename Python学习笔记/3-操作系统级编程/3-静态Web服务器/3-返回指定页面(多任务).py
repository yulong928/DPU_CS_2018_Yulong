import socket
import threading

def thread_for_server(new_socket):
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



def main():
    tcp_service_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    tcp_service_socket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,True)
    tcp_service_socket.bind(("",9000))
    tcp_service_socket.listen(128)
    while True:
        new_socket,ip_port = tcp_service_socket.accept()
        print(ip_port)
        sub_thread = threading.Thread(target=thread_for_server, args=(new_socket,))
        sub_thread.setDaemon(True)
        sub_thread.start()


if __name__ == '__main__':
    main()