/* CHANGES FROM UNIX VERSION                                                   */
/*                                                                             */
/* 1.  Changed header files.                                                   */
/* 2.  Added WSAStartUP().                                                     */
/* 3.  Used Sleep(3000) instead of sleep(3)                                    */
/* 4.  Used int instead of unsigned character for multicastTTL                 */
#if 0
#include <stdio.h>      /* for printf(), fprintf() */
#include <winsock.h>    /* for socket(),... */
#include <stdlib.h>     /* for exit() */
#endif

#include <cstdio>
#include <cstdlib>
#include <thread>
#ifdef _WIN32
#include <Winsock2.h>
#include <Ws2tcpip.h>
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#include <iostream>
#include <thread>
#include <queue>

using namespace std;

void DieWithError(const char *errorMessage);  /* External error handling function */

void handleRecv(int sock); /* Handle Receive */

int main(int argc, char *argv[])
{
    int sock;                         /* Socket */
    struct sockaddr_in multicastAddr; /* Multicast address */
    char *multicastIP;                /* IP Multicast address */
    unsigned short multicastPort;     /* Server port */
    char *sendString;                 /* String to multicast */
	char *recvString;
    int multicastTTL;                 /* TTL of multicast packets */
    unsigned int sendStringLen;       /* Length of string to multicast */
	unsigned int recvStringLen;
    WSADATA wsaData;                  /* Structure for WinSock setup communication */

    if ((argc < 4) || (argc > 5))     /* Test for correct number of parameters */
    {
        fprintf(stderr,"Usage:  %s <IP Address> <Port> <Send String> [<TTL>]\n", 
                 argv[0]);
        exit(1);
    }

    multicastIP = argv[1];            /* First arg:  Multicast IP address */ 
    multicastPort = atoi(argv[2]);    /* Second arg:  Multicast port */
    sendString = argv[3];             /* Third arg:  String to multicast */

    if (argc == 5)                     /* Is TTL specified on command-line? */
        multicastTTL = atoi(argv[4]);  /* Command-line specified TTL */
    else
        multicastTTL = 1;              /* Default TTL = 1 */

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) /* Load Winsock 2.0 DLL */
    {
        fprintf(stderr, "WSAStartup() failed");
        exit(1);
    }

    /* Create socket for sending/receiving datagrams */
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        DieWithError("socket() failed");

    /* Set TTL of multicast packet */
    if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, (char *) &multicastTTL, 
          sizeof(multicastTTL)) == SOCKET_ERROR)
        DieWithError("setsockopt() failed");

    /* Construct local address structure */
    memset(&multicastAddr, 0, sizeof(multicastAddr));   /* Zero out structure */
    multicastAddr.sin_family = AF_INET;                 /* Internet address family */
    multicastAddr.sin_addr.s_addr = inet_addr(multicastIP);/* Multicast IP address */
    multicastAddr.sin_port = htons(multicastPort);         /* Multicast port */

    sendStringLen = strlen(sendString);  /* Find length of sendString */

	/* start Receive Thread */
	std::thread recvHandler(handleRecv, sock);

    for (;;) /* Run forever */
    {
		printf("Send Msg : "); fflush(stdout);
		scanf("%[^\n]", sendString);
		getchar();
		if(strcmp(sendString, "exit") == 0) break;

    	sendStringLen = strlen(sendString);  /* Find length of sendString */

        /* Multicast sendString in datagram to clients every 3 seconds */
        if (sendto(sock, 
						sendString, 
						sendStringLen, 
						0, 
						(struct sockaddr *) &multicastAddr, 
						sizeof(multicastAddr)) != sendStringLen)
            DieWithError("sendto() sent a different number of bytes than expected");

#if AUTOSEND
#ifdef _WIN32
        Sleep(3000);
#else
		sleep(3);
#endif
#endif
    }

#ifdef _WIN32
WSACleanup();
#else
#endif
    /* NOT REACHED */
	return EXIT_SUCCESS;
}


void handleRecv(int sock)
{
	if(!sock) 
	{
        DieWithError("handleRecv return with error : socket is already closed");
		return;
	}

	int recvStringLen = 512;
	char* recvString = new char[recvStringLen];
	struct sockaddr_in svr_addr;
	int svr_addr_len;
	while(1)
	{
			if((recvStringLen = recvfrom(sock, 
											recvString, 
											recvStringLen, 
											0, 
											(struct sockaddr*)&svr_addr, 
											&svr_addr_len)) < 0)
			{
				DieWithError("recvfrom in handleRecv is failed, then DiewithError : ");
				break;
			}
			std::cout << "handleRecv : " << recvString << ", addr=" << inet_ntoa(svr_addr.sin_addr) << std::endl;
			if(strcmp("exit", recvString) == 0) break;
	}	
	delete[] recvString;
	recvString = nullptr;
}
