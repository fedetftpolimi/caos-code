
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char command[100];

  while (1) {
    // Prompt for a command
    printf("My-Tiny-Shell> ");
    scanf("%s", command);

    // Exit the loop if the command is "exit"
    if (strcmp(command, "exit") == 0) {
      printf("Exiting mini-shell.\n");
      break;
    }

    // Fork a new process
    pid_t child_pid = fork();

    if (child_pid == -1) {
      printf("Error forking");
      exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
      // Child process
      execlp(command, command, NULL);
      printf("Error in exec");
      exit(EXIT_FAILURE);
    } else {
      // Parent process
      int status;
      waitpid(child_pid, &status, 0);

      if (WIFEXITED(status)) {
        printf("Child process exited with status %d.\n", WEXITSTATUS(status));
      } else {
        printf("Child process did not exit normally.\n");
      }
    }
  }

  return 0;
}
