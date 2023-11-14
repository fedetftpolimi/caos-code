#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
char person[]="John Doe";
int balance=1000;

void *thread1(void *arg)
{
    pthread_mutex_lock(&mutex); //Begin critical section
    int newbalance=balance+100;
    printf("Depositing 100€: before %d and after %d\n", balance, newbalance);
    balance=newbalance;
    pthread_mutex_unlock(&mutex); //End critical section
    return NULL;
}

int main()
{
    pthread_t thr;
    pthread_create(&thr,NULL,thread1,NULL);
    pthread_mutex_lock(&mutex); //Begin critical section
    int newbalance=balance-100;
    printf("Withdrawing 100€: before %d and after %d\n", balance, newbalance);
    balance=newbalance;
    pthread_mutex_unlock(&mutex); //End critical section
    pthread_join(thr,NULL);
    printf("Final balance %d€\n",balance);
    return 0;
}
