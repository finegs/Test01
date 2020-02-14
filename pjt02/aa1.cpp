#include <cstdlib>
#include <iostream>
#include <unordered_map>

#include "mutil.hpp"
#include "mtest.hpp"

using namespace std;

template<typename T>
T square(T n) { return n*n; }

int f1(int argc, char* argv[]) {
	cout << getTimestamp() << ": f1 " << "argc = " << argc <<(argc>0? ", " : "")<< (argc>0 ? argv[0]: "")<< endl;
	return EXIT_SUCCESS;
}

int f2(int argc, char* argv[]) {
	cout << getTimestamp() << ": f2 " << "argc = " << argc <<(argc>0? ", " : "")<< (argc>0 ? argv[0]: "")<< endl;
	return EXIT_SUCCESS;
}

int f3(int argc, char* argv[]) {
	cout << getTimestamp() << ": f3 " << "argc = " << argc <<(argc>0? ", " : "")<< (argc>0 ? argv[0]: "")<< endl;
	return EXIT_SUCCESS;
}

int f4(int argc, char* argv[]) {
	long a;
	if(argc < 2) return EXIT_SUCCESS;
	a = atol(argv[1]);
	
	cout << "square(" << a << ")=" << square(a) <<endl;

	return EXIT_SUCCESS;
}

int f5(int argc, char* argv[]) {
	int text = 0;
	if(argc < 2) return EXIT_SUCCESS;
	while(true) {
		text = 0;
		printf("What text:");
		cout << "scan count"<<scanf("%d", &text)<<endl;
		printf("text : %d\n", text);
		fseek(stdin, 0, SEEK_END);
	}
}



typedef int(*handler)(int argc, char* argv[]);
typedef int command;

unordered_map<command, handler> commandMap;


void showCommand() {
	cout << "1:f1, 2:f2, 3:f3, 4:f4, 5:f5 -1:Exit" << endl;
}

int main(int argc,char* argv[]) {
	bool toExit = false;
	int cmd = 0;

	commandMap.insert(make_pair(1, f1));
	commandMap.insert(make_pair(2, f2));
	commandMap.insert(make_pair(3, f3));
	commandMap.insert(make_pair(4, f4));
	commandMap.insert(make_pair(5, f5));

	while(!toExit) {
		showCommand();
		cin >> cmd;

		auto it = commandMap.find(cmd);
		if(it != commandMap.end()) {
			it->second(argc, argv);
		}
		else if(-1 == cmd) {
			cout << "Exit" << endl;
			toExit = true;
		}
		else {
			cout << "Unsupported Command : " << cmd << endl;
		}
	}

	return EXIT_SUCCESS;
}
