#include <stdio.h>
#include <unistd.h>

#define NPROCS 3

int main() {
  pid_t pids[NPROCS];
  for (int i = 0; i < NPROCS; i++) {
    printf("%d (Parent %d), i=%d", getpid(), getppid(), i);
    pids[i] = fork();
  }
}
