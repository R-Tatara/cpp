#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "unistd.h"

#define IP_ADDRESS "192.168.11.2"
#define BUFFER_SIZE_REQUEST 256
#define BUFFER_SIZE_RESPONSE 256

int main() {
  struct sockaddr_in dstAddr;
  
  int cycle = 0;
  int dstSocket;
  int status;
  int numrcv;
  int numsnt;
  unsigned short port = 9800;
  char destination[80] = IP_ADDRESS;
  char request[BUFFER_SIZE_REQUEST];
  char response[BUFFER_SIZE_RESPONSE];
  float x = 3.0F;
  float y = 4.0F;
  float z;
  float w;

  memset(&dstAddr, 0, sizeof(dstAddr));
  dstAddr.sin_port = htons(port);
  dstAddr.sin_family = AF_INET;
  dstAddr.sin_addr.s_addr = inet_addr(destination);
  dstSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (connect(dstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr))) {
    printf("%s cannot be connected.\n", destination);
    return -1;
  }

  while (cycle < 10) {
    sprintf(request, "%f, %f", x, y);
    numsnt = send(dstSocket, request, strlen(request) + 1, 0);

    numrcv = recv(dstSocket, response, strlen(response) + 1, 0);
    printf("%d, %c\n", numrcv, response); //Error
    //printf("%d response : %c\n", cycle, response);
    //scanf(response, "%f, %f", &z, &w);
    cycle++;
    usleep(50000); //0.05s
  }

  close(dstSocket);
  return 0;
}
