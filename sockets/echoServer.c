#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc,char **argv){

  //int socket(int domain, int type, int protocol);
  int serverSocket=socket(AF_INET,SOCK_STREAM,0);

  struct sockaddr_in addr;
  addr.sin_family=AF_INET;
  addr.sin_port=htons(12345);
  addr.sin_addr.s_addr=INADDR_ANY;
  
  int connectionStatus=connect(serverSocket,
			       (struct sockaddr *) &addr,
			       sizeof(addr)
			       );
  if (connectionStatus==0) {
    printf ("connected to port 12345\n");
  }
  else{
    printf("error:%d\n",connectionStatus);
    return -1;
  }

  /** 
  //socket is now connected
  char serverResponse[256];
  recv(serverSocket,&serverResponse, sizeof(serverResponse), 0);
  
  //echo what was rx'ed into the buffer
  printf("%s\n", serverResponse);
  close(serverSocket);
  **/


  /** client

   **/
  bind(serverSocket,
       (struct sockaddr*) &addr,
       sizeof(addr)
       );

  int maxWaitingConnections=10;
  listen(serverSocket,maxWaitingConnections);

  int clientSocket=accept(serverSocket,NULL,NULL);

  send(clientSocket,"message",sizeof("message"),0);
  
  
  printf("end main()\n");
}

