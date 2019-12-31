#ifndef _MUTIL_HPP_
#define _MUTIL_HPP_

#include <string>

#define NANO 1000000000L
#define uint unsigned int

char* mstrtok(char* _str, const char* _delim); 
int   mstrcmp(const char* _str1, const char* _str2);
std::string getTimestamp();
char* getTimestamp2();
int timespec2str(char *buf, uint len, struct timespec *ts);

typedef struct _Node
{
	char name[256];
	struct _Node* next;
}Node;

void runHash();
int str2key(char name[]);
void presentation();
void addNode();
int searchNode(char name[]);
void deleteNode(char name[]);
void printfList(Node* n);
void printHashTable();


#endif
