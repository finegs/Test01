#include <stdio.h>
#include "ml.h"

int main() {
	size_t input;
	printf("Input:"); fflush(stdout);
	scanf("%d", (int*)&input);
	printf("signum of (%zu) == %zu\n", input, signum(input));
	return 0;
}
