// socket就像是一个接口，客户端需要先创建接口，然后监听接口通信
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{	
	// 1 创建套接字
	int socketfd = socket(AF_INET, SOCK_STREAM, 0); // 网络协议族 TCP连接
	if (socketfd == -1)
	{
		std::cout << "客户端 socket 创建失败 \n";
	}
	
	// 2 通过套接字连接到服务器
	struct sockaddr_in server;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(10086);
	if (connect(socketfd, (struct sockaddr *)(&server), sizeof(server)) < 0)// 向服务器发送第一次握手请求，并收到服务器的请求确认后，完成三次握手流程
	{
		std::cout << "连接服务器失败 \n";
	}

	// 3 发送消息给服务器
	std::string message = "Hello From 客户端";
	send(socketfd, message.data(), message.size(), 0);

	// 4 接受来自服务器的响应
	char response[100];
	read(socketfd, response, sizeof(response));
	std::cout << "服务器说:" << response << '\n';

	std::cout << "通信结束 \n";
	close(socketfd);
}
