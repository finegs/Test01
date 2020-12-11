#include <stdio.h>
#include "ml.h"

size_t signum(size_t input)
{
	printf("From shared library, I got input of %zu\n", input);
	if(0==input) return 0;
	return input < 0 ? -1 : 1;
}


