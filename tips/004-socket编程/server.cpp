#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class SimpleSocket
{
public:
	SimpleSocket(int address, int type, int protocol, int port): socketfd(socket(address, type, protocol))
	{
		server.sin_addr.s_addr = INADDR_ANY;// 监听本机的所有网卡
		server.sin_family = AF_INET;
		server.sin_port = htons(port);
		if (bind(socketfd, (struct sockaddr *)&server, sizeof(server)))
		{
			"";
		}
		
	}
private:
	int socketfd;
	
	struct sockaddr_in server;
	
};

int main()
{
	// 1 创建 socket
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	
	// 2 将 socket 绑定到某个端口
	struct sockaddr_in server;
	server.sin_addr.s_addr = INADDR_ANY;// 监听本机的所有网卡
	server.sin_family = AF_INET;
	server.sin_port = htons(10086);
	if (bind(socketfd, (struct sockaddr *)&server, sizeof(server)))
	{
		std::cout << "绑定失败 \n";
	}

	// 3 监听端口
	listen(socketfd, 3);

	// 4 接受连接，得到新的 socket 描述符
	int address_len = sizeof(server);
	int new_socketfd = accept(socketfd, (struct sockaddr *)&server, (socklen_t *)&address_len);//接受客户端的连接请求，然后向客户端发送请求确认消息，服务器的三次握手流程完成

	// 5 读取来自客户端的消息
	char response[100] = {};
	read(new_socketfd, response, sizeof(response)); 
	std::cout << "客户端说:" << response << '\n';	

	// 6 向客户端发送消息
	char message[] = "Hello from Server";
	send(new_socketfd, message, sizeof(message), 0);

	close(socketfd);
	close(new_socketfd);
}
