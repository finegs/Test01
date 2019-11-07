#include <iostream>
#include <string>
#include <windows.h>


using namespace std;


int main(int argc, char* argv[])
{

	if (argc > 0 )
	{
		for(int i = 0;i<argc;i++) 
			cout << "argv[" << i << "] = " << argv[i] << ((i < argc-1) ? " ," : "");
	}

	cout << endl;
	int a;
	if(argc > 1) {
		a = atoi(argv[1]);
	} else {
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
	for(int i = 31;i>=0;i--)
//		cout << (a&(0x01<<(32-i))) << "";
//		cout << ((a<<i)&(0x01<<i)) << "";
		cout << ((a & (1<<i)) ? "1" : "0") << (i > 3 &&(i%8==0) ? " " : "");
	cout << endl;
	cout << "~a : " << (~a) << endl;
    cout << "Hello World" << endl;

	string  aa("aabbcc");
	
	cout << aa << endl;


	if(WM_LBUTTONDOWN)
		printf("%d:%d\n", LOWORD(LPARAM), HIWORD(LPARAM));

	return 0;
}
