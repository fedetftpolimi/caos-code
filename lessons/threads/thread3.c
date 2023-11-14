
#include <stdio.h>
#include <pthread.h>

int parameter;
int result;

void *thread1(void *arg)
{
    printf("Into thread1, parameter is %d\n",parameter);
    result=0;
    return NULL;
}

int main()
{
    pthread_t thr;
    parameter=10;
    pthread_create(&thr,NULL,thread1,NULL);
    printf("Into main\n");
    pthread_join(thr,NULL);
    printf("The returned value is %d\n",result);
    return 0;
}
