
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>

#define IP_TARGET "127.0.0.1"
#define G_BUF_LEN (1024+1)

BOOL bEnd = false;
WORD srcPort,dstPort;

struct Msg
{
	public:
		Msg() : seq(++G_SEQ) 
		{
			memset(buf, '\0', sizeof(char)*G_BUF_LEN);
		}
	public:
		static uint32_t G_SEQ;
		uint32_t seq;
		char buf[G_BUF_LEN];
};

unsigned char* marshal(const Msg* msg, unsigned char* buf)
{
	size_t bufLen = sizeof(uint32_t) + sizeof(unsigned char) * G_BUF_LEN;
	if(!buf)
		buf = new unsigned char[bufLen];
	unsigned char* pos = buf;

	memset(buf, '\0', bufLen);

	*(uint32_t*)pos = htonl(msg->seq);
	pos+=sizeof(uint32_t);

	memcpy((char*)pos, msg->buf, sizeof(char)*G_BUF_LEN);
	pos += sizeof(char)*G_BUF_LEN;

//	printf("[D] marshal : sndBuf[%d]=%s\n", sizeof(uint32_t), pos-G_BUF_LEN);

	pos = nullptr;

	return buf;
}

Msg* unmarshal(unsigned char* buf, Msg* msg = nullptr)
{
	if(!msg)
		msg = new Msg();
	unsigned char* pos = buf;

	// seq : uinit32_t
	memcpy(&msg->seq, pos, sizeof(uint32_t));
	msg->seq = ntohl(msg->seq);
	pos += sizeof(uint32_t);

	// buf : char[G_BUF_LEN]
	memset(msg->buf, '\0', G_BUF_LEN);
	memcpy(msg->buf, pos, sizeof(char)*G_BUF_LEN);
	pos += sizeof(char)*G_BUF_LEN;

//	printf("[D] : unmarshal : rcvbuf=%s, msg->buf[%d]=%s\n", pos-sizeof(char)*G_BUF_LEN,  strlen(msg->buf), msg->buf);

	pos = nullptr;

	return msg;
}


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
BOOL sendData(void* pParam, WORD wDstPort, unsigned char* sndBuf, size_t sndBufLen)
{
	SOCKET sock = *((SOCKET*)pParam);
	SOCKADDR_IN sendAddr = {0};
	Msg msg;
//	char buf[1024];
	int rc;

	sendAddr.sin_family = AF_INET;
	sendAddr.sin_port = htons(wDstPort);
	sendAddr.sin_addr.s_addr = inet_addr(IP_TARGET);

	memset(msg.buf, '\0', G_BUF_LEN);

	printf("[I] Enter Message : "); 
	fflush(stdout);
	fgets(msg.buf, G_BUF_LEN, stdin);

	if(msg.buf[0] == 'q' || msg.buf[0] == 'Q')
	{
		return false;
	}

	marshal(&msg, sndBuf);
	rc = sendto(sock, (char*)sndBuf, sndBufLen, 0, (SOCKADDR*)&sendAddr, sizeof(sendAddr));
	if(SOCKET_ERROR == rc)
	{
		printf("[E] sent bytes : %d, errno : %d\n", rc, WSAGetLastError());
	}

	return TRUE;
}


//DWORD WINAPI rcvTask(LPVOID pParam)
DWORD WINAPI rcvTask(void* pParam)
{
	SOCKET sock  = *((SOCKET*)pParam);
	SOCKADDR_IN recvAddr = {0};
	int iRet, iRecvSize;
	Msg msg;
	size_t bufLen = sizeof(uint32_t) + sizeof(char)*G_BUF_LEN;
	unsigned char* rcvBuf = new unsigned char[bufLen];
	unsigned char* sndBuf = new unsigned char[bufLen];
	while(!bEnd)
	{
		memset(msg.buf, '\0', G_BUF_LEN);
		iRecvSize = sizeof(recvAddr);
		memset(rcvBuf, '\0', sizeof(Msg));		
		iRet = recvfrom(sock, (char*)rcvBuf, sizeof(Msg), 0, (SOCKADDR*)&recvAddr, &iRecvSize);
		if(iRet == SOCKET_ERROR)
		{
			printf("[E] recvfrom failed : rc:%d,error code:%d\n", iRet, WSAGetLastError());
			continue;
		}

		//msg.buf[iRet] = '\0';
        if(srcPort != htons(recvAddr.sin_port))
        {
            printf("\n");
        }

		unmarshal((unsigned char*)rcvBuf, &msg);
		printf("[R] [%s:%d] : [%d]%s", inet_ntoa(recvAddr.sin_addr), htons(recvAddr.sin_port), msg.seq, msg.buf);
		fflush(stdout);

		if('?' == msg.buf[0])
		{
				msg.buf[0] = '!';
				marshal(&msg, sndBuf);
				iRet = sendto(sock, (char*)sndBuf, sizeof(msg), 0, (SOCKADDR*)&recvAddr, sizeof(recvAddr));
				if(iRet == SOCKET_ERROR)
				{
					printf("[E] sendto failed : rc:%d,error code:%d\n", iRet, WSAGetLastError());
				}
		}

	}

	printf("[I] Recv Thread End\n"); 	
	return 0;
}

uint32_t Msg::G_SEQ = 0;

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
	size_t sndBufLen = sizeof(uint32_t)+sizeof(char)*G_BUF_LEN;
	unsigned char* sndBuf = new unsigned char[sndBufLen];
	if(sock)
	{
		//HANDLE hThread = CreateThread(NULL, 0, rcvTask, (void*)sock, 0, NULL);
		std::thread recv = std::thread(rcvTask, &sock);

		while(1)
		{
			if(!sendData(&sock, wDstPort, sndBuf, sndBufLen))
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
