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
  // This call require the binary file args_printing.out to be present in the
  // process working directory
  execl("./args_printing.out", "args_printing.out", "do", "i", "wanna", "know", NULL);
  // What is the output of the following printf?
  printf("Original process has pid: %d\n", pidget);
  return 0;
}
