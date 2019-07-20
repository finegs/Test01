/* CHANGES FROM UNIX VERSION                                                   */
/*                                                                             */
/* 1.  Changed header files.                                                   */
/* 2.  Used WSAGetLastError() instead of perror().                             */ 

#include <iostream>
#include <cstdio>    /* for fprintf() */
#include <cstdlib>
#include <errno.h>

#ifdef _WIN32
    #ifndef _WIN32_WINNT 0x0501 // Windows XP 
    #endif
#include <winsock2.h>  /* for WSAGetLastError() */
#include <Ws2tcpip.h>
#else
#include <sys/socket.h> // Socket Header
#include <arpa/inet.h>  // Socket Inet
#include <netdb.h>      // Needed for getaddrinfo() and freeaddrinfo()
#include <unistd.h>     // Needed for close()
#endif

#include <cstdlib>   /* for exit() */
#include <cstring>
#include <string>
#include <functional>

#include "u.hpp"

bool T_IS_EXIT = false;
bool T_IS_DEBUG = true;

void DieWithError(const char *errorMessage)
{
#ifdef _WIN32
    fprintf(stderr,"%s: %d\n", errorMessage, WSAGetLastError());
#else
	if(errorMessage)
    	fprintf(stderr,"%s: %d\n", errorMessage, errno);
	else
//   	fprintf(stderr,"%s: %d\n", strerror(errno), errno);
//    	fprintf(stderr,"Socket Failed : %m\n");
    	perror("Socket Failed");
#endif
    exit(1);
}

int closeSocket(SOCKET sock)
{
	int status = 0;
#ifdef _WIN32
	status = shutdown(sock, SD_BOTH);
	if(status == 0) { status = closesocket(sock); }
#else
	status = shutdown(sock, SHUT_RDWR);
	if(status == 0) { status = close(sock); }
#endif

	return status;
}

int shutdown(SOCKET sock, int opt) {
	// TODO : shutdown should be implemented win/linux
	return 0;
}

struct Buffer* new_buffer(size_t data_len)
{
	struct Buffer* b = (struct Buffer*)malloc(sizeof(Buffer));

	b->data = malloc(data_len);
	b->size = data_len;
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

const size_t Packet::MaxDataSize = INITIAL_SIZE;

SerializedPacket::SerializedPacket() : senderId(-1), sequenceNumber(-1) {
    data = new char[Packet::MaxDataSize];
}

SerializedPacket::~SerializedPacket() {
    delete[] data;
    data = nullptr;
}

void* Packet::serialize()
{
	struct SerializedPacket* s = new SerializedPacket();
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

MyClz::MyClz() : id(""), value(""), desc("") {}
MyClz::MyClz(const std::string& _id, const std::string& value, const std::string& _desc) : id(_id), value(value), desc(_desc) {}
MyClz::MyClz(const MyClz& o) : id(o.id), value(o.value), desc(o.desc) {}
MyClz::MyClz(MyClz&& o) : id(std::move(o.id)), value(std::move(o.value)), desc(std::move(o.desc)) {}
MyClz& MyClz::operator=(const MyClz& o) {
      if(this==&o) return *this;
      id = o.id;
      value = o.value;
      desc = o.desc;
      return *this;
}

MyClz& MyClz::operator=(MyClz&& o) {
     if(this==&o) return *this;
     id = std::move(o.id);
     value = std::move(o.value);
     desc = std::move(o.desc);
     return *this;
}

void MyClz::setDesc(const std::string& newDesc) {
    desc = newDesc;
}

std::ostream& operator<<(std::ostream& os, const MyClz& o) {
    os << "{\"" << o.id << "\", \"" << o.value << "\", \"" << o.desc << "\"}";
    return os;
}

std::istream& operator>>(std::istream& is, MyClz& o) {
  is >> o.id >> o.value >> o.desc;
  return is;
}

struct	MyClz::MyClzComparator {
    bool operator() (const MyClz& a, const MyClz& b) const {
        return a.id < b.id;
    }
};

struct MyClz::MyClzHash {
	std::size_t operator() (const MyClz& o) const noexcept {
		return std::hash<std::string>{}(o.id);
	}
};

struct MyClz::MyClzEqual {
	bool operator() (const MyClz& a, const MyClz& b) const {
		return a.id == b.id;
	}
};


void MyClz::printCRUDUsage() {
	std::cout << "\t>> [I] Usage :  -qQeE : Quit/Exit, -iI : Insert, -dD : Delete, -pP : Print, -cC : Clear )" << std::endl;
}


void MyClz::testFibo(int n) {

	int x, y, z, cnt;

//	while(1) {
		cnt = 0;
		x = 0;
		y = 1;

		do {
			printf("[%d] : %d%s", cnt, x, (cnt % 5 == 0 ? "\n" : " ,"));
			z = x + y;
			x = y;
			y = z;
		} while(cnt++ < n);
//	}
}

std::ostream& operator<<(std::ostream& os, const My& o) {
	os << "(" << o.a << ", " << o.b << ", " << o.c << ")";
	return os;
}

std::istream& operator>>(std::istream& is, My& o) {
	is >> o.a >> o.b >> o.c;
	return is;
}

void cls() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

Door::Door(std::shared_ptr<Room> roomA, std::shared_ptr<Room> roomB) 
		: roomA(roomA), roomB(roomB) {
	roomA->door1 = roomB->door1 = std::shared_ptr<Door>(this);
}

World::World()
{
	auto newRoom = std::make_shared<Room>();
	rooms.insert(newRoom);
	auto anotherNewRoom = std::make_shared<Room>();
	rooms.insert(anotherNewRoom);

	new Door(newRoom, anotherNewRoom);
}

int World::doTest()
{
	World w;

	return 0;
}

// template<typename T>
// struct map_init_helper
// {
// 	T& data;
// 	map_init_helper(T& t) : data(d) {}
// 	map_init_helper& operator() (typename T::key_type const& Key, typename T:value_type const& value)
// 	{
// 		data[key] = value;
// 		return *this;
// 	}
// };

// template<typename T> map_init_helper<T> map_init(T& item)
// {
// 	return map_init_helper<T>(item);
// }
