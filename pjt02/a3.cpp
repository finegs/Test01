#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

#include "mutil.hpp"

class Clz {
	public:
		int age;
		std::string name;
		Clz() : age(0), name("") {}
		Clz(int age, const std::string& name) : age(age), name(name) {}
		Clz(const Clz& o) : age(o.age), name(o.name) {}
		const Clz& operator=(const Clz& o) {
			if(this==&o) return *this;
			age = o.age;
			name =o.name;
			return *this;
		}
		
		friend
		std::ostream& operator<<(std::ostream& os, const Clz& o); 
};

class Clz2 {
	public:
		Clz2() : key("__"), name("__") {}
		Clz2(const std::string& _key, const std::string& _name) : key(_key), name(_name){}
		Clz2(const Clz2& o) : key(o.key) , name(o.name) {}
		Clz2(Clz2& o) : key(std::move(o.key)), name(std::move(o.name)) {}
		const Clz2& operator=(const Clz2& o) {
			key = o.key; name = o.name;
			return o;
		}
		const Clz2& operator=(Clz2& o) {
			key=std::move(o.key);
			name=std::move(o.name);
			return *this;
		}			

		friend 
		std::ostream& operator<<(std::ostream& os, const Clz2& o);

		std::string getKey() { return key; }
		std::string getName() { return name; }
	private:
		std::string key;
		std::string name;
};


std::ostream& operator<<(std::ostream& os, const Clz2& o) {
	os << "(" << o.key << " = " << o.name << ")" << std::endl;
	return os;
}


std::ostream& operator<<(std::ostream& os, const Clz& o) {
	os << "(" << o.age << ", " << o.name << ")" << std::endl;
	return os;
}

<<<<<<< HEAD
void log(const char* msg) {
	std::cout << std::put_time(std::localtime(Îk
}
=======
int main(int argc, char* argv[]) {

	int i = 0;
	char *str, *ss;
>>>>>>> 2009b616a91c5287bdbf6f54a05049f9d917a3aa

	if(argc < 2) {
		printf("Usage : %s string delimeter\n", argv[0]);
		return 0;
	}

	ss = argv[1];
	str = NULL;
	while(true) {
		str = mstrtok(!i ? ss : NULL, argv[2]);
		if(!*str) break;
		printf("[%d]=%s\n", i++, str);
	}

	printf("argv[2]=%s\n", ss);

	return 0;

#if 0
	std::unordered_map<std::string, Clz2> m2;
	std::set<std::string> argset;
	bool verbose = false;
	char* inputFile;
	for(int i = 1;i < argc;i++) {
		argset.insert(std::string(argv[i]));
		if(!strcmp("-in", argv[i]) && argc > i+1) {
			inputFile = argv[i+1];	
		}		
	}

	if(argset.count("-V") > 0
			|| argset.count("-v") > 0 
			|| argset.count("-D") > 0 
			|| argset.count("-d") > 0) {
		verbose = true;
	}

	if (inputFile) {
		std::ifstream infs(inputFile);
		int count=0;
		infs>>count;
		infs.ignore(1, '\n');
		for(int i = 0;i < count;i++) {
			std::string line;
			std::getline(infs, line);

			std::stringstream iss(line);

			std::string key;
			std::string name;

			std::getline(iss, key, ',');
			std::getline(iss, name, ',');

			m2.insert({key, {key, name}});
		}
	}

	std::unordered_map<int, Clz> m;

	m.insert(std::make_pair<int, Clz>(1, Clz(1, "name")));
	m.insert({2, {2, "name2"}});
	m.insert({{3, {3, "name3"}},{4,{4,"name4"}}});
	
	Clz a = Clz(5, "ccc");
	m.insert({a.age, a});

	std::cout << m[1].age << " = " << m[1].name << std::endl;
	std::cout << m[1].age << " = " << m[1].name << std::endl;

	std::cout << "##### Start #############" << std::endl;

	std::cout << "m.size()=" << m.size() << std::endl;
	if(verbose) {
		std::cout << "m.content=" << std::endl;
		int i = 0;
		for(const auto& e : m) {
			std::cout << "[" << i++ << "] " <<  e.first << " = " << e.second << std::endl;
		}
	}
	std::cout << "##### End ###############" << std::endl;

	std::cout << "##### Start #############" << std::endl;
	std::cout << "m2.size()=" << m2.size() << std::endl;
	if(verbose) {
		std::cout << "m2.content= " << std::endl;
		int i = 0;
		for(const auto& e : m2) {
			std::cout << "[" << i++ << "] " <<  e.first << " = " << e.second << std::endl;
		}
	}
	std::cout << "##### End ###############" << std::endl;

	return 0;
#endif

}
