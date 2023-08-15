#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include "AsyncLogger.h"
#include "WorkerThread.hpp"

using namespace std;

std::atomic<int> AsyncLoggers::g_loggerId{0};
std::mutex AsyncLoggers::sMutex;
std::atomic<int> WorkerThreadMsg::g_seq{0};
std::vector<WorkerThread> threads;

int main(int argc, char* argv[])
{
	int threadCnt,sleepMils;

	if(argc < 2) {
		printf("Usage : %s -n {thread count} -t {sleep time mills}\n", argv[0]);
		return EXIT_SUCCESS;
	}
	else {
		if(threadCnt < 1) threadCnt = 2;
		if(sleepMils < 1) sleepMils = 3000;

		for(int i = 0;i<argc;i++) {
			if(!strcmp("-n", argv[i]) && i+1<argc) {
				threadCnt = atoi(argv[i+1]);
				i++;
			}
			if(!strcmp("-t", argv[i]) && i+1<argc) {
				sleepMils = atoi(argv[i+1]);
				i++;
			}
		}
	}
    AsyncLoggers::getInstance();

	WorkerQueue workQueue;

	for(int i = 0; i<threadCnt;i++) {
		std::string tName("WT");
		tName+="1";
		threads.emplace_back(tName.c_str(), workQueue);
	}

	for(auto& t : threads) {
		t.createThread();
	}

	// Create message to send to worker thread 1
	UserData* userData1 = new UserData();
	userData1->msg.assign("Hello world");
	userData1->year = 2017;

	// Post the message to worker thread 1
	workQueue.post(userData1);

	// Create message to send to worker thread 2
	UserData* userData2 = new UserData();
	userData2->msg.assign("Goodbye 2017 and Hello 2018");
	userData2->year = 2018;

	// Post the message to worker thread 2
	workQueue.post(userData2);

	// Give time for messages processing on worker threads
	this_thread::sleep_for(999999999999s);

	for(auto& t : threads) {
		t.exitThread();
	}

	return EXIT_SUCCESS;
}
