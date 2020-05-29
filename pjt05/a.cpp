#include <stdio.h>

int main() {
	int nInput = 0, i = 0;

	printf("Enter Number:"); fflush(stdout);
	scanf("%d", &nInput);fflush(stdin);
	if(nInput<1) nInput = 1;
	else if(nInput>9) nInput = 9;

	while(i<nInput) {
		putchar('*');
		i++;
	}

	putchar('\n');
	return 0;
}
