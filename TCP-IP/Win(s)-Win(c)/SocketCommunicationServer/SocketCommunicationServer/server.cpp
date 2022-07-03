#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

static const int SERVER_PORT = 9800;
static const int DATA_LENGTH = 1024;
static const int MAX_QUEUES = 1;

//Server for socket communication
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
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(serverSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr))) == SOCKET_ERROR) {
		puts("Failed to bind");
		return -1;
	}
	if (listen(serverSocket, MAX_QUEUES) ==  SOCKET_ERROR) {
		puts("Failed to bind");
		return -1;
	}

	struct sockaddr_in clientAddr;
	SOCKET clientSocket;
	int cycle = 0;
	int clientAddrSize = sizeof(clientAddr);
	int recvSize = -1;
	int sendSize = -1;
	char requestMsg[DATA_LENGTH];
	char responseMsg[DATA_LENGTH];

	while(1) {
		printf("Port %d is opened. Waiting client...\n", SERVER_PORT);
		clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddr, &clientAddrSize);
		if(clientSocket == INVALID_SOCKET) {
			closesocket(clientSocket);
			puts("Failed to accept");
			return -1;
		}

		while(1) {
			//Receive packet
			memset(requestMsg, 0, sizeof(requestMsg));
			recvSize = recv(clientSocket, requestMsg, sizeof(char) * DATA_LENGTH, 0);
			if (recvSize <= 0) {
				closesocket(clientSocket);
				printf("Disconnected...#%d\n", WSAGetLastError());
				break;
			}

			//Send packet
			memset(responseMsg, 0, sizeof(responseMsg));
			sprintf_s(responseMsg, "fuga[%d]", cycle);
			sendSize = send(clientSocket, responseMsg, sizeof(char) * DATA_LENGTH, 0);
			if (sendSize != sizeof(char) * DATA_LENGTH) {
				closesocket(clientSocket);
				printf("Send error...#%d\n", WSAGetLastError());
				break;
			}

			printf("Request : %s, Response : %s\n", requestMsg, responseMsg);
			cycle++;
		}
	}

	WSACleanup();
	return 0;
}