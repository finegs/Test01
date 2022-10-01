#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum MyConstants {
	MAX_N = 1000000,

	MODE_EXCEPT = 101,
	MODE_INCLUDE = 102

};

int g_mode = MODE_EXCEPT;

void f1(int case_n, int case_c, int case_idx, char arr[], char rarr[], int* cnt) {
	if(case_idx > case_c) {
#if defined(__MYDEBUG)
		static char* str;
		if(!str) str = (char*)malloc(sizeof(char)*MAX_N);
		memset(str, 0, MAX_N);
		// strcat(str, "result:");
		char ss[20];
		memset(ss, 0, 20);

		sprintf(str, "%10d", *cnt);
		for(int i = 1;i<case_idx;i++) {
			sprintf(ss, "%s%d", (i>1?", " : " "), rarr[i]);
			strcat(str, ss);
		}
		printf("%s\n", str);
#endif	
		(*cnt)++;
		return;
	}

	for(int i = 1;i <= case_n;i++) {
		if((g_mode == MODE_EXCEPT) && arr[i]) continue;
		arr[i]=1;
		rarr[case_idx]=(char)i;

		f1(case_n, case_c, case_idx+1, arr, rarr, cnt);

		arr[i]=0;
	}
}

int main(int argc, char* argv[]) {

	const size_t FILE_NAME_LEN = 1024;
	char filename[1025];

	int case_n;
	int case_c;
	int cnt;

	memset(filename,0, FILE_NAME_LEN);
	filename[FILE_NAME_LEN] = '\0';
	case_n = 6;
	case_c = 3;
	for(int i = 1;i < argc;i++) {
		if ('-' == argv[i][0]) {
			if(strlen(argv[i])>1) {
				switch(argv[i][1]) {
					case 'f': { 
								  strcpy_s(filename, FILE_NAME_LEN, argv[i]+2); 
							  }
						break;
					case 'n': { 
								  if(strlen(argv[i]+2) > 0)  
									  case_n = atoi(argv[i]+2); 
							  } 
						break;
					case 'c': { 
								  if(strlen(argv[i]+2) > 0)  
									  case_c = atoi(argv[i]+2); 
							  } 
						break; 
					case 'm': { 
								  if(strlen(argv[i]+2) > 0) {
									  if('e'==argv[i][2] || 'E'==argv[i][2]) g_mode = MODE_EXCEPT; 
									  else if('i'==argv[i][2] || 'I'==argv[i][2]) g_mode = MODE_INCLUDE; 
									  else {
										  fprintf(stderr, "Unknown Mode : %c, (Default Mode = 'E')\n", argv[i][2]);
									  }
								  }
							  }
						break;
					default: {
								 fprintf(stderr, "Unknown Option : %s\n", argv[i]);
								 exit(1);
							 }
				}
			}
		}
	}

	printf("%d : argc:%d, filename:%s\n", __LINE__, argc, filename);

	char *arr, *rarr;

	arr = (char*)malloc(sizeof(char)*MAX_N);
	rarr = (char*)malloc(sizeof(char)*MAX_N);

	memset(arr, 0, MAX_N);
	memset(rarr, 0, MAX_N);

	f1(case_n, case_c, 1, arr, rarr, &cnt);

	printf("%d : ### Result : cnt = %d ###\n", __LINE__, cnt);

	return 0;
}
