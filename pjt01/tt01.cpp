#if 0

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "uu1.hpp"
#include "mipc.hpp"

int main(int argc, char* argv[]) {

	MyUU1::testCode02();
	
	return EXIT_SUCCESS;
}

#endif

#if 1

#include <functional>
#include <iostream>
#include <queue>
#include <mutex>
#include "u.hpp"
#include "uu1.hpp"
#include "mipc.hpp"

extern bool T_IS_EXIT;
extern bool T_IS_DEBUG;

std::queue<std::string> MyIPC::cmdQueue;
std::mutex              MyIPC::q_cmdQueue_mtx;

struct Foo {
	Foo(int _num) : num (_num) {}
	void print_add(int i) const { std::cout << num+i << std::endl; }
	int num;
};

void print_num(int i) {
	std::cout << i << std::endl;
};

struct PrintNum {
	void operator()(int i) const {
		std::cout << i << std::endl;
	}
};

using t_cb01 = std::function<void(int,char* [])>;

std::unordered_map<int, t_cb01> funcMap;

void t01(int argc, char* argv[]) {
	std::cout << "t01" << std::endl;

	for(int i = 0;i<argc;i++) {
		std::cout << (i!=0 ? ", " : "") << "argv["<< i << "]="<< argv[i] << "\t"<<std::endl;
	}
}

int main(int argc, char* argv[]) {
	
	funcMap.insert(std::make_pair<int, t_cb01>(1, t01));

	funcMap[1](argc, argv);

	T_IS_EXIT = false;
	T_IS_DEBUG = false;

	std::function<void(int)> f_display = print_num;
	f_display(-9);

	std::function<void()> f_display_42 = []() { print_num(42);};
	f_display_42();

	std::function<void()> f_display_31337 = std::bind(print_num, 31337);
	f_display_31337();

	std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
	const Foo foo(314156);
	f_add_display(foo, 1);
	f_add_display(314159, 1);

	std::function<int(Foo const&)> f_num = &Foo::num;
	std::cout << "num : " << f_num(foo) << std::endl;

 	using std::placeholders::_1;
	std::function<void(int)> f_add_display2 = std::bind(&Foo::print_add, foo, _1);
	f_add_display2(2);

	std::function<void(int)> f_add_display3 = std::bind(&Foo::print_add, &foo, _1);
	f_add_display3(3);

	std::function<void(int)> f_display_obj = PrintNum();
	f_display_obj(18);

	return EXIT_SUCCESS;
}

#endif
