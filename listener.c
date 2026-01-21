#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

//example: ./listener.exe 8443

int main(int argc, char *argv[]){

	argc = 1;
	int port = atoi(argv[1]);
	struct sockaddr_in server;
	int addrlen = sizeof(server);

	int s = socket(AF_INET, SOCK_STREAM, 0);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = INADDR_ANY;
	bind(s, (struct sockaddr *) &server, sizeof(server));
	
	listen(s, 3);
	printf("\t Waiting for a connection \n");

	int new_s = accept(s, (struct sockaddr *) &server, (socklen_t *) &addrlen);
	printf("\t the door is open, connection accepted \n");

    close(s);
    close(new_s);

	return 0;
}
