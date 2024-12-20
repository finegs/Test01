
/*
 * k ==> Number of floors
  n ==> Number of Eggs
  eggDrop(n, k) ==> Minimum number of trials needed to find the critical
                    floor in worst case.
  eggDrop(n, k) = 1 + min{max(eggDrop(n - 1, x - 1), eggDrop(n, k - x)): 
                 x in {1, 2, ..., k}}
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


int max(int a, int b) { return a>b? a: b; }

#if 0
int eggdrop(int n, int f) {

	if(f==1||f==0) return f;

	if(n == 1) return f;

	int min = INT_MAX, x, res;

	for(x = 1; x <= f;x++) {
		res = max(eggdrop(n-1, x-1),  // break
				eggdrop(n, f-x)); // no-break
		if(res<min) min = res;
	}

	return min+1;
}

#endif

#if 1

int eggdrop(int n, int f) {
	int arr[n+1][f+1];
	int res;
	int i,j,x;

	for(i=1;i<=n;i++) {
		arr[i][1]=1;
		arr[i][0]=0;
	}

	for(j=1;j<=f;j++) {
		arr[1][j]=j;
	}

	for(i=2;i<=n;i++) {
		for(j=2;j<=f;j++) {
			arr[i][j]=INT_MAX;
			for(x=1;x<=j;x++) {
				res = 1 + max(arr[i-1][x-1], arr[i][j-x]);
				if(res<arr[i][j]) arr[i][j] = res;
			}
		}
	}

	return arr[n][f];
}
#endif

int main(int argc, char* argv[]) {

	int n,f;
	for(int i=1;i<argc;i++) {
		if(!strcmp("-n", argv[i]) && i+1<argc) n = atoi(argv[i+1]);
		else if(!strcmp("-f", argv[i]) && i+1<argc) f = atoi(argv[i+1]);
	}

	if(n<1||f<0) { printf("Illegal arguments : n=%d, f=%d\n", n, f); return EXIT_FAILURE; }

	printf("arguments : n=%d, f=%d\n", n, f);

	printf("min attempt : %d\n", eggdrop(n,f));


	return EXIT_SUCCESS;
}

