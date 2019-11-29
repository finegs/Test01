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

#if 0

string getTimestamp() {
  // get a precise timestamp as a string
  const auto now = std::chrono::system_clock::now();
  const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
  const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(
      now.time_since_epoch()) % 1000;
  std::stringstream nowSs;
  nowSs
	  << std::put_time(std::localtime(&nowAsTimeT), "%Y-%m-%d %H:%M:%S")
   //   << std::put_time(std::localtime(&nowAsTimeT), "%a %b %d %Y %T")
      << '.' << std::setfill('0') << std::setw(3) << nowMs.count();
  return nowSs.str();
}

#endif

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

    			int x = 100;
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
				cout << "\t\t[" << i << "] = " << argv[i] << (i<=argc-1 ? "\n" : "");
			}	

			int j = 0;
			cout << getTimestamp() << " args : " << endl;
			for(std::string s: args) {
				std::cout << "\t[" << j++ << "] = " << s << ",";
			}
			cout << endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		}
	}
	else {
		cout << getTimestamp() << " ";
		for(int i = 0;i<argc;i++) {
			cout << "[" << i << "] = " << argv[i] << (i<=argc-1 ? "\n" : "");
		}	
	}

	return 0;
}
