#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <thread>
#include <cstring>
#include <vector>
#include <time.h>

#include "mutil.hpp"

#if USE_MSTR_TOK > 0
#define __STRTOK mstrtok
#else
#define __STRTOK strtok
#endif

using namespace std;



int main(int argc,char* argv[]) {
	unordered_map<string, string> argm;
	std::vector<std::string> args;

	long sleepTime, sleepCount;

	sleepTime = 1000;
	sleepCount = 0;
	for(int i = 1;i<argc;i++) {
		if(!strcmp("-t", argv[i]) && i+1 < argc){
			argm.insert({argv[i], argv[i+1]});

			sleepTime = atol(argv[i+1]);

			i++;
		}
		else if (!strcmp("-n", argv[i]) && i+1 < argc){
			argm.insert({argv[i], argv[i+1]});

			sleepCount = atol(argv[i+1]);

			i++;
		}
		else if(!strcmp("-tt", argv[i])) {
		//	char* tt = (char*)malloc(sizeof(char)*1);
		//	memset(tt, '\0', 1);
			std::cout << getTimestamp() << " {\"timestamp\":\"" << getTimestamp() << "\"}" << endl;
			std::cout << getTimestamp() << " {\"timestamp2\":\"" << getTimestamp() << "\"}" << endl;
		}
		else if(!strcmp("-t01", argv[i])) {
			std::cout << getTimestamp() << " : -t01" << std::endl;
		}	
		else if (!strcmp("-a", argv[i]) && i+1 < argc) {
			argm.insert({argv[i], argv[i+1]});

			size_t len;
			char* tdelim;
			if(i+2<argc) {
				tdelim = argv[i+2];
			} else {
				tdelim = ",";
			}

			const char* delim = tdelim;
			char* temp = (char*)malloc((len = strlen(argv[i+1]))+1);
			memset(temp+len, '\0', 1);

			strncpy(temp, argv[i+1], len);
			std::cout << getTimestamp() << " {\"temp\":\"" << temp << "\"}"<< std::endl;
			std::cout << getTimestamp() << " {\"delim\":\"" << delim <<"\"}"<< std::endl;
			char* token= __STRTOK(temp, delim);
			while(token) {
				args.push_back(std::string(token));
				token = __STRTOK(NULL, delim);
			}

			free(temp);
			temp = token = NULL;

			std::cout << getTimestamp() << " {\"tokens\":[";
			int j=0;
			for(auto it = args.cbegin();it!=args.cend();it++) {
				std::cout << ((j>0)? ", ":"") << "\"" << (*it) << "\"";
				j++;
			}
			cout << "]}"<<endl;

			i++;
		}
		else {
			argm.insert({argv[i], argv[i]});
		}
	}
	
	auto search = argm.find("-t");
	if(search != argm.end()) {
		cout << getTimestamp() << " [I]" << " sleep time=" << sleepTime<< endl;
		cout << getTimestamp() << " [I]" << " sleep count=" << sleepCount<< endl;
		system("pause");

		for (int i=0;!sleepCount || i< sleepCount;i++) {
			cout << getTimestamp() << " {\"argv\":[";
			for(int i = 0;i<argc;i++) {
				cout << (i > 0 ? "," : "") << "\"" << argv[i] << "\"";
			}
			cout << "]}" << endl;

			int j = 0;
			cout << getTimestamp() << " {\"args\":[";
			for(auto it = args.cbegin();it!= args.cend();it++) {
				cout << (j>0? ",":"") << "\"" << (*it) << "\"";
				j++;
			}
			cout << "]}"<<endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		}
	}
	else {
		cout << getTimestamp() << " { args:[";
		for(int i = 0;i<argc;i++) {
			cout << (i>0?",":"") << "\"" << argv[i] << "\"";
		}
		cout << "]}"<<endl;
	}
	return 0;
}

