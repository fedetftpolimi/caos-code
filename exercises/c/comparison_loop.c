#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int A, B;

  do {
    printf("Insert first number greater than or equal to 0\n");
    scanf("%d", &A);
    printf("Insert second number greater than or equal to 0\n");
    scanf("%d", &B);
    if (A > B) {
      printf("A greater than B\n");
    } else if (A<B) {
      printf("A smaller than B\n");
    } else {
      printf("A equal to B, exit\n");
    }
  } while (A != B);
  return 0;
}
