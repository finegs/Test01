#include<iostream>
#ifndef _WIN32
	#include<dlfcn.h>
#else
	#include <dlfcn_win32.h>
#endif
#include "testVir.h"

using namespace std;

int main()
{
	void *handle;
	handle = dlopen("./testLib.so", RTLD_NOW);
	if (!handle)
	{
	cout<< dlerror();
	}

	typedef TestVir* create_t();
	typedef void destroy_t(TestVir*);

	create_t* creat=(create_t*)dlsym(handle,"create");
	destroy_t* destroy=(destroy_t*)dlsym(handle,"destroy");
	if (!creat)
	{
		cout<<"The error is %s"<<dlerror();
	}
	if (!destroy)
	{
		cout<<"The error is %s"<<dlerror();
	}

	TestVir* tst = creat();
	tst->init();
	destroy(tst);

	return 0 ;
}
