#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

int main() {
  char command[MAX_COMMAND_LENGTH];

  while (1) {
    // Prompt for a command
    printf("Mini-Shell> ");
    scanf("%s", command);

    // Exit the loop if the command is "exit"
    if (strcmp(command, "exit") == 0) {
      printf("Exiting mini-shell.\n");
      break;
    }

    // Fork a new process
    pid_t child_pid = fork();

    if (child_pid == -1) {
      perror("Error forking");
      exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
      // Child process
      execlp(command, command, NULL);
      perror("Error in exec");
      exit(EXIT_FAILURE);
    } else {
      // Parent process (no wait)
      // No wait for the child process
      // Bug: This may result in the parent printing the prompt before the child has finished
    }
  }

  return 0;
}
