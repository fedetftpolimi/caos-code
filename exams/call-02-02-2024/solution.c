//gcc -Wall -fsanitize=address -o solution solution.c

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

void compute();

void performComputation()
{
    printf("PerformComputation -- begin\n");
    sleep(5);
    printf("PerformComputation -- end\n");
}

void startApplication()
{
    char c;
    for(;;)
    {
        c=getchar();
        if(c=='\n') continue;
        if(c=='q') break;
        printf("compute -- begin\n");
        compute();
        printf("compute -- end\n");
    }
}

///////////////

sem_t semaphore;

void compute()
{
    sem_post(&semaphore);
}

void *thread(void*)
{
    while(1)
    {
        sem_wait(&semaphore);
        performComputation();
    }
}

int main()
{
    sem_init(&semaphore,0,0); //IMPORTANT: initial value is 0 so first sem_wait blocks
    pthread_t t;
    pthread_create(&t,NULL,thread,NULL);
    startApplication();
}


