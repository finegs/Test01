#ifndef _MUTIL_HPP_
#define _MUTIL_HPP_

#include <string>

char* mstrtok(char* _str, const char* _delim); 
int   mstrcmp(const char* _str1, const char* _str2);
std::string getTimestamp();

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
