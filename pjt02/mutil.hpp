#ifndef _MUTIL_HPP_
#define _MUTIL_HPP_

#include <string>
#include <vector>
#include <istream>
#include <fstream>

#define NANO 1000000000L
#define uint unsigned int

char* mstrtok(char* _str, const char* _delim); 
int   mstrcmp(const char* _str1, const char* _str2);
char* getTimestamp();

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

void buildMaxHeap(int arr[], int n);
void heapSort(int arr[], int n);
std::vector<std::vector<std::string>> load_csv(const char* path);
std::vector<std::string> csv_read_row(std::istream &file, char delimiter);

#endif
