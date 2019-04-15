
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>

#define IP_TARGET "127.0.0.1"

BOOL bEnd = false;
WORD srcPort,dstPort;


SOCKET makeSocket(WORD wPort)
{
	SOCKET sock = (SOCKET)NULL;
    SOCKADDR_IN addr = {0};

    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sock == INVALID_SOCKET)
    {
        return (SOCKET)NULL;
    }

	addr.sin_family = AF_INET;
	addr.sin_port = htons(wPort);
	addr.sin_addr.s_addr = inet_addr(IP_TARGET);


	if(bind(sock, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		closesocket(sock);
		return (SOCKET)NULL;
	}
	return sock;
}

//BOOL sendData(SOCKET& sock, WORD wDstPort)
BOOL sendData(void* pParam, WORD wDstPort)
{
	SOCKET sock = *((SOCKET*)pParam);
	SOCKADDR_IN sendAddr = {0};
	char buf[1024];
	int rc;

	sendAddr.sin_family = AF_INET;
	sendAddr.sin_port = htons(wDstPort);
	sendAddr.sin_addr.s_addr = inet_addr(IP_TARGET);

	memset(buf, '\0', 1024);

	printf("[I] Enter Message : "); 
	fflush(stdout);
	fgets(buf, 1024, stdin);

	if(buf[0] == 'q' || buf[0] == 'Q')
		return false;

	rc = sendto(sock, buf, strlen(buf), 0, (SOCKADDR*)&sendAddr, sizeof(sendAddr));
	if(SOCKET_ERROR == rc)
	{
		printf("[E] sent bytes : %d, errno : %d\n", rc, WSAGetLastError());
	}
	
	return TRUE;
}


//DWORD WINAPI recvTask(LPVOID pParam)
DWORD WINAPI recvTask(void* pParam)
{
	SOCKET sock  = *((SOCKET*)pParam);
	SOCKADDR_IN recvAddr = {0};
	int iRet, iRecvSize;
	char buf[1024];
	while(!bEnd)
	{
		memset(buf, '\0', 1024);
		iRecvSize = sizeof(recvAddr);
		iRet = recvfrom(sock, buf, 1024, 0, (SOCKADDR*)&recvAddr, &iRecvSize);

		if(iRet == SOCKET_ERROR)
		{
			printf("[E] recvfrom failed : rc:%d,error code:%d\n", iRet, WSAGetLastError());
			continue;
		}

		buf[iRet] = '\0';
        if(srcPort != htons(recvAddr.sin_port))
        {
            printf("\n");
        }
		printf("[R] [%s:%d] : %s", inet_ntoa(recvAddr.sin_addr), htons(recvAddr.sin_port), buf);
		fflush(stdout);

		if('?' == buf[0])
		{
				buf[0] = '!';
				iRet = sendto(sock, buf, strlen(buf), 0, (SOCKADDR*)&recvAddr, sizeof(recvAddr));
				if(iRet == SOCKET_ERROR)
				{
					printf("[E] sendto failed : rc:%d,error code:%d\n", iRet, WSAGetLastError());
				}
		}

	}

	printf("[I] Recv Thread End\n"); 	
	return 0;
}

int main(int argc, char* argv[])
{
	WSAData wsData = {0};
	SOCKET sock;
	WORD wSrcPort, wDstPort;

	if(argc != 3)
	{
		printf("[I] Usage : uc [srcport] [dstport]\n");
		return EXIT_FAILURE;
	}

	wSrcPort = srcPort = (WORD)atoi(argv[1]);
	wDstPort = dstPort = (WORD)atoi(argv[2]);

	WSAStartup(MAKEWORD(2,2), &wsData);

	sock = makeSocket(wSrcPort);
	if(sock)
	{
		//HANDLE hThread = CreateThread(NULL, 0, recvTask, (void*)sock, 0, NULL);
		std::thread recv = std::thread(recvTask, &sock);

		while(1)
		{
			if(!sendData(&sock, wDstPort))
				break;
		}

		bEnd = TRUE;
		closesocket(sock);

//		if(WaitForSingleObject(hThread, 3000) == WAIT_TIMEOUT)
//		{
//			printf("Error : Thread end\n");
//			TerminateThread(hThread, 0);
//		}
		recv.join();
		printf("[I] Recv Thread is terminated\n");
	}

	WSACleanup();

	return EXIT_SUCCESS;
}
