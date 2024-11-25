#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid;
  for (int i = 0; i < 5; i++) {
    pid = fork();
    if (pid > 0) {
      // Parent, do nothing
    } else {
      // Child, just exit
      exit(0);
    }
  }
  // only executed by parent, the children already exited
  sleep(50);

  return 0;
}
