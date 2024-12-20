#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include "libmodule.h"

void* g_hModule = NULL;
LPFN_LIBMODULE_API g_pfnAPI = NULL;

/////////////////////////////////////////////////////////////////////////
// Function
bool LoadModule(void);
void UnLoadModule(void);

int main(int argc, char* argv[])
{
	int nExitCode = 1;

	// Load libmodule.so
	if (false == LoadModule())
	{
		fprintf(stderr, "Fail to load module\r\n");
		goto FINAL;
	}

	printf("Success to load module\r\n");
	
	// call
	(*g_pfnAPI)();

	// 여기까지 왔다면 성공
	nExitCode = 0;

FINAL:
	// Unload module
	UnLoadModule();
	return nExitCode;
}

bool LoadModule(void)
{
	bool bRtnValue		= false;
	char szPath[260]	= {0,};

	strcat(szPath, "./libmodule.so");
	g_hModule = dlopen(szPath, RTLD_LAZY);
	if (NULL == g_hModule)
	{
		fprintf(stderr, "Fail to load %s,[%s]\r\n", szPath, dlerror());
		goto FINAL;
	}

	g_pfnAPI = (LPFN_LIBMODULE_API)dlsym(g_hModule, "libmodule_api");
	if (NULL == g_pfnAPI)
	{
		fprintf(stderr, "Fail to dlsym,[%s]\r\n", dlerror());
		goto FINAL;
	}

	// 여기까지 왔다면 성공
	bRtnValue = true;

FINAL:
	return bRtnValue;
}

void UnLoadModule(void)
{
	if (NULL != g_hModule)
	{
		::dlclose(g_hModule);
		g_hModule = NULL;
	}

	g_hModule = NULL;
}