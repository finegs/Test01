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
	if(0==len) return NULL;
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
char* getTimestamp() {
      static char* buf;
      static size_t buf_len;

      struct timespec ts;
      struct tm tm;
      struct tm* rtm;
      if(!buf) {
              buf_len = strlen("2019-12-31 11:59:59.123456789") + 1;
              buf = (char*)malloc(sizeof(char)*buf_len);
              memset(buf, '\0', buf_len);
      }

      clock_gettime(CLOCK_REALTIME, &ts);

#ifdef USE_LOCAL_TIME
    rtm = localtime_r (&ts.tv_sec, &tm);
#else
    rtm = gmtime_r (&ts.tv_sec, &tm);
#endif

      strftime(buf, buf_len, "%Y-%m-%d %H:%M:%S", rtm);
      sprintf(buf+19, ".%09ld", ts.tv_nsec);
      return buf;
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

void buildMaxHeap(int arr[], int n)
{
	for(int i = 1;i<n;i++) {
		if(arr[i]>arr[(i-1)/2]) {
			int j= i;

			while(arr[j]>arr[(j-1)/2]) {
				std::swap(arr[j], arr[(j-1)/2]);
				j = (j-1)/2;
			}
		}
	}
}


void heapSort(int arr[], int n) {
	buildMaxHeap(arr, n);

	for(int i = n-1;i>0;i--) {
		std::swap(arr[0], arr[i]);

		int j = 0, index;

		do {
			index = (2*j+1);

			if(arr[index]<arr[index+1]
					&& index<(i-1))
				index++;

			if(arr[j]<arr[index]
					&& index<i)
				std::swap(arr[j], arr[index]);

			j = index;

		} while(index < i);
	}
}

