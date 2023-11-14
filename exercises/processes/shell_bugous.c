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
    printf("My-Tiny-Shell> ");
    scanf("%s", command);
    if (strcmp(command, "exit") == 0) {
      printf("Exiting.\n");
      return 0;
    }
    // Fork a new process
    pid_t pid = fork();
    if (pid == -1) {
      printf("Error forking");
      exit(EXIT_FAILURE);
    }
    if (pid == 0) {
      // Child process
      execlp(command, command, NULL);
      printf("Error in exec");
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}
