#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int shared = 0, glob = 10;

void *f1(void *arg) {
  int a = 3;
  pthread_mutex_lock(&mutex);
  printf("Mutex acquired in 1\n");
  shared++;
  glob = 11;
  pthread_cond_signal(&cond);
  printf("Cond signaled\n");
  sleep(2);
  pthread_mutex_unlock(&mutex);
  printf("Mutex released in 1\n");
  glob = 12;
  a = 4;
  shared--;
  return NULL;
}

void *f2(void *arg) {
  int b = 20;
  pthread_mutex_lock(&mutex);
  printf("Mutex acquired in 2\n");
  while (shared == 0){
    printf("About to wait\n");
    pthread_cond_wait(&cond, &mutex);
  }
  printf("After wait\n");
  b = 30;
  glob = 13;
  pthread_mutex_unlock(&mutex);
  printf("Mutex released in 1\n");
  return NULL;
}

int main() {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, f1, NULL);
  pthread_create(&t2, NULL, f2, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}
