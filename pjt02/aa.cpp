#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

string getTimestamp() {
  // get a precise timestamp as a string
  const auto now = std::chrono::system_clock::now();
  const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
  const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(
      now.time_since_epoch()) % 1000;
  std::stringstream nowSs;
  nowSs
	  << std::put_time(std::localtime(&nowAsTimeT), "Y-m-d H:M:S")
   //   << std::put_time(std::localtime(&nowAsTimeT), "%a %b %d %Y %T")
      << '.' << std::setfill('0') << std::setw(3) << nowMs.count();
  return nowSs.str();
}

int main(int argc,char* argv[]) {

	cout << getTimestamp() << " ";
	for(int i = 0;i<argc;i++) {
		cout << "[" << i << "] = " << argv[i] << (i<=argc-1 ? "\n" : "");
	}	

	return 0;
}
