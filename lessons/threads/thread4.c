
#include <stdio.h>
#include <pthread.h>

void *function(void *arg)
{
    const char *string=(const char*)arg;
    printf("Function called: %s\n",string);
    return NULL;
}

int main()
{
    pthread_t thr;
    pthread_create(&thr,NULL,function,(void*)"I'm a thread");
    function((void*)"I'm not a thread");
    pthread_join(thr,NULL);
    return 0;
}
