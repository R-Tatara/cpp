#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

//Server of TCP/IP communication
int main() {
	struct sockaddr_in srcAddr;
	struct sockaddr_in dstAddr;
	
	int srcSocket;  // 自分ポート番号
	int dstSocket;  // 相手ポート番号
	int dstAddrSize = sizeof(dstAddr);
	int status;
	int numrcv;
	char request[1024];
	char response[1024] = "response";

	int res1 = 5;
	float res2 = 2.4;
	sprintf_s(response, "%d,%f", res1, res2);

	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);
	memset(&srcAddr, 0, sizeof(srcAddr));
	srcAddr.sin_port = htons(9876);
	srcAddr.sin_family = AF_INET;
	srcAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	srcSocket = socket(AF_INET, SOCK_STREAM, 0);
	bind(srcSocket, (struct sockaddr *) &srcAddr, sizeof(srcAddr));
	listen(srcSocket, 1);

	while (1) {
		printf("接続待ち\n");
		dstSocket = accept(srcSocket, (struct sockaddr *) &dstAddr, &dstAddrSize);

		while (1) {
			//printf("入力待ち\n");
			numrcv = recv(dstSocket, request, sizeof(char) * 1024, 0);
			if (numrcv == 0 || numrcv == -1) {
				status = closesocket(dstSocket);
				break;
			}

			//////////////////////////////////////////////////////

			printf("Response : %s\n", response);
			send(dstSocket, response, sizeof(char) * 1024, 0);
		}
	}

	WSACleanup();

	return(0);
}
