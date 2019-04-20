/* CHANGES FROM UNIX VERSION                                                   */
/*                                                                             */
/* 1.  Changed header files.                                                   */
/* 2.  Added WSAStartUP() and WSACleanUp().                                    */
/* 3.  Used closesocket() instead of close().                                  */ 

#include <stdio.h>      /* for printf(), fprintf() */
#if _WIN32
#include <Winsock2.h>
#include <Ws2tcpip.h>
#include <Windows.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#endif

#include <iostream>
#include <string>
#include <cstdlib>     /* for exit() */
#include <queue> 		/* Priority Queue to send */
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <thread>

#define MAXRECVSTRING 255  /* Longest string to receive */

using namespace std;
using namespace std::literals::chrono_literals;

void DieWithError(const char *errorMessage);  /* External error handling function */
void handle_recv(int sock);					  /* Handle Receive */
void handle_send(int sock);							  /* Handle Send Quee */

namespace my
{
	class Msg
	{
		public:
			Msg(const std::string& _msg, struct sockaddr_in* _from_addr) 
					: msg(_msg), from_addr(_from_addr) {}
			~Msg() 
			{
				delete from_addr;
				from_addr = nullptr;
			}
			Msg(const my::Msg& _msg) : msg(_msg.msg), from_addr(_msg.from_addr) {}
			Msg(const my::Msg&& _msg)  : msg(std::move(_msg.msg)), from_addr(std::move(_msg.from_addr)) {}

			Msg& operator=(Msg& o)
			{
				if(this==&o) return *this;
				msg = o.msg;
				from_addr = o.from_addr;
				return *this;
			}
			Msg& operator=(Msg&& o)
			{
				if(this==&o) return *this;
				msg = std::move(o.msg);
				from_addr = std::move(o.from_addr);
				return *this;
			}
			const std::string& getCMsg() const { return msg; }
			struct sockaddr_in* getFromAddr() const { return from_addr; }

		private:
			std::string msg;
			struct sockaddr_in* from_addr;
	};
}
std::priority_queue<my::Msg*> sendQueue;
std::mutex sendQueueMtx;
std::condition_variable sendQueueCV;
void pushSendQueue(my::Msg* msg);
my::Msg* popSendQueue();

int main(int argc, char *argv[])
{
    int sock;                         /* Socket */
    sockaddr_in multicastAddr; /* Multicast Address */
    char *multicastIP;                /* IP Multicast Address */
    unsigned short multicastPort;     /* Port */
//	char recvString[MAXRECVSTRING+1]; /* Buffer for received string */
//  unsigned int recvStringLen;       /* Length of received string */
    ip_mreq multicastRequest;  /* Multicast address join structure */
    WSADATA wsaData;                  /* Structure for WinSock setup communication */

    if (argc != 3)    /* Test for correct number of arguments */
    {
        fprintf(stderr,"Usage: %s <Multicast IP> <Multicast Port>\n", argv[0]);
        exit(1);
    }

    multicastIP = argv[1];        /* First arg: Multicast IP address (dotted quad) */
    multicastPort = atoi(argv[2]);/* Second arg: Multicast port */

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) /* Load Winsock 2.2 DLL */
    {
        fprintf(stderr, "WSAStartup() failed");
        exit(1);
    }

    /* Create a best-effort datagram socket using UDP */
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        DieWithError("socket() failed");

    /* Construct bind structure */
    memset(&multicastAddr, 0, sizeof(multicastAddr));   /* Zero out structure */
    multicastAddr.sin_family = AF_INET;                 /* Internet address family */
    multicastAddr.sin_addr.s_addr = htonl(INADDR_ANY);  /* Any incoming interface */
    multicastAddr.sin_port = htons(multicastPort);      /* Multicast port */

    /* Bind to the multicast port */
    if (bind(sock, (sockaddr *) &multicastAddr, sizeof(multicastAddr)) < 0)
        DieWithError("bind() failed");

    /* Specify the multicast group */
    multicastRequest.imr_multiaddr.s_addr = inet_addr(multicastIP);
    /* Accept multicast from any interface */
    multicastRequest.imr_interface.s_addr = htonl(INADDR_ANY);
    /* Join the multicast address */
    //if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *) &multicastRequest, sizeof(multicastRequest)) < 0)
    //if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, multicastIP, sizeof(multicastRequest)) < 0)
    if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*)&multicastRequest, sizeof(multicastRequest)) < 0)
        DieWithError("setsockopt() failed");

	std::thread send_worker(handle_send, sock);
	std::thread recv_worker(handle_recv, sock);

	sockaddr_in addr;
	int addrlen = sizeof(addr);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(multicastPort);

	std::string recvString;

	while(1)
	{
		recvString.clear();

		std::cout << "Server Msg : "; 
		std::cout.flush();
		std::cin >> recvString;

	//    recvString[recvStringLen] = '\0';
		std::cout << "Your Msg : " << recvString << std::endl;    /* Print the received string */

		my::Msg* m = new my::Msg(recvString.c_str(), NULL);
		pushSendQueue(m);
	}
    
    closesocket(sock);
    WSACleanup();   /* Cleanup Winsock */

    exit(0);
}

void handle_recv(int sock)
{
	if(!sock) 
	{
        DieWithError("SVR : handleRecv return with error : socket is already closed");
		return;
	}
	int recvStringLen = 512;
	char* recvString = new char[recvStringLen];

	while(1)
	{
			struct sockaddr_in* cli_addr;
			int cli_addr_len = 0;
			if(NULL == (cli_addr = (struct sockaddr_in*)malloc(cli_addr_len = sizeof(struct sockaddr_in))))
			{
        		DieWithError("SVR : handleRecv return with error : fail to malloc sizeof(struct sockaddr_in)");
				return;
			}	
			if((recvStringLen = recvfrom(sock, recvString, recvStringLen, 0, 
											(struct sockaddr*)cli_addr, &cli_addr_len)) < 0)
			{
				DieWithError("SVR : recvfrom in handleRecv is failed, then DiewithError : ");
				break;
			}
			printf("SVR : handleRecv : %s, client=%s\n", recvString, inet_ntoa(cli_addr->sin_addr));
			// Check 'exit' command from client
			if(strcmp("exit", recvString) == 0) break;

			my::Msg* m = new my::Msg(recvString, cli_addr);
			pushSendQueue(m);
	}	
	delete[] recvString;
	recvString = nullptr;
}

void handle_send(int sock)
{
	while(1)
	{
		int msgLen;
		my::Msg* msg = popSendQueue();
		if(!msg) continue;
       	if (sendto(sock, 
						msg->getCMsg().c_str(),
					   	msgLen = strlen(msg->getCMsg().c_str()), 
						0, 
						(struct sockaddr*)msg->getFromAddr(), 
						 sizeof(msg->getFromAddr())) != msgLen)
		{
        	DieWithError("sendto() sent a different number of bytes than expected");
		}
		delete msg;
		msg = nullptr;
	}
}

void pushSendQueue(my::Msg* msg)
{
	std::unique_lock<std::mutex> lck(sendQueueMtx);
	sendQueue.push(msg);
	sendQueueCV.notify_one();	
}

my::Msg* popSendQueue()
{
	std::unique_lock<std::mutex> lck(sendQueueMtx);
	while(sendQueue.empty()) 
	{
		sendQueueCV.wait_for(lck, 100ms);
	}
	my::Msg* m = sendQueue.top();
	sendQueue.pop();
	return m;
}
