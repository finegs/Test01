#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "mutil.hpp"

char* mstrtok(char* _str, const char* _delim) {
	static char* pstr;
//	static char bdelim;
	const char* pdelim;
	size_t len;

	len = 0;
	if(NULL == _str) {
		_str = pstr;
//		if(!*pstr) // replace previous null-terminator '\0' with previous delimeter
//			*(pstr-1)=bdelim;
	}
	else {
		pstr = _str;
	}

	while(*pstr) {
		pdelim = _delim;

		while(*pdelim) {
			if(*pstr == *pdelim) {
//				bdelim = *pdelim;
				*pstr = '\0'; 
				pstr++;
				return _str;
			}
			pdelim++;
		}
		pstr++;
		len++;
	}
	return _str;
}

int mstrcmp(const char* _arr1, const char* _arr2) {
	int i = 0;
	while(_arr1[i] != '\0' || _arr2[i] != '\0') {
		if(_arr1[i] > _arr2[i])
			return _arr1[i] - _arr2[i];
		else if (_arr1[i] < _arr2[i])
			return _arr1[i] - _arr2[i];
		else
			i++;
	}
	return 0;
}



std::string getTimestamp() {
  // get a precise timestamp as a string
  const auto now = std::chrono::system_clock::now();
  const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
  const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(
      now.time_since_epoch()) % 1000;
  std::stringstream nowSs;
  nowSs
	  << std::put_time(std::localtime(&nowAsTimeT), "%Y-%m-%d %H:%M:%S")
   //   << std::put_time(std::localtime(&nowAsTimeT), "%a %b %d %Y %T")
      << '.' << std::setfill('0') << std::setw(3) << nowMs.count();
  return nowSs.str();
}

Node *hashTable[1000];
int hashTableSize = 10;

int str2key(char name[]) {
	size_t c,s = 0;
	for(size_t i = 0;i<strlen(name);i++) {
		c = name[i];
		s = s+c;
	}
	return s;
}

void presentation() {
	printf("\t\tHash Table C Program\n\n");
	printf("\tto add an node press 1...\n");
	printf("\tto search a node press 2...\n");
	printf("\tto delete a node press 3...\n");
	printf("\tto print the hash table press 4...\n");
	printf("\tto exit press 0...\n");
	//printf("\tto exit press any other key...\n");
}

void addNode() {
	Node* n, *n1;
	int ascii,key;
	printf("adding node...\n");
	n = (Node*)malloc(sizeof(Node));
	printf("Node Name:"); fflush(stdout);
	scanf("%s", n->name);
	n->next = NULL;
	printf("|[%d]|\n", (int)strlen(n->name));
	ascii = str2key(n->name);
	key = ascii % hashTableSize;
	if(hashTable[key]==NULL) {
		hashTable[key] = n;
	}
	else {
		for(n1=hashTable[key];n1->next != NULL;n1=n1->next);
		n1->next = n;
	}
}


int searchNode(char nName[]) {
	int ascii = str2key(nName);
	int key = ascii & hashTableSize;
	Node* n;
	for(n=hashTable[key];n!=NULL;n=n->next) {
		if(strcmp(n->name, nName) ==0) {
			return key;
		}
	}
	return -1;
}

void deleteNode(char nName[]) {
	printf("delete Node...\n");
	int ascii = str2key(nName);
	int key = ascii % hashTableSize;

	Node *n,*n1;
	if(strcmp(hashTable[key]->name, nName)==0) {
		n = hashTable[key];
		hashTable[key] = hashTable[key]->next;
		free(n);
		return;
	}
	
	for(n=hashTable[key];n->next!=NULL;n=n->next) {
		n1 = n->next;
		if(strcmp(n1->name, nName)==0) {
			n->next = n1->next;
			free(n1);
			return;
		}
	}
}

void printfList(Node *n) {
	Node* n1;
	int i;
	for(i=0,n1=n;n1!=NULL;n1=n1->next,i++) {
		printf(" [%d]=%s", i, n1->name);
	}
	printf("\n");
}

void printHashTable() {
	for(int i= 0;i<hashTableSize;i++) {
		printf("\nHash Table[%d]: ", i);
		printfList(hashTable[i]);
	}
}


void runHash() {

	for(int i=0;i<hashTableSize;i++) {
		hashTable[i] = NULL;
	}

	char nName[256];
	int key, action  = 1 ;
	presentation();
	while(action==1||action==2||action==3||action==4) {
		switch(action) {
			case 1: // Add Node
				{
					addNode();
				}
				break;
			case 2: // Search Node
				{
					memset(nName, '\0', strlen(nName));
					printf("Name:"); fflush(stdout); scanf("%s", nName);
					
					printf("#### Name=%s\n", nName); 

					key = searchNode(nName); 

					if(key==-1) {
						printf("Node doesn't exist!\n");
					}
					else {
						printf("Node exist in:");
						printf("Hash Table[%d]\n", key);
						printfList(hashTable[key]);
					}
				}
				break;
			case 3: // Delete Node
				{
					printf("Node Name:"); fflush(stdout); scanf("%s", nName);
					key = str2key(nName);
					if(key == -1) {
						printf("Unknown Name:%s\n", nName);
						return;
					}
					else {
						deleteNode(nName);
					}
				}
				break;
			case 4: // Print Hash Table
				{
					printHashTable();
				}
				break;
			case 0:
				{
					printf("exit...\n");
					system("pause");
					return;
				}
				break;

			default:
				{
					printf("\nUnknown action:%d\n", action);
				}

		}

		presentation();
		scanf("%d", &action);
		fflush(stdin);
	}
}
						
