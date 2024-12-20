#include <stdio.h>
#include <stdlib.h>

#if 0
#define a_len  100000000
int a[a_len];

void init(int a[], int initValue, size_t size) {
	for(int i =0;i<(int)size;i++) {
		a[i] = (int)initValue;
	}
}

int isprime(int n) {
	if(a[n]>=0) return a[n];
	
	if(n==2) return 0;

	return a[n]=2*isprime(n/2) + n;
}

#endif

// C++ program Miller-Rabin primality test 
#include <stdio.h>
// #include <bits/stdc++.h> 
// using namespace std; 

// Utility function to do modular exponentiation. 
// It returns (x^y) % p 
int power(int x, unsigned int y, int p) 
{ 
	int res = 1;	 // Initialize result 
	x = x % p; // Update x if it is more than or 
				// equal to p 
	while (y > 0) 
	{ 
		// If y is odd, multiply x with result 
		if (y & 1) 
			res = (res*x) % p; 

		// y must be even now 
		y = y>>1; // y = y/2 
		x = (x*x) % p; 
	} 
	return res; 
} 

// This function is called for all k trials. It returns 
// false if n is composite and returns false if n is 
// probably prime. 
// d is an odd number such that d*2<sup>r</sup> = n-1 
// for some r >= 1 
int miillerTest(int d, int n) 
{ 
	// Pick a random number in [2..n-2] 
	// Corner cases make sure that n > 4 
	int a = 2 + rand() % (n - 4); 

	// Compute a^d % n 
	int x = power(a, d, n); 

	if (x == 1 || x == n-1) return 1; 

	// Keep squaring x while one of the following doesn't 
	// happen 
	// (i) d does not reach n-1 
	// (ii) (x^2) % n is not 1 
	// (iii) (x^2) % n is not n-1 
	while (d != n-1) 
	{ 
		x = (x * x) % n; 
		d *= 2; 

		if (x == 1)	 return 0; 
		if (x == n-1) return 1; 
	} 

	// Return composite 
	return 0; 
} 

// It returns false if n is composite and returns true if n 
// is probably prime. k is an input parameter that determines 
// accuracy level. Higher value of k indicates more accuracy. 
int isPrime(int n, int k) 
{ 
	// Corner cases 
	if (n <= 1 || n == 4) return 0; 
	if (n <= 3) return 1; 

	// Find r such that n = 2^d * r + 1 for some r >= 1 
	int d = n - 1; 
	while (d % 2 == 0) 
		d /= 2; 

	// Iterate given nber of 'k' times 
	for (int i = 0; i < k; i++) 
		if (!miillerTest(d, n)) 
			return 0; 

	return 1; 
} 

#if 0
// Driver program 
int main() 
{ 
	int k = 4; // Number of iterations 

	cout << "All primes smaller than 100: \n"; 
	for (int n = 1; n < 100; n++) 
	if (isPrime(n, k)) 
		cout << n << " "; 

	return 0; 
} 
#endif


int main(int argc, char* argv[]) {

	if(argc<2) {
		printf("usage : %s {string}\n", argv[0]);
		return EXIT_SUCCESS;
	}

	// char* sptr = argv[1], *tptr;
	// tptr = sptr;
// 
	// printf("sptr=%s, tptr=%s\n", sptr, tptr);
	
	int n,k;

	for(int i = 1 ;i<argc;i++) {
		if('-'==argv[i][0]) {
			if(argc>i+1) {
				if('n'==argv[i][1]) {
					n = atoi(argv[i+1]);
				} 
				else if('a'==argv[i][1]) {
					k = atoi(argv[i+1]);
				} 
			}
			i++;
		}
	}

	for(int i = 1;i<n;i++) {
		if(!isPrime(i,k)) continue;
		printf("%s%d", (i > 2) ? " ":"", i);
	}
	printf("\n");

	// init(a, -1, a_len);
	// printf("%d is %s\n", n, isprime(n,) ? "prime":"non-prime");

	return EXIT_SUCCESS;
}
