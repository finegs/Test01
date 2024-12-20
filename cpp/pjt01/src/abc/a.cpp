#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>

const int MAX_ARR_LEN = 1000000+1;

void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

typedef struct priority_queue Queue;
struct priority_queue {
	int heap[MAX_ARR_LEN];
	int size = 0;
	int push(int value);
	int pop();
	void sort();
	void heapify();
	int empty();
	void print(std::ostream& os);
	friend std::ostream& operator<<(std::ostream& os, Queue& o);
	Queue* clone();
};

int Queue::empty() {
	return size==0;
}

int Queue::push(int value) {
	if(size+1 > MAX_ARR_LEN) return 0;

	int current = size;
	int parent = (size-1)/2;
	heap[current] = value;
	while(current > 0 && heap[current]>heap[parent]) {
		swap(&heap[current], &heap[parent]);
		current= parent;
		parent = (parent-1)/2;
	}
	size++;
	return 1;
};

int Queue::pop() {
	if(size<=0) return 0;

	int ret = heap[0];
	size--;
	heap[0] = heap[size];

	int current = 0;
	int leftchild = current*2+1;
	int rightchild = current*2+2;
	int maxNode = current;

	while(leftchild<size) {
		if(heap[maxNode]<heap[leftchild]) maxNode= leftchild;
		if(rightchild<size&&heap[maxNode]<heap[rightchild]) maxNode=rightchild;
		if(maxNode==current) break;
		else {
			swap(&heap[current], &heap[maxNode]);
			current= maxNode;
			leftchild=current*2+1;
			rightchild=current*2+2;
		}
	}
	return ret;
}

void Queue::sort() {
	int len = size;
	int v;
	while(!empty()) {
		v = pop();
		heap[--len] = v;
		printf("heap[%d]=%d\n", len, v);
//		heap[size] = pop();
	}
}

void Queue::heapify() {
	int len = size;
	size = 0; // before heapify
	for (int i = len-1; i >=0; --i) {
		push(heap[i]);
	}
}

void Queue::print(std::ostream& os) {
	int len  = size;
	for (int i = 0; i < len; ++i) {
		os << heap[i] << (i== len-1? "" : ", ");
	}
	os<< std::endl;
}

std::ostream& operator<<(std::ostream& os, Queue& q) {
	q.print(os);
	return os;
}

Queue* Queue::clone() {
	Queue* po;
	po = (Queue*)malloc(sizeof(Queue));
	if(!po) { fprintf(stderr, "Fail to malloc(sizeof(Queue)). %s.%d\n", __FILE__, __LINE__); return po;}
	po->size = size;
	memcpy(po->heap, heap, MAX_ARR_LEN);
	return po;
}

Queue q;


int main(int argc, char* argv[]) {

	int N;

	printf("N:"); fflush(stdout);
	scanf("%d", &N); fflush(stdin);

	int value;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &value); q.push(value);
	}
	q.print(std::cout);

	Queue* qq = q.clone();
	qq->sort();
	qq->size = q.size; // size should be set after sort to know size

	std::cout << "## 1. sorted ##" << std::endl;
	qq->print(std::cout);

	qq->heapify();
	std::cout << "## 2.heapified ##" << std::endl;
	qq->print(std::cout);

	free(qq);
//
	std::cout << "## 3.final ##" << std::endl;
	while(!q.empty()) { printf("%d%s", q.pop(), (q.empty() ? "\n" : ", ")); };
	fflush(stdout);
#if !defined(NDEBUG)
	system("pause");
#endif

	return 0;
}

#if 0
enum MyConstants {
	MAX_N = 1000000,

	MODE_EXCEPT = 101,
	MODE_INCLUDE = 102

};

int g_mode = MODE_EXCEPT;

void f1(int case_n, int case_c, int case_idx, char arr[], char rarr[], int* cnt) {
	if(case_idx > case_c) {
#if defined(__MYDEBUG)
		static char* str;
		if(!str) str = (char*)malloc(sizeof(char)*MAX_N);
		memset(str, 0, MAX_N);
		// strcat(str, "result:");
		char ss[20];
		memset(ss, 0, 20);

		sprintf(str, "%10d", *cnt);
		for(int i = 1;i<case_idx;i++) {
			sprintf(ss, "%s%d", (i>1?", " : " "), rarr[i]);
			strcat(str, ss);
		}
		printf("%s\n", str);
#endif	
		(*cnt)++;
		return;
	}

	for(int i = 1;i <= case_n;i++) {
		if((g_mode == MODE_EXCEPT) && arr[i]) continue;
		arr[i]=1;
		rarr[case_idx]=i;

		f1(case_n, case_c, case_idx+1, arr, rarr, cnt);

		arr[i]=0;
	}
}

int main(int argc, char* argv[]) {

	char filename[1024];

	int case_n;
	int case_c;
	int cnt;

	memset(filename,0, 1024);
	case_n = 6;
	case_c = 3;
	for(int i = 1;i < argc;i++) {
		if ('-' == argv[i][0]) {
			if(strlen(argv[i])>1) {
				switch(argv[i][1]) {
					case 'f': { 
								  strcpy(filename, argv[i]+2); 
							  }
						break;
					case 'n': { 
								  if(strlen(argv[i]+2) > 0)  
									  case_n = atoi(argv[i]+2); 
							  } 
						break;
					case 'c': { 
								  if(strlen(argv[i]+2) > 0)  
									  case_c = atoi(argv[i]+2); 
							  } 
						break; 
					case 'm': { 
								  if(strlen(argv[i]+2) > 0) {
									  if('e'==argv[i][2] || 'E'==argv[i][2]) g_mode = MODE_EXCEPT; 
									  else if('i'==argv[i][2] || 'I'==argv[i][2]) g_mode = MODE_INCLUDE; 
									  else {
										  fprintf(stderr, "Unknown Mode : %c, (Default Mode = 'E')\n", argv[i][2]);
									  }
								  }
							  }
						break;
					default: {
								 fprintf(stderr, "Unknown Option : %s\n", argv[i]);
								 exit(1);
							 }
				}
			}
		}
	}

	printf("%d : argc:%d, filename:%s\n", __LINE__, argc, filename);

	char *arr, *rarr;

	arr = (char*)malloc(sizeof(char)*MAX_N);
	rarr = (char*)malloc(sizeof(char)*MAX_N);

	memset(arr, 0, MAX_N);
	memset(rarr, 0, MAX_N);

	f1(case_n, case_c, 1, arr, rarr, &cnt);

	printf("%d : ### Result : cnt = %d ###\n", __LINE__, cnt);

	return 0;
}

#endif
