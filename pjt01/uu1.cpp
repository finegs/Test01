
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <exception>
#include <sstream>

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

using std::initializer_list;

template<typename T, typename... Args>
T createT(Args&&... args) {
	return T(std::forward<Args>(args)...);
};

class MyData01 {
	private:
		int a;
		std::string b;
		float c;
	public:
		MyData01() : a(-1), b(""), c(-1) {}
		MyData01(int _a, const std::string& _b, float _c) : a(_a), b(_b), c(_c) {}
		friend std::ostream& operator<<(std::ostream& os, const MyData01& o);

};

std::ostream& operator<<(std::ostream& os, const MyData01& o) {
	os << "(" << o.a << ", " << o.b << ", " << o.c << ")";
	return os;
}

void MyUU1::testCode(const std::string& strCode) {
	MyTestCodeEnum& e = testCodeEnumMap[strCode];
	std::cout << "test : " << strCode << " is initiated. " << std::endl;
	switch(e) {
		case TC01:
			{
				// TODO : TC01
#if 0
				auto r = std::minmax({1, 100});
				std::cout << "std::minmax(1, 100), min = " << r.first << ", max=" << r.second << std::endl;
#endif

				int a = createT<int>();
				int b = createT<int>(12);
				MyData01 d1 = createT<MyData01>(1, "aaa", 3.8);

				std::cout << "d1 :" << d1 << std::endl;
				
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
