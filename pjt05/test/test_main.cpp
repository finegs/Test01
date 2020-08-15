
#include <iostream>
#include <cstdio>
#include <map>
#include <my.hpp>


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
	cout <<  my::ts() << "mm.count(40):"<<mm.count(40)<<endl;


	for(iter = mm.begin();iter != mm.end();iter++) {
		cout << (iter == mm.begin() ? "" : ", " ) << "{" << iter->first << "," << iter->second << "}";
	}

	cout << "\n";

	std::getchar();

	return 0;
}


