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

void* operator new(size_t size) {
	std::cout << "Allocating " << size << " bytes" << std::endl;
	return malloc(size);
}

class MyTimeStamp {
	private:

	MyTimeStamp() {}

	public:
	static MyTimeStamp ts() {
		MyTimeStamp a;
		return a;
	}
	friend std::ostream& operator<<(std::ostream& os, const MyTimeStamp& o);
};

std::ostream& operator<<(std::ostream& os, const MyTimeStamp& o) {
    using namespace std::chrono;

    // get current time
    auto now = system_clock::now();

    // get number of milliseconds for the current second
    // (remainder after division into seconds)
    auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

    // convert to std::time_t in order to convert to std::tm (broken time)
    auto timer = system_clock::to_time_t(now);

    // convert to broken time
    std::tm bt = *std::localtime(&timer);

    std::ostringstream oss;

    oss << std::put_time(&bt, "%H:%M:%S"); // HH:MM:SS
    oss << '.' << std::setfill('0') << std::setw(3) << ms.count();
	oss << " : ";

	os << oss.str();

	return os;
};

struct Object {
	int x,y,z;
};

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


int main() {

#if 0
	int nInput;
	printf("n:"); fflush(stdout);
	scanf("%d", &nInput);

	std::cout << MyTimeStamp::ts() << ("#######################\n");
    std::time_t t = std::time(nullptr);
    std::cout << MyTimeStamp::ts() << "UTC:       " << std::put_time(std::gmtime(&t), "%c %Z") << "\n";
    std::cout << MyTimeStamp::ts() << "local:     " << std::put_time(std::localtime(&t), "%c %Z") << "\n";
    // POSIX-specific:
    std::string tz = "TZ=Asia/Seoul";
    putenv((char*)tz.data());
    std::cout << MyTimeStamp::ts() << "Seoul: " << std::put_time(std::localtime(&t), "%c %Z") << std::endl;

	std::vector<uint8_t> v;
	v.push_back((uint8_t)0);
	
	std::cout << MyTimeStamp::ts() << " ##################" << std::endl;
	std::cout << MyTimeStamp::ts();
	for(size_t i = 0;i<v.size();i++) {
		std::cout << std::to_string(v[i]);
		std::cout << ((i%5==0) ? "\n" : "\t");
	}
	std::cout << std::endl;
	std::cout << MyTimeStamp::ts() << "Good" << std::endl;

	Object* o = new Object();

	Singleton& instance = Singleton::getInstance();

	instance.function();

	std::cout << MyTimeStamp::ts() << "Enter any keyboard : "; std::cout.flush();

#endif

	std::string m = "Hello";
	m.insert(3, "  ");
	m.replace(3, 2, "");

	m.replace(m.find("Hell"), 4, "****");
	std::cout << m << std::endl;



	std::string line;
	std::getline(std::cin, line);

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
