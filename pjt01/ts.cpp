#if 1


#include <iostream>
#include <cstdlib>

using namespace std;

void foo(int a) {}
void goo(int& a) { a = 0; }

template<typename F, typename A>
void lockAndCall(F f, A& a) {
	f(a);
}

template<typename F, typename A>
void lockAndCall(F f, const A& a) {
	f(a);
}

int main(int argc, char* argv[]) {
	int x = 10;

	lockAndCall(foo, 0);
	lockAndCall(goo, x);

	cout << x << endl;

	return EXIT_SUCCESS;
}

#endif



#if 0
// Server program 
#include <cerrno> 
#include <csignal> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 


#if ( defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__MINGW) )

#include <winsock2.h> 
#include <windows.h>
#include <ws2tcpip.h>

#else

#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 

#endif

#include <sys/types.h>

#include <iostream>
#include <vector>

#if 0

#define PORT 5000 
#define MAXLINE 1024 

int max(int x, int y) 
{ 
    if (x > y) 
        return x; 
    else
        return y; 
} 
int main(int argc, char* argv[]) 
{ 
    int listenfd, connfd, udpfd, nready, maxfdp1; 
    char buffer[MAXLINE]; 
    pid_t childpid; 
    fd_set rset; 
    ssize_t n; 
    socklen_t len; 
    const int on = 1; 
    struct sockaddr_in cliaddr, servaddr; 
    const char* message = "Hello Client"; 
    void sig_chld(int); 
  
    /* create listening TCP socket */
    listenfd = socket(AF_INET, SOCK_STREAM, 0); 
    memset(&servaddr, '\0',sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // binding server addr structure to listenfd 
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)); 
    listen(listenfd, 10); 
  
    /* create UDP socket */
    udpfd = socket(AF_INET, SOCK_DGRAM, 0); 
    // binding server addr structure to udp sockfd 
    bind(udpfd, (struct sockaddr*)&servaddr, sizeof(servaddr)); 
  
    // clear the descriptor set 
    FD_ZERO(&rset); 
  
    // get maxfd 
    maxfdp1 = max(listenfd, udpfd) + 1; 
    for (;;) { 
  
        // set listenfd and udpfd in readset 
        FD_SET(listenfd, &rset); 
        FD_SET(udpfd, &rset); 
  
        // select the ready descriptor 
        nready = select(maxfdp1, &rset, NULL, NULL, NULL); 
  
        // if tcp socket is readable then handle 
        // it by accepting the connection 
        if (FD_ISSET(listenfd, &rset)) { 
            len = sizeof(cliaddr); 
            connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &len); 
            if ((childpid = fork()) == 0) { 
                close(listenfd); 
                memset(buffer, '\0', sizeof(buffer)); 
                printf("[TC ] : "); 
                read(connfd, buffer, sizeof(buffer)); 
                puts(buffer); 
                write(connfd, (const char*)message, sizeof(buffer)); 
                close(connfd); 
                exit(EXIT_SUCCESS); 
            }
            close(connfd); 
        } 
        // if udp socket is readable receive the message. 
        if (FD_ISSET(udpfd, &rset)) { 
            len = sizeof(cliaddr); 
            memset(buffer, '\0', sizeof(buffer)); 
            printf("\n[UC] : "); 
            n = recvfrom(udpfd, buffer, sizeof(buffer), 0, 
                         (struct sockaddr*)&cliaddr, &len); 
            puts(buffer); 
            sendto(udpfd, (const char*)message, sizeof(buffer), 0, 
                   (struct sockaddr*)&cliaddr, sizeof(cliaddr)); 
        } 
    } 
} 

#endif


int initudp(int port)
{
    int sock;
    struct sockaddr_in servaddr;

    memset(&servaddr, '\0',sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(port); 

    sock = socket(AF_INET, SOCK_DGRAM, 0); 

    bind(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)); 

    return sock;
}

int handleServer(int port) 
{
    int BUF_LEN = 8192;
	int rdsocks, udpsock;
	//fd_set rdsocks, udpsock;
    int max, res;
    char* buff;

    struct sockaddr_in udpclient;
    int lenaddr;

	udpsock = initudp(port); //setup udp socket
	
	std::vector<SOCKET> tcpsocks;

	SOCKET tcpsock;
    buff = new char[BUF_LEN];

    memset(&udpclient, '\0',sizeof(udpclient)); 
    udpclient.sin_family = AF_INET; 
    udpclient.sin_addr.s_addr = htonl(INADDR_ANY); 
    udpclient.sin_port = htons(port); 

	
	while(1)
	{
	    FD_ZERO(&rdsocks);
	    FD_SET(udpsock, &rdsocks);
	    max = udpsock;
	
	    for(size_t i = 0; i < tcpsocks.size(); ++i)
	    {
	        tcpsock = tcpsocks[i];
	        FD_SET(tcpsock, &rdsocks);
	
	        if( tcpsock > udpsock )
	            max = tcpsock;
	    }
	
	    if( select(max+1, (fd_set*)&rdsocks, NULL, NULL, NULL) == SOCKET_ERROR )
	    {
	        perror("Select error");
	        WSACleanup();
	        return 1;
	    }
	
	    for(size_t i = 0; i < tcpsocks.size(); ++i) // loop on TCP sockets
	    {
	        tcpsock = tcpsocks[i];            
	        if( FD_ISSET(tcpsock, &rdsocks) )
	        {
	            printf("Socket %lld is ready \n", tcpsock);
	            // process tcp message
	        }
	    }
	
	    if( FD_ISSET(udpsock, &rdsocks) )
	    {
	        int ret = 0;
	        res = recvfrom(udpsock, buff, sizeof(buff), 0, (struct sockaddr*)&udpclient, &lenaddr);
            buff[res] = '\0';
            printf("recvfrom : %s:%lld, msg=%s\n", inet_ntoa(udpclient.sin_addr), htons(udpclient.sin_port), buff);
	        // process udp message...
//	        if( setup tcp connection is requested )
//	        {
//	            tcpsock = ...;
//	            if( tcpsock != INVALID_SOCKET )
//	                tcpsocks.push_back(tcpsock);
//	        }
	    }
	}
	
    return EXIT_SUCCESS;

}


#endif