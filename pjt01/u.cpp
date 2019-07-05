/* CHANGES FROM UNIX VERSION                                                   */
/*                                                                             */
/* 1.  Changed header files.                                                   */
/* 2.  Used WSAGetLastError() instead of perror().                             */ 

#include <iostream>
#include <cstdio>    /* for fprintf() */
#include <winsock2.h>  /* for WSAGetLastError() */
#include <cstdlib>   /* for exit() */
#include <string>

#include "inc/u.hpp"

void DieWithError(const char *errorMessage)
{
    fprintf(stderr,"%s: %d\n", errorMessage, WSAGetLastError());
    exit(1);
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

MyClz::MyClz() : id(""), name(""), desc("") {}
MyClz::MyClz(const std::string& _id, const std::string& _name, const std::string& _desc) : id(_id), name(_name), desc(_desc) {}
MyClz::MyClz(const MyClz& o) : id(o.id), name(o.name), desc(o.desc) {}
MyClz::MyClz(MyClz&& o) : id(std::move(o.id)), name(std::move(o.name)), desc(std::move(o.desc)) {}
MyClz& MyClz::operator=(const MyClz& o) {
      if(this==&o) return *this;
      id = o.id;
      name = o.name;
      desc = o.desc;
      return *this;
}

MyClz& MyClz::operator=(MyClz&& o) {
     if(this==&o) return *this;
     id = std::move(o.id);
     name = std::move(o.name);
     desc = std::move(o.desc);
     return *this;
}

void MyClz::setDesc(const std::string& newDesc) {
    desc = newDesc;
}

std::ostream& operator<<(std::ostream& os, const MyClz& o) {
    os << "{\"" << o.id << "\", \"" << o.name << "\", \"" << o.desc << "\"}";
    return os;
}

std::istream& operator>>(std::istream& is, MyClz& o) {
  is >> o.id >> o.name >> o.desc;
  return is;
}

MyClz::~MyClz() = default;
struct	MyClz::MyClzComparator {
    bool operator() (const MyClz& a, const MyClz& b) const {
        return a.id < b.id;
    }
};
MyClz::MyClz() : id(""), value(""), desc("") {}
MyClz::MyClz(const std::string& _id, const std::string& _value, const std::string& _desc) : id(_id), value(_value), desc(_desc) {}
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

void MyClz::printCRUDUsage() {
	std::cout << "\t>> [I] Usage :  -qQeE : Quit/Exit, -iI : Insert, -dD : Delete, -pP : Print, -cC : Clear )" << std::endl;
}


struct MyClz::MyClzComparator {

    bool operator() (const MyClz& a, const MyClz& b) const {
        return a.id < b.id;
    }
};

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
	system("cls");
}
