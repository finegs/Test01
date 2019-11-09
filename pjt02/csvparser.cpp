#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cerror>

typedef struct Test_Data
{
	int aa;
	char bb[30];
	double cc;
}testData;


testData tData[300];

int  parse(const char* file, testData* tData)
{
	FILE *pFile;
	char *pStr;
	char strTmp[255];
	char *token;
	int cnt = 0, colCnt = 0, ec;
	errno_t ec;
	int i=0;

	ec = fopen_s(&pFile, file, "rb");
	if(pFile) {
		while(!feof(pFile))
		{
			pStr = fgets(strTmp, sizeof(strTmp), pFIle);

			if(colCnt >= 2) {
				if(pStr == NULL) break;
				sscanf(pStr, "%d,%[^,],%lf\n",
						&tData[cnt].aa,
						&tData[cnt].bb,
						&tData[cnt].cc
					  );
				cnt++;
			}
			else
				colCnt++;
		}
		fclose(pFile);
	}
	else {
		printf("Fail");
	}
	return cnt;
}

