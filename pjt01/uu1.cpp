
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <exception>
#include <sstream>
#include <functional>
#include <thread>
#include <chrono>

#include "inc/uu1.hpp"

// create MyUU1::testCodeEnumMap field
std::unordered_map<std::string, MyTestCodeEnum> MyUU1::testCodeEnumMap;

void MyUU1::registerTestEnumCode(std::string& strCode, MyTestCodeEnum& e) {
	if(testCodeEnumMap.count(strCode)) {
//		std::stringstream ss("TestCodeEnum is already registered");
//		ss << ", Code : " << strCode;
//		throw std::exception(ss.str());
		throw std::runtime_error("MyUU1::registerTestEnumCode() : Duplicated TestCodeEnum , Code = " + strCode);
	}
	testCodeEnumMap.emplace(strCode,e);
}

void MyUU1::unregisterTestEnumCode(std::string& strCode) {
	testCodeEnumMap.erase(strCode);
};

void MyUU1::initTestEnumMap() {
	testCodeEnumMap.emplace("TC01", MyTestCodeEnum::TC01);
	testCodeEnumMap.emplace("TC02", MyTestCodeEnum::TC02);
	testCodeEnumMap.emplace("TC03", MyTestCodeEnum::TC03);
};

void MyUU1::test04() {
//std::unordered_map<std::string, std::string> mm = 
	std::unordered_multimap<std::string, std::string> mm1 = 
		{{"1", "0000"}, 
			{"1", "00"}, 
			{"1", "11"}, 
			{"2", "22"}, 
			{"3", "33"}, 
			{"4", "44"}};

	auto range = mm1.equal_range("2");
	for(auto it = range.first;it != range.second;++it) {
		std::cout << it->first << ' ' << it->second << '\n';
	}

	int n = 0;
	std::for_each(mm1.begin(), mm1.end(), [&](auto& it) {
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

using std::initializer_list;
template<typename T, typename... Args>
T createT(Args&&... args) {
	return T(std::forward<Args>(args)...);
};

void MyUU1::testCode(const std::string& strCode) {
	MyTestCodeEnum& e = testCodeEnumMap[strCode];
	std::cout << "test : " << strCode << " is initiated. " << std::endl;
	switch(e) {
		case TC01:
			{
				MyUU1::testCInWithAsyncReader();
			}
		break;
		case TC02:
			{
				// TODO : TC02
			}
		break;
		case TC03:
			{
				// TODO : TC03
			}
		break;

		default:
		{
		}
	}

	std::cout << "test : " << strCode << " is done. " << std::endl;

};

void testCInWithAsyncReader() {
				// TODO : TC01
#if 0
				auto r = std::minmax({1, 100});
				std::cout << "std::minmax(1, 100), min = " << r.first << ", max=" << r.second << std::endl;
#endif

				int a = createT<int>();
				int b = createT<int>(12);

				int c = createT<int>(1+1+3+3+4);
				My d1 = createT<My>(1, "aaa", 3.8);

				std::cout << "a : " << a << std::endl;
				std::cout << "b : " << b << std::endl;
				std::cout << "c : " << c << std::endl;
				std::cout << "d1 : " << d1 << std::endl;

				std::function<int(int)> ff01 = [&](int tId) {
					using namespace std::chrono_literals;
					std::string line;
					bool run = true;
					while(run) {
						std::cin.clear();
						std::cout << tId << " # function<int(void)> is running." << std::endl;
						std::cout << tId << " # enter command : ( -q : quit )";
						std::cout.flush();
					//	std::cin >> line;
						std::cin.clear();

						if("-q" == line || "-exit" == line) { run = false; continue; }
						std::cout << tId << " # your command : " << line << std::endl;

						std::this_thread::sleep_for(100ms);
					//	system("pause");
					};
					std::cout << tId << " # thread is done. "<< std::endl;
					return EXIT_SUCCESS;
				};

				for (int i = 0;i < 1;i++) {
					std::thread t(ff01, i);
				}
}

