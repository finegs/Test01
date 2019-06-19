
#ifndef __UU1_HPP
#define __UU1_HPP

#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <exception>

class MyUU1 {
	private:
		int age;
		std::string name;
		std::string desc;

	public:
		MyUU1() : age(-1), name(""), desc("") {}
		MyUU1(int _age, const std::string& _name, const std::string& _desc)
			: age(_age), name(_name), desc(_desc) {}
		MyUU1(const MyUU1& o) : age(o.age), name(o.name), desc(o.desc) {}
		MyUU1(MyUU1&& o) : age(o.age), name(std::move(o.name)), desc(std::move(o.desc)) {}
		MyUU1& operator=(const MyUU1& o) {
			if(this==&o) return *this;

			age = o.age;
			name = o.name;
			desc = o.desc;

			return *this;
		}
		MyUU1& operator=(MyUU1&& o) {
			if(this==&o) return *this;

			age = o.age;
			name = std::move(o.name);
			desc = std::move(o.desc);

			return *this;
		}

		friend
		std::ostream& operator<<(std::ostream& os, const MyUU1& o) {
			os << "{" << o.age << ", " << o.name << ", " << o.desc << "}";
			return os;
		}
};


class Investment {
};

class Stock : public Investment {
};

class Bond : public Investment {
};

class RealEstate : public Investment {
};

void makeLogEntry(void* ptr) {
	std::cout << "[D] " << ptr << std::endl;
}

auto delInvmt = [](Investment* pInvestment) {
	makeLogEntry(pInvestment);
	delete pInvestment;
};
template<typename ... Ts>
std::unique_ptr<Investment, decltype(delInvmt)>
makeInvestment(Ts&& ... params) {
	std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);
	if(0==0) {
		pInv.reset(new Stock(std::forward<Ts>(params)...));
	}
	else if (1==1) {
		pInv.reset(new Bond(std::forward<Ts>(params)...));
	}
	else if (2==2) {
		pInv.reset(new RealEstate(std::forward<Ts>(params)...));
	}
	else {
		throw std::exception("Unsupported Investment Type");
	}


	return pInv;
};

constexpr
int mypow(int base, int exp) noexcept {
	return (exp == 0 ? 1 : base * pow(base, exp -1));
}

int matoi(const char* s) {
	int n = 0;
	bool ne = false;
	if('-' == s[0]) { ne = true;s++; }
	while(s[0] != '\0' && '0' <= s[0] && '9' >= s[0]) {
		n = 10*n + (*s - '0');
		s++;
	}
	n = (ne ? -1 : 1) * n;
	return n;
}
#endif
