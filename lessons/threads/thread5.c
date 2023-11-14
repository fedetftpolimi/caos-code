//Program is wrong and used to show what a race condition is
//For a correct version, see semaphore1.c

#include <stdio.h>
#include <pthread.h>

char person[]="John Doe";
int balance=1000;

void *thread1(void *arg)
{
    int newbalance=balance+100;
    printf("Depositing 100€: before %d and after %d\n", balance, newbalance);
    balance=newbalance;
    return NULL;
}

int main()
{
    pthread_t thr;
    pthread_create(&thr,NULL,thread1,NULL);
    int newbalance=balance-100;
    printf("Withdrawing 100€: before %d and after %d\n", balance, newbalance);
    balance=newbalance;
    pthread_join(thr,NULL);
    printf("Final balance %d€\n",balance);
    return 0;
}
