#include "comm.h"

#define MAX_THREAD 1024
pthread_t pid[MAX_THREAD];

void * fun (void *arg)
{
    printf("I am thread%ld\n", Pthread_self());
    sleep(5);
    return NULL;
}

int main()
{
    
    for (int i = 0; i < 5; i++)
    {
        Pthread_create(&pid[i], NULL, fun, NULL);
    }

    for (int i = 0; i < 5; i++)
    {
        Pthread_join(pid[i], NULL);
    
    }
    return 0;
}