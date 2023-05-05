#include <cstdio>
#include <iostream>

struct DynArrayQueue {
    int front, rear;
    int capacity;
    int padd;
    int *array;
};

void resizeQueue(DynArrayQueue* queue);

struct DynArrayQueue *createDynQueue() {
   DynArrayQueue* q = new DynArrayQueue(); 
   if(!q) return NULL;
   q->capacity = 1;
   q->front = q->rear = 1;
   q->array = new int[(size_t)q->capacity];
   if(!q->array) return NULL;
   return q;
}

int isEmptyQueue(DynArrayQueue* q) {
    return q->front == -1;
}

int isFullQueue(DynArrayQueue* q) { 
    return (q->rear+1)%q->capacity == q->front;
}

int queueSize(DynArrayQueue* q) {
    return ((q->capacity-q->front+q->rear+1)%q->capacity);
}

void enqueue(DynArrayQueue* q, int data) {
    if(isFullQueue(q))
        resizeQueue(q);
    q->rear = (q->rear+1)%q->capacity;
    q->array[q->rear] = data;
    if(q->front == -1)
        q->front = q->rear;
}

void resizeQueue(DynArrayQueue* q) {
    int size = q->capacity;
    q->capacity = q->capacity * 2;
    q->array = (int*)realloc((void*)q->array, (size_t)q->capacity);
    if(!q->array) {
        printf("Memory Error, %s:%d\n", __FILE__, __LINE__);
        return;
    }

    if(q->front > q->rear) {
        for(int i = 0;i < q->front;i++) {
            q->array[i+size] = q->array[i];
        }
        q->rear = q->rear+size;
    }
}

int queueFront(DynArrayQueue* q) {
    if(isEmptyQueue(q)) return -1;
    return q->array[q->front];
}

void printQueue(FILE* fp, DynArrayQueue* q) {
    for (int i = q->front; i < (q->rear); i=((i+1)%q->capacity)) {
        fprintf(fp, "[%d]=%d\n", i, q->array[i]);
    }
}

int main() {

	using namespace std;
    cout << "###0###" << std::endl;
    DynArrayQueue* q = createDynQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    cout << "###1###" << std::endl;
    enqueue(q, 3);
    enqueue(q, 4);
    cout << "###2###" << std::endl;
    enqueue(q, 5);
    enqueue(q, 6);
    
    cout << "###3###" << std::endl;

    cout << "###4 ### : size(queue) : " << queueSize(q) << std::endl;;
    printQueue(stdout, q);

    return 0;
}
