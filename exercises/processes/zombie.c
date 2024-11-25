#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  while (1) {
    printf("Press Enter to execute ls");
    while (getchar() != '\n')
      ;
    if (!fork()) {
      /* printf("child\n"); */
      /* execlp("ls", "ls", NULL); */
      sleep(2);
      exit(7);
    } /* else { */
    /*   printf("father\n"); */
    /* } */
  }
  return 0;
}
