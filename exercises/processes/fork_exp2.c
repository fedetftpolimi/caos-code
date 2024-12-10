#include <stdio.h>
#include <unistd.h>

int a = 3;

int main() {
  a++;
  fork();
  a *= 2;
  fork();
  a *= 2;
}
