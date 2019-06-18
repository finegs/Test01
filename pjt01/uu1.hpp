
#ifndef __UU1_HPP
#define __UU1_HPP

#include <iostream>
#include <string>
#include <utility>

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

#endif
