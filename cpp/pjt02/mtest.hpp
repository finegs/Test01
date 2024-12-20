#ifndef _MTEST_HPP
#define _MTEST_HPP

#include <ctime>
#include <chrono>
#include <iostream>
#include <thread>
#include <sstream>
#include <unordered_map>

#define INT_BITS 32


class MTest {
	private:
		static std::unordered_map<std::thread::id, unsigned int> timeMap; 


	public:
		static void setCurrentTimestamp() {
			// struct timespec ts; 
      		// clock_gettime(CLOCK_REALTIME, &ts);
			// timeMap[std::this_thread::get_id()] = ts.tv_nsec;
			timeMap[std::this_thread::get_id()] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		}

		static unsigned int getDiffTime() {
			// struct timespec ts;
			// clock_gettime(CLOCK_REALTIME, &ts);
			// return ts.tv_nsec - timeMap[std::this_thread::get_id()];
			return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - timeMap[std::this_thread::get_id()];
		}

	int leftRotate(int n, unsigned int d) {
		return (n<<d)|(n>>(INT_BITS -d));
	}

	int rightRotate(int n, unsigned int d) {
		return (n>>d)|(n<<(INT_BITS-d));
	}

	unsigned int countSetBits(unsigned int n) {
		// TODO : countSetBits :://www.geeksforgeeks.org/count-set-bits-in-an-integer/ 
		int c = 0;
		int j = 32;
		while(j-->0) {
			if(n&1) c++;
			n<<=1;
		}
		return c;
	}
};



#endif
