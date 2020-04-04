#include <stdio.h>
#include <stdlib.h>
#if defined(__linux)
	#include <stdio_ext.h>
	#define msleep(n) sleep(n)
	#define mfpurge(fp) __fpurge(fp)
#elif defined(WIN32) || defined(WIN64) || defined(__WIN32__) || defined(__NT__)
	#include <windows.h>	
	#define msleep(n) Sleep(n)
	#define mfpurge(fp) fflush(fp)
#endif

int main(int argc, char* argv[]) {
	int sleepMsec = 3000;
	int hz = 1000;
	int duration = 3000;
	int verbose = 0;
	if(argc > 1) {
		for(int i = 1;i < argc;i++) {
			if(!strcmp("-sp", argv[i]) && i+1<argc) {
				sleepMsec = atoi(argv[i+1]);
				i++;
			}
			else if(!strcmp("-hz", argv[i]) && i+1<argc) {
				hz = atoi(argv[i+1]);
				i++;
			}
			else if(!strcmp("-du", argv[i]) && i+1<argc) {
				duration = atoi(argv[i+1]);
				i++;
			}
			else if(!strcmp("-v", argv[i])) {
				verbose = 1;
			}

			for(int j = 0;argv[i][j]!='\0';j++){
				putchar(argv[i][j]);
			}
			putchar('\n');
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
	sleepMsec = 5000;
	for(int i = 0;i<n;i++) {
		scanf("%d", arr+i);
		sum+=*(arr+i);
	}
	avg = sum/n;

	printf("sum : %lld, avg : %030.2lf\n", sum , avg);

	while(1) {
		printf("\a");
		msleep(sleepMsec);
		Beep(hz, duration);
		MessageBeep(-1);
		MessageBeep(MB_OK);
		MessageBeep(MB_ICONINFORMATION);
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

	return 0;
}


