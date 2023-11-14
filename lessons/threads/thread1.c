
#include <stdio.h>
#include <pthread.h>

void *thread1(void *arg)
{
    printf("Into thread1\n");
    return NULL;
}

int main()
{
    pthread_t thr;
    pthread_create(&thr,NULL,thread1,NULL);
    printf("Into main\n");
    pthread_join(thr,NULL);
    return 0;
}
