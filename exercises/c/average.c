#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("START\n");
  float A, B, Y;
  printf("Insert A\n");
  scanf("%f", &A);
  printf("Insert B\n");
  scanf("%f", &B);

  Y = (A + B) / 2;

  printf("Average = %f\n", Y);
  printf("END\n");

  return 0;
}
