#include <stdio.h>
#include <unistd.h>

#define NPROCS 3

int main() {
  pid_t pids[NPROCS];
  for (int i = 0; i < NPROCS; i++) {
    printf("A: %d (Parent %d), i=%d\n", getpid() % 50 + 2, getppid() % 50 + 2, i);
    pids[i] = fork();
    printf("B: %d (Parent %d), i=%d\n", getpid() % 50 + 2, getppid() % 50 + 2, i);
  }
}
