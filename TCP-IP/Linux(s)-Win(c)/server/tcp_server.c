#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE_REQUEST 256
#define BUFFER_SIZE_RESPONSE 256

int main() {
  struct sockaddr_in srcAddr;
  struct sockaddr_in dstAddr;

  int cycle = 0;
  int srcSocket; //Server socket
  int dstSocket; //Client socket
  int status;
  int numrcv;
  int dstAddrSize = sizeof(dstAddr);
  unsigned short port = 9800;
  char request[BUFFER_SIZE_REQUEST];
  char response[BUFFER_SIZE_RESPONSE];
  float x;
  float y;
  float z = 5.0F;
  float w = 6.0F;

  memset(&srcAddr, 0, sizeof(srcAddr));
  srcAddr.sin_port = htons(port);
  srcAddr.sin_family = AF_INET;
  srcAddr.sin_addr.s_addr = htonl(INADDR_ANY);

  srcSocket = socket(AF_INET, SOCK_STREAM, 0);
  bind(srcSocket, (struct sockaddr *) &srcAddr, sizeof(srcAddr));
  listen(srcSocket, 1);
  printf("Accepting.\n");

  while(1) {
    dstSocket = accept(srcSocket, (struct sockaddr *) &dstAddr, &dstAddrSize);
    while(1) {
      numrcv = recv(dstSocket, request, BUFFER_SIZE_REQUEST, 0); 
      if(numrcv == 0 || numrcv == -1) {
        status = close(dstSocket);
        break;
      }
      
      printf("%d request : %s\n", cycle, request);
      //scanf(request, "%f, %f", &x, &y);
      //printf("%d request : %f, %f", cycle, x, y);

      sprintf(response, "%f, %f", z, w);
      send(dstSocket, response, strlen(response) + 1, 0);
      cycle++;
    }
  }

  return 0;
}
