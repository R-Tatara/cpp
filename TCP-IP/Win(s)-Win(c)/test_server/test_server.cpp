#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

struct sockaddr_in srcAddr;
struct sockaddr_in dstAddr;
WSADATA data;

class Server {
public : 
	int srcSocket;  // 自分ポート番号
	int dstSocket;  // 相手ポート番号
	int dstAddrSize;
	int status;
	int numrcv;
	char request[1024];
	char response[1024];
	Server();

	int InitServer(void) {
		WSAStartup(MAKEWORD(2, 0), &data);
		memset(&srcAddr, 0, sizeof(srcAddr));
		srcAddr.sin_port = htons(9800);
		srcAddr.sin_family = AF_INET;
		srcAddr.sin_addr.s_addr = htonl(INADDR_ANY);
		this->srcSocket = socket(AF_INET, SOCK_STREAM, 0);
		bind(this->srcSocket, (struct sockaddr *) &srcAddr, sizeof(srcAddr));
		listen(this->srcSocket, 1);
		printf("Connecting...\n");
		this->dstSocket = accept(this->srcSocket, (struct sockaddr *) &dstAddr, &this->dstAddrSize);
		return 0;
	}
};

Server::Server()
	: dstAddrSize(sizeof(dstAddr))
{
}

Server server;

//Server of TCP/IP communication
int main() {
	int res1 = 0;
	float res2;

	server.InitServer();

	while (1) {
		//////////////////////////////////////////////////////
		res1++;
		res2 = 0.0F;
		server.numrcv = recv(server.dstSocket, server.request, sizeof(char) * 1024, 0);  //Receive packet
		if (server.numrcv == 0 || server.numrcv == -1) {
			server.status = closesocket(server.dstSocket);
			break;
		}

		sprintf_s(server.response, "%d, %f", res1, res2);
		printf("Request : %s, Response : %s\n", server.request, server.response);
		send(server.dstSocket, server.response, sizeof(char) * 1024, 0); //Transmit packet
		//////////////////////////////////////////////////////
	}

	WSACleanup();

	return 0;
}