#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>

#include "mutil.hpp"

using namespace std;

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

void log(const char* msg) {
	std::cout << getTimestamp() << " " << msg << std::endl;
}

int gcd(int a, int b) {
	int tmp, n;
	if(a<b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	

	while(b!=0) {
		n = a%b;
		a = b;
		b = n;
	}

	return a;
}




int main(int argc, char* argv[]) {
	int a = -100,b = -100;
	if(argc > 1) {
		a = atoi(argv[1]);
	}
	if(argc > 2) {
		b = atoi(argv[2]);
	}

	int result;
	printf("a:%d, b:%d\n", a,b);
	result = gcd(a,b);
	printf("gcd : %d\n", result);

#if 0
	int i = 0, rc;

	if(argc < 2) {
		printf("Usage : %s string1 string2\n", argv[0]);
		return 0;
	}


	printf("%s %s %s\n", argv[i], !(rc = mstrcmp(argv[1], argv[2])) ? " = " :  rc < 0 ?  " < " : " > ", argv[2]);

	
	int i = 0;
	char *str, *ss;
	int i;
	char *str;
	size_t len;
	std::vector<std::string> args;

	if(argc < 2) {
		printf("Usage : %s string delimeter\n", argv[0]);
		return 0;
	}

	str = NULL;
	i = 0;
	char* temp = (char*)malloc(len = strlen(argv[1])+1);
	memset(temp, '\0', len);
	strncpy(temp, argv[1], len-1);
	cout << getTimestamp() << " [D] argv[1]=" << temp << endl;
	while(true) {
		str = mstrtok(!i ? temp : NULL, argv[2]);
		//str = strtok(!i ? temp : NULL, argv[2]);
		if(!*str) break;
		printf("\t[%d]=%s\n", i++, str);
		args.push_back(std::string(str));
	}

	free(temp);
	temp = NULL;

	cout << getTimestamp() << " [D] Parsed Result : " << endl;
	int j = 0;
	for(std::string s : args) {
		cout << "\t[" << j++ << "] = " << s << std::endl;
	}
	cout << endl;

	return 0;

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
