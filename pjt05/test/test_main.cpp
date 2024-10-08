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

#if 0

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <sstream>
#include <atomic>

#include <my.hpp>


using namespace std::literals::chrono_literals;
using namespace my;

// std::mutex MyInst::s_mtx;
// MyInst* MyInst::inst = nullptr;

int main(int argc, char* argv[]) {


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

#if 1

#include <mutex>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

#include <my.hpp>

struct Box {
	explicit Box(const std::string& _name, int num) 
		: name(_name), num_things{num} {}

	std::string name;
	int num_things;
	std::mutex m;
	friend std::ostream& operator<<(std::ostream& os, const Box& o);
};

std::ostream& operator<<(std::ostream& os, const Box& o) {
	os << " Box {\"name\": " << o.name << ", \"num\":" << o.num_things << "}";
	return os;
}

void transfer(Box &from, Box &to, int num) {
	std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
	std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);

	std::lock(lock1, lock2);

	from.num_things -= num;
	to.num_things  += num;
}

std::vector<std::string> parse(std::string str) {
	std::vector<std::string> rt;
	std::stringstream ss;
	ss.str(str);
	for(std::string s; ss>>s;) {
		rt.push_back(s);
	}
	return rt;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
	if(v.empty()) return out;
	out << "[";
	std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
	out << "\b\b]";
	return out;
}

template<auto...> struct C {};
C<'C', 0, 2L, nullptr> x;

template<class T> struct A { 
	A(T _a,T _b) : a(_a), b(_b) {}
	T a;
	T b;

	template <class U>
	friend std::ostream &operator<<(std::ostream &os, const A<U> &o);

	template <class U>
	friend std::istream &operator>>(std::istream &is, A<U> &o);
};

template<class U>
std::ostream& operator<< (std::ostream& os, const A<U>& o) {
	os << o.a << ":" << o.b << "";
	return os;
}

template<class U>
std::istream& operator>> (std::istream& is, A<U>& o) {
	is >> o.a >> o.b;
	return is;
}
auto y = new A{1,2};

// struct AA { friend bool operator==(const AA&, const AA&) = default; };
// template<AA a> void f() {
// 	&a;
// 	const AA& ra = a, &rb = a;
// 	assert(&ra == &rb);
// }

int main() {
	Box acc1("acc1", 100);
	Box acc2("acc2", 50);

	std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
	std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

	t1.join();
	t2.join();

	std::cout << acc1 << std::endl;
	std::cout << acc2 << std::endl;

	int i = 0;
	auto l = parse("aa bb cc");
	std::for_each(l.begin(), l.end(), 
		[&](std::string& s) { std::cout << my::ts() << " [" << i++ << "]" << s << "\n";});
	
	std::cout << '\n';

	std::cout << " 2. " << '\n';

	std::cout << l << '\n';
	
	auto& ry = *y;

	std::cout << "y : " << *y << '\n'; 

	delete y;

	auto yy = new A{0,0};

	std::cout << "yy : (ex. a b)" << '\n';
	std::cin >> *yy;

	std::cout << "yy : " << yy << '\n';
	delete yy;

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	srand(0);
	size_t n;
	for (size_t i = 0; i < 10; i++)
	{
		pq.push(n = (rand()%100));
		std::cout << i << ":" << n;
		std::cout << " " << '\n';
	}

	while(!pq.empty()) { std::cout << pq.top() << " "; pq.pop(); }
	std::cout << '\n';

	std::cin.get();

	return 0;
}

#endif