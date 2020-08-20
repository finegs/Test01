#if 0

#include <iostream>
#include <cstdio>
#include <map>
#include <my.hpp>


template<typename T, typename... Types>
void print(T firstArg, Types... args) {
	std::cout << firstArg << ' ';
	print(args...);
	std::cout << '\n';;
}

using namespace std;
using namespace my;

int main(int argc, char* argv[]) {

	if(argc > 1) {
		cout << my::ts() << "argc:" << argc << ", argv=" << argv[1] << endl;
	}

	multimap<int, int> mm;

	mm.insert({10,1});
	mm.insert({30,3});
	mm.insert({40,4});
	mm.insert({70,7});
	mm.insert({60,6});
	mm.insert({30,3});
	mm.insert({20,2});
	mm.insert({80,8});
	mm.insert({90,9});
	mm.insert({40,11});
	mm.insert({70,17});

	multimap<int, int>::iterator iter;

	std::cout << my::ts() << "mm.size() : " << mm.size() << endl;
	std::cout << my::ts() << "mm.count() : " << mm.count(40) << endl;

	cout << my::ts() << "mm = [";
	for(iter = mm.begin();iter != mm.end();iter++) {
		cout << (iter == mm.begin() ? "" : ", " ) <<"{" << iter->first << "," << iter->second << "}";
	}

	cout << "]\n";

	mm.insert({40,440});
	mm.insert({40,3});

	cout << my::ts() << "mm.size():"<<mm.size()<<endl;
	cout << my::ts() << "mm.count(40):"<<mm.count(40)<<endl;


	for(iter = mm.begin();iter != mm.end();iter++) {
		cout << (iter == mm.begin() ? "" : ", " ) << "{" << iter->first << "," << iter->second << "}";
	}

	cout << "\n";

	string ss("Welcome to ");

	print(ss, "C++", 2011, '\n');

	std::getchar();

	return 0;
}


void print(T t, typename... Types) {
	std::cout << t << ', ';
	print(args...);
	std::cout << '\n';
}

#endif

#if 1

#include <iostream>
#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <thread>
#include <sstream>
#include <atomic>

class MyInst {
	private:
	MyInst(){
		run.store(true);
		pause.store(false);
	}

	std::mutex mtx;
	std::condition_variable cv;
	std::queue<std::string> queue;
	static std::mutex s_mtx;
	static MyInst* inst;

	public:
	static MyInst& getInstance(){
		// std::lock_guard<std::mutex> lg(*mtx);
		// if(inst == NULL) inst = new MyInst();
		// return inst*;
		if(inst != NULL) return *inst;
		std::lock_guard<std::mutex> lg(s_mtx);
		if(inst == NULL) inst = new MyInst();
		return *inst;
	}
	std::atomic_bool run;
	std::atomic_bool pause;

	void push(std::string msg);
	std::string pop();
	void clearQueue();
};


void MyInst::push(std::string msg) {
	std::unique_lock<std::mutex> lk(mtx);

	cv.wait(lk, [&]() { return queue.size() < 10; });

	queue.push(msg);

	cv.notify_all();
}

std::string MyInst::pop() {
	std::unique_lock<std::mutex> lk(mtx);
	cv.wait(lk, [&] () { return !queue.empty(); });

	std::string msg = queue.front();
	queue.pop();
	// lk.unlock();
	cv.notify_all();
	return msg;
}


void MyInst::clearQueue() {

	if(queue.empty()) return;
	std::unique_lock<std::mutex> lk(mtx);

	std::queue<std::string> eq;
	std::swap(queue, eq);
	// lk.unlock();
	// cv.notify_all();
}

using namespace std::literals::chrono_literals;

std::mutex MyInst::s_mtx;
MyInst* MyInst::inst;

int main() {

	MyInst::getInstance();

	std::thread prod([] { 
		int i = 0;
		while(MyInst::getInstance().run) {
			  std::this_thread::sleep_for(3s); 
			  if(MyInst::getInstance().pause) 
			  	continue; 
			  MyInst::getInstance().push("a_" + i++);
		 }
	});
	std::thread cons([] { 
		int i = 0; 
		while(MyInst::getInstance().run) { 
			std::cout << "con : " << i++ << " : " << MyInst::getInstance().pop() << "\n"; 
		}
	});

	std::string line, cmd, word;
	std::stringstream ss;
	while(MyInst::getInstance().run) {
		std::cout << "Command>>" << "\n";
		std::cin >> line;

		ss.str(""); ss.str(line);
		ss >> cmd;

		if("stop" == cmd) {
			MyInst::getInstance().run.store(false);
		}
		else if("pause" == cmd) {
			MyInst::getInstance().pause.store(true);
		}
		else if("resume" == cmd) {
			MyInst::getInstance().pause.store(false);
		}
		else if ("push" == cmd) {
			ss >> word;
			MyInst::getInstance().push(word);
		}
		else if ("clear" == cmd) {
			MyInst::getInstance().clearQueue();
		}

		// std::cout << "main is sleeping ..." << std::endl;
		// std::this_thread::sleep_for(10s);
	}
}
#endif