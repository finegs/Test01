#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <cstring>

using namespace std;

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

int main(int argc,char* argv[]) {
	unordered_map<string, string> argm;
	long sleepTime;
	for(int i = 1;i<argc;i++) {
		if(!strcmp("-t", argv[i]) && i+1 < argc){
			argm.insert({argv[i], argv[i+1]});

			sleepTime = atol(argv[i+1]);

			i++;
		}
		else {
			argm.insert({argv[i], argv[i]});
		}
	}

	
	auto search = argm.find("-t");
	if(search != argm.end()) {
		cout << getTimestamp() << " [I]" << " sleep time=" << sleepTime<< endl;
		system("pause");

		for (;1;) {
			cout << getTimestamp() << " ";
			for(int i = 0;i<argc;i++) {
				cout << "[" << i << "] = " << argv[i] << (i<=argc-1 ? "\n" : "");
			}	
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
