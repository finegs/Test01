#include "libmodule.h"
#include "a.h"

#ifdef __cplusplus
extern "C"
{
#endif

void libmodule_api(void)
{
    lib_a();
    printf("[libmodule.cpp] say good-bye!\r\n");
}

#ifdef __cplusplus
}
#endif