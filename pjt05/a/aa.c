#if 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <list.h>

int arr[1000001];;
int rarr[1000];
void dfs(int depth, int arr[], int rarr[], int idx) {
    if(idx >= depth) {
        char str[4096];
        memset(str, 0, 4096);
        for (size_t i = 1; i <= depth; i++)
        {
            strcat_s(str, strlen(str)+1, (i>0?",":" "));
            sprintf(str, "%s%d", str, rarr[idx]);
        }
        printf("%s\n", str);
                   
        return;
    }

    for (size_t i = 1; i <= 6; i++)
    {
        if(arr[i]) continue;
        arr[i] = 1;

        rarr[idx] = i;

        dfs(depth, arr, rarr, idx+1);

        arr[i] = 0;
    }
    
}


int main(int argc, char* argv[]) {

    printf("========== %s    =========='\n'", argv[0]);
    printf("========== %s:%d =========='\n'", __FILE__, __LINE__);
    
    dfs(2, arr, rarr, 0);



    getchar();

    return 0;
}


#endif