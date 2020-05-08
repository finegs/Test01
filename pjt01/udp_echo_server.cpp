#if 1

/*
	Simple UDP Server
*/

#include<stdio.h>

#ifdef _WIN32
#include<winsock2.h>
#else
#include<netinet/in.h> 
#include<sys/socket.h> 
#include<arpa/inet.h>
#endif

// #pragma comment(lib,"ws2_32.lib") //Winsock Library

#define BUFLEN 512	//Max length of buffer
#define PORT 9099	//The port on which to listen for incoming data

int main()
{
	SOCKET s;
	struct sockaddr_in server, si_other;
	int slen , recv_len;
	char buf[BUFLEN];
	WSADATA wsa;

	slen = sizeof(si_other) ;
	
	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf(";Failed. Error Code : %d",WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n");
	
	//Create a socket
	if((s = socket(AF_INET , SOCK_DGRAM , 0 )) == INVALID_SOCKET)
	{
		printf(";Could not create socket : %d", WSAGetLastError());
	}
	printf(";Socket created.\n");
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( PORT );
	
	//Bind
	if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
	{
		printf(";Bind failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	puts(";Bind done");

	//keep listening for data
	while(1)
	{
		printf(";Waiting for data...");
		fflush(stdout);
		
		//clear the buffer by filling null, it might have previously received data
		memset(buf, 0, BUFLEN);
		
		//try to receive some data, this is a blocking call
		if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR)
		{
			printf(";recvfrom() failed with error code : %d" , WSAGetLastError());
			exit(EXIT_FAILURE);
		}
		
		//print details of the client/peer and the data received
		printf(";Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
		printf(";Data: %s\n", buf);
		
		//now reply the client with the same data
		if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR)
		{
			printf(";sendto() failed with error code : %d" , WSAGetLastError());
			exit(EXIT_FAILURE);
		}
	}

	closesocket(s);
	WSACleanup();
	
	return 0;
}

#endif 

#if 0

// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 

#ifndef _WIN32
	#include <sys/socket.h> 
	#include <arpa/inet.h> 
	#include <netinet/in.h> 
#else
	#include <winsock2.h>
#endif

#define PORT	 9099 
#define MAXLINE 1024 

// Driver code 
int main() { 
	int sockfd; 
	char buffer[MAXLINE]; 
	char hello[] = {"Hello from server"}; 
	struct sockaddr_in servaddr, cliaddr; 
	
	// Creating socket file descriptor 
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 
	
	// Bind the socket with the server address 
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
			sizeof(servaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	int len, n; 

	do {

		len = sizeof(cliaddr); //len is value/resuslt 
	
		n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
					MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
					&len); 
		buffer[n] = '\0'; 
		printf("Client : %s\n", buffer); 
		sendto(sockfd, (const char *)hello, strlen(hello), 
			// MSG_CONFIRM, (const struct sockaddr *) &cliaddr, 
			0, (const struct sockaddr *) &cliaddr, 
				len); 
		printf("Hello message sent.\n"); 
	
	} while(1);
	
	return 0; 
} 

#endif

#if 0

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#ifndef _WIN32
#include<netinet/in.h>
#include<sys/socket.h>
#else
#include <winsock2.h>
#endif

#define UDP_PORT 9909

int main(int argc, char** argv)
{
	int sockfd,n;
	struct sockaddr_in servaddr, cliaddr;
	int len;
	char mesg[1000];

	sockfd=socket(AF_INET, SOCK_DGRAM, 0); //UDP를 위한 소켓 생성

	//접속 되는 클라이언트를 위한 주소 설정 후 운영체제에 서비스 등록
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(UDP_PORT);
	bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	//클라이언트로부터 메시지를 받아 다시 클라이언트로 전송
	do
	{
		len=sizeof(cliaddr);
		n=recvfrom(sockfd, mesg, 1000, 0, (struct sockaddr *)&cliaddr, &len);
		sendto(sockfd, mesg, n, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));

		mesg[n]='\0';
		printf("Received data: %s\n", mesg);
	} while(!strlen(mesg));

	close(sockfd);

	return 0;
}

#endif


#if 0
#include<stdio.h> 
#include<sys/types.h> 
#ifndef _WIN32
#include<netinet/in.h>
#include<sys/socket.h> 
#else
#include <winsock2.h>
#endif
#include<string.h> 
#include<unistd.h> 
#include<stdlib.h>

#define PORT 9099

int main(int argc,char *argv[]) {
    char buf[2000];
    int sockfd,len,a;
    struct sockaddr_in servaddr,cliaddr;
    if((sockfd=socket(AF_INET, SOCK_DGRAM, 0))<0) {
        printf("Error creating socket, [%d]\n", sockfd); 
		return 0;
    }
    printf("UDP Server Socket Created Successfully.\n"); 

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(PORT); 
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY); 

    if(bind(sockfd,(struct sockaddr *)&servaddr, sizeof(servaddr))<0) {
        perror("Error binding socket."); 
        exit(0);
    }
    printf("UDP Server Socket Binded.\n"); 
    len=sizeof(cliaddr);

    do {
        strcpy(buf," "); 
        if((a=recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&cliaddr,&len))<0){
            perror("ERROR"); 
            exit(0);
        }
        printf("From Client : %s",buf); 
        if((sendto(sockfd,buf,a,0,(struct sockaddr *)&cliaddr,len))<0)
        {
            perror("NOTHING SENT"); 
            exit(0);
        }
        printf("Server : ");
        fgets(buf,sizeof(buf),stdin);

        if((sendto(sockfd,buf,a,0,(struct sockaddr *)&cliaddr,len))<0)
        {
            perror("NOTHING SENT"); 
            exit(0);
        }
    } while(strcmp(buf," ")!=0); 

    close(sockfd); 
    return 0;
}

#endif


