#include <iostream>

using namespace std;

char array1[] = "Foo" "bar";

char array2[] = {'F', 'o', 'o', 'b', 'a', 'r', '\0'};

const char* s1 = "foo(\
				Hello\
				Worl\
				) foo";


const char* s2 = "\nHello\nWorld\n";

int main(int argc, char* argv[])
{
	cout << s1 << endl;
	cout << s2 << endl;
	cout << array1 << endl;
	cout << array2 << endl;
    cout << "Hello World" << endl;
    return 0;
}
