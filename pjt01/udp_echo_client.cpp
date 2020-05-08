#if 1

/*
	Simple udp client
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<thread>
#include<atomic>
#include<chrono>

#ifdef _WIN32
#include<winsock2.h>
#else
#include<netinet/in.h> 
#include<sys/socket.h> 
#include<arpa/inet.h>
#endif

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define DEFAULT_BUFLEN 512			//Default Max length of buffer
#define DEFAULT_SERVER_PORT 9099	//Default The port on which to listen for incoming data

using namespace std::chrono_literals;

const char DEFAULT_SERVER[128] = "127.0.0.1";

typedef struct Env_info_ {
	char* svr_addr;
	int svr_port;
	int buflen;
	struct sockaddr_in si_other;
	int sock;
	int slen;
	std::atomic_bool exit{false};

	WSADATA wsa;

} Env_info;

Env_info envinfo;
int init_env(int argc, char* argv[]);

int init_sock();
int create_sock();
int connect_sock();
int disconnect_sock();
int close_sock();
int dispose_sock();

int handle_recv();
int handle_usrinput();

int main(int argc, char** argv)
{
	init_env(argc, argv);

	init_sock();

	create_sock();

	connect_sock();

	std::thread receiver(handle_recv);
	std::thread handler(handle_usrinput);

	//start communication
	while(1) {
		if(envinfo.exit) break;
		std::this_thread::sleep_for(1s);
	}

	disconnect_sock();

	receiver.join();
	handler.join();

	close_sock();

	dispose_sock();

	return 0;
}

int init_env(int argc, char* argv[]) {
	envinfo.svr_addr = (char*)DEFAULT_SERVER;
	envinfo.svr_port = DEFAULT_SERVER_PORT;
	envinfo.slen = sizeof(envinfo.si_other);
	envinfo.buflen = 512;

	if(1<argc) {
		for(int i=1;i<argc;i++) {
			if('-' == *argv[i] && i+1<argc) {
				if(!strcmp("svr", argv[i+1]+1)) {
					envinfo.svr_addr = argv[i+1]+1; i++;
				}
				else if(!strcmp("svrport", argv[i+1]+1)) {
					envinfo.svr_port = atoi(argv[i+1]+1); i++;
				}
				else if(!strcmp("buflen", argv[i+1]+1)) {
					envinfo.buflen = atoi(argv[i+1]+1); i++;
				}
			}
		}
	}
	return 0;
}

int connect_sock() {

	if(!envinfo.sock) {
		printf("connect_sock: socket is not created\n");
		return 1;
	}
	//Connect
	connect(envinfo.sock, (struct sockaddr*)&envinfo.si_other, envinfo.slen);

	printf("connect_sock is executed. socket=%d\n", envinfo.sock);

	return 0;
}

int disconnect_sock() {
	return 0;
}

int init_sock() {

	WSADATA& wsa 			 = envinfo.wsa;

	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
		printf("Failed. Error Code : %d",WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n");
	
	return 0;
}

int dispose_sock() {
	WSACleanup();
	return 0;
}

int create_sock() {

	sockaddr_in& si_other	= envinfo.si_other;

	//create socket
	if ((envinfo.sock=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
	{
		printf("create_sock : socket() failed with error code : %d" , WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	
	//setup address structure
	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(envinfo.svr_port);
	si_other.sin_addr.S_un.S_addr = inet_addr(envinfo.svr_addr);

	printf("create_sock() is executed. [%s:%d]\n", envinfo.svr_addr, envinfo.svr_port);
	return 0;
}

int close_sock() {
	if(envinfo.sock) {
		closesocket(envinfo.sock);
		envinfo.sock = 0;
		printf("disconnect_sock is executed\n");
	}
	return 0;
}


int handle_usrinput() {

	int& s = envinfo.sock;
	int& slen = envinfo.slen;
	struct sockaddr_in& si_other = envinfo.si_other;

	char usrinbuf[envinfo.buflen];
	//start communication
	while(1) {
		printf("Enter message : ");
		gets(usrinbuf);

		if('-'==usrinbuf[0]) {
			if(!strcmp("exit", usrinbuf+1)) {
				printf("User Input: exit\n");
				envinfo.exit.store(true);
				disconnect_sock();
				break;
			}
		}
		else {
			
			//send the message
			// if (sendto(s, usrinbuf, strlen(usrinbuf), 0 ,(struct sockaddr *) &si_other, slen) == SOCKET_ERROR) {
			if (send(s, usrinbuf, strlen(usrinbuf), 0) == SOCKET_ERROR) {
				printf("sendto() failed with error code : %d" , WSAGetLastError());
				exit(EXIT_FAILURE);
			}
		}
	}

	return 0;
}

int handle_recv() {

	int& buflen = envinfo.buflen;
	int& s = envinfo.sock;

	char rcvbuf[envinfo.buflen];
	//start communication
	while(1)
	{
		//receive a reply and print it
		//clear the buffer by filling null, it might have previously received data
		memset(rcvbuf, 0, buflen);
		//try to receive some data, this is a blocking call
		// if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR)
		if (recv(s, rcvbuf, buflen, 0) == SOCKET_ERROR) {
			printf("recv() failed with error code : %d" , WSAGetLastError());
			exit(EXIT_FAILURE);
		}
		
		printf("<<%s\n", rcvbuf);
		// puts(buf);
	}

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
