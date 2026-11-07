#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int a, b;

  do {
    printf("Insert first number greater than or equal to 0\n");
    scanf("%d", &a);
    printf("Insert second number greater than or equal to 0\n");
    scanf("%d", &b);
    if (a > b) {
      printf("a greater than b\n");
    } else if (a<b) {
      printf("a smaller than b\n");
    } else {
      printf("a equal to b, exit\n");
    }
  } while (a != b);
  return 0;
}
