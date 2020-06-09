#include <cstdio>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h> // defines putenv in POSIX
int main() {

    std::time_t t = std::time(nullptr);
    std::cout << "UTC:       " << std::put_time(std::gmtime(&t), "%c %Z") << '\n';
    std::cout << "local:     " << std::put_time(std::localtime(&t), "%c %Z") << '\n';
    // POSIX-specific:
    std::string tz = "TZ=Asia/Seoul";
    putenv(tz.data());
    std::cout << "Seoul: " << std::put_time(std::localtime(&t), "%c %Z") << '\n';

#if 0
	int nInput = 0;
	int n2;
	// int i = 0;

	printf("Enter Number:"); fflush(stdout);
	scanf("%d", &nInput);fflush(stdin);

	printf("2-Comp(%d) : %d\n", nInput, n2=(~nInput)+1);
	printf("OV(%d) : %d\n", nInput, (~n2)+1);
	printf("-OV(%d) : %d\n", nInput, ((1<<31) | nInput)+1);
	printf("~OV(%d) : %d\n", nInput, ~nInput);
	printf("1<<31(%d) : %d\n", 1, 1<<31);
	int n3=nInput;
	for(int i = 0;i<31;i++) {
		n3 <<=1; n3|=1;
	}
	printf("OV(%d)<<1 |1 = %d\n", nInput, n3);
#endif

#if 0
	if(nInput<1) nInput = 1;
	else if(nInput>9) nInput = 9;

	while(i<nInput) {
		putchar('*');
		i++;
	}

	putchar('\n');
#endif
	return 0;
}
