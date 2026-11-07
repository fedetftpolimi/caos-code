#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b;
  printf("Insert first number\n");
  scanf("%d", &a);
  printf("Insert second number\n");
  scanf("%d", &b);
  printf("a = %d, b = %d\n", a, b);
  if (a == b) {
    printf("a = b\n");
  }
  else if (a > b) {
    printf("a greater than b\n");
  }
  else {
    printf("a less than b\n");
  }
  return 0;
}
