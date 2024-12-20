#if 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <list.h>

int arr[1000001];
int rarr[1000];
char str[4096];
void dfs(int depth, int case_size, int arr[], int rarr[], int idx, int* cnt) {
    if(idx > depth) {
#if __MYDEBUG
        memset(str, 0, 4096);
        for (size_t i = 1; i < idx; i++)
        {
            strcat_s(str+strlen(str), 2, (i>1?",":" "));
            sprintf(str, "%s%d", str, rarr[i]);
        }
        printf("%03d : %s\n", *cnt, str);
#endif
        (*cnt)++;
        return;
    }

    for (size_t i = 1; i <= case_size; i++)
    {
        if(arr[i]) continue;
        arr[i] = 1;

        rarr[idx] = i;

        dfs(depth, case_size, arr, rarr, idx+1, cnt);

        arr[i] = 0;
    }
    
}

int case_size,case_cnt,cnt;

void init(int argc, char* argv[]) {
    for (size_t i = 1; i < argc; i++)
    {
        if('-'==argv[i][0] && strlen(argv[i])>2) {
            switch(argv[i][1]) {
                case 'S':
                case 's':
                {
                    case_size = atoi(argv[i]+2);
                }
                break;
                case 't':
                case 'T':
                {
                    case_cnt = atoi(argv[i]+2);
                }
                break;
            }
        }
    }
}


int main(int argc, char* argv[]) {

    printf("========== %s    =========='\n'", argv[0]);
    printf("========== %s:%d =========='\n'", __FILE__, __LINE__);

    if(case_cnt < 1) case_cnt = 3;
    if(case_size < 1) case_size = 6;
    cnt = 0; 
    
    dfs(case_cnt, case_size, arr, rarr, 1, &cnt);

    printf("### Cnt = %d\n", cnt);

    getchar();

    return 0;
}


#endif