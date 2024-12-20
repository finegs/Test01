#if 1

#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char* argv[])
{
	using namespace std::chrono_literals;

	std::setvbuf(stdout, NULL, 0, 0);
	std::putchar('a');
	std::this_thread::sleep_for(1s);
	std::putchar('b');
	std::getchar();

	return 0;
}

#endif


#if 0
#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

char array1[] = "Foo" "bar";

char array2[] = {'F', 'o', 'o', 'b', 'a', 'r', '\0'};

const char* s1 = "foo(\
				Hello\
				World\
				) foo";


const char* s2 = "\nHello\nWorld\n";

int main(int argc, char* argv[])
{

#if 0
	cout << s1 << endl;
	cout << s2 << endl;
	cout << array1 << endl;
	cout << array2 << endl;
#endif

	if (argc > 0 )
	{
		cout << "################################" << endl;
		for(int i = 0;i<argc;i++) 
			cout << "\targv[" << i << "] = " << argv[i] << ((i < argc-1) ? "\n" : "");
		cout << endl;
		cout << "################################" << endl;
	}

	cout << endl;

	int a;

	if(argc > 1) {
		a = atoi(argv[1]);
	} 
	else {
		cout << "Enter a : "; std::cout.flush();
		cin >> a;
		cin.clear();
	}
	cout << "a is : " << a << endl;
	cout << "a & 0xFF : " << (a & 0xFF) << endl;
	cout << "a | 0xFF : " << (a | 0xFF) << endl;
	cout << "a ^ 0xFF : " << (a ^ 0xFF) << endl;
	cout << "a ^ 0x00 : " << (a ^ 0x00) << endl;
	cout << "a << 1 : " << (a << 1) << endl;
	cout << "a >> 1 : " << (a >> 1) << endl;
	cout << "a ^ a : " << (a ^ a ) << endl;
	for(int i = 31;i>=0;i--) {
		cout << ((a & (1<<i)) ? "1" : "0") << ((i%8==0) ? " " : "");
	}
	cout << endl;
	cout << "~a : " << (~a) << endl;

	string  aa("aabbcc");

	cout << aa << endl;

//	if(WM_LBUTTONDOWN)
//		printf("%d:%d\n", LOWORD(LPARAM), HIWORD(LPARAM));
	

	return EXIT_SUCCESS;
}

#endif
