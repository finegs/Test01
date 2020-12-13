#if 0

// CodeTest : std::unordered_map   Customer Class, CustomerEqual, CustomerHash

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

class Customer {
	private:
		std::string name;
		std::string desc;
		
	public:
		Customer(const std::string& n) : name(n), desc("-") {}
		std::string getName() const { return name; }
		void setDesc(const std::string& _desc) { desc = _desc; }
		std::string getDesc() const { return desc; }
		friend std::ostream& operator<<(std::ostream& os, const Customer& o);
};

std::ostream& operator<<(std::ostream& os, const Customer& o) {
	os << "(" << o.getName() << ", " << o.getDesc() << ")";
	return os;
}

int main() {
	struct MyCustomerHash {
		std::size_t operator() (const Customer& o) const {
			return std::hash<std::string>()(o.getName());
		}
	};

	struct MyCustomerEqual {
		bool operator()(const Customer& a, const Customer& b) const {
			return a.getName() == b.getName();
		}
	};

	auto hash  = [](const Customer& o) { return std::hash<std::string>()(o.getName()); };
	auto equal = [](const Customer& a, const Customer& b) { return a.getName() == b.getName(); };

	std::unordered_set<Customer, MyCustomerHash, MyCustomerEqual> coll;
	// coll.emplace("aa");
	// coll.insert(Customer("aa"));
	coll.insert({"aa"});
	coll.emplace("aa");

	std::cout << (coll.end() != coll.find({"aa"}) ? "founded" : "not found") << std::endl;

	using CustomHashSet = std::unordered_set<Customer, decltype(hash), decltype(equal)>;
	CustomHashSet cs(10, hash, equal);
	cs.insert({"aa"});
	cs.emplace("aa");
	cs.insert({"bb"});

	std::cout << (cs.end() != cs.find({"aa"}) ? "founded" : "not found") << std::endl;
	// std::unordered_set<Customer, decltype(hash), decltype(equal)> col2;

	std::for_each(cs.begin(), cs.end(), [](auto& i) { std::cout<< ", (" << i <<")" << std::endl; });
	std::unordered_map<Customer, Customer, MyCustomerHash, MyCustomerEqual> m1;
	Customer c{"bb"};
	m1.insert({{"a"},{"b"}});
	m1.insert({c, c});
	std::for_each(m1.begin(), m1.end(), [](auto& i) { std::cout<< ", (" << i.first << ", " << i.second << ")"; });
	std::cout<< std::endl;

	std::unordered_multimap<Customer&, Customer&, MyCustomerHash, MyCustomerEqual> m2;

	Customer a1{"a1"};
	Customer a2{"a2"};
	Customer a3{"a3"};

	m2.insert({a1, a1});
	m2.insert({a2, a2});
	m2.insert({a3, a3});

	std::for_each(m2.begin(), m2.end(), [](auto& i) { std::cout<< ", (" << i.first << ", " << i.second << ")"; });

	std::cout<< std::endl;

	a3.setDesc("New Desc");

	std::for_each(m2.begin(), m2.end(), [](auto& i) { std::cout<< ", (" << i.first << ", " << i.second << ")"; });

	std::cout<< std::endl;

	return 0;
}

#endif


#if 1


#include <iostream>
#include <vector>
#include <atomic>
#include <thread>
#include <chrono>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>

using namespace std::chrono_literals;

typedef struct task_info_ {
	std::ostream& os;
	std::atomic_bool run;
	std::atomic_bool data_ready;
	std::queue<int> data;
	std::atomic_int  task_period;
} task_info;

void task_read(task_info& info);
void task_write(task_info& info);

int main(int argc, char* argv[]) {

	int readThreadNo;
	int writerThreadNo;
	bool help;
	std::vector<std::thread> threadList;

	for(int i = 0; i < argc;i++) {
		if('-' == argv[i][0]) {
			if(!strcmp("-reader.no", argv[i]) && i+1 < argc) {
				readThreadNo = atoi(argv[i+1]);
				i++;
			}
			else { std::cout << "illegal optin : [" << i << "]" << ":" << argv[i] << std::endl; help = true; break; }
			if(!strcmp("-writer.no", argv[i]) && i+1 < argc) {
				writerThreadNo = atoi(argv[i+1]);
				i++;
			}
			else { std::cout << "illegal optin : [" << i << "]" << ":" << argv[i] << std::endl; help = true; break; }
		}
	}

	if( help || argc <2) {
		std::cout << "usage : " << argv[0] << " -reader.no {reader thread number} -writer.no {writer thread no}" << std::endl;
		return 0;
	}

	task_info ti{std::cout, true, false, {}, 3000};

	for(int i=0;i<readThreadNo;i++) threadList.push_back(std::thread{task_read, std::ref(ti)});
	for(int i=0;i<writerThreadNo;i++) threadList.push_back(std::thread{task_write, std::ref(ti)});

	std::string line;
	while(ti.run.load()) {
		std::cout << "<<" << std::endl;
		std::cin >> line;
		if("exit"==line || "quit"==line) {
			ti.run.store(false);
			std::cout << " exiting ... " << std::endl;
			continue;
		}
	}

	std::for_each(threadList.begin(), 
			threadList.end(), 
			[&](auto& o) { 
				o.join(); 
				std::cout << o.get_id() << " is joined." << std::endl;
			});

	std::cout << "Done. " << std::endl;

	return 0;
}


void task_read(task_info& info) {
	std::ostream& os = info.os;
	std::atomic_bool& run = info.run;
	std::atomic_bool& data_ready = info.data_ready;
	std::queue<int>& data  = info.data;
	int n = 0;

	os << __func__ << " started." << std::endl;
	while(run.load()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(info.task_period));
		while(!data_ready.load()) std::this_thread::sleep_for(1ms);

		os << std::this_thread::get_id() << " : "  
					<<__func__ << " : " 
					<< "[" << n << "/" << data.size() << "]=" << data.front() << std::endl; 
		data.pop();
		data_ready.store(false);
	}

	os << __func__ << " end." << std::endl;
}

void task_write(task_info& info) {
	std::ostream& os = info.os;
	std::atomic_bool& run = info.run;
	std::atomic_bool& data_ready = info.data_ready;
	std::queue<int>& data  = info.data;
	int n = 0;

	os << __func__ << " started." << std::endl;
	while(run.load()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(info.task_period));
		while(data_ready.load()) std::this_thread::sleep_for(1ms);
		os << std::this_thread::get_id() << " : "  
					<<__func__ << " : " 
					<< "[" << n << "/" << data.size() << "]=" << n << std::endl; 
		data.push(n++);
		data_ready.store(true);
	}

	os << __func__ << " end." << std::endl;
}

#endif
