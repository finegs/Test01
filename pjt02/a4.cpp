#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <memory>

std::string getString(const char* str) {
	return std::string(str);
}

int main(int argc, char* argv[]) {
	char* s;
	if(argc > 1) {
		s = argv[1];
	}
	else {
		size_t len;
		s = new char[(len = strlen("bbbb"))+1];
		memset(s, '\0', len+1);
		strncpy(s, "bbbb", len);
	}

	std::string ss(s);

	std::cout << s << " : " << (void*)s << std::endl;

	std::cout << ss << " : " << (void*)&(ss.c_str()[0]) << std::endl;
A
	std::string s1 = getString(ss.c_str());

	std::cout << s1 << " : " << (void*)&(s1.c_str()[0]) << std::endl;

	std::cout << "s == s1 ? " << (s == s1 ? "true" : "false") << std::endl;
	std::cout << "s == ss ? " << (s == ss ? "true" : "false") << std::endl;
	std::cout << "s == \"bbbb\" ? " << (s == "bbbb" ? "true" : "false") << std::endl;
	return EXIT_SUCCESS;
}
#if 0

#include <iostream>
#include <memory>

template<typename First, typename Second>
struct Pair{
	Pair(First t_First, Second t_Second) 
		: first(std::move(t_First))
		  , second(std::move(t_Second)) 
	{}

	First first;
	Second second;
};


int main() {

	Pair p{1, 2.3};

	std::cout << p.first << ":" << p.second << std::endl;


	return EXIT_SUCCESS;
}
#endif

#if 0

#include <iostream>
#include <cstdlib>
#include <unordered_map>

int main() {
	std::unordered_map<std::string, std::string> my_map({{"a1", "aa"},{"a2", "aaa"},{"mykey","myvalue"}});

	if(auto [key, value] = *my_map.begin(); key == "mykey") {
		std::cout << key << ":" << value << std::endl;
	}

	return EXIT_SUCCESS;
}


#endif
