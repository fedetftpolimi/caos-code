
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1(void *arg)
{
    int *parameter=(int*)arg;
    printf("Into thread1, parameter is %d\n",*parameter);
    free(parameter);
    int *result=malloc(sizeof(int));
    *result=0;
    return (void*)result;
}

int main()
{
    pthread_t thr;
    int *parameter=malloc(sizeof(int));
    *parameter=10;
    pthread_create(&thr,NULL,thread1,(void*)parameter);
    int *result;
    pthread_join(thr,(void**)&result);
    printf("The returned value is %d\n",*result);
    free(result);
    return 0;
}
