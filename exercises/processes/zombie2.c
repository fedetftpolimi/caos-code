#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  while (1) {
    printf("Press Enter to execute ls");
    while (getchar() != '\n')
      ;
    if (!fork()) {
      execl("/bin/ls", "ls", NULL);
      sleep(1);
    }
  }
  return 0;
}
