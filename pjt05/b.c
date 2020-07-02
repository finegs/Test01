#include <stdio.h>

int main2() {
	int nInput = 0, i = 0;

	scanf("%d", &nInput);
	if(nInput<1) nInput = 1;
	else if(nInput>9) nInput = 9;

	while(i<nInput) {
		putchar('*');
		i++;
	}

	putchar('\n');
	return 0;
}
