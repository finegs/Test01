#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

#include <my.hpp>

namespace my
{

	std::ostream &operator<<(std::ostream &os, const TimeStamp &o)
	{
		using namespace std::chrono;

		// get current time
		auto now = system_clock::now();

		// get number of milliseconds for the current second
		// (remainder after division into seconds)
		auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

		// convert to std::time_t in order to convert to std::tm (broken time)
		auto timer = system_clock::to_time_t(now);

		// convert to broken time
		std::tm bt = *std::localtime(&timer);

		std::ostringstream oss;

		oss << std::put_time(&bt, "%H:%M:%S"); // HH:MM:SS
		oss << '.' << std::setfill('0') << std::setw(3) << ms.count();
		oss << " : ";

		os << oss.str();
		return os;
	}

	MyInst& MyInst::getInstance()
	{
		if (inst != NULL)
			return *inst;
		std::lock_guard<std::mutex> lg(s_mtx);
		if (inst == NULL)
			inst = new MyInst();
		return *inst;
	}

	void MyInst::push(std::string msg)
	{
		std::unique_lock<std::mutex> lk(mtx);

		cv.wait(lk, [&]() { return queue.size() < 10; });

		queue.push(msg);

		cv.notify_all();
	}

	std::string MyInst::pop()
	{
		std::unique_lock<std::mutex> lk(mtx);
		cv.wait(lk, [&]() { return !queue.empty(); });

		std::string msg = queue.front();
		queue.pop();
		// lk.unlock();
		cv.notify_all();
		return msg;
	}

	void MyInst::clearQueue()
	{

		if (queue.empty())
			return;
		std::unique_lock<std::mutex> lk(mtx);

		std::queue<std::string> eq;
		std::swap(queue, eq);
		// lk.unlock();
		// cv.notify_all();
	}

	std::mutex MyInst::s_mtx;
	MyInst* MyInst::inst = nullptr;
} // namespace my
