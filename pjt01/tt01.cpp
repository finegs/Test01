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

#if 0

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


#if 0

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <memory>


using namespace std;

class Entity {
	private:
		std::string m_Name;

	public:
		Entity() : m_Name("unknown") {}
		~Entity() { cout << "~Entity() " << *this << endl; };
		Entity(const std::string& name) : m_Name(name) {}
		Entity(const Entity& o) : m_Name(o.m_Name) {}
		Entity(Entity&& o) : m_Name(std::move(o.m_Name)) {}
		Entity& operator=(const Entity& o) {
			if(this==&o) return *this;
			m_Name = o.m_Name;
			return *this;
		}
		Entity& operator=(Entity&& o) {
			if(this==&o) return *this;
			m_Name = std::move(o.m_Name);
			return *this;
		}

		const std::string& getName() const { return m_Name; }

		friend
		std::ostream& operator<<(std::ostream& os, const Entity& o) {
			os << o.m_Name;
			return os;
		}
};

Entity*  newEntity(const std::string& name) {
	Entity* e = new Entity(name);
	cout << "newEntity : " << *e << endl;
	return e;
}


int main(int argc, char* argv[]) {
	
	Entity* e;
	{
		Entity* ie = new Entity("bbbb");

		e = ie;

		cout << *ie << endl;

		delete ie;
	}

	Entity* ee[10];
	for(int i = 0;i <10;i++) {
		ee[i] = new Entity("name_"s + i);
	}

	for(int i = 0;i <10;i++) {
		cout << "ee[" << i << "] = " <<  *(ee[i]) << endl;
	}

	for(int i = 0;i <10;i++) {
		delete ee[i];
	}
	
	delete e;

	cout << "==========" << endl;
	cout << "main : " << newEntity("@@@@") << endl;

	return EXIT_SUCCESS;
}

#endif

#if 0

// CPP program to illustrate assigning 
// *char value to other variable 
#include <iostream> 
#include "u.hpp"
using namespace std; 

int main() 
{ 
	// This initialization gives warning in C++. 
	// "deprecated conversion from string constant 
	// to 'char*'" 
	char str[] = {"Hello"}; 

	const char str1[] = {"Hello"}; // No warning 


	// trying to modify const string literal 
	// gives Runtime error 
	str[1] = 'o'; 

	cout << str << endl; 

	PacketHeader hd =  {.b0 = 0, .b7 = 0};
	cout << hd << endl;

	return 0; 
} 



#endif

#if 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include <threads.h> // pthread.h in POSIX
#include <pthread.h> // pthread.h in POSIX
 
// the function f() does some time-consuming work
///int f(void* thr_data) // return void* in POSIX
void* f(void* thr_data) // return void* in POSIX
{
    volatile double d = 0;
    for (int n=0; n<10000; ++n)
       for (int m=0; m<10000; ++m)
           d += d*n*m;
    return 0;
}

 
int main(void)
{
    struct timespec ts1, tw1; // both C11 and POSIX
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1); // POSIX
    clock_gettime(CLOCK_MONOTONIC, &tw1); // POSIX; use timespec_get in C11
    clock_t t1 = clock();
 
   // thrd_t thr1, thr2;  // C11; use pthread_t in POSIX
//    thrd_t thr1, thr2;  // C11; use pthread_t in POSIX
//    thrd_create(&thr1, f, NULL); // C11; use pthread_create in POSIX
//    thrd_create(&thr2, f, NULL);
//    thrd_join(thr1, NULL); // C11; use pthread_join in POSIX
//    thrd_join(thr2, NULL);


    pthread_t thr1, thr2;  // C11; use pthread_t in POSIX
    pthread_create(&thr1, NULL, f, NULL); // C11; use pthread_create in POSIX
    pthread_create(&thr2, NULL, f, NULL);
    pthread_join(thr1, NULL); // C11; use pthread_join in POSIX
    pthread_join(thr2, NULL);
 
    struct timespec ts2, tw2;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2);
    clock_gettime(CLOCK_MONOTONIC, &tw2);
    clock_t t2 = clock();
 
    double dur = 1000.0*(t2-t1)/CLOCKS_PER_SEC;
    double posix_dur = 1000.0*ts2.tv_sec + 1e-6*ts2.tv_nsec
                       - (1000.0*ts1.tv_sec + 1e-6*ts1.tv_nsec);
    double posix_wall = 1000.0*tw2.tv_sec + 1e-6*tw2.tv_nsec
                       - (1000.0*tw1.tv_sec + 1e-6*tw1.tv_nsec);
 
    printf("CPU time used (per clock(): %.2f ms\n", dur);
    printf("CPU time used (per clock_gettime()): %.2f ms\n", posix_dur);
    printf("Wall time passed: %.2f ms\n", posix_wall);
}

#endif
