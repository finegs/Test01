#include <iostream>
#include "testVir.h"
#include "testLib.h"

using namespace std;
void TestLib::init()
{
cout<<"TestLib::init: Hello World!! "<<endl ;
}

static TestLib *cr();
//Define functions with C symbols (create/destroy TestLib instance).
extern "C" TestLib* create()
{
return cr();
}

static TestLib *cr()
{
TestLib *test;
test = new TestLib;
return test;
}

extern "C" void destroy(TestLib* Tl)
{
delete Tl ;
}
