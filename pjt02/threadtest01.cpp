

// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <type_traits>

typedef struct {
	int threadId;
	std::mutex& mtx;
	std::condition_variable& condvar;
	int threadCnt;
} threadpara;

bool g_ready = false;
void print_id (void* threadpara);
void go(void* threadpara);

using threadfp = void (*)(void* threadpara);
using threadmain = void (*)(void* threadpara);

int testThread(void* threadpara, threadmain, threadfp);
void teststring();

int main ()
{

	std::mutex mtx;
	std::condition_variable cndCv;

	threadpara* tp = new threadpara{-1, mtx, cndCv, 10};

	testThread(tp, go, print_id);

	teststring();
	
	return EXIT_SUCCESS;
}

void teststring() {
	int width,height;
	
	width = 30;
	height = 20;
	
	std::string **vvs;
	vvs = new std::string*[width];
	for (int i = 0; i < width; ++i) {
	  vvs[i] = new std::string[height];
	}
	
	for (int i = 0; i < width; ++i) {
	  delete[] vvs[i];
	}
	delete[] vvs;
	vvs = nullptr;
	
	char** ccs;
	ccs = new char*[height];
	for (int i = 0; i < height; ++i) {
	  ccs[i] = new char[width];
	}
	
	for (int i = 0; i < height; ++i) {
	  delete[] ccs;
	}
	
	delete[] ccs;
	ccs = nullptr;

}


int testThread(void* _tp, threadmain _threadmain, threadfp _threadfp) {
	threadpara* tp = (threadpara*)_tp;
	std::thread threads[tp->threadCnt];
	// spawn 10 threads:
	for (int i=0; i<tp->threadCnt; ++i) {
	  	threadpara* ttp = new threadpara{i, tp->mtx, tp->condvar, tp->threadCnt};
	  threads[i] = std::thread(_threadfp, ttp);
	}

	std::cout << "10 threads ready to race...\n";

	_threadmain(tp);

	for (auto& th : threads) th.join();

	delete tp;

	return EXIT_SUCCESS;
}

void print_id (void* _tp) {
	threadpara* tp = (threadpara*)_tp;
  std::unique_lock<std::mutex> lck(tp->mtx);
  while (!g_ready) tp->condvar.wait(lck);
  // ...
  std::cout << "thread [" << std::this_thread::get_id() << "] id = " << tp->threadId << '\n';

	delete tp;
}

void go(void* _tp) {
	threadpara* tp = (threadpara*)_tp;
	std::unique_lock<std::mutex> lck(tp->mtx);
	g_ready = true;
	tp->condvar.notify_all();

	delete tp;
}

/*
 * main.cpp
 *
 *  Created on: 2017. 12. 10.
 *      Author: finegs
 */

#if 0
#include <stdio.h>
#include <iostream>

#ifdef _DEBUG
setbuff(stdout, NULL);
setbuff(stderr, NULL);
#endif

int main()
{
	using namespace std;

	int examples;

	cout << "Enter examples" << endl;

	cin >> examples;

	cout << examples << endl;

	examples = 25;

	cout << "I have ";
	cout << examples;
	cout << " examples. ";
	cout << endl;
	examples = examples -1;
	cout << "I have " << examples << " examples." << endl;

	std::string str;
	std::string base = "The quick brown for jumps over a lazy dog.";

	  str.assign(base,10,9);
	  std::cout << str << '\n';         // "brown fox"

	  str.assign("pangrams are cool",7);
	  std::cout << str << '\n';         // "pangram"

	  str.assign("c-string");
	  std::cout << str << '\n';         // "c-string"

	  str.assign(10,'*');
	  std::cout << str << '\n';         // "**********"

//	  str.assign(10, 0x2D);
//	  std::cout << str << '\n';         // "----------"

	  str.assign(base.begin()+16,base.end()-12);
	  std::cout << str << '\n';         // "fox jumps over"
	return 0;
}

#endif
