#include <stdio.h>
#include <stdlib.h>
#include <cpuid.h>

int testing_cpu()
{
	unsigned int eax = 0;
	unsigned int ebx = 0;
	unsigned int ecx = 0;
	unsigned int edx = 0;
	unsigned int max_level = 0;
	unsigned int ext_level = 0;
	unsigned int vendor = 0;
	unsigned int model = 0;
	unsigned int family = 0;

	unsigned int has_sse3 = 0;

	max_level = __get_cpuid_max(0, &vendor);
	if(max_level < 1)
		return 0;
	__cpuid(1, eax, ebx, ecx, edx);
	model = (eax >> 4) & 0x0F;
	family = (eax >> 8) & 0x0F;

	return 1;
}

int main(int argc, char* argv[])
{

	printf("testing_cpu()=%s\n", testing_cpu());

	return 0;
}
	

