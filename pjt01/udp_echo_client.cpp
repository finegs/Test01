#if 1

/*
	Simple udp client
*/
#include<stdio.h>

#ifdef _WIN32
#include<winsock2.h>
#else
#include<netinet/in.h> 
#include<sys/socket.h> 
#include<arpa/inet.h>
#endif

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SERVER "127.0.0.1"	//ip address of udp server
#define BUFLEN 512	//Max length of buffer
#define PORT 9099	//The port on which to listen for incoming data

int main(void)
{
	struct sockaddr_in si_other;
	int s, slen=sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa;

	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n");
	
	//create socket
	if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
	{
		printf("socket() failed with error code : %d" , WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	
	//setup address structure
	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);

	connect(s, (struct sockaddr*)&si_other, slen);

	//start communication
	while(1)
	{
		printf("Enter message : ");
		gets(message);
		
		//send the message
		if (sendto(s, message, strlen(message) , 0 , (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d" , WSAGetLastError());
			exit(EXIT_FAILURE);
		}
		
		//receive a reply and print it
		//clear the buffer by filling null, it might have previously received data
		memset(buf,0, BUFLEN);
		//try to receive some data, this is a blocking call
		// if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR)
		if (recv(s, buf, BUFLEN, 0) == SOCKET_ERROR)
		{
			printf("recvfrom() failed with error code : %d" , WSAGetLastError());
			exit(EXIT_FAILURE);
		}
		
		printf("<<%s\n", buf);
		// puts(buf);
	}

	closesocket(s);
	WSACleanup();

	return 0;
}

#endif

#if 0

#include<stdio.h>
#include<sys/types.h> 

#ifndef _WIN32
#include<netinet/in.h> 
#include<sys/socket.h> 
#include<arpa/inet.h>
#else
#include <winsock2.h>
#endif

#include<string.h> 
#include<unistd.h> 
#include<stdlib.h>

#define PORT 9909

int main(int argc,char *argv[]) {
    int sockfd,len;
    struct sockaddr_in serv,cliaddr;
    char buff[2000]; 
    if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0)
    {
        perror("ERROR creating socket");
        exit(0);
    }
    printf("UDP Client Socket Created Successfully.\n"); 
    memset(&serv,0,sizeof(serv)); 
    serv.sin_family=AF_INET; 
    serv.sin_port=htons(PORT);
    serv.sin_addr.s_addr=inet_addr(argv[1]);
    do
    {
        printf("Client : ");
        fgets(buff,sizeof(buff),stdin);
        if((sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&serv,sizeof(serv)))<0) {
            perror("ERROR IN SENDTO");
        }
        if(strcmp(buff,"exit:")==0) {
            exit(0);
        } 
        // strcpy(buff," ");
        memset(buff,'\0',2000);
        if((recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&cliaddr,&len))<0) {
            perror("ERROR IN RECVFROM"); 
            exit(0);
        }
        fputs("From Server : ",stdout); 
        fputs(buff,stdout); 

    } while(strcmp(buff," ")!=0);

    close(sockfd);

    return 0;
}

#endif
