#ifndef _WORKERTHREAD_H
#define _WORKERTHREAD_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <atomic>

#include "LogDetailMsg.h"
#include "ThreadMsg.h"
#include "UserData.hpp"

class WorkerQueue;

class WorkerThread
{
public:
	WorkerThread(const char* threadName, WorkerQueue& _queue );

	~WorkerThread();

	WorkerThread(const WorkerThread& o);
	WorkerThread& operator=(const WorkerThread& o);
	WorkerThread(WorkerThread&& o);
	WorkerThread& operator=(WorkerThread&& o);

	bool createThread();

	void exitThread();

	std::thread::id getThreadId();
	
	static std::thread::id getCurrentThreadId();

	void postMsg(UserData* data);

private:
	// WorkerThread(const WorkerThread&);
	// WorkerThread& operator=(const WorkerThread&);

	void process();

	void timerThread();

	std::thread* m_thread;
	WorkerQueue& m_queue;
	std::atomic<bool>	m_timerExit;
	std::atomic<bool>   m_run;
	const char* threadName;
};


class WorkerQueue {
	private:
		std::mutex m_mtx;
		std::condition_variable_any m_cv;
		std::queue<WorkerThreadMsg*> m_queue;

	public:
		int post(UserData* data);
		int post(WorkerThreadMsg* msg);
		WorkerThreadMsg* pop(bool wait);
};


class WorkerObject {
	private:
		std::string m_name;

	public:
		WorkerObject(const std::string& name) : m_name(name) {}

		const std::string& getName() { return m_name; };
		friend std::ostream& operator<<(std::ostream& os, const WorkerObject& o);
		friend std::istream& operator>>(std::istream& is, WorkerObject& o);
};

#endif
