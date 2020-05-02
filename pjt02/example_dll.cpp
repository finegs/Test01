#include <stdio.h>
#include "example_dll.h"

// __stdcall void hello(const char* s) {
void hello(const char* s) {
	printf("#### Hello %s\n", s);
}

int toDouble(int x) {
	return 2*x + 200;
}

void cppFunc(void) {
	puts("cppFunc 2");
}

void MyClass::func(void) {
	puts("MyClass::func()~~~ ");
}
