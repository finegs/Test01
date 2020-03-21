#include <stdio.h>

size_t signum(size_t input)
{
	printf("From shared library, I got input of %li\n", input);
	if(0==input) return 0;
	return input < 0 ? -1 : 1;
}


