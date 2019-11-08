#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>

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
		Clz2(const std::string& _key, const std::string& _name) : key(_key), name(_name){ }
		const Clz2& operator=(const Clz2& o) {
			key = o.key; name = o.name;
			return o;
		}

		friend std::ostream& operator<<(std::ostream& os, const Clz2& o);

		std::string getKey() { return key; }
		std::string getName() { return name; }
	private:
		std::string key;
		std::string name;
};

std::ostream& operator<<(std::ostream& os, const Clz& o) {
	os << "(" << o.age << ", " << o.name << ")" << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Clz2& o) {
	os << "(" << o.key << " = " << o.name << ")" << std::endl;
}

int main(int argc, char* argv[]) {
	std::unorderd_map<std::string, Clz2> m2;
	if (argc > 0) {
		std::ifstream infs(argv[1]);
		int count=0;
		infs>>count;
		infs.ignore(1, '\n');
		for(int i = 0;i < count;i++) {
			std::string line;
			std::getline(infs, line);

			std::istringstream iss(line);

			std::string key;
			std::string name;

			std::getline(iss, key, ',');
			std::getline(iss, name, ',');

			m2.put({key, {key, name}});
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


	std::cout << "m1 is " << std::endl;
	int i = 0;
	for(const auto& e : m) {
		std::cout << "[" << i++ << "] " <<  e.first << " = " << e.second << std::endl;
	}

	std::cout << "m2 is " << std::endl;
	i = 0;
	for(const auto& e : m2) {
		std::cout << "[" << i++ << "] " <<  e.first << " = " << e.second << std::endl;
	}
	return 0;
}
