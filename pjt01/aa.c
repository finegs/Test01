#include <stdio.h>
#include <stdio_ext.h>

int main(int argc, char* argv[]) {

	if(argc > 1) {
		for(int i = 1;i < argc;i++) {
			for(int j = 0;argv[i][j]!='\0';j++){
				putchar(argv[i][j]);
			}
			putchar('\n');
		}
	}

	char szName[32] = {0};
	int nAge = 0;

#if __WIN32 || __WIN64
	fflush(stdin);
#else
	__fpurge(stdin);
#endif
	printf("Input Age : "); fflush(stdout);
	fscanf(stdin, "%d", &nAge);
#if __WIN32 || __WIN64
	fflush(stdin);
#else
	__fpurge(stdin);
#endif
	printf("Input Name: "); fflush(stdout);
	fgets(szName,sizeof(szName), stdin);

	printf("%d, %s\n", nAge, szName);

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


