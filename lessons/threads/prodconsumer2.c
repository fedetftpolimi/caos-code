#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
#define numElements 3
int buffer[numElements];
int putPos=0;
int getPos=0;
int size=0;

int put(int element)
{
    if(size>=numElements) return 1; //Error buffer full
    buffer[putPos]=element;
    putPos++; size++;
    if(putPos>=numElements) putPos=0;
    return 0; //Success
}

int get(int *element)
{
    if(size==0) return 1; //Error buffer empty
    *element=buffer[getPos];
    getPos++; size--;
    if(getPos>=numElements) getPos=0;
    return 0; //Success
}

void *consumer(void *) //The consumer
{
    for(;;)
    {
        int receivedData;
        pthread_mutex_lock(&mutex);   //Begin critical section
        while(get(&receivedData)!=0)
            pthread_cond_wait(&cond,&mutex); //Buffer full
        pthread_cond_signal(&cond);   //Wake producer
        pthread_mutex_unlock(&mutex); //End critical section
        printf("Consumer: received %d\n",receivedData);
        sleep(5); //Sleep 5 seconds, to simulate heavy computation
        printf("Consumer: sleep completed\n");
    }
}

int main() //The producer
{
    pthread_t thr;
    pthread_create(&thr,NULL,&consumer,NULL);
    for(;;)
    {
        int sendData;
        printf("Producer: insert a number\n");
        scanf("%d",&sendData);
        pthread_mutex_lock(&mutex);   //Begin critical section
        while(put(sendData)!=0)
            pthread_cond_wait(&cond,&mutex); //Buffer empty
        pthread_cond_signal(&cond);   //Wake consumer
        pthread_mutex_unlock(&mutex); //End critical section
        
    }
    //Code to terminate threads omitted for simplicity
    //Type Ctrl-C to kill the program when trying it
}
