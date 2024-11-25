/**
 * To show usage of execl and execlp and to show that the process PID does not
 * change with exec.
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pidget = getpid();
  printf("Original process has pid: %d\n", pidget);
  // Try to execute either execlp or execl to understand the differences between
  // the two
  /* execlp("ls", "ls", "-l", "--color=always", NULL); */
  execl("./args_printing.out", "args_printing.out", "do", "i", "wanna", "know", NULL);
  // What is the output of the following printf?
  printf("Original process has pid: %d\n", pidget);
  return 0;
}
