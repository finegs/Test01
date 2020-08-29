#ifndef __MY_HPP__
#define __MY_HPP__

#include <iostream>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>

namespace my {
	class TimeStamp {
		public:
		friend std::ostream& operator<<(std::ostream& os, const TimeStamp& o);
	};

	static inline TimeStamp ts() { return TimeStamp(); }

	class MyInst
	{
	private:
		MyInst() 
		{
			run.store(true);
			pause.store(false);	
		}
		std::mutex mtx;
		std::condition_variable cv;
		std::queue<std::string> queue;
		static std::mutex s_mtx;
		static MyInst *inst;

	public:
		static MyInst &getInstance();
		std::atomic_bool run;
		std::atomic_bool pause;

		void push(std::string msg);
		std::string pop();
		void clearQueue();
	};

};

#endif