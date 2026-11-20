#include <pthread.h>

void *threadfunc(void *)
{
    for(long long i=0LL;i<10000000000LL;i++) ;
}

int main()
{
      pthread_t t1,t2,t3;
      pthread_create(&t1,NULL,&threadfunc,NULL);
      pthread_create(&t2,NULL,&threadfunc,NULL);
      pthread_create(&t3,NULL,&threadfunc,NULL);
      
      for(long long i=0LL;i<10000000000LL;i++) ;
      
      pthread_join(t1,NULL);
      pthread_join(t2,NULL);
      pthread_join(t3,NULL);
}
