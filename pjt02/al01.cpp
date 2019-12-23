#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cstring>

#define max(x,y)  (x) > (y) ? (x) : (y)

using namespace std;

int lcs[1001][1001];
//char str1[1001];
//char str2[1001];

int main() {
	char *str1,*str2;
	str1 = (char*)malloc(sizeof(char)*1001);
	memset(str1, '\0', 1001);
	str2 = (char*)malloc(sizeof(char)*1001);
	memset(str2, '\0', 1001);
	cout << "Enter two string" << endl;
	scanf("%s", str1+1);
	scanf("%s", str2+1);

	str1[0] = '0';
	str2[0] = '0';

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 =0;

	for(int i = 0;i < len1;i++) {
		for(int j = 0;j<len2;j++) {
			if(i==0||j==0) {
				lcs[i][j]=0;
				continue;
			}

			if(str1[i]==str2[j]) {
				lcs[i][j] = lcs[i-1][j-1]+1;
			} else {
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}


	int i = len1 - 1;
	int j  =len2 - 1;

//	stack<int> st;
	int *st;
	int st_t=0,st_b = 0;

	st = (int*)malloc(sizeof(int*)*1001);
	memset(st, 0, 1001);

	while(lcs[i][j] != 0) {
		if(lcs[i][j] == lcs[i][j-1])  { j--; }
		else if(lcs[i][j] == lcs[i-1][j]) { i--; }
		else if(lcs[i][j] -1 == lcs[i-1][j-1]) {
			//st.push(i);
			st[st_t++]=i;
			i--;
			j--;
		}
	}


	cout << "str[" << lcs[len1-1][len2-1] << "]=";
	stringstream ss;
	while(st_t>0) {
		ss << str1[st[st_t-1]];
		st_t--;
	}
	cout << ss.str() << endl;

	cout << "str1:" << str1 <<endl;
	cout << "str2:" << str2 <<endl;
//	cout << "str1.find(str2)=" << strlen(str1) - (strstr(str1,str2) - str1) << endl;
	char* s = strstr(str1+1, str2+1);
	cout << "str1.find(str2)=" << s << ", abs(str1+1-s)="<< abs(str1+1-s) << endl;
	cout << "str1.find(str2)=" << s << ", pos="<< str1+1-s << endl;

	return 0;
}

