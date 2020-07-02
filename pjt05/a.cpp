#include <stdio.h>

int main() {
	int nInput = 0, i = 0;

	printf("n:"); fflush(stdout);
	scanf("%d", &nInput);
	if(nInput<1) nInput = 1;
	else if(nInput>9) nInput = 9;

	while(i<nInput) {
		putchar('*');
		i++;
	}
	getchar();
	putchar('\n');
	return 0;
}
