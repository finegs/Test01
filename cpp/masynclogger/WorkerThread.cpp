#include <iostream>
#include <queue>
#include <mutex>
#include <assert.h>
#include <sstream>

#include "WorkerThread.hpp"
#include "ThreadMsg.h"
#include "AsyncLogger.h"

using namespace std;

WorkerThread::WorkerThread(const char* name, WorkerQueue& _queue)
	: m_thread(nullptr), m_queue(_queue), m_timerExit(false), m_run(false), threadName(name) {}

WorkerThread::~WorkerThread() 
{
	if (m_thread) {
		if (m_thread->joinable()) {
			m_thread->join();
		}
		delete m_thread;
		m_thread = nullptr;
	}
}

WorkerThread::WorkerThread(const WorkerThread& o)
	: m_thread(nullptr), m_queue(o.m_queue), m_timerExit(false), m_run(false), threadName(o.threadName)
{
}

WorkerThread& WorkerThread::operator=(const WorkerThread& o) {
	if(this==&o) return *this;
	threadName = o.threadName;
	return *this;
}

WorkerThread::WorkerThread(WorkerThread&& o)
	: m_thread(o.m_thread), m_queue(o.m_queue), m_timerExit(o.m_timerExit.load()), m_run(o.m_run.load()), threadName(o.threadName) {
	o.m_thread = nullptr;
}

WorkerThread& WorkerThread::operator=(WorkerThread&& o) {
	if(this==&o) return *this;
	if (m_thread) {
		if (m_thread->joinable()) {
			m_thread->join();
		}
		delete m_thread;
	}
	m_thread = o.m_thread;
	o.m_thread = nullptr;
	m_timerExit = o.m_timerExit.load();
	m_run = o.m_run.load();
	threadName = o.threadName;
	return *this;
}

std::thread::id WorkerThread::getThreadId() {
	if (m_thread) return m_thread->get_id();
	return std::thread::id();
}

std::thread::id WorkerThread::getCurrentThreadId() {
	return this_thread::get_id();
}

bool WorkerThread::createThread() 
{
	if (!m_thread)
		m_thread = new thread(&WorkerThread::process, this);
	return true;
}


void WorkerThread::process() 
{
	m_timerExit = false;
	m_run = true;
	thread timerThread(&WorkerThread::timerThread, this);

    stringstream ss;
	while (m_run) {
		WorkerThreadMsg* msg = m_queue.pop(true);

        ss.str("");
        ss.clear();
		
		if (!msg) continue;

		if (!m_run) {
			if (msg->getMsgType() != MSG_EXIT_THREAD) {
				m_queue.post(msg);
			} else {
				delete msg;
			}
			break;
		}

		switch (msg->getMsgType()) {
		case MSG_POST_USER_DATA:
		{
			assert(msg->getMsgDetail() != NULL);

			UserData* userData = msg->getMsgDetail();
            
            ss << "[" << msg->getMsgSeq() << "] "<< userData->msg.c_str() << " on " << userData->year << " by " << threadName << endl;

            LogRecord* rec = new LogRecord(ss.str());

            AsyncLoggers::log(LoggersNames.ROOT, rec);

			delete msg;
            msg = nullptr;

			break;
		}

		case MSG_TIMER:
		{
            ss << "[" << msg->getMsgSeq() << "] Timer expired on " << threadName << endl;

            LogRecord* rec = new LogRecord(ss.str());

            AsyncLoggers::log(LoggersNames.ROOT, rec);

			delete msg;
			msg = nullptr;
			break;
		}

		case MSG_EXIT_THREAD:
		{
			if (m_run) {
				m_queue.post(msg);
				this_thread::sleep_for(std::chrono::milliseconds(10));
				continue;
			}
			delete msg;
			msg = nullptr;
			break;
		}

		default:
			assert(false);
		}
	}

	m_timerExit = true;
	if (timerThread.joinable()) {
		timerThread.join();
	}

    ss.str("");
    ss.clear();
	ss << "Exit thread on " << threadName << endl;
    LogRecord* rec = new LogRecord(ss.str());
    AsyncLoggers::log(LoggersNames.ROOT, rec);
}

void WorkerThread::postMsg(UserData* data)
{
	m_queue.post(data);
}

void WorkerThread::exitThread() {
	if (!m_thread) return;

	m_timerExit = true;
	m_run = false;

	WorkerThreadMsg* msg = new WorkerThreadMsg(MSG_EXIT_THREAD, 0);
	m_queue.post(msg);

	m_thread->join();
	delete m_thread;
	m_thread = nullptr;
}


void WorkerThread::timerThread() {
	while (!m_timerExit) 
	{
		this_thread::sleep_for(250ms);

		WorkerThreadMsg* threadMsg = new WorkerThreadMsg(MSG_TIMER, 0);

		m_queue.post(threadMsg);
	}
}

int WorkerQueue::post(UserData* data) {
	if(nullptr==data) return 1;

	WorkerThreadMsg* m = new WorkerThreadMsg(MSG_POST_USER_DATA, data);

	return post(m);
}

int WorkerQueue::post(WorkerThreadMsg* msg) {
	if(nullptr==msg) return 1;
	std::unique_lock<std::mutex> lck(m_mtx);

	m_queue.push(msg);
	m_cv.notify_one();
	return EXIT_SUCCESS;
}

WorkerThreadMsg* WorkerQueue::pop(bool wait) {
	WorkerThreadMsg* m = nullptr;

	std::unique_lock<std::mutex> lck(m_mtx);
	if(wait) {
		m_cv.wait(lck, [this]() { return !m_queue.empty(); });
	} else {
		if(m_queue.empty()) return nullptr;
	}

	if(!m_queue.empty()) {
		m = m_queue.front();
		m_queue.pop();
	}
	return m;
}

std::ostream& operator<<(std::ostream& os, const WorkerObject& o) {
	os << "{\"" << "name\":" << o.m_name << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, WorkerObject& o) {
	is >> o.m_name;
	return is;
}
