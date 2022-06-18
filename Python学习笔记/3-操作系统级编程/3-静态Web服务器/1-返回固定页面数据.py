import socket
if __name__ == '__main__':
    tcp_server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    tcp_server_socket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,True)
    tcp_server_socket.bind(("",9000))
    tcp_server_socket.listen(128)
    while True:
        new_socket,ip_port = tcp_server_socket.accept()
        recv_client_data = new_socket.recv(4096)
        print(recv_client_data.decode("utf-8"))
        with open("index.html","rb") as file:
            file_data = file.read()
        response_line = "HTTP/1.1 200 OK\r\n"
        response_header = "Server:PWS1.0\r\n"
        response_body = file_data
        response_data = (response_line + response_header + "\r\n").encode("utf-8")+response_body
        new_socket.send(response_data)
        new_socket.close()