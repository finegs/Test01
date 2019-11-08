#include <windows.h>
#include <winuser.h>
#include <iostream>
#include <conio.h>
using namespace;

int main()
{

int x,y,w,z,c;
c=0;

while(c!=10)
{
mouse_event(MOUSEEVENTF_MOVE, x, y,w,z);
POINT pt;
GetCursorPos(&pt);
x=pt.x;
y=pt.y;
cout << x << "," << y << endl;
Sleep(1000);
x=0;
y=0;
c=c+1;
}
system("pause");
return 0;
}
