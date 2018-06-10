//Server of TCP/IP communication
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma warning(disable:4996)

#define BUFFER_SIZE_REQUEST 256
#define BUFFER_SIZE_RESPONSE 256

int main() {
	struct sockaddr_in srcAddr;
	struct sockaddr_in dstAddr;
	
	int i;
	int cycle = 0;
	int srcSocket;
	int dstSocket;
	int status;
	int numrcv;
	int numsnt;
	int dstAddrSize = sizeof(dstAddr);
	unsigned short port = 9800;
	char request[BUFFER_SIZE_REQUEST];
	char response[BUFFER_SIZE_RESPONSE];
	float x;
	float y;
	float z = 3.0F;
	float w = 4.0F;

	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);
	memset(&srcAddr, 0, sizeof(srcAddr));
	srcAddr.sin_port = htons(port);
	srcAddr.sin_family = AF_INET;
	srcAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	srcSocket = socket(AF_INET, SOCK_STREAM, 0);
	bind(srcSocket, (struct sockaddr *) &srcAddr, sizeof(srcAddr));
	listen(srcSocket, 1);
	printf("Accepting.\n");

	while (1) {
		dstSocket = accept(srcSocket, (struct sockaddr *) &dstAddr, &dstAddrSize);
		while (1) {
			numrcv = recv(dstSocket, request, BUFFER_SIZE_REQUEST, 0);
			if (numrcv == 0 || numrcv == -1) {
				status = closesocket(dstSocket);
				break;
			}

			i = sscanf_s(request, "%f, %f", &x, &y);
			printf("%d request : %f, %f\n", cycle, x, y);

			sprintf(response, "%f, %f", z, w);
			numsnt = send(dstSocket, response, strlen(response) + 1, 0);
			cycle++;
		}
	}
	
	
	WSACleanup();
	return 0;
}