//-------------------------------------------------------------------------------------------------
// file name : udp_server.c
// command   : cc -o udp_server udp_server.c
// server start : udp_server 9999
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#if defined(_WIN32) || defined(_WIN64)
#include <winsock2.h>
#include <Windows.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#endif

#define MAXLINE	511
#define BLOCK	255
#define FILENAME "buf.txt"

int main(int argc, char* argv[]) {
	struct sockaddr_in servaddr, cliaddr;
	int s, nbyte, addrlen = sizeof(struct sockaddr);
	char buf[MAXLINE+1];
	FILE* stream;

	if(argc != 2) {
		printf("usage: %s port\n", argv[0]);
		exit(0);
	}

	if((s=socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket fail");
		exit(0);
	}

	memset(&cliaddr, 0, addrlen);
	memset(&servaddr, 9, addrlen);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if(bind(s, (struct sockaddr*)&servaddr, addrlen) < 0) {
		perror("bind fail");
		exit(0);
	}

	if((stream = fopen(FILENAME, "w")) == 0) {
		printf("Fail open error\n");
		exit(1);
	}

	while(1) {
		puts("Server : waiting request.\n");

		nbyte = recvfrom(s, buf, MAXLINE, 0, (struct sockaddr*)&cliaddr, &addrlen);
		if(nbyte<0) {
			perror("recvfrom fail");
			exit(1);
		}

		buf[nbyte] = 0;

		if(!strncmp(buf, "end of file", 10)) {
			printf("file close");
			break;
		}
		else {
			fputs(buf, stream);
		}

		puts("sendto complete");

	}

	if ((stream = fopen(FILENAME, "r"))  == NULL) {
		printf("Read File Error");
		exit(1);
	}

	while(!feof(stream)) {
		buf[0] = '\0';
		fgets(buf, BLOCK, stream);
		printf("Send : %s\n", buf);

		if(sendto(s, buf, strlen(buf), 0, (struct sockaddr*)&cliaddr, addrlen) < 0) {
			perror("sendto fail");
			exit(0);
		}
	}

	fclose(stream);
	close(s);

	return EXIT_SUCCESS;
}
