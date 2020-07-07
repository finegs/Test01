#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib> // defines putenv in POSIX
#include <vector>

void* operator new(size_t size) {
	std::cout << "Allocating " << size << " bytes";
	return malloc(size);
}

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

	int nInput;
	printf("n:"); fflush(stdout);
	scanf("%d", &nInput);

	printf("#######################");
    std::time_t t = std::time(nullptr);
    std::cout << "UTC:       " << std::put_time(std::gmtime(&t), "%c %Z") << "\n";
    std::cout << "local:     " << std::put_time(std::localtime(&t), "%c %Z") << "\n";
    // POSIX-specific:
    std::string tz = "TZ=Asia/Seoul";
    putenv((char*)tz.data());
    std::cout << "Seoul: " << std::put_time(std::localtime(&t), "%c %Z") << std::endl;

	std::cout << "aaaaaaaaaaa";
	std::vector<uint8_t> v;
	v.push_back((uint8_t)0);
	
	std::cout << " ##################" << std::endl;
	for(size_t i = 0;i<v.size();i++) {
		std::cout << std::to_string(v[i]);
		std::cout << ((i%5==0) ? "\n" : "\t");
	}
	std::cout << std::endl;
	std::cout << "Good" << std::endl;

	Object* o = new Object();

	Singleton& instance = Singleton::getInstance();

	instance.function();

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
