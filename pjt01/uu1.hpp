
#ifndef __UU1_HPP
#define __UU1_HPP

#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <exception>
#include <unordered_map>
#include <vector>

enum MyTestCodeEnum {
	TC01=1,
	TC02,
	TC03,
	TC04,
	TC05 
}; 
class MyUU1
{
private:
	int age;
	std::string name;
	std::string desc;

	static bool checkPrime(unsigned int);

public:
	MyUU1() : age(-1) {}
	MyUU1(int _age, const std::string &_name, const std::string &_desc)
		: age(_age), name(_name), desc(_desc) {}
	MyUU1(const MyUU1 &o) : age(o.age), name(o.name), desc(o.desc) {}
	MyUU1(MyUU1 &&o) : age(o.age), name(std::move(o.name)), desc(std::move(o.desc)) {}
	MyUU1 &operator=(const MyUU1 &o) {
		if (this == &o)
			return *this;

		age = o.age;
		name = o.name;
		desc = o.desc;

		return *this;
	}
	MyUU1 &operator=(MyUU1 &&o) {
		if (this == &o)
			return *this;

		age = o.age;
		name = std::move(o.name);
		desc = std::move(o.desc);

		return *this;
	}

	friend std::ostream &operator<<(std::ostream &os, const MyUU1 &o) {
		os << "{" << o.age << ", " << o.name << ", " << o.desc << "}";
		return os;
	}

public:
	static void test04();
	static constexpr int mypow(int base, int exp) noexcept {
		return (exp == 0 ? 1 : base * MyUU1::mypow(base, exp - 1));
	}
	static int matoi(const char *s);
	static void makeLogEntry(void *ptr);
	static void testCode(const std::string &strNum, int argc, char* argv[], std::vector<std::string>& params);
	static void registerTestEnumCode(const std::string& strCode, const MyTestCodeEnum &e);
	static void unregisterTestEnumCode(const std::string& strCode);
	static void initTestEnumMap();
	static void testCInWithAsyncReader();
	static void testLList();
	static void testCode01(int threadCnt);
	static void testCode02();
	static void testCode03();
	static void testCode04();

	static void print2Arr(int (*arrp)[2], int n);
	static unsigned int findLessThanEqualPrime(unsigned int n);

private:
	static std::unordered_map<std::string, MyTestCodeEnum> testCodeEnumMap;
};

class Investment {
};

class Stock : public Investment {
};

class Bond : public Investment {
};

class RealEstate : public Investment {
};

#endif

#if 0

auto delInvmt = [](Investment *pInvestment) {
	MyUU1::makeLogEntry(pInvestment);
	delete pInvestment;
};
template <typename... Ts>
std::unique_ptr<Investment, decltype(delInvmt)>
makeInvestment(Ts &&... params)
{
	std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);
	if (0 == 0)
	{
		pInv.reset(new Stock(std::forward<Ts>(params)...));
	}
	else if (1 == 1)
	{
		pInv.reset(new Bond(std::forward<Ts>(params)...));
	}
	else if (2 == 2)
	{
		pInv.reset(new RealEstate(std::forward<Ts>(params)...));
	}
	else
	{
		throw std::exception("Unsupported Investment Type");
	}

	return pInv;
}

#endif

