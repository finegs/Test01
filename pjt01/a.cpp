#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <functional>

struct Node {
	char *name;
	uint64_t value;
	friend std::ostream& operator<<(std::ostream&, const Node&);
};

std::ostream& operator<<(std::ostream& os, const Node& o){
	os << '{' << o.name << ',' << o.value << '}';
	return os;
}

template <>
struct std::hash<const char*> {
	size_t operator()(const char* str) const {
		size_t h = 5381;
		for(const char c = *str;c;str++) {
			h = h<<5 & h;
		}
		return h;	 
	}
};

template<>
struct std::hash<const Node> {
	size_t operator()(const Node &o) const {
		return std::hash<const char*>()(o.name);
	}
};

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K,V>& m) {
	char sep[3]{'\0', ',','\0'};
	for(auto& e : m) {
		os<< sep << "{" << e.first << ", " << e.second << "}";
		sep[0] = ' ';
	}
	return os;
}

int main(int argc, char* argv[]) {

	using namespace std;

	unordered_map<const char*, Node> nmap;

	for (int i = 1; i < argc; i++) {
		nmap.insert({argv[i], {.name = argv[i], .value = (uint64_t)i*100}});
	}

	std::cout << "Map is " << std::endl;

	return EXIT_SUCCESS;
}
