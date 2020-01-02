#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	char* aa;
	aa = (char*)malloc(sizeof(char)*10);
	memset(aa, '\0', 10);

	aa[0] = 'a';
	aa[1] = 'z';
	aa[2] = '\0';

	printf("%s\n", aa);
	char* tt  = aa;
	while(*tt) {
		printf("%c", *tt);
		tt++;
	}
	printf("\n");

	printf("strlen[%d]=%s\n", strlen(aa), aa);

	return 0;
}
