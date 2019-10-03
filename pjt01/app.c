#include <stdio.h>

size_t signum(size_t input);

int main() {
	size_t input = -10;
	printf("signum of (%ld) == %ld\n", input, signum(input));
	return 0;
}

