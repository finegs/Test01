#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <thread>
#include <cstring>
#include <vector>

#include "mutil.hpp"
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
		else if (!strcmp("-a", argv[i]) && i+1 < argc) {
			argm.insert({argv[i], argv[i+1]});

			size_t len;
			const char* delim = ", ";
			char* temp = (char*)malloc(len = strlen(argv[i+1])+1);
			memset(temp, '\0', len);

			strncpy(temp, argv[i+1], len-1);
			std::cout << getTimestamp() << " temp is " << temp << std::endl;
			char* token= strtok(temp, delim);
			while(token) {
				args.push_back(std::string(token));
				token = strtok(NULL, delim);
			}

			free(temp);
			temp = token = NULL;

			std::cout << getTimestamp() << " -a is " << std::endl;
			int j = 0;
			for(std::string s: args) {
				std::cout << "\t[" << j++ << "] = " << s << ",";
			}
			cout << endl;

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
			cout << getTimestamp() << " ";
			for(int i = 0;i<argc;i++) {
				cout << " [" << i << "] = " << argv[i] << (i<=argc-1 ? "," : "");
			}
			cout << std::endl;

			int j = 0;
			cout << getTimestamp() << " args : ";
			for(std::string s: args) {
				std::cout << "[" << j << "] = " << s << (j <argc-1 ? "," : "");
				j++;
			}
			cout << endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		}
	}
	else {
		cout << getTimestamp() << " ";
		for(int i = 0;i<argc;i++) {
			cout << "[" << i << "] = " << argv[i] << (i <= argc-1 ? ",": "\n");
		}
	}

	
	return 0;
}
