#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore; //Semaphore protecting the shared data
char person[]="John Doe";
int balance=1000;

void *thread1(void *arg)
{
    sem_wait(&semaphore); //Begin critical section
    int newbalance=balance+100;
    printf("Depositing 100€: before %d and after %d\n", balance, newbalance);
    balance=newbalance;
    sem_post(&semaphore); //End critical section
    return NULL;
}

int main()
{
    sem_init(&semaphore,0,1);
    pthread_t thr;
    pthread_create(&thr,NULL,thread1,NULL);
    sem_wait(&semaphore); //Begin critical section
    int newbalance=balance-100;
    printf("Withdrawing 100€: before %d and after %d\n", balance, newbalance);
    balance=newbalance;
    sem_post(&semaphore); //End critical section
    pthread_join(thr,NULL);
    sem_destroy(&semaphore);
    printf("Final balance %d€\n",balance);
    return 0;
}
