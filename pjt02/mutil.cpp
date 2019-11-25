#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

char* mstrtok(char* _str, const char* _delim) {
	static char* pstr;
//	static char bdelim;
	const char* pdelim;
	size_t len;

	len = 0;
	if(NULL == _str) {
		_str = pstr;
//		if(!*pstr) // replace previous null-terminator '\0' with previous delimeter
//			*(pstr-1)=bdelim;
	}
	else {
		pstr = _str;
	}

	while(*pstr) {
		pdelim = _delim;

		while(*pdelim) {
			if(len != 0 && *pstr == *pdelim) {
//				bdelim = *pdelim;
				*pstr = '\0'; 
				pstr++;
				return _str;
			}
			pdelim++;
		}
		pstr++;
		len++;
	}
	return _str;
}

std::string getTimestamp() {
  // get a precise timestamp as a string
  const auto now = std::chrono::system_clock::now();
  const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
  const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(
      now.time_since_epoch()) % 1000;
  std::stringstream nowSs;
  nowSs
	  << std::put_time(std::localtime(&nowAsTimeT), "%Y-%m-%d %H:%M:%S")
   //   << std::put_time(std::localtime(&nowAsTimeT), "%a %b %d %Y %T")
      << '.' << std::setfill('0') << std::setw(3) << nowMs.count();
  return nowSs.str();
}

