#if __unix__

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
//#elif defined (_WIN32) || (WIN32)
#include <cstdio>

using namespace std;

int main()
{
	//ftok to gernate unique key 
	key_t key = ftok("shmfile", 65);

	// shmget returns an identifier in shmid
	int shmid = shmget(key, 1024, 0666|IPC_CREATE);

	// shmatto to attach to shared memory
	char* str = (char*)shmat(shmid, (void*)0, 0);

	cout << "Write data : ";
	gets(str);

	cout << "Data written in memory:%s\n", str);

	//detach from shared memory
	shmdt(str);
	
	return EXIT_SUCCESS;
}

#endif

//#if defined(__SM__) && defined(__unix__)
// ============================================================================
//     Author: K Perkins
//     Date:   Oct 3, 2013
//     Taken From: http://programmingnotes.org/
//     File:  Condvar.cpp
//     Description: Demonstrate the use of the producer consumer problem
//       using mutext and condition variables
// ============================================================================
#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;
 
// Compile & Run
// g++ Condvar.cpp -lpthread -o Condvar
// ./Condvar
 
// function prototypes
void* Produce(void* arg);
void* Consume(void* arg);
 
// global variables
// the mutex and the condition variable
pthread_mutex_t mutex;
pthread_cond_t cond;
 
// the condition flag
bool condition = false;
 
// the item produced
int count = 0;
 
// how much to produce
const int NUM_TO_PRODUCE = 6;
 
int main()
{
    // declare variables
    pthread_t producerThread;
    pthread_t consumerThread;
 
    // initialize the mutex and the condition variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    
    cerr<<"The Parent is creating the producer and consumer threads..\n\n";
 
    // create a producer thread
    if(pthread_create(&producerThread, NULL, Produce, NULL) < 0)
    {
        cerr<<"pthread_create";
        exit(1);
    }
 
    // create a consumer thread
    if(pthread_create(&consumerThread, NULL, Consume, NULL) < 0)
    {
        cerr<<"pthread_create";
        exit(1);
    }
 
    // wait for the threads to complete 
    // similar to the wait() system call for fork() processes
    if(pthread_join(producerThread, NULL) < 0)
    {
        cerr<<"pthread_join";
        exit(1);
    }
 
    if(pthread_join(consumerThread, NULL) < 0)
    {
        cerr<<"pthread_join";
        exit(1);
    }
    
    cerr<<"\nBoth threads have completed and have terminated!\n"
        <<"\nThe Parent is now exiting...\n";    
 
    return 0;
}// end of main
 
/**
 * The producer thread function
 * @param arg - pointer to the thread local data - unused
 */
void* Produce(void* arg)
{
    // produce things until the loop condition is met
    while(count < NUM_TO_PRODUCE)
    {
        // lock the mutex to protect the condition variable
        if(pthread_mutex_lock(&mutex) < 0)
        {
            cerr<<"pthread_mutex_lock";
            exit(1);
        }
        
        // we have produced something that has not been
        // consumed yet, so we sleep (wait) until the consumer 
        // wakes us up.
        while(condition)
        {
            // sleep (wait) on a condition variable until the
            // the consumer wakes the producer up.
            if(pthread_cond_wait(&cond, &mutex) < 0)
            {
                cerr<<"pthread_cond_wait";
                exit(1);
            }
        }
 
        // produce an item
        cerr<<"Produced: "<<++count<<endl;
        
        // we have produced something
        condition = true;
        
        // wake up the sleeping consumer
        if(pthread_cond_signal(&cond) < 0)
        {
            cerr<<"pthread_cond_signal";
            exit(1);
        }
        
        // release the mutex lock
        if(pthread_mutex_unlock(&mutex) < 0)
        {
            cerr<<"pthread_mutex_unlock";
            exit(1);
        }
    }
    return 0;
}// end of Produce
 
/**
 * The consumer function
 * @param arg - pointer to the thread local data - unused
 */
void* Consume(void* arg)
{
    // consume things until the loop condition is met
    while(count < NUM_TO_PRODUCE)
    {	
        // lock the mutex to protect the condition variable
        if(pthread_mutex_lock(&mutex) < 0)
        {
            cerr<<"pthread_mutex_lock";
            exit(1);
        }
        
        // if there is nothing to consume, then sleep
        while(!condition)
        {			
            // sleep (wait) on a condition variable until the
            // producer wakes the consumer up.
            if(pthread_cond_wait(&cond, &mutex) < 0)
            {
                cerr<<"pthread_cond_wait";
                exit(1);
            }
        }
 
        cerr<<"Consumed: "<<count<<endl<<endl;
        
        // consume the item
        condition = false;
            
        // wake up the sleeping producer
        if(pthread_cond_signal(&cond) < 0)
        {
            cerr<<"pthread_cond_signal";
            exit(1);
        }
        
        // unlock the mutex
        if(pthread_mutex_unlock(&mutex) < 0)
        {
            cerr<<"pthread_mutex_unlock";
            exit(1);
        }
    }
    return 0;
}// http://programmingnotes.org/

//#endif
