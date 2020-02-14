#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <thread>
#include <cstring>
#include <vector>
#include <time.h>

#include "mutil.hpp"
#include "mtest01.hpp"

#if USE_MSTR_TOK > 0
#define __STRTOK mstrtok
#else
#define __STRTOK strtok
#endif

using namespace std;

/*
void buildMaxHeap(int arr[], int n)  
{  
    for (int i = 1; i < n; i++)  
    { 
        // if child is bigger than parent 
        if (arr[i] > arr[(i - 1) / 2])  
        { 
            int j = i; 
      
            // swap child and parent until 
            // parent is smaller 
            while (arr[j] > arr[(j - 1) / 2])  
            { 
                swap(arr[j], arr[(j - 1) / 2]); 
                j = (j - 1) / 2; 
            } 
        } 
    } 
} 
  
void heapSort(int arr[], int n)  
{ 
    buildMaxHeap(arr, n); 
  
    for (int i = n - 1; i > 0; i--) 
    { 
        // swap value of first indexed  
        // with last indexed  
        swap(arr[0], arr[i]); 
      
        // maintaining heap property 
        // after each swapping 
        int j = 0, index; 
          
        do
        { 
            index = (2 * j + 1); 
              
            // if left child is smaller than  
            // right child point index variable  
            // to right child 
            if (arr[index] < arr[index + 1] && 
                                index < (i - 1)) 
                index++; 
          
            // if parent is smaller than child  
            // then swapping parent with child  
            // having higher value 
            if (arr[j] < arr[index] && index < i) 
                swap(arr[j], arr[index]); 
          
            j = index; 
          
        } while (index < i); 
    } 
} 

*/

#if 0
void buildMaxHeap(int arr[], int n)
{
	for(int i = 1;i<n;i++) {
		if(arr[i]>arr[(i-1)/2]) {
			int j = i;

			while(arr[j]>arr[(j-1)/2]) {
				swap(arr[j], arr[(j-1)/2]);
				j=(j-1)/2;
			}
		}
	}
}

void heapsort(int arr[], int n)
{
	buildMaxHeap(arr,n);

	for(int i = n-1;i>0;i--) {
		swap(arr[0], arr[i]);

		int j = 0, index;

		do {
			index =  (2*j +1);

			if(arr[index]<arr[index+1] &&
					index < (i-1))
				index++;

			if(arr[j]<arr[index] && index<i)
				swap(arr[j], arr[index]);

			j = index;

		} while(index < i);
	}
}

#endif

int main(int argc,char* argv[]) {
	unordered_map<string, string> argm;
	std::vector<std::string> args;

	long sleepTime, sleepCount;

	sleepTime = 1000;
	sleepCount = 0;
	for(int i = 1;i<argc;i++) {
		if(!strcmp("-t", argv[i]) && i+1 < argc){
			argm.insert({argv[i], argv[i+1]});

			sleepTime = atol(argv[i+1]);

			i++;
		}
		else if (!strcmp("-n", argv[i]) && i+1 < argc){
			argm.insert({argv[i], argv[i+1]});

			sleepCount = atol(argv[i+1]);

			i++;
		}
		else if(!strcmp("-tt", argv[i])) {
		//	char* tt = (char*)malloc(sizeof(char)*1);
		//	memset(tt, '\0', 1);
			std::cout << getTimestamp() << " {\"timestamp\":\"" << getTimestamp() << "\"}" << endl;
			std::cout << getTimestamp() << " {\"timestamp2\":\"" << getTimestamp() << "\"}" << endl;
		}
		else if(!strcmp("-t01", argv[i])) {
			std::cout << getTimestamp() << " : -t01" << std::endl;
		}	
		else if(!strcmp("-t02", argv[i])) {
			char buf[256];
			int len;
			int i;

			len = sprintf(buf, "Hello\n");
			for(i=0;i<5;i++)
				len += sprintf(buf+len, " %d",i);

			printf("buf=%s\n", buf);

			char buf2[20];
			char str[] = "Hello world!";
			snprintf(buf2, strlen(str), "%s", str);
			printf("%s\n", buf2);
			snprintf(buf2, 10, "%s", str);
			printf("%s\n", buf2);

		}
		else if(!strcmp("-t03", argv[i])) {
#if 0
			int n = 10;
			if(i+1<argc) {
				n = atoi(argv[i+1]);
			}

			for(int i = 0;i<n;i++) {
				printf("%3d is %4s\n", i, (i&1)? "ODD" : "EVEN");
			}
#endif

			Point pt;
			pt(3,2);
			pt.show();
		}
		else if(!strcmp("-t04", argv[i])) {
			int n = 253;
			if(i+1<argc) {
				n = atoi(argv[i+1]);
			}

			std::cout << getTimestamp() << " 0. n : " << n << std::endl;

			std::srand(static_cast<unsigned int>(std::time(0)));

			char *arr = (char*)malloc(sizeof(char)*n);
			memset(arr, '\0', n);
			for(int i = 0;i<n;i++) {
				// arr[i] = (i + 0x21)%255 + 2;
				switch(rand()%3) {
					case 0:
						arr[i] = '0' + std::rand()%('9'-'0');
					break;
					case 1:
						arr[i] = 'A' + std::rand()%('Z'-'A');
					break;
					case 2:
						arr[i] = 'a' + std::rand()%('z'-'a');
					break;
					default:
					;
				}
			}

			std::cout << "'0'="<<(int)'0' << ",'A'="<<(int)'A'<<",'z'="<<(int)'z'<<std::endl;

			string s = std::string(arr);

			std::cout << getTimestamp() << " 1. s[" << s.length() << "]=" << s << std::endl;

			std::cout << getTimestamp() << " 1. Start. " << std::endl;

			remove_ctrl(s);

			std::cout << getTimestamp() << " 1. Done."<< std::endl;
			
			memset(arr, '\0', n);
			for(int i = 0;i<n;i++) {
				// arr[i] = (i + 0x21)%255 + 2;
				arr[i] = 'A' + std::rand() % ('z'-'A');
			}
			s.clear();
			s.append(arr);
			// s = std::string(arr);

			std::cout << getTimestamp() << " 2. s[" << s.length() << "]=" <<  s << std::endl;
			std::cout << getTimestamp() << " 2. Start. " << std::endl;

			remove_ctrl_mutating(s);

			std::cout << getTimestamp() << " 2. Done."<< std::endl;

			free(arr);

		}
		else if (!strcmp("-a", argv[i]) && i+1 < argc) {
			argm.insert({argv[i], argv[i+1]});

			size_t len;
			char* tdelim;
			if(i+2<argc) {
				tdelim = argv[i+2];
			} else {
				tdelim = (char*)malloc(sizeof(char)*(len=strlen(",")+1));
				memset(tdelim, '\0',len);
				strcpy(tdelim, ",");
			}

			const char* delim = tdelim;
			char* temp = (char*)malloc((len = strlen(argv[i+1]))+1);
			memset(temp+len, '\0', 1);

			strncpy(temp, argv[i+1], len);
			std::cout << getTimestamp() << " {\"temp\":\"" << temp << "\"}"<< std::endl;
			std::cout << getTimestamp() << " {\"delim\":\"" << delim <<"\"}"<< std::endl;
			char* token= __STRTOK(temp, delim);
			while(token) {
				args.push_back(std::string(token));
				*(token+strlen(token)) = delim[0];
				token = __STRTOK(NULL, delim);
			}

			free(temp);
			temp = token = NULL;

			std::cout << getTimestamp() << " {\"tokens\":[";
			int j=0;
			for(auto it = args.cbegin();it!=args.cend();it++) {
				std::cout << ((j>0)? ", ":"") << "\"" << (*it) << "\"";
				j++;
			}
			cout << "]}"<<endl;


			i++;
		}
		else if(argv[i][0] == '-' && i+1 < argc) {
			argm.insert({argv[i], argv[i+1]});
		}
		else {
			argm.insert({argv[i], argv[i]});
		}
	}
	
	// auto search = argm.find("-t");
	if(argm.find("-t") != argm.end()) {
	// if(search != argm.end()) {
		cout << getTimestamp() << " [I]" << " sleep time=" << sleepTime<< endl;
		cout << getTimestamp() << " [I]" << " sleep count=" << sleepCount<< endl;
		system("pause");

		for (int i=0;!sleepCount || i< sleepCount;i++) {
			cout << getTimestamp() << " {\"argv\":[";
			for(int i = 0;i<argc;i++) {
				cout << (i > 0 ? "," : "") << "\"" << argv[i] << "\"";
			}
			cout << "]}" << endl;

			int j = 0;
			cout << getTimestamp() << " {\"args\":[";
			for(auto it = args.cbegin();it!= args.cend();it++) {
				cout << (j>0? ",":"") << "\"" << (*it) << "\"";
				j++;
			}
			cout << "]}"<<endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		}
	}
	else if(argm.find("-ht") != argm.end()) {
		std::string &ss = argm["-a"];
		std::vector<char> tv(ss.begin(), ss.end());
		tv.push_back('\0');
		char* a = &tv[0];
		// char* a = argm["-a"].c_str();
		int *arr;
		int arrLen = 10;
        int n;
		// printf("-a is %s\n", ss.c_str());

        if(!ss.empty()) {
			arr = (int*)malloc(sizeof(int)*arrLen);
			memset(arr, 0, arrLen);

			int num;
			char *ta = mstrtok(a,",");
			n = 0;
			printf("\n");
			while(ta) {
				if (n >= arrLen) {
				  int *tarr =
					  (int *)malloc(sizeof(int) * arrLen * 2);
				  if (!tarr) {
					fprintf(stderr, "fail to malloc\n");
					exit(-100);
				  }
				  memset(tarr, 0, arrLen * 2);
				  memcpy(tarr, arr, sizeof(int)*arrLen);

				  free(arr);
				  arr = NULL;

				  arrLen = arrLen * 2;
				  arr = tarr;
				  tarr = NULL;
				}
				num = atoi(ta);
				// printf("%s[%d]=%d", (n>0?", ":""), n, num);
				arr[n++] = num;
				ta=mstrtok(NULL, ",");
			}
			// printf("\nn=%d\n", n);
		}
		else {
			std::vector<int> iv{10,20,15,27,9,21,88,55,33,99,1001,12,1,2,-100,-201};
			arr = &iv[0];
            n = iv.size();
        }

     	// int n = sizeof(arr)/sizeof(arr[0]);
		
		printf("before:\t");
		for(int i = 0;i<n;i++) printf("%s%d", (i>0?", " : ""), arr[i]);
		printf("\n");

		heapSort(arr, n);

		printf("after:\t");
		for(int i = 0;i<n;i++) printf("%s%d", (i>0?", ":""), arr[i]);
		printf("\n");

		if(a) a = NULL;
		if(arr) free(arr);

	}
	else {
		cout << getTimestamp() << " { args:[";
		for(int i = 0;i<argc;i++) {
			cout << (i>0?",":"") << "\"" << argv[i] << "\"";
		}
		cout << "]}"<<endl;
	}

	return 0;
}


