#include <stdio.h>
#include <stdlib.h>
#if defined(__linux)
	#include <stdio_ext.h>
	#define msleep(n) sleep(n)
	#define mfpurge(fp) __fpurge(fp)
#elif defined(WIN32) || defined(WIN64) || defined(__WIN32__) || defined(__NT__)
	#include <windows.h>	
	#include <pthread.h>
	#define msleep(n) Sleep(n)
	#define mfpurge(fp) fflush(fp)
#endif

struct thread_params {
	int values[10];
};

long unsigned int doBeep(void* argv);
long mhash(const char* str);

int main(int argc, char* argv[]) {
	int sleepMsec = 3000;
	int hz = 1000;
	int duration = 3000;
	int verbose = 0;
	int f1 = 0, f2 = 0, f3;
	int async = 0;
	if(argc > 1) {
		for(int i = 1;i < argc;i++) {

			if(!strcmp("-f1", argv[i])) {
				f1 = 1;
			}
			else if(!strcmp("-f2", argv[i])) {
				f2 = 1;
			}
			else if(!strcmp("-f3", argv[i])) {
				f3 = 1;
			}
			else if(!strcmp("-period", argv[i]) && i+1<argc) {
				sleepMsec = atoi(argv[i+1]);
				i++;
			}
			else if(!strcmp("-hz", argv[i]) && i+1<argc) {
				hz = atoi(argv[i+1]);
				i++;
			}
			else if(!strcmp("-duration", argv[i]) && i+1<argc) {
				duration = atoi(argv[i+1]);
				i++;
			}
			else if(!strcmp("-v", argv[i])) {
				verbose = 1;
			}
			else if(!strcmp("-async", argv[i])) {
				async = 1;
			}
		}
	}

	if(verbose) {
		if(argc > 1) {
			for(int i = 1;i < argc;i++) {
				for(int j = 0;argv[i][j]!='\0';j++){
					putchar(argv[i][j]);
				}
				putchar('\n');
			}
		}
	}

	if(f1) {
		int n;
		int* arr;
		long long int sum;
		double avg;
	
		mfpurge(stdin);
		printf("Input Data(ex. length data#1 data#2 .... ) : "); fflush(stdout);
		scanf("%d", &n);
		arr = (int*)malloc(sizeof(char)*n);
		sum = 0;
		avg = 0.0;
		for(int i = 0;i<n;i++) {
			scanf("%d", arr+i);
			sum+=*(arr+i);
		}
		avg = sum/n;
		printf("sum : %lld, avg : %030.2lf\n", sum , avg);
	
		free(arr);
	}
	else if(f2) {
		struct thread_params param = { sleepMsec, hz, duration };
		DWORD t_decriptor;
		if(async) {
			CreateThread(NULL, 0, doBeep, (void*)&param, 0, &t_decriptor);

			char c;
			int lineno = 0;
			while(1) {
				if(lineno>50) { lineno = 0; system("cls"); }
				printf("Main program, Enter 'q' or Ctrl+C : "); fflush(stdout);
				lineno++;
				c = getchar();
				if('q'==c||'Q'==c) break;
				// msleep(3000);
			}

		} else {
			doBeep(&param);
		}
	}
	else if(f3) {
		char* str;
		str = (char*)malloc(sizeof(char)*1024);
		while(1) {
			mfpurge(stdin);
			printf("Enter str t hash: "); fflush(stdout);
			gets(str);
			if(!strcmp("-quit", str)) break;
			printf(" hash(\"%s\") = %ld\n", str, mhash(str));
		}
		free(str);
	}

#if 0
	char szName[32] = {0};
	int nAge = 0;

	mfpurge(stdin);
	printf("Input Age : "); fflush(stdout);
	// fscanf(stdin, "%d", &nAge);
	fscanf(stdin, "%d%*c", &nAge);

	mfpurge(stdin);
	printf("Input Name: "); fflush(stdout);
	fgets(szName,sizeof(szName), stdin);

	printf("%d, %s\n", nAge, szName);
#endif
#if 0
	if(argc > 1) {
		for(int i = 1;i < argc;i++) {
			for(int j = 0;argv[i][j]!='\0';j++){
				putchar(argv[i][j]);
			}
			putchar('\n');
		}
	}

	char ch = 0;

	ch = getchar();

	putchar(ch);

	putchar('z');
#endif

	return EXIT_SUCCESS;
}

long unsigned int doBeep(void* argv) {
	struct thread_params* p = (struct thread_params*)argv;
	int sleepMsec = p->values[0];
	int hz = p->values[1];
	int duration = p->values[2];
	while(1) {
		printf("\a");
		msleep(sleepMsec);
		Beep(hz, duration);
		// MessageBeep(-1);
		// MessageBeep(MB_OK);
		// MessageBeep(MB_ICONINFORMATION);
	}
}

long mhash(const char* str) {
	long hc;
	if(!str) return -1;
	hc = 37;
	for(int i =0;*(str+i)!='\0';i++) {
		hc += hc << 3;
		hc += *(str+i);
		hc %= 37;
	}
	return hc;
}
