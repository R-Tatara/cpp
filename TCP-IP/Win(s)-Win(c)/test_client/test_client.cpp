#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma warning(disable:4996)

struct sockaddr_in dstAddr;
WSADATA data;

class Client {
public :
	int dstSocket; //‘ŠŽèƒ|[ƒg”Ô†
	char IPaddr[32];
	char request[1024];
	char response[1024];
	Client();

	int InitClient(void) {
		WSAStartup(MAKEWORD(2, 0), &data);
		memset(&dstAddr, 0, sizeof(dstAddr));
		dstAddr.sin_port = htons(9800);
		dstAddr.sin_family = AF_INET;
		dstAddr.sin_addr.s_addr = inet_addr(this->IPaddr);
		this->dstSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (connect(this->dstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr))) {
			printf("%s‚ÉÚ‘±‚Å‚«‚Ü‚¹‚ñ‚Å‚µ‚½\n", this->IPaddr);
			return(-1);
		}
		return 0;
	}
};

Client::Client()
	: IPaddr{'1', '2', '7', '.', '0', '.', '0', '.', '1'}, 
	request{'0'}
{
}

Client client;

//Client of TCP/IP communication
int main() {
	int s;
	int res1 = 0;
	float res2 = 0.0F;
	
	client.InitClient();

	while (1) {
		//////////////////////////////////////////////////////
		send(client.dstSocket, client.request, 1024, 0); //Transmit packet
		recv(client.dstSocket, client.response, 1024, 0); //Receive packet
		s = sscanf_s(client.response, "%d, %f", &res1, &res2);
		printf("Request : %s, Response : %d, %f\n", client.request, res1, res2);
		//////////////////////////////////////////////////////
	}

	closesocket(client.dstSocket);
	WSACleanup();
	return 0;
}
