#ifndef __U_HPP
#define __U_HPP

#define INITIAL_SIZE 1024

void DieWithError(const char*);
struct Buffer
{
    void* data;
    int next;
    size_t size;
};

struct Buffer* new_buffer(size_t data_len = INITIAL_SIZE);
void reserve_space(Buffer* b,size_t bytes);
void serialize_int(int x, Buffer* b);

class Packet
{
    public:
        static const size_t MaxDataSize;
		int senderId;
		int sequenceNumber;
		char *data;
    public:
        Packet();
        ~Packet();
	public:
		unsigned char* serialize();
		void deserialize(unsigned char* message);
};

struct SerializedPacket {
	int senderId;
	int sequenceNumber;
    char* data;
} __attribute__((packed));


#endif
