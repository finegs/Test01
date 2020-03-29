#include <iostream>
#include <dlfcn.h>

void* handle = NULL;

int main(int argc, char* argv[]) {
	char* libName;
	if(!(libName = (char*)malloc(sizeof(char)*1024))) {
		fprintf(stderr, "libname malloc failed");
		exit(1);
	}

	if(!libName) {
		strcpy(libName, "libaa.so");
	}

	handle = dlopen(libName, RTLD_LAZY);

	if(handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(-1);
	}

	return 1;
}


