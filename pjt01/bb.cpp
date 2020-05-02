
#if 1

#include <stdio.h>
#include <chrono>
#include <ctime>

void print_timediff(const char* prefix, const struct timespec& start, const 
struct timespec& end)
{
    double milliseconds = end.tv_nsec >= start.tv_nsec
                        ? (end.tv_nsec - start.tv_nsec) / 1e6 + (end.tv_sec - start.tv_sec) * 1e3
                        : (start.tv_nsec - end.tv_nsec) / 1e6 + (end.tv_sec - start.tv_sec - 1) * 1e3;
    printf("%s: %lf milliseconds\n", prefix, milliseconds);
}

int main()
{
    int i, n = 1000000;
    struct timespec start, end;

    // Test stopwatch
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < n; ++i) {
        struct timespec dummy;
        clock_gettime(CLOCK_MONOTONIC, &dummy);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    print_timediff("clock_gettime", start, end);

    // Test chrono system_clock
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < n; ++i)
        auto dummy = std::chrono::system_clock::now();
    clock_gettime(CLOCK_MONOTONIC, &end);
    print_timediff("chrono::system_clock::now", start, end);

    // Test chrono steady_clock
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < n; ++i)
        auto dummy = std::chrono::steady_clock::now();
    clock_gettime(CLOCK_MONOTONIC, &end);
    print_timediff("chrono::steady_clock::now", start, end);

    // Test chrono high_resolution_clock
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < n; ++i)
        auto dummy = std::chrono::high_resolution_clock::now();
    clock_gettime(CLOCK_MONOTONIC, &end);
    print_timediff("chrono::high_resolution_clock::now", start, end);

    return 0;
}
#endif


#if 0

#include <stdio.h>
int n,cnt;

int isprime(int x) {
	if(x<2) return 0;
	for(int i = 2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}

void f(int num, int len) {
	if(len==n) {
		if(num==0) return;

		int flag=1;
		int temp = num;
		while(temp) {
			if(!isprime(temp)) return;
			temp /= 10;
		}
		cnt++;
		printf("%d\n", num);
		return;
	}
	else {
		for(int i=1;i<=9;i++) {
			f(num*10+i, len+1);
		}
	}
}

int main() {
	scanf("%d", &n);
	f(0,0);
	printf("cnt : %d\n", cnt);

	return 0;
}

#endif

#if 0

#include <time.h>
#include <stdio.h>

int isprime(int x) {
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) {
		if(x%i==0) return 0;
	}
	return 1;
}

void searchPrime(int* n,int num,int len, int* cnt) {
	if(len==*n) {
		if(num==0) return;

		int flag = 1;
		int temp = num;
		while(temp) {
			if(!isprime(temp)) return;
			temp /= 10;
		}
		(*cnt)++;
		printf("%d\n", num);
		return;
	}
	else {
		for(int i =1;i<=9;i++) {
			searchPrime(n, num*10+i, len+1, cnt);
		}
	}
}


int main(int argc, char* argv[]) {

	int n,cnt;
	time_t start,end;

	scanf("%d",&n);
	cnt = 0;

	time(&start);
	searchPrime(&n, 0, 0, &cnt);
	time(&end);

	printf("cnt : %d, Elapsed : %.2lf\n", cnt, difftime(end, start));

	return 0;
}


#endif
