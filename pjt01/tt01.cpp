#include <iostream>
#include <cstdio>
#include <cstdlib>

void print2Arr(int (*arrp)[2], int n);


int main(int argc, char* argv[]) {

	int arr[][2] = {{1, 2},{3,4},{5,6},{7,8},{9,10}};

	int (*arrp)[2] = arr;

	printf("Before\n");

	print2Arr(arrp, 5);

	printf("After\n");

	arrp = arr;

	for (int i = 0;i<5;i++) {
		printf("arr=0x%p, **arr=%d\n", arrp, **arrp);
		arrp++;
	}
	return EXIT_SUCCESS;
}


void print2Arr(int (*arrp)[2], int n) {
	for (int i = 0;i<n;i++) {
		printf("arr=0x%p, **arr=%d\n", arrp, **arrp);
		arrp++;
	}
}
