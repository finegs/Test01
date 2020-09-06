#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib> // defines putenv in POSIX
#include <vector>
#include <string>
#include <chrono>
#include <sstream>
#include <my.hpp>
#include <utility>
#include <functional>

void* operator new(size_t size, std::align_val_t al) {
	std::cout << "Allocating " << size << " bytes" << std::endl;
	return malloc(size);
}

void* operator new[](size_t size, std::align_val_t al) {
	std::cout << "Allocating " << size << " bytes" << std::endl;
	return malloc(size);
}

struct Object {
	int x,y,z;
	friend std::ostream& operator<<(std::ostream& os, const Object& o);
};

std::ostream& operator<<(std::ostream& os, const Object& o) {
	os << "{" << o.x << "," << o.y << "," << o.z << ")";
	return os;
}


class Singleton {
	public:
		static Singleton& getInstance() {
			return s_Instance;
		}

		void function() {
		}

	private:
		Singleton() {}
		Singleton(const Singleton&) = delete;

		static Singleton s_Instance;
};

Singleton Singleton::s_Instance;


template<typename T>
T passR(T&& arg) {
	std::remove_reference_t<T> x;
	x = arg*arg;
	arg += x;
	return arg;
}

template<typename T>
T add(T&& o) {
	o++;
	return o;
}

template<typename T>
void g(T&);
template<typename T>
void g(T const&);
template<typename T>
void g(T&&);

template<typename T>
void forwardToG(T&& x) {
	g(std::forward<T>(x));
}

class Clz {
	public:
		std::string name;
	friend std::ostream& operator<<(std::ostream& os, const Clz& o);
};

std::ostream& operator<<(std::ostream& os, const Clz& o) {
	os << "{\"name\":" << "\"" << o.name << "\"}";
	return os;
}

// template<typename T>
void g(Clz& o) {
	std::cout << "T& : " <<  o << '\n';
}

void g(Clz const& o) {
	std::cout << "T const& : " <<  o << '\n';
}

void g(Clz&& o) {
	std::cout << "T&& : " <<  o << '\n';
}

using namespace std;

int main() {

// passR(42);
// int i;
// passR(i);

	{
		std::unique_ptr<Object[]> aaa = std::make_unique<Object[]>(10);

		aaa[0].x = 100;
		aaa[9].z = 200;

		int ii = 0;
		cout <<  __LINE__ << " : " << '\n';
		for_each(next(aaa.get(), 0), next(aaa.get(), 10), [&](Object& o) {
			o.z = o.x*1 + o.y*2 + ii++;
		});
		cout << '\n';

		cout <<  __LINE__ << " : " << '\n';
		for_each(&aaa[0], &aaa[10], [] (Object& o) { cout << o << ",";});
		cout << '\n';

		cout <<  __LINE__ << " : " << '\n';
		for_each(std::next(aaa.get(), 0), next(aaa.get(), 10), [](const Object& o) {
			cout << o << ',';
		});
		cout << '\n';
	}

	int i;
	cout << " i : "; cout.flush();
	cin >> i;
	cin.clear(); 
	cout << "add(" << i << ") : " << passR(i) << endl;

	// string l;
	// getline(cin, l);

	Clz cc;
	cc.name = "Name";
	forwardToG(cc);

	system("pause");

#if 0
	int nInput;
	printf("n:"); fflush(stdout);
	scanf("%d", &nInput);

	std::cout << my::ts() << ("#######################\n");
    std::time_t t = std::time(nullptr);
    std::cout << my::ts() << "UTC:       " << std::put_time(std::gmtime(&t), "%c %Z") << "\n";
    std::cout << my::ts() << "local:     " << std::put_time(std::localtime(&t), "%c %Z") << "\n";
    // POSIX-specific:
    std::string tz = "TZ=Asia/Seoul";
    putenv((char*)tz.data());
    std::cout << my::ts() << "Seoul: " << std::put_time(std::localtime(&t), "%c %Z") << std::endl;

	std::vector<uint8_t> v;
	v.push_back((uint8_t)0);
	
	std::cout << my::ts() << " ##################" << std::endl;
	std::cout << my::ts();
	for(size_t i = 0;i<v.size();i++) {
		std::cout << std::to_string(v[i]);
		std::cout << ((i%5==0) ? "\n" : "\t");
	}
	std::cout << std::endl;
	std::cout << my::ts() << "Good" << std::endl;

	Object* o = new Object();

	Singleton& instance = Singleton::getInstance();

	instance.function();

	std::cout << my::ts() << "Enter any keyboard : "; std::cout.flush();

#endif

#if 0
	std::string m = "Hello";
	m.insert(3, "  ");
	m.replace(3, 2, "");

	m.replace(m.find("Hell"), 4, "****");
	std::cout << my::ts() << m << std::endl;

	std::string line;
	std::getline(std::cin, line);
#endif

#if 0
	EFEM Temp
	int nInput = 0;
	int n2;
	// int i = 0;

	printf("Enter Number:"); fflush(stdout);
	scanf("%d", &nInput);fflush(stdin);

	if(nInput<1) nInput = 1;
	printf("2-Comp(%d) : %d\n", nInput, n2=(~nInput)+1);
	printf("OV(%d) : %d\n", nInput, (~n2)+1);
	printf("-OV(%d) : %d\n", nInput, ((1<<31) | nInput)+1);
	printf("~OV(%d) : %d\n", nInput, ~nInput);
	printf("1<<31(%d) : %d\n", 1, 1<<31);
	int n3=nInput;
	for(int i = 0;i<31;i++) {
		n3 <<=1; n3|=1;
	}
	printf("OV(%d)<<1 |1 = %d\n", nInput, n3);
#endif

#if 0
	std::vector<uint8_t> v;
	else if(nInput>9) nInput = 9;

	while(i<nInput) {
		putchar('*');
		i++;
	}
	getchar();
	putchar('\n');
#endif
	return 0;
}
