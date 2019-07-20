
#ifndef __U_HPP
#define __U_HPP

#include <string>
#include <set>
#include <memory>
#define INITIAL_SIZE 1024

#define VERSION_U "v1.0.0_20190602_b01"

extern bool T_IS_DEBUG;
extern bool T_IS_EXIT;

#define EXIT_OTHERS 2

#ifdef _WIN32
	#define SOCKET unsigned int
#else
	#define SOCKET int
#endif

void DieWithError(const char* errorMessage);

struct Buffer
{
		void* data;
		int next;
		size_t size;
};

struct Buffer* new_buffer(size_t data_len = INITIAL_SIZE);
void reserve_space(Buffer* b, size_t bytes);

void serialize_int(int x, Buffer* b);

int closeSocket(SOCKET sock);
int shutdown(SOCKET sock, int opt);

class Packet
{
	public:
		static const size_t MaxDataSize;
		int senderId;
		int sequenceNumber;
		char* data;

	public:
		Packet();
		~Packet();

	public:
		void* serialize();
		void deserialize(void* message);
};

struct SerializedPacket {

	public:
		int senderId;
		int sequenceNumber;
		char *data;
	public:
		SerializedPacket();
		~SerializedPacket();

} __attribute__((packed));

class MyClz
{
private:
	std::string id;
	std::string value;
	std::string desc;

public:
	MyClz();
	MyClz(const std::string &_id, const std::string &_value, const std::string &_desc = "");
	MyClz(const MyClz &o);
	MyClz(MyClz &&o);
	MyClz &operator=(const MyClz &o);
	MyClz &operator=(MyClz &&o);
	~MyClz() = default;

public:
	std::string getId() const { return id; }
	std::string getValue() const { return value;}
	std::string getDesc() const { return desc;}
	const std::string& getCId() const { return id; }
	const std::string& getCValue() const { return value;}
	const std::string& getCDesc() const { return desc;} 
	void setDesc(const std::string &);

	friend std::ostream &operator<<(std::ostream &os, const MyClz &o);
	friend std::istream &operator>>(std::istream &is, MyClz &o);

	static void printCRUDUsage();
	static void testFibo(int n = 255);

public:
	struct MyClzComparator;
	struct MyClzHash;
	struct MyClzEqual;
};

class My {
	private:
		int a;
		std::string b;
		float c;
	public:
		My() : a(-1), b(""), c(-1) {}
		My(int _a, const std::string& _b, float _c) : a(_a), b(_b), c(_c) {}
		My(const My& o) : a(o.a), b(o.b), c(o.c) {}
		My(My&& o) : a(o.a), b(std::move(o.b)), c(o.c) {}

		My& operator=(const My& o) {
			if(this==&o) return *this;
			a = o.a;
			b = o.b;
			c = o.c;
			return *this;
		}

		My& operator=(My&& o) {
			if(this==&o) return *this;
			a = o.a;
			b = std::move(o.b);
			c = o.c;

			return *this;
		}
		friend std::ostream& operator<<(std::ostream& os, const My& o);
		friend std::istream& operator>>(std::istream& os, My& o);

		const int& getA() const { return a; }
		const std::string& getB() const { return b; };
		const float& getC() const { return c; }

};


namespace my
{
	class Msg // s.cpp Msg to communication
	{
		public:
			Msg(const std::string& _msg, struct sockaddr_in* _from_addr = nullptr) 
					: msg(_msg), from_addr(_from_addr) {}
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
			
			~Msg() 
			{
				free(from_addr);
				from_addr = nullptr;
			}

		private:
			std::string msg;
			struct sockaddr_in* from_addr;
	};
}

class Door;
class Room {
	public:
	std::shared_ptr<Door> door1 = {};
	std::shared_ptr<Door> door2 = {};
	~Room() = default;
};

class Door {
public:
	const std::weak_ptr<Room> roomA;
	const std::weak_ptr<Room> roomB;

	Door(std::shared_ptr<Room> roomA, std::shared_ptr<Room> roomB);
	~Door() = default;
};

class World {
	public:
	std::set<std::shared_ptr<Room>> rooms = {};
	World();

	~World() = default;

	static int doTest();
};


#endif
