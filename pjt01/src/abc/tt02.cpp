#if 1

#include <cstdlib>
#include <iostream>
#include "uu1.hpp"
#include <functional>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;


using FService = std::function<int(int argc, char* argv[])>;
using FSvcMap = std::unordered_map<std::string, FService>;

std::unordered_map<std::string, FService> fsvcmap;

int getService(FSvcMap svcMap, std::string svc_name, FService& svc) {
	auto r = svcMap.find(svc_name);
	if(r != svcMap.end()) { svc = r->second; return EXIT_SUCCESS; }
	return EXIT_FAILURE;
}

int some_function(const std::string& a) {
	std::cout << "some_function called : " << a << std::endl;
	return EXIT_SUCCESS;
}

struct S001 {
	int operator()(int argc, char* argv[]) {
		std::cout << "S Function is called, argc : " << argc << ", argv[0] : " << (argc>0?argv[0]:"") << std::endl;
		return EXIT_SUCCESS;
	}
};


int main() {

	// MyUU1::test06();	
	
	std::function<int(const std::string&)> f1 = some_function;
	std::function<int(int argc, char* argv[])> f2 = S001();
	std::function<void(const char* str)> f3 = [](const char* str) { std::cout << "function3 called, str : " << str << std::endl; };

	fsvcmap["f2"] = S001();

	f1("Hello");
	
	int paramLen = 1;
	int strlength  = 0;
	char** param = (char**)malloc(sizeof(char*)*paramLen);
	param[0] = (char*)malloc(sizeof(char)*(strlength = strlen("Good")+1));
	memset(param[0], '\0', strlength);
	strncpy(param[0], "Good", strlength);
	f2(paramLen, param);

	fsvcmap["f2"](paramLen, param);
	FService svc;
	if(!getService(fsvcmap, "f2", svc)) svc(paramLen, param);

	f3("f3");

	for(int i=0;i<paramLen;i++) {
		delete param[i];
	}
	delete[] param;

	return EXIT_SUCCESS;
}

#endif

#if 0

#include <iostream>
#include <vector>

template <typename T, int& SZ>
class Arr {
	private:
		std::vector<T> elems;

	public:
		Arr() : elems(SZ) {}

		void print() const {
			for(int i=0;i<SZ;i++) {
				std::cout<< elems[i] << " ";
			}
		}
};

int size =10;

int main() {
	// Arr<int&, size> y;

	Arr<int,size> x;

	x.print();
	// size += 100;
	x.print();
	
	return 0;
}

#endif
