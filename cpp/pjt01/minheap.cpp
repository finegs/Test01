//============================================================================
// Name        : aaa.cpp
// Author      : 11
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>

#define LM 20010

//inline int MAX_HEAP_LEN = 1000000;
//
//int heap[MAX_HEAP_LEN];
//int hn = 0;
int N;
long long ans;

inline void swap(int& a, int& b) { int t = a; a = b ; b = t; }
bool max(int a, int b) { return a>b; }
bool min(int a, int b) { return a<b; }

struct PriorityQueue {
	int heap[LM];

	int hn;
	bool (*comp)(int,int);

	void init(int isMax) {
		hn = 0;
		comp = isMax ? max : min;
	}

	int top() { return heap[1]; }
	int size() { return hn; }
	bool empty() { return hn == 0; }

	void push(int val) {
		heap[++hn] = val;
		for(int c = hn;c>1 && comp(heap[c], heap[c/2]);c /= 2) {
			swap(heap[c], heap[c/2]);
		}
	}

	int pop() {
		int p,c, ret;

		ret = heap[1];
		swap(heap[1], heap[hn--]);
		for(p=1,c=2;c<=hn;c*=2) {
			if(c<hn&&comp(heap[c+1],heap[c])) c++;
			if(!comp(heap[c], heap[p])) break;
			swap(heap[c], heap[p]);
		}
		return ret;
	}
} minpq;
//
//void push_heap(int val) {
//	heap[++hn] = val;
//	for(int c = hn;c>1&&heap[c] < heap[c/2];c/=2) {
//		swap(heap[c], heap[c/2]);
//	}
//}
//
//int pop_heap() {
//	int p, c, ret = heap[1];
//	swap(heap[1], heap[hn--]);
//	for(p=1,c=2;c<=hn;p =c, c *= 2) {
//		if(c<hn&&heap[c+1]<heap[c]) c++;
//		if(heap[c]>=heap[p]) break;
//		swap(heap[c], heap[p]);
//	}
//	return ret;
//}

int main() {
	freopen("input.txt", "r", stdin);

	minpq.init(0);
	scanf("%d", &N);
	int i,val;

	for(i=0;i<N;++i) {
		scanf("%d", &val);
		minpq.push(val);
	}

	for(i=1;i<N;++i) {
		int sum = minpq.pop() + minpq.pop();
		ans += sum;
		minpq.push(sum);
	}

	printf("%lld\n", ans);
//	scanf("%d", &N);
//	int i, val;
//	for(i = 0;i<N;++i) {
//		scanf("%d", &val);
//		push_heap(val);
//	}
//
//	for(i = 1;i < N;++i) {
//		int sum = pop_heap() + pop_heap();
//		ans += sum;
//		push_heap(sum);
//	}
//
//	printf("%lld\n", ans);
	return 0;
}


#if 0

#include <iostream>
#include <string>

using namespace std;

int main() {

  	std::string s;

	cin.clear();

	cout << ">> s:";

	cout.flush();

	cin >> s;

	cout << "<< s:" << s << endl;

	cin.clear();
	cout.flush();

	char a = getc(stdin);

	cout << a << endl;

	system("pause");

	return 0;
}


#endif
