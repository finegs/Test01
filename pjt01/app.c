#include <stdio.h>
#include "ml.h"

int main() {
	size_t input = -10;
	printf("signum of (%zu) == %zu\n", input, signum(input));
	return 0;
}

