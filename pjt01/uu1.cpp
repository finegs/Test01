
#include <iostream>
#include <unordered_map>
#include <algorithm>

#include "uu1.hpp"

void MyUU1::test04() {
//std::unordered_map<std::string, std::string> mm = 
	std::unordered_multimap<std::string, std::string> mm = 
		{{"1", "0000"}, 
			{"1", "00"}, 
			{"1", "11"}, 
			{"2", "22"}, 
			{"3", "33"}, 
			{"4", "44"}};

	auto range = mm.equal_range("2");
	for(auto it = range.first;it != range.second;++it) {
		std::cout << it->first << ' ' << it->second << '\n';
	}

	int n = 0;
	std::for_each(mm.begin(), mm.end(), [&](auto& it) {
		std::cout << "[" << n++ << "] " << it.first << ", " << it.second << std::endl;
	});
};

//constexpr
//int MyUU1::mypow(int base, int exp) noexcept {
//	return (exp == 0 ? 1 : base * MyUU1::mypow(base, exp -1));
//};


int MyUU1::matoi(const char* s) {
	int n = 0;
	bool ne = false;
	if('-' == s[0]) { ne = true;s++; }
	while(s[0] != '\0' && '0' <= s[0] && '9' >= s[0]) {
		n = 10*n + (*s - '0');
		s++;
	}
	n = (ne ? -1 : 1) * n;
	return n;
};

void MyUU1::makeLogEntry(void* p) {
	std::cout << "[D] " << p << std::endl;
};

