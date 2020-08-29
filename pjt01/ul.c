#if 0
#include <stdio.h>
#include <stdlib.h>

int foo(int x) {
	return x+1>x;
}

int main() {
	int x = 1;

	printf("%d+1>%d=%d\n", x,x,foo(x));

	return 0;
}

#endif


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

	bool p;
	if(p) puts("p is true");
	if(!p) puts("p is false");

	return 0;
}
