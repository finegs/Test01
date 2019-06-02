
#ifndef __U_HPP
#define __U_HPP

#define INITIAL_SIZE 1024

#define VERSION_U "v1.0.0_20190602_b01"

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


#endif
