#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

static const char *serverIP = "192.168.11.110";
static const int SERVER_PORT = 9800;
static const int DATA_LENGTH = 1024;

int main() {
	WSADATA wsaData;
	struct sockaddr_in serverAddr;
	SOCKET serverSocket;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) { //winsock version 2.0
		puts("Failed to initialize winsock");
		return -1;
	}

	//Socket generation
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(serverSocket == INVALID_SOCKET) { //IPv4, TCP
		puts("Failed to generate socket");
		return -1;
	}

	//Assign a port number and IP address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET; //IPv4
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(serverIP); //Need SDL off
    //serverAddr.sin_addr.s_addr = inet_addr("192.168.11.110"); //Need SDL off
	if (connect(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr))) { //[CHECK]
		printf("Failed to connect %s\n", serverIP);
		return(-1);
	}

	int cycle = 0;
	int sendSize = -1;
	int recvSize = -1;
	char requestMsg[DATA_LENGTH];
	char responseMsg[DATA_LENGTH];

	while (1) {
		//Send packet
		memset(requestMsg, 0, sizeof(requestMsg));
		sprintf_s(requestMsg, "hoge[%d]", cycle);
		sendSize = send(serverSocket, requestMsg, sizeof(char) * DATA_LENGTH, 0);
		if (sendSize != sizeof(char) * DATA_LENGTH) {
			closesocket(serverSocket);
			printf("Send error...#%d\n", WSAGetLastError());
			break;
		}

		//Receive packet
		memset(responseMsg, 0, sizeof(responseMsg));
		recvSize = recv(serverSocket, responseMsg, sizeof(char) * DATA_LENGTH, 0);
		if (recvSize <= 0) {
			closesocket(serverSocket);
			printf("Disconnected...#%d\n", WSAGetLastError());
			break;
		}

		printf("Request : %s, Response : %s\n", requestMsg, responseMsg);
		cycle++;
	}

	closesocket(serverSocket);
	WSACleanup();
	return 0;
}