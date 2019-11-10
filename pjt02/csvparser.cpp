#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef struct Test_Data
{
	int aa;
	char bb[30];
	double cc;
}testData;


testData tData[1000000];

int  parse(const char* file, testData* tData)
{
	FILE *pFile;
	char *pStr;
	char strTmp[255];
//	char *token;
	int recCnt = 0, lineNo = 0;
	errno_t ec;
	int i=0;

	ec = fopen_s(&pFile, file, "rb");
	if(pFile) {
		while(!feof(pFile))
		{
			pStr = fgets(strTmp, sizeof(strTmp), pFile);

			if(lineNo >= 2) { // skip ignore columns
				if(pStr == NULL) break;
				sscanf(pStr, "%d,%[^,],%lf\n",
						&tData[recCnt].aa,
						tData[recCnt].bb,
						&tData[recCnt].cc
					  );
				recCnt++;
			}
			else
				lineNo++;
		}
		fclose(pFile);
	}
	else {
		printf("Fail");
		recCnt = (int)ec;
	}
	return recCnt;
}


int main(int argc, char* argv[])
{

	if(argc < 1) {
		printf("Usage %s {file name}\n", argv[0]);
		return 0;
	}

	int rc = parse(argv[1], tData);
	if(!rc) printf("Error : %d\n", rc);
	else { printf("Parse Count : %d\n", rc); }
	return 0;
}

