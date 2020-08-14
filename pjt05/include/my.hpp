#ifndef __MY_HPP__
#define __MY_HPP__

#include <iostream>
#include <chrono>

namespace my {
	class TimeStamp {
		public:
		friend std::ostream& operator<<(std::ostream& os, const TimeStamp& o);
	};

	static inline TimeStamp ts() { return TimeStamp(); }
}

#endif