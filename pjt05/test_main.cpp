
#include <iostream>
#include <cstdio>
#include <map>


using namespace std;

int main(int argc, char* argv[]) {

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

	cout << "mm.size() : " << mm.size() << endl;
	cout << "mm.count() : " << mm.count(40) << endl;

	for(iter = mm.begin();iter != mm.end();iter++) {
		cout << "[" << iter->first << "," << iter->second << "] ";
	}

	cout << endl << endl;

	mm.insert({40,440});
	mm.insert({40,3});

	cout << "mm.size():"<<mm.size()<<endl;
	cout << "mm.count(40):"<<mm.count(40)<<endl;


	for(iter = mm.begin();iter != mm.end();iter++) {
		cout << "[" << iter->first << "," << iter->second << "] ";
	}

	std::getchar();

	return 0;
}


