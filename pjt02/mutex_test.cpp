#if 0
#include <mutex>
#include <thread>
#include <vector>
#include <sstream>

std::mutex cout_mutex; // control access to std::cout
std::timed_mutex mutex;
 
void job(int id) 
{
    using Ms = std::chrono::milliseconds;
    std::ostringstream stream;
			 
    for (int i = 0; i < 3; ++i) {
        if (mutex.try_lock_for(Ms(100))) {
            stream << "success ";
            std::this_thread::sleep_for(Ms(100));
            mutex.unlock();
        } else {
																				            stream << "failed ";
        }
        std::this_thread::sleep_for(Ms(100));
    }

    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "[" << id << "] " << stream.str() << "\n";
}
 
int main() 
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(job, i);
    }
			 
    for (auto& i: threads) {
        i.join();
    }
}


#endif


#if 0
#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
 
std::shared_timed_mutex test_mutex;
 
void f()
{
	auto now=std::chrono::steady_clock::now();
	test_mutex.try_lock_until(now + std::chrono::seconds(10));
	std::cout << "hello world\n";
}
 
int main()
{
	std::lock_guard<std::shared_timed_mutex> l(test_mutex);
	std::thread t(f);
	t.join();
}
#endif

#if 0
#include <stdio.h>
#include <thread>
#include <stdatomic.h>
 
atomic_int acnt;
int cnt;
 
int f(void* thr_data)
{
    for(int n = 0; n < 1000; ++n) {
        ++cnt;
        ++acnt;
        // for this example, relaxed memory order is sufficient, e.g.
        // atomic_fetch_add_explicit(&acnt, 1, memory_order_relaxed);
    }
    return 0;
}
 
int main(void)
{
    std::thread thr[10];
    for(int n = 0; n < 10; ++n)
        thr[n] = std::thread(f, NULL);
    for(int n = 0; n < 10; ++n)
        thr[n].join();
 
    printf("The atomic counter is %u\n", acnt);
    printf("The non-atomic counter is %u\n", cnt);
}
#endif


#if 0

#include <stdio.h>
#include <time.h>
 
int main(void)
{
    clock_t t = clock();
    double d = 0.0;
    for (int n=0; n<10000; ++n)
       for (int m=0; m<10000; ++m) {
           d += d*n*m; // reads and writes to a non-volatile 
		}

    printf("Modified a non-volatile variable 100m times. "
           "Time used: %.2f seconds\n",
           (double)(clock() - t)/CLOCKS_PER_SEC);
 
    t = clock();
    volatile double vd = 0.0;
    for (int n=0; n<10000; ++n)
       for (int m=0; m<10000; ++m)
           vd += vd*n*m; // reads and writes to a volatile 
    printf("Modified a volatile variable 100m times. "
           "Time used: %.2f seconds\n",
           (double)(clock() - t)/CLOCKS_PER_SEC);
}

#endif 


#if 0

#include <stdio.h>
#include <time.h>

int main(void) {
	clock_t t = clock();
	double d = 0.0;
	for(int n=0;n<10000;++n) 
		for(int m=0;m<10000;m++)
			d += d*n*m;

	printf("Modified a non-volatile variable 100m times. "
			"Time used:%.2f seconds\n",
			(double)(clock()-t)/CLOCKS_PER_SEC);

	t = clock();
	volatile double vd = 0.0;
	for(int n=0;n<10000;++n) 
		for(int m=0;m<10000;m++)
			vd += vd*n*m;

	printf("Modified a volatile variable 100m times. "
			"Time used:%.2f seconds\n",
			(double)(clock()-t)/CLOCKS_PER_SEC);

}

#endif


#if 0
#include <stdio.h>

struct S {
	unsigned b1:5,:11,b2:6, b3:2;
};

int main(void)
{
	printf("%zu\n", sizeof(struct S));
	return 0;
}

#endif


#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* arr;

int main(void) {
	int n;

	printf("n:"); fflush(stdout);
	n = 0;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int)*n);

	free(arr);

	char* carr;

	carr = (char*)malloc(sizeof(char)*n);
	if(!carr) return -1;
	memset(carr, '\0', n);
	printf("Enter Messages len=%d(end with newline)\n", n);
	fflush(stdin);

	gets(carr);

	printf("Message :[%zu] = %s\n", strlen(carr), carr);

	free(carr);

	return 0;
}


#endif

#if 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparator_int(void* a, void* b){
	return *((int*)a)-*((int*)b);
}
int comparator_int_r(void* a, void* b){
	return *((int*)b)-*((int*)a);
}

void quicksort(int* number, int first, int last, int (*cf)(void* a, void* b)) {
	int i,j,p,t;

	if(first<last) {
		p = first;
		i = first;
		j= last;

		while(i<j) {
			while(cf(&number[i], &number[p])<=0 && i<last)
				i++;
			while(cf(&number[j], &number[p])>0)
				j--;
			if(i<j) {
				t = number[i];
				number[i]=number[j];
				number[j]=t;
			}
		}

		t = number[p];
		number[p]=number[j];
		number[j]=t;

		quicksort(number, first, j-1, cf);
		quicksort(number, j+1, last, cf);
	}
}

void loadData(const char* fileName, int** arr, int* arrLen) {
	FILE *f;
	int lineNo;
	char line[1024];
	char* str;
	errno_t ec;

	lineNo = 1;
	ec = fopen_s(&f, fileName, "rb");
	if(!f) { fprintf(stderr, "file open failed.[%d]\n", ec); return;}
	while(!feof(f)) {
		memset(line, '\0', 1024);
		str = fgets(line, sizeof(line), f);
		if(lineNo==1) {
			printf("Line[%d]=%s\n", lineNo, str);
			*arrLen = atoi(str);
			*arr = (int*)malloc(sizeof(int)*(*arrLen));
		}
		else {
			if(str==NULL) break;
			(*arr)[lineNo-2] = atoi(str);
			////			**(arr++) = atoi(str);
		}
		lineNo++;
	}

   	fclose(f); 	
}

void printArr(const char* msg, int* arr, int arrLen) {
	printf("=================== %s =====================\n", msg);
	for(int i = 0;i<arrLen;i++) {
		printf("%d\t%s", arr[i], (i>0 && i%5==0) ? "\n" :"");
	}
	if(arrLen <5) printf("\n");
	printf("============================================\n");
}


int main(int argc, char** argv) {
	if(argc<1) { printf("Usage : %s {fileName}\n", argv[0]); return 0; }

	char* fileName;
	int reverse = 0;

	for(int i = 0;i<argc;i++) {
		if((!strcmp("-f", argv[i]) || 
					!strcmp("-F", argv[i])) && argc > i+1) {
			fileName = argv[i+1];i++;
		}
		else if(!strcmp("-r", argv[i]) ||
				!strcmp("-R", argv[i])) {
			reverse = 1;
		}
	}

	int* arr;
	int arrLen;

	loadData(argv[1], &arr, &arrLen);

	printArr("Before quicksort", arr, arrLen);

	quicksort(arr, 0, arrLen-1, reverse? comparator_int_r : comparator_int);

	printArr("After quicksort", arr, arrLen);
	
	return 0;
}
    		
#endif
