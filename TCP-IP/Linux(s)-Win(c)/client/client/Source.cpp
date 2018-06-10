//Client of TCP/IP communication
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma warning(disable:4996)

#define IP_ADDRESS "192.168.11.12"
#define BUFFER_SIZE_REQUEST 256
#define BUFFER_SIZE_RESPONSE 256

int main() {
	struct sockaddr_in dstAddr;
	
	int i;
	int cycle = 0;
	int dstSocket;
	int status;
	int numrcv;
	int numsnt;
	unsigned short port = 9800;
	char destination[80] = IP_ADDRESS;
	char request[BUFFER_SIZE_REQUEST];
	char response[BUFFER_SIZE_RESPONSE];
	float x = 1.0F;
	float y = 2.0F;
	float z;
	float w;

	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(port);
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(destination);
	dstSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(dstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr))) {
		printf("%s cannot be connected.\n", destination);
		getchar();
		return -1;
	}
	
	while (cycle < 10) {
		sprintf(request, "%f, %f", x, y);
		numsnt = send(dstSocket, request, strlen(request) + 1, 0);
		
		numrcv = recv(dstSocket, response, strlen(response) + 1, 0);
		i = sscanf_s(response, "%f, %f", &z, &w);
		printf("%d response : %f, %f\n", cycle, z, w);
		cycle++;
		Sleep(1);
	}
	
	closesocket(dstSocket);
	WSACleanup();
	getchar();
	return 0;
}