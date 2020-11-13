#if 0

#include <stdio.h>

int heap_push(int* arr, int* arr_len, int data);
int heap_pop(int* arr, int* arr_len, int* data);

int main(int argc, char* argv[]) {

    return 0;
}

int heap_push(int* arr, int* arr_len, int data) {
    arr[((*arr_len)++] = data;
    int i = *arr_len-1;
    while(i>0) {
        if(arr[i/2]>arr[i]) { int t = arr[i/2]; arr[i/2] = arr[i]; arr[i]=t;}
        i=i/2;
    }
    return 0;
}

int heap_pop(int* arr, int* arr_len, int* data) {
    if(*arr_len<1) return 1;

    *data = arr[0];
    arr[0]=arr[*arr_len-1];
    (*arr_len)--;



    int i = 0;
        int mc;
    while(i<*arr_len) {
        if(arr[i*2]<arr[i*2+1]) { mc = i*2; } else { mc = i*2+1;}
        if(arr[i]>arr[mc]) { int t = arr[i];arr[i]=arr[mc]; arr[mc]=t; }
        i=mc;
    }    

     return 0;
}

#endif
#if 1

#include <stdio.h>
#define SWAP(x,y) { int t = (x); (x) = (y); (y) = (t);}

int heap[5000010];
int N;


void push(int p) {
    if(p<=1||heap[p/2] > heap[p]) return;
    SWAP(heap[p/2], heap[p]);
    push(p/2);
}

void pop(int p, int n) {
    int np = p*2;
    if(np<n && heap[np]<heap[np+1]) np++;
    if(np>n||heap[p]>=heap[np]) return;
    SWAP(heap[p], heap[np]);
    pop(np, n);
}

void output() {
    for(int i = 0;i<= N;i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

}

int main() {
    int i;
    scanf("%d", &N);
    for (size_t i = 1; i <= N; i++)
    {
        scanf("%d", &heap[i]);
        push(i);
    }

    output();
    for (size_t i = N; i >1; i--)
    {
        SWAP(heap[1], heap[i]);
        pop(1, i-1);
    }
    output();
    return 0;
    
}
#endif


