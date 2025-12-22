#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("Press Enter to execute ls");
  while (getchar() != '\n')
    ;
  pid_t pid = fork();
  /* if (pid < 0) { */
  /*   // If fork fails */
  /*   perror("Fork failed"); */
  /*   exit(1); */
  /* } else  */

  if (pid == 0) {
    // What's the difference b/w execl and execlp?
    // Check the manual pages using man 3 exec
    execlp("ls","ls",NULL);
    /* execl("/bin/ls", "ls", NULL); */
  } else {
    // This is the parent process
    printf("Fork successful! Waiting for child to complete...\n");
    wait(NULL); // Wait for child process to complete
    printf("[Parent] One of my child processes finished.\n");
  }
  return 0;
}
