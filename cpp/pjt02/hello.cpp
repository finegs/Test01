#include <stdio.h>
#include <iostream>
#include <string>
    
int main(int argc, char* argv[]) {
	printf("Hello World\n");
	std::cout << "Hello with std::cout" << std::endl;

	std::string s("World");

	std::cout << "World from string : " << s << std::endl;

	return 0;
}
