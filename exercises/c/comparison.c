#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("START\n");
  int A, B;
  printf("Insert first number\n");
  scanf("%d", &A);
  printf("Insert second number\n");
  scanf("%d", &B);
  printf("A = %d, B = %d\n", A, B);
  if (A == B) {
    printf("A = B\n");
  }
  else if (A > B) {
    printf("A greater than B\n");
  }
  else {
    printf("A less than B\n");
  }
  printf("END\n");
  return 0;
}
