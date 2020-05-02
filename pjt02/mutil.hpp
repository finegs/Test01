#ifndef _MUTIL_HPP_
#define _MUTIL_HPP_

#include <string>
#include <vector>
#include <istream>
#include <fstream>

#define NANO 1000000000L
#define uint unsigned int

// #define MYDEBUG(fmt, ...) { printf("[%s:%d] %s "fmt, __FILE__, __LINE__, __FUNCTION__, ##_VA_ARGS__); } 
//
//#ifndef LOG_DEBUG
//#define LOG_DEBUG(fmt, ...) { VLog* log = getLog(); if (log != NULL && log->level <= VLog::LEVEL_DEBUG) log->debug("[%s:%d] %s "fmt, __FILENAME__, __LINE__, __FUNCNAME__, ##__VA_ARGS__); }
//#define LOG_INFO(fmt, ...)  { VLog* log = getLog(); if (log != NULL && log->level <= VLog::LEVEL_INFO ) log->info ("[%s:%d] %s "fmt, __FILENAME__, __LINE__, __FUNCNAME__, ##__VA_ARGS__); }
//#define LOG_WARN(fmt, ...)  { VLog* log = getLog(); if (log != NULL && log->level <= VLog::LEVEL_WARN ) log->warn ("[%s:%d] %s "fmt, __FILENAME__, __LINE__, __FUNCNAME__, ##__VA_ARGS__); }
//#define LOG_ERROR(fmt, ...) { VLog* log = getLog(); if (log != NULL && log->level <= VLog::LEVEL_ERROR) log->error("[%s:%d] %s "fmt, __FILENAME__, __LINE__, __FUNCNAME__, ##__VA_ARGS__); }
//#define LOG_FATAL(fmt, ...) { VLog* log = getLog(); if (log != NULL && log->level <= VLog::LEVEL_FATAL) log->fatal("[%s:%d] %s "fmt, __FILENAME__, __LINE__, __FUNCNAME__, ##__VA_ARGS__); }
//#define LOG_TRACE(fmt, ...) { VLog* log = getLog(); if (log != NULL)                                    log->trace("[%s:%d] %s "fmt, __FILENAME__, __LINE__, __FUNCNAME__, ##__VA_ARGS__); }
//#endif // LOG_DEBUG

char* mstrtok(char* _str, const char* _delim); 
int   mstrcmp(const char* _str1, const char* _str2);
char* getTimestamp();

typedef struct _Node
{
	char name[256];
	struct _Node* next;
}Node;

void runHash();
int str2key(const char* name);
void presentation();
int addNode();
int searchNode(const char* name);
int deleteNode(const char* name);
void printfList(Node* n);
void printHashTable();

void buildMaxHeap(int arr[], int n);
void heapSort(int arr[], int n);
std::vector<std::vector<std::string>> load_csv(const char* path);
std::vector<std::string> csv_read_row(std::istream &file, char delimiter);

class MyClz {
	private:
		std::string name;
		std::string desc;

	public:
		MyClz() = default;
		MyClz(const std::string& _name, const std::string& _desc) 
			: name(_name), desc(_desc) {}
		MyClz(const MyClz& o) 
			: name(o.name), desc(o.desc) {}
		MyClz(MyClz&& o) 
			: name(std::move(o.name)), desc(std::move(o.desc)) {}
		MyClz& operator=(const MyClz& o) {
			if(this==&o) return *this;
			name = o.name;
			desc = o.desc;
			return *this;
		}
		MyClz& operator=(MyClz&& o) {
			if(this==&o) return *this;
			name = std::move(o.name);
			desc = std::move(o.desc);
			return *this;
		}


		friend 
		std::ostream& operator<<(std::ostream& os, const MyClz& o);

		bool operator==(const MyClz& o) const {
			if(this==&o) return true;
			return name == o.name && o.desc == o.desc;
		}
};


#endif
