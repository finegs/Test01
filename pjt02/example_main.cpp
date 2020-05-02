#include <stdio.h>
#include <stdlib.h>
#include "example_dll.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

int main(void)
{
	std::string line;
	while(1) {

		hello("World");
	    printf("%d\n", toDouble(333));
	    cppFunc();
	
	    MyClass a;
	    a.func();

		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		hello("\n");

		line.clear();
		std::getline(std::cin, line);
	 
	}

    return 0;
}
