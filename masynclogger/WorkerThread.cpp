#include <iostream>
#include <queue>
#include <mutex>
#include <assert.h>
#include <sstream>

#include "WorkerThread.hpp"
#include "ThreadMsg.h"
#include "AsyncLogger.h"

using namespace std;

WorkerThread::WorkerThread(const char* name, WorkerQueue& _queue) : m_queue(_queue), threadName(name) {}
WorkerThread::~WorkerThread() 
{
	//delete THREAD_NAME;
	//THREAD_NAME = nullptr;
}

WorkerThread::WorkerThread(const WorkerThread& o)
{
	if(this==&o) return;
	// std::copy(o.m_queue.front(), o.m_queue.back(), m_queue.front());
	threadName = o.threadName;
	m_queue = o.m_queue;
}

WorkerThread& WorkerThread::operator=(const WorkerThread& o) {
	if(this==&o) return *this;
	threadName = o.threadName;
	m_queue = o.m_queue;
	// std::copy(o.m_queue.front(), o.m_queue.back(), m_queue.front());
	return *this;
}

WorkerThread::WorkerThread(WorkerThread&& o) {
	if(this==&o) return;
	m_queue = std::move(o.m_queue);
	threadName = std::move(o.threadName);
	std::move(o.m_queue.front(), o.m_queue.back(), m_queue.front());
}

WorkerThread& WorkerThread::operator=(WorkerThread&& o) {
	if(this==&o) return *this;
	threadName = std::move(o.threadName);
	std::move(o.m_queue.front(), o.m_queue.back(), m_queue.front());
	return *this;
}

std::thread::id WorkerThread::getThreadId() {
	if (m_thread) m_thread->get_id();
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
		WorkerThreadMsg* msg = nullptr;
		{
			msg = m_queue.pop(true);
			// std::unique_lock<std::mutex> lk(m_mutex);
			// while (m_queue.empty())
				// m_cv.wait(lk);
// 
			// if (m_queue.empty())
				// continue;
			// msg = m_queue.front();
			// m_queue.pop();
		}

        ss.clear();
		
		if (!msg) continue;

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
			m_timerExit = true;
			timerThread.join();

			delete msg;
            msg = nullptr;

			while(!(msg = m_queue.pop(false)) {
                ss.clear();

                UserData* ud = msg->getMsgDetail();

                ss << "[" << msg->getMsgSeq() << "] [" << ((ud) ? ud->msg.c_str() : "" ) << "] on " << ( ud  ? ud->year : 0) << " by " << threadName << endl;

                LogRecord* rec = new LogRecord(ss.str());

                AsyncLoggers::log(LoggersNames.ROOT, rec);

				m_queue.pop();
				delete msg;
                msg = nullptr;
			}

			// unique_lock<mutex> lk(m_mutex);
// 
			// while (!m_queue.empty()) {
				// msg = m_queue.front();
// 
                // ss.clear();
// 
                // UserData* ud = msg->getMsgDetail();
// 
                // ss << "[" << msg->getMsgSeq() << "] [" << ((ud) ? ud->msg.c_str() : "" ) << "] on " << ( ud  ? ud->year : 0) << " by " << threadName << endl;
// 
                // LogRecord* rec = new LogRecord(ss.str());
// 
                // AsyncLoggers::log(LoggersNames.ROOT, rec);
// 
				// m_queue.pop();
				// delete msg;
                // msg = nullptr;
			// }

            ss.clear();

			ss << "Exit thread on " << threadName << endl;

            LogRecord* rec = new LogRecord(ss.str());

            AsyncLoggers::log(LoggersNames.ROOT, rec);

			m_run = false;

			break;
		}

		default:
			assert(false);
		}
	}
}

void WorkerThread::postMsg(UserData* data)
{
	// assert(m_thread);

	m_queue.post(data);

	// WorkerThreadMsg* threadMsg = new WorkerThreadMsg(MSG_POST_USER_DATA, data);
// 
	// unique_lock<mutex> lk(m_mutex);
	// m_queue.push(threadMsg);
	// m_cv.notify_one();
}

void WorkerThread::exitThread() {
	if (!m_thread) return;

	WorkerThreadMsg* msg =  new WorkerThreadMsg(MSG_EXIT_THREAD, 0);
	m_queue.post(msg);
	// {
		// std::lock_guard<mutex> lk(m_mutex);
		// m_queue.push(threadMsg);
		// m_cv.notify_one();
	// }
// 
	m_thread->join();
	delete m_thread;
	m_thread = 0;
}


void WorkerThread::timerThread() {
	while (!m_timerExit) 
	{
		this_thread::sleep_for(250ms);

		WorkerThreadMsg* threadMsg = new WorkerThreadMsg(MSG_TIMER, 0);

		// unique_lock<mutex> lk(m_mutex);
		m_queue.push(threadMsg);
		// m_cv.notify_one();
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
		m_cv.wait(lck, !m_queue.empty());
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

