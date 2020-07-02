#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib> // defines putenv in POSIX
#include <vector>
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
	v.push_back((uint8_t)1);
	v.push_back((uint8_t)2);
	v.push_back((uint8_t)3);
	v.push_back((uint8_t)4);
	v.push_back((uint8_t)5);
	v.push_back((uint8_t)6);
	v.push_back((uint8_t)7);
	v.push_back((uint8_t)8);
	v.push_back((uint8_t)9);
	v.push_back((uint8_t)10);
	v.push_back((uint8_t)11);
	v.push_back((uint8_t)12);
	v.push_back((uint8_t)13);
	v.push_back((uint8_t)14);
	v.push_back((uint8_t)15);
	v.push_back((uint8_t)16);
	v.push_back((uint8_t)17);
	v.push_back((uint8_t)18);
	v.push_back((uint8_t)19);
	v.push_back((uint8_t)20);
	v.push_back((uint8_t)21);
	v.push_back((uint8_t)22);
	v.push_back((uint8_t)23);
	v.push_back((uint8_t)24);
	v.push_back((uint8_t)25);
	v.push_back((uint8_t)26);
	v.push_back((uint8_t)27);
	v.push_back((uint8_t)28);
	v.push_back((uint8_t)29);
	v.push_back((uint8_t)30);
	v.push_back((uint8_t)31);
	v.push_back((uint8_t)32);
	v.push_back((uint8_t)33);
	v.push_back((uint8_t)34);
	v.push_back((uint8_t)35);
	v.push_back((uint8_t)36);
	v.push_back((uint8_t)37);
	v.push_back((uint8_t)38);
	v.push_back((uint8_t)39);
	v.push_back((uint8_t)40);
	v.push_back((uint8_t)41);
	v.push_back((uint8_t)42);
	v.push_back((uint8_t)43);
	v.push_back((uint8_t)44);
	v.push_back((uint8_t)45);
	v.push_back((uint8_t)46);
	v.push_back((uint8_t)47);
	v.push_back((uint8_t)48);
	v.push_back((uint8_t)49);
	v.push_back((uint8_t)50);
	v.push_back((uint8_t)51);
	v.push_back((uint8_t)52);
	v.push_back((uint8_t)53);
	v.push_back((uint8_t)54);
	v.push_back((uint8_t)55);
	v.push_back((uint8_t)56);
	v.push_back((uint8_t)57);
	v.push_back((uint8_t)58);
	v.push_back((uint8_t)59);
	v.push_back((uint8_t)60);
	v.push_back((uint8_t)61);
	v.push_back((uint8_t)62);
	v.push_back((uint8_t)63);
	v.push_back((uint8_t)64);
	v.push_back((uint8_t)65);
	v.push_back((uint8_t)66);
	v.push_back((uint8_t)67);
	v.push_back((uint8_t)68);
	v.push_back((uint8_t)69);
	v.push_back((uint8_t)70);
	v.push_back((uint8_t)71);
	v.push_back((uint8_t)72);
	v.push_back((uint8_t)73);
	v.push_back((uint8_t)74);
	v.push_back((uint8_t)75);
	v.push_back((uint8_t)76);
	v.push_back((uint8_t)77);
	v.push_back((uint8_t)78);
	v.push_back((uint8_t)79);
	v.push_back((uint8_t)80);
	v.push_back((uint8_t)81);
	v.push_back((uint8_t)82);
	v.push_back((uint8_t)83);
	v.push_back((uint8_t)84);
	v.push_back((uint8_t)85);
	v.push_back((uint8_t)86);
	v.push_back((uint8_t)87);
	v.push_back((uint8_t)88);
	v.push_back((uint8_t)89);
	v.push_back((uint8_t)90);
	v.push_back((uint8_t)91);
	v.push_back((uint8_t)92);
	v.push_back((uint8_t)93);
	v.push_back((uint8_t)94);
	v.push_back((uint8_t)95);
	v.push_back((uint8_t)96);
	v.push_back((uint8_t)97);
	v.push_back((uint8_t)98);
	v.push_back((uint8_t)99);
	v.push_back((uint8_t)100);
	v.push_back((uint8_t)101);

	std::cout << " ##################" << std::endl;
	for(size_t i = 0;i<v.size();i++) {
		std::cout << std::to_string(v[i]);
		std::cout << ((i%5==0) ? "\n" : "\t");
	}
	std::cout << std::endl;
	std::cout << "Good" << std::endl;

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
