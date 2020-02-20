#include <stdio.h>
#include "example_dll.h"

int main(void)
{
        hello("World");
        printf("%d\n", toDouble(333));
        cppFunc();

        MyClass a;
        a.func();

        return 0;
}
