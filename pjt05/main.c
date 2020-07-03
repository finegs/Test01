
#include <stdio.h>
#include "myi2c.h"

int main() {

#if 0
	int a;
	printf("a:"); fflush(stdout);
	scanf("%d", &a); 
	printf("a:%d\n", a);

#endif

	myi2c_init();

	myi2c_release();

	return 0;
}
