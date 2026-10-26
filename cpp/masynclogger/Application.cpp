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
	int threadCnt = 2, sleepMils = 3000;

	if(argc < 2) {
		printf("Usage : %s -n {thread count} -t {sleep time mills}\n", argv[0]);
		return EXIT_SUCCESS;
	}
	else {
		for(int i = 1; i < argc; i++) {
			if(!strcmp("-n", argv[i]) && i+1<argc) {
				threadCnt = atoi(argv[i+1]);
				i++;
			}
			if(!strcmp("-t", argv[i]) && i+1<argc) {
				sleepMils = atoi(argv[i+1]);
				i++;
			}
		}
		if(threadCnt < 1) threadCnt = 2;
		if(sleepMils < 1) sleepMils = 3000;
	}
    AsyncLoggers::getInstance();

	WorkerQueue workQueue;

	std::vector<std::string> threadNames;
	threadNames.reserve(threadCnt);
	for(int i = 0; i<threadCnt;i++) {
		threadNames.push_back("WT" + std::to_string(i + 1));
		threads.emplace_back(threadNames.back().c_str(), workQueue);
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
	this_thread::sleep_for(std::chrono::milliseconds(sleepMils));

	for(auto& t : threads) {
		t.exitThread();
	}

	AsyncLogger* rootLogger = AsyncLoggers::getInstance()->getLogger(LoggersNames.ROOT);
	if (rootLogger) {
		rootLogger->shutdown();
	}

	return EXIT_SUCCESS;
}
