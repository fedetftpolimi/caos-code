#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void *thread1(void *arg)
{
    for(;;)
    {
        printf("Waiting\n");
        sem_wait(&semaphore);
        printf("Awakened!\n");
    }
}

int main()
{
    sem_init(&semaphore,0,0);
    pthread_t thr;
    pthread_create(&thr,NULL,thread1,NULL);
    for(;;)
    {
        getchar();
        sem_post(&semaphore);
    }
    //Code to terminate threads omitted for simplicity
    //Type Ctrl-C to kill the program when trying it
}
