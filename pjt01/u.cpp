/* CHANGES FROM UNIX VERSION                                                   */
/*                                                                             */
/* 1.  Changed header files.                                                   */
/* 2.  Used WSAGetLastError() instead of perror().                             */ 

#include <stdio.h>    /* for fprintf() */
#include <winsock.h>  /* for WSAGetLastError() */
#include <stdlib.h>   /* for exit() */

#include <u.hpp>

void DieWithError(const char *errorMessage)
{
    fprintf(stderr,"%s: %d\n", errorMessage, WSAGetLastError());
    exit(1);
}

struct Buffer* new_buffer(size_t data_len = INITIAL_SIZE)
{
	struct Buffer* b = (struct Buffer*)malloc(sizeof(Buffer));

	b->data = malloc(INITIAL_SIZE);
	b->size = INITIAL_SIZE;
	b->next = 0;

	return b;
}

void reserve_space(Buffer* b, size_t bytes)
{
	if((b->next + bytes) > b->size)
	{
		b->data = realloc(b->data, b->size*2);
		b->size *= 2;
	}
}

void serialize_int(int x, Buffer* b)
{
	x = htonl(x);

	reserve_space(b, sizeof(int));

	memcpy(((char*)b->data) + b->next, &x, sizeof(int));
	b->next += sizeof(int);
}
	

void* Packet::serialize()
{
	struct *SerializedPacket* s = new SerializedPacket();
	s->senderId = htonl(this->senderId);
	s->sequenceNumber = htonl(this->sequenceNumber);
	memcpy(s->data, this->data, MaxDataSize);
	return s;
}

void Packet::deserialize(void* message)
{
	struct SerializedPacket* s =  (struct SerializedPacket*)message;
	this->senderId = ntohl(s->senderId);
	this->sequenceNumber = ntohl(s->sequenceNumber);
	memcpy(this->data, s->data, MaxDataSize);
}

