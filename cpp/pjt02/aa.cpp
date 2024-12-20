#include <chrono>
#include <cstring>
#include <ios>
#include <iostream>
//#include <iomanip>
#include <string>
#include <thread>
#include <time.h>
#include <unordered_map>
#include <vector>

#include "mtest.hpp"
#include "mutil.hpp"

#if USE_MSTR_TOK > 0
#define __STRTOK mstrtok
#else
#define __STRTOK strtok
#endif

using namespace std;

char rand_char() {
	int n = std::rand();
	switch (n % 3) {
	case 0:
		return '0' + (n % ('9' - '0'));
	case 1:
		return 'A' + (n % ('Z' - 'A'));
	case 2:
		return 'a' + (n % ('z' - 'a'));
	}
	return '-';
}

#if 0
void buildMaxHeap(int arr[], int n)
{
	for(int i = 1;i<n;i++) {
		if(arr[i]>arr[i-1]/2) {
			int j = i;

			while(arr[j]>arr[(j-1)/2]) {
				swap(arr[j], arr[(j-1)/2]);
				j=(j-1)/2;
			}
		}
	}
}

void heapsort(int arr[], int n)
{
	buildMaxHeap(arr,n);

	for(int i = n-1;i>0;i--) {
		swap(arr[0], arr[i]);

		int j = 0, index;

		do {
			index =  (2*j +1);

			if(arr[index]<arr[index+1] &&
					index < (i-1))
				index++;

			if(arr[j]<arr[index] && index<i)
				swap(arr[j], arr[index]);

			j = index;

		} while(index < i);
	}
}

#endif

std::string remove_ctrl(std::string s) {
	std::string r;
	size_t len = s.length();
	for (size_t i = 0; i < len; i++) {
		if (s[i] >= 0x20)
			r = r + s[i];
	}
	return r;
}

std::string remove_ctrl_mutating(std::string s) {
	std::string r;
	r.reserve(s.length());
#if 0
	for(size_t i =0;i<s.length();i++) {
		if(s[i] >= 0x20) r += s[i];
	}
#endif
	for (auto it = s.begin(), end = s.end(); it != end; ++it) {
		if (*it >= 0x20)
			r += *it;
	}
	return r;
}

std::unordered_map<std::thread::id, unsigned int> MTest::timeMap;

#if 0
int f_t(int& i, char* argv[], std::unordered_map<std::string, std::string> argm);
int f_n(int& i, char* argv[], std::unordered_map<std::string, std::string> argm);


typedef int (*service_t)(int& i, int argc, char* argv[], std::unordered_map<std::string, std::string> argm);
std::unordered_map<std::string, service_t> svcMap
= {
	"-t", f_t,
	"-n", f_n
};


int f_t(int& i, char* argv[], std::unordered_map<std::string, std::string> argm) {
	argm.insert({argv[i], argv[i + 1]});

	long sleepTime = atol(argv[i + 1]);

	i++;
	return EXIT_SUCCESS;
};

#endif


int main(int argc, char *argv[]) {
	unordered_map<string, string> argm;
	std::vector<std::string> args;

	long sleepTime, sleepCount;

	sleepTime = 1000;
	sleepCount = 0;

	
	for (int i = 1; i < argc; i++) {
		if (!strcmp("-t", argv[i]) && i + 1 < argc) {
			argm.insert({argv[i], argv[i + 1]});

			sleepTime = atol(argv[i + 1]);

			i++;
		} else if (!strcmp("-n", argv[i]) && i + 1 < argc) {
			argm.insert({argv[i], argv[i + 1]});

			sleepCount = atol(argv[i + 1]);

			i++;
		} else if (!strcmp("-tt", argv[i])) {
			//	char* tt = (char*)malloc(sizeof(char)*1);
			//	memset(tt, '\0', 1);
			std::cout << getTimestamp() << " {\"timestamp\":\"" << getTimestamp() << "\"}" << endl;
			std::cout << getTimestamp() << " {\"timestamp2\":\"" << getTimestamp() << "\"}" << endl;
		} else if (!strcmp("-t01", argv[i])) {
			std::cout << getTimestamp() << " : -t01" << std::endl;
		} else if (!strcmp("-t02", argv[i])) {
			int n = -1, d = -1;
			if (argc > i + 1) {
				n = atoi(argv[i + 1]);
			} else {
				printf("N : ");
				fflush(stdout);
				scanf("%d", &n);
			}
			if (argc > i + 2) {
				d = atoi(argv[i + 2]);
			} else {
				printf("D : ");
				fflush(stdout);
				scanf("%d", &d);
			}

#if 0
			for(int i = 0;i<n;i++) {
				printf("%3d is %4s\n", i, (i&1)?"ODD":"EVEN");
			}
#endif

			MTest mt;
			printf("left rotation of %d by %d is %d\n", n, d, mt.leftRotate(n, d));
			printf("right rotation of %d by %d is %d\n", n, d, mt.rightRotate(n, d));

		} else if (!strcmp("-t03", argv[i])) {
#if 0
			int n = 10;
			if(i+1<argc) {
				n = atoi(argv[i+1]);
			}

			for(int i = 0;i<n;i++) {
				printf("%3d is %4s\n", i, (i&1)? "ODD" : "EVEN");
			}
#endif

			// Point pt;
			// pt(3,2);
			// pt.show();
		} else if (!strcmp("-t04", argv[i])) {
			int n = 255;
			if (i + 1 < argc) {
				n = atoi(argv[i + 1]);
			}

#ifdef M_DEBUG
			std::cout << getTimestamp() << " 0. n : " << n << std::endl;
#endif

			char *arr = (char *)malloc(sizeof(char) * n + 1);
			memset(arr, '\0', n + 1);

			std::srand(static_cast<unsigned int>(std::time(NULL)));

			for (int i = 0; i < n; i++) {
				arr[i] = rand_char();
			}

			std::cout << "'0'=" << (int)'0' 
				<< ",'A'=" << (int)'A' 
				<< ",'z'=" << (int)'z' 
				<< std::endl;

			string s = std::string(arr);

#ifdef M_DEBUG
			std::cout << getTimestamp() << " 1. s[" << s.length()
						    << "]=" << (s.length() > 100 ? "..." : s) << std::endl;
			std::cout << getTimestamp() << " 1. Start. " << std::endl;
#endif
			MTest::setCurrentTimestamp();

			std::string r = remove_ctrl(s);

			std::cout << getTimestamp() << " 1. Done."
						    << ", ES=" << MTest::getDiffTime() << std::endl;

			memset(arr, '\0', n + 1);
			for (int i = 0; i < n; i++) {
				arr[i] = rand_char();
			}
			s.clear();
			s.append(arr);
			// s = std::string(arr);
#ifdef M_DEBUG
			std::cout << getTimestamp() << " 2. s[" << s.length()
						    << "]=" << (s.length() > 100 ? "..." : s) << std::endl;
			std::cout << getTimestamp() << " 2. Start. " << std::endl;
#endif

			MTest::setCurrentTimestamp();

			r = remove_ctrl_mutating(s);

			std::cout << getTimestamp() << " 2. Done."
						    << ", ES=" << MTest::getDiffTime() << std::endl;

			free(arr);

		} else if (!strcmp("-t05", argv[i])) {

			MTest::setCurrentTimestamp();

			float d, t, a = -9.8f, v0 = 0.0f, d0 = 100.0f;
			for (t = 0.0; t < 3.01f; t += 0.1f) {
				d = a * t * t + v0 * t + d0;
			}
			std::cout << "float : d = " << d << std::endl;

			std::cout << "float : ES : " << MTest::getDiffTime() << std::endl;

			MTest::setCurrentTimestamp();

			double dd, td, ad = -9.8f, vd0 = 0.0, dd0 = 100.0;
			for (td = 0.0; td < 3.01; td += 0.1) {
				dd = ad * td * td + vd0 * td + dd0;
			}

			std::cout << "double : dd = " << dd << std::endl;
			std::cout << "double : ES : " << MTest::getDiffTime() << std::endl;

		} else if (!strcmp("-a", argv[i]) && i + 1 < argc) {
			argm.insert({argv[i], argv[i + 1]});

			size_t len;
			char *tdelim;
			if (i + 2 < argc) {
				tdelim = argv[i + 2];
			} else {
				tdelim = (char *)malloc(sizeof(char) * (len = strlen(",") + 1));
				memset(tdelim, '\0', len);
				strcpy(tdelim, ",");
			}

			const char *delim = tdelim;
			char *temp = (char *)malloc((len = strlen(argv[i + 1])) + 1);
			memset(temp + len, '\0', 1);

			strncpy(temp, argv[i + 1], len);
			std::cout << getTimestamp() << " {\"temp\":\"" << temp << "\"}"
						    << std::endl;
			std::cout << getTimestamp() << " {\"delim\":\"" << delim << "\"}"
						    << std::endl;
			char *token = __STRTOK(temp, delim);
			while (token) {
				args.push_back(std::string(token));
				token = __STRTOK(NULL, delim);
			}

			free(temp);
			temp = token = NULL;

			std::cout << getTimestamp() << " {\"tokens\":[";
			int j = 0;
			for (auto it = args.cbegin(); it != args.cend(); it++) {
				std::cout << ((j > 0) ? ", " : "") << "\"" << (*it) << "\"";
				j++;
			}
			cout << "]}" << endl;

			i++;
		} else if (!strcmp(argv[i], "-tt01") && i+1 < argc) {
			MyClz c("name", argv[i+1]);
			MyClz cc(c);
			MyClz ccc;
			MyClz cccc;
			ccc = cc;
			std::cout << getTimestamp() << " : " << "c : " << c << std::endl;
			std::cout << getTimestamp() << " : " << "c == cc : " << std::boolalpha << (c == cc) << std::endl;
			std::cout << getTimestamp() << " : " << "c == ccc : " << std::boolalpha << (c == ccc) << std::endl;
			cccc = std::move(ccc);
			std::cout << getTimestamp() << " : cccc("<< cccc  << ") == ccc(" << ccc << ")  : " << std::boolalpha << (cccc == ccc) << std::endl;
		} else if (argv[i][0] == '-' && i + 1 < argc) {
			argm.insert({argv[i], argv[i + 1]});
 		} else {
			argm.insert({argv[i], argv[i]});
		}
	}

	// auto search = argm.find("-t");
	if (argm.find("-t") != argm.end()) {
		// if(search != argm.end()) {
		cout << getTimestamp() << " [I]"
				 << " sleep time=" << sleepTime << endl;
		cout << getTimestamp() << " [I]"
				 << " sleep count=" << sleepCount << endl;
		system("pause");

		for (int i = 0; !sleepCount || i < sleepCount; i++) {
			cout << getTimestamp() << " {\"argv\":[";
			for (int i = 0; i < argc; i++) {
				cout << (i > 0 ? "," : "") << "\"" << argv[i] << "\"";
			}
			cout << "]}" << endl;

			int j = 0;
			cout << getTimestamp() << " {\"args\":[";
			for (auto it = args.cbegin(); it != args.cend(); it++) {
				cout << (j > 0 ? "," : "") << "\"" << (*it) << "\"";
				j++;
			}
			cout << "]}" << endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		}
	} else if (argm.find("-ht") != argm.end()) {
		std::string ss = argm["-a"];
		std::vector<char> tv(ss.begin(), ss.end());
		tv.push_back('\0');
		char *a = &tv[0];
		// char* a = argm["-a"].c_str();
		int *arr;
		int arrLen = 10;
		int n;
		if (a) {
			arr = (int *)malloc(sizeof(int) * arrLen);
			int num;
			char *ta = mstrtok(a, ",");
			n = 0;
			printf("\n");
			while (ta) {
				num = atoi(ta);
				if (n >= arrLen) {
					int *tarr = (int *)malloc(sizeof(int) * arrLen * 2);
					if (!tarr) {
						fprintf(stderr, "fail to malloc\n");
						exit(-100);
					}
					memset(tarr, 0, arrLen * 2);
					memcpy(tarr, arr, arrLen);
					free(arr);
					arr = NULL;
					arrLen = arrLen * 2;
					arr = tarr;
					tarr = NULL;
				}
				arr[n++] = num;
				printf("%d\t", num);
				ta = mstrtok(NULL, ",");
			}
			printf("\n");
		} else {
			std::vector<int> iv{10, 20, 15, 27, 9, 21};
			// arr = {10,20, 15, 27, 9, 21};
			arr = &iv[0];
			n = 6;
		}

		// int n = sizeof(arr)/sizeof(arr[0]);

		printf("before:");
		for (int i = 0; i < n; i++)
			printf("%s%d", (i > 0 ? ", " : ""), arr[i]);
		printf("\n");

		heapSort(arr, n);

		printf("after:");
		for (int i = 0; i < n; i++)
			printf("%s%d", (i > 0 ? ", " : ""), arr[i]);
		printf("\n");

	} else {
#ifdef M_DEBUG
		cout << getTimestamp() << " { args:[";
		for (int i = 0; i < argc; i++) {
			cout << (i > 0 ? "," : "") << "\"" << argv[i] << "\"";
		}
		cout << "]}" << endl;

#endif
	}

	return 0;
}
