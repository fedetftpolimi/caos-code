#include <stdio.h>
#include <unistd.h>

int a = 3;

void show(int depth) {
  for (int i = 0; i < depth; i++)
    printf("  "); // indentation (2 spaces per level)

  printf("PID=%d, PPID=%d, a=%d\n", getpid(), getppid(), a);
}

int main() {
  int depth = 0;

  a++;         // a = 4
  show(depth); // before first fork

  if (fork() == 0) {
    depth++; // child goes one level deeper
  }
  a *= 2; // a = 8
  show(depth);

  if (fork() == 0) {
    depth++; // child goes one level deeper again
  }
  a *= 2; // a = 16 or 32 depending on path
  show(depth);

  return 0;
}
