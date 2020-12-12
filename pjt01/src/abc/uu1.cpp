
#include <iostream>
#include <algorithm>
#include <utility>
#include <exception>
#include <sstream>
#include <functional>
#include <thread>
#include <chrono>
#include <list>
#include <cmath>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <map>


#include "u.hpp"
#include "uu1.hpp"
#include "mipc.hpp"


// create MyUU1::testCodeEnumMap field
std::unordered_map<std::string, MyTestCodeEnum> MyUU1::testCodeEnumMap;

void MyUU1::registerTestEnumCode(const std::string& strCode, const MyTestCodeEnum& e)
{
	if (testCodeEnumMap.count(strCode))
	{
		//		std::stringstream ss("TestCodeEnum is already registered");
		//		ss << ", Code : " << strCode;
		//		throw std::exception(ss.str());
		throw std::runtime_error("MyUU1::registerTestEnumCode() : Duplicated TestCodeEnum , Code = " + strCode);
	}
	testCodeEnumMap.emplace(strCode, e);

	// if (T_IS_DEBUG)
		// std::cout << "[D] MyUU1::testCodeEnumMap.registerTestEnumCode" << strCode << ", " << e << std::endl;

}

void MyUU1::unregisterTestEnumCode(const std::string &strCode)
{
	testCodeEnumMap.erase(strCode);
}

void MyUU1::initTestEnumMap()
{
	registerTestEnumCode("TC01", MyTestCodeEnum::TC01);
	registerTestEnumCode("TC02", MyTestCodeEnum::TC02);
	registerTestEnumCode("TC03", MyTestCodeEnum::TC03);
	registerTestEnumCode("TC04", MyTestCodeEnum::TC04);
	registerTestEnumCode("TC05", MyTestCodeEnum::TC05);
}

void MyUU1::test04()
{
	//std::unordered_map<std::string, std::string> mm =
	std::unordered_multimap<std::string, std::string> mm1 =
		{{"1", "0000"},
		 {"1", "00"},
		 {"1", "11"},
		 {"2", "22"},
		 {"3", "33"},
		 {"4", "44"}};

	auto range = mm1.equal_range("2");
	for (auto it = range.first; it != range.second; ++it)
	{
		std::cout << it->first << ' ' << it->second << '\n';
	}

	int n = 0;
//	std::for_each(mm1.begin(), mm1.end(), [&](std::pair<std::string, std::string>& it) {
	std::for_each(mm1.begin(), mm1.end(), [&](auto& it) {
		std::cout << "[" << n++ << "] " << it.first << ", " << it.second << std::endl;
	});

}

int MyUU1::test06() {
	using namespace std;
	
	unsigned short us = 0xff00;
	short s = (short)0xff00;

	unsigned short us_shift = us >> 4;
	short s_shift_r =  s >> 4;

	cout << "\t\tus = " << bitset<16>(us) << "(" << us << ")\n";
	cout << "\t\ts = " << bitset<16>(s) << "(" << s << ")\n";
	cout << "\t\tus >> 4 = " << bitset<16>(us_shift) << "(" << us_shift << ")\n";
	cout << "\t\ts << 4 = " << bitset<16>(s_shift_r) << "(" << s_shift_r << ")\n";

	return EXIT_SUCCESS;
}


int MyUU1::test07() {
	using namespace std;

	float sum = 0.0;
	for(int i = 0;i < 1000;i++) {
		sum += 0.1;
	}

	cout<< "sum(0.1 x 1000) = " << sum << std::endl;

	return EXIT_SUCCESS;
}


int MyUU1::test08(int argc, char* argv[]) {
	int cnt = 10000;	
	std::stringstream ss;

	for(int i = 1;i<argc;i++) { 
		if(!strcmp("-test08.cnt", argv[i]) && i+1<argc) { 
			cnt = atoi(argv[i+1]);i++;
			break;
		}
	}

	char a[100];
	std::srand(std::time(nullptr));
	
	using namespace std;
	for(int i = 0;i<cnt;i++) {
		sprintf(a, "%c{ y:'%d', a:%d, b:%d }\n",(i>0?',':' '), 1900+(i%200), rand()%100, rand()%100);
		ss<<a;
	}

	std::cout << ss.str() << std::endl;
		
	return EXIT_SUCCESS;
}

//constexpr
//int MyUU1::mypow(int base, int exp) noexcept {
//	return (exp == 0 ? 1 : base * MyUU1::mypow(base, exp -1));
//};

int MyUU1::matoi(const char *s)
{
	int n = 0;
	bool ne = false;
	if ('-' == s[0])
	{
		ne = true;
		s++;
	}
	while (s[0] != '\0' && '0' <= s[0] && '9' >= s[0])
	{
		n = 10 * n + (*s - '0');
		s++;
	}
	n = (ne ? -1 : 1) * n;
	return n;
}

bool MyUU1::checkPrime(unsigned int n)
{
	int j;
	if (n == 2 || n == 3)
		return true;
	// if(PRIME[n] == 1) return n; // Prime
	// if(PRIME[n] == 2) return 0; // Non Prime
	for (j = sqrt(n); j > 1; --j)
	{
		if (n % j == 0)
			return false;
	}
	// PRIME[n] = 1;
	return true;
}

unsigned int MyUU1::findLessThanEqualPrime(unsigned int n)
{
	for (size_t i = n; i > 1; i--)
	{
		if (checkPrime(i))
			return i;
	}
	return 0;
}

void MyUU1::makeLogEntry(void *p)
{
	std::cout << "[D] " << p << std::endl;
}

using std::initializer_list;
template <typename T, typename... Args>
T createT(Args &&... args)
{
	return T(std::forward<Args>(args)...);
}

void MyUU1::print2Arr(int (*arrp)[2], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("arr=0x%p, **arr=%d\n", arrp, **arrp);
		arrp++;
	}
}

void MyUU1::testCode(const std::string &strCode, int argc, char* argv[], std::vector<std::string>& params)
{
	MyTestCodeEnum e = testCodeEnumMap[strCode];

	if (T_IS_DEBUG)
		std::cout << "test : " << strCode << " is test : ["<< e << "] starting. " << std::endl;
	switch (e)
	{
	case TC01:
	{
		MyUU1::testCInWithAsyncReader();
	}
	break;
	case TC02:
	{
		MyUU1::testCode01(1);
	}
	break;
	case TC03:
	{
		MyUU1::testCode03();
	}
	break;
	case TC04:
	{
		MyUU1::testCode04();
	}
	break;
#ifdef USE_BOOST
	case TC05:
	{

		 MyIPC::testIPCMapFile(argc, argv , params);

	}
	break;
#endif

	default:
	{
		std::cout << "test : " << strCode << " is incomplete : Unknown Test : " << strCode << " (" << e << ")" << std::endl;
		return;
	}
	}

	if (T_IS_DEBUG)
		std::cout << "test : " << strCode << " : [" << e << "]"
			  << " is done. " << std::endl;
}

void MyUU1::testLList()
{
}

// TODO : TC01
void MyUU1::testCode01(int threadCnt)
{
	// TODO :
	std::function<int(int)> ff01 = [&](int tId) {
		using namespace std::chrono_literals;
		std::string line;
		bool run = true;
		while (run)
		{
			std::cin.clear();
			std::cout << tId << " # function<int(void)> is running." << std::endl;
			std::cout << tId << " # enter command : ( -q : quit )";
			std::cout.flush();
			std::cin >> line;
			//	std::cin.clear();

			if ("-q" == line || "-exit" == line)
			{
				run = false;
				continue;
			}
			std::cout << tId << " # your command : " << line << std::endl;

			//	std::this_thread::sleep_for(100ms);
			//	system("pause");
		};
		std::cout << tId << " # thread is done. " << std::endl;
		return EXIT_SUCCESS;
	};

	std::list<std::thread> tList(threadCnt);
	for (int i = 0; i < threadCnt; i++)
	{
		tList.push_back(std::move(std::thread(ff01, i)));
	}

	for (std::thread &t : tList)
	{
		t.join();
	}
}

void MyUU1::testCode02()
{

	int arr[][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};

	int(*arrp)[2] = arr;

	printf("Before\n");

	print2Arr(arrp, 5);

	printf("After\n");

	arrp = arr;

	for (int i = 0; i < 5; i++)
	{
		printf("arr=0x%p, **arr=%d\n", arrp, **arrp);
		arrp++;
	}
}

void MyUU1::testCode03()
{
}

void MyUU1::testCode04()
{
//	World::doTest();
}

void MyUU1::testCInWithAsyncReader()
{

#if 1
	auto r = std::minmax({1, 100});
	std::cout << "std::minmax(1, 100), min = " << r.first << ", max=" << r.second << std::endl;
#endif

	int a = createT<int>();
	int b = createT<int>(12);

	int c = createT<int>(1 + 1 + 3 + 3 + 4);
	My d1 = createT<My>(1, "aaa", 3.8);

	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "d1 : " << d1 << std::endl;
}

char** MyUU1::mtail(const char* fileName, int lineNo, int f) {
	FILE* fp=NULL;
	char c = '\0';
	long leng = 1l;
	long lineSize = 512;
	char* oneLine;
	char** lines;
	extern int errno;

	if((fp = fopen(fileName, "rb")) == NULL) {
		fprintf(stderr, "File Open Error, ErrorCode=%d, File=%s\n", errno, fileName);
	}

	if(f) {
		oneLine = (char*)malloc(sizeof(char)*lineSize);
		while(leng++<lineNo) {
			fseek(fp, -(leng), SEEK_END);
			if(c=='\n') {
				fgets(oneLine, leng, fp);
				fprintf(stdout, "%s\n", oneLine);
			}
		}
		free(oneLine);
		oneLine = NULL;
	}
	else {
		for(int i = 0;i<lineNo;i++) {
			*lines++ = (char*)malloc(sizeof(char)*lineSize);
		}

		while(leng++<lineNo) {
			fseek(fp, -(leng), SEEK_END);
			if(c=='\n') {
				fgets(*lines++, leng, fp);
			}
		}

		for(int i = 0;i<lineNo;i++) {
			free(*lines);
			*lines++ = NULL;
		}
		lines = NULL;
	}

	return lines;		
}
			

#define SIZE 100 
  
// Utility function to sleep for n seconds 
void sleep(unsigned int n) 
{ 
    clock_t goal = n * 1000 + clock(); 
    while (goal > clock()); 
} 
  
// function to read last n lines from the file 
// at any point without reading the entire file 
void mtail2(FILE* in, int n) { 
    int count = 0;  // To count '\n' characters 
  
    // unsigned long long pos (stores upto 2^64 �� 1
    // chars) assuming that long long int takes 8  
    // bytes 
    unsigned long long pos; 
    char str[2*SIZE]; 
  
    // Go to End of file 
    if (fseek(in, 0, SEEK_END)) {
        perror("fseek() failed"); 
	} 
	else { 
        // pos will contain no. of chars in 
        // input file. 
        pos = ftell(in); 
  
        // search for '\n' characters 
        while (pos) { 
            // Move 'pos' away from end of file. 
            if (!fseek(in, --pos, SEEK_SET)) { 

                if (fgetc(in) == '\n') {
                    // stop reading when n newlines 
                    // is found 
                    if (count++ == n) 
                        break; 
				}
            } 
            else {
                perror("fseek() failed"); 
			}
        } 
  
        // print last n lines 
        printf("Printing last %d lines -\n", n); 
        while (fgets(str, sizeof(str), in)) 
            printf("%s", str); 
    } 
    printf("\n\n"); 
} 




int Test01::test(int argc, char* argv[]) {
	using namespace std;

	if(argc>1) {
		for(int i = 0;i < argc;i++) {
			cout << "argv[" << i << "] : " << argv[i] << (i<argc-1?"," : "\n");
		}
	}
	return EXIT_SUCCESS;
}

