#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib> // defines putenv in POSIX
#include <vector>

//template<typename T>
//int m_for_each(const std::vector<T>& v, int(*func)(T t)) {
//	for(T t : v) func(t);
//	return 0;
//}

int m_for_each(const std::vector<uint8_t>& values, int(*func)(uint8_t t)) {
	for(uint8_t t:values) func(t);
	return 0;
}

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

	std::vector<uint8_t> v;
	
	for(int i=0;i<nInput;i++) v.push_back((uint8_t)nInput);

	std::cout << " ##################" << std::endl;
	
	m_for_each(v, [](uint8_t i) { std::cout<<std::to_string(i); std::cout<<((i%5==0)?"\n":"\t"); return 0;});

	std::cout << std::endl;
	std::cout << "Good" << std::endl;

	std::cin.get();

#if 0
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
