#include <stdio.h>
#include <pthread.h>

void *thread1(void *arg)
{
    int *param=(int*)arg;
    printf("Into thread1, parameter is %d (%p)\n",*param,param);
    return NULL;
}

int main()
{
    pthread_t thr;
    int parameter=10;
    printf("Parameter is %d (%p)\n",parameter,&parameter);
    pthread_create(&thr,NULL,thread1,(void*)&parameter);
    pthread_join(thr,NULL);
    return 0;
}
