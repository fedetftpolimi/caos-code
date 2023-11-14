#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
char sharedData;
int valid=0;

void *consumer(void *) //The consumer
{
    for(;;)
    {
        char receivedData;
        pthread_mutex_lock(&mutex);          //Begin critical section
        while(valid==0)
            pthread_cond_wait(&cond,&mutex); //Wait for producer
        receivedData=sharedData;
        valid=0;
        pthread_cond_signal(&cond);          //Wake producer if blocked
        pthread_mutex_unlock(&mutex);        //End critical section
        printf("Consumer: received '%c'\n",receivedData);
    }
}

int main() //The producer
{
    pthread_t thr;
    pthread_create(&thr,NULL,&consumer,NULL);
    for(;;)
    {
        char sendData;
        do { sendData=getchar(); } while(sendData=='\n');
        pthread_mutex_lock(&mutex);          //Begin critical section
        while(valid==1)
            pthread_cond_wait(&cond,&mutex); //Wait for consumer
        sharedData=sendData;
        valid=1;
        pthread_cond_signal(&cond);          //Wake consumer if blocked
        pthread_mutex_unlock(&mutex);        //End critical section
        
    }
    //Code to terminate threads omitted for simplicity
    //Type Ctrl-C to kill the program when trying it
}
