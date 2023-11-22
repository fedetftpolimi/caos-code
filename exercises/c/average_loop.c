#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  float sum = 0;
  int n = 0;
  float x;
  printf("Insert number\n");
  scanf("%f", &x);

  while (x != 0) {
    sum += x;
    n += 1;
    printf("Insert number");
    scanf("%f", &x);
  }

  if (n == 0) {
    printf("No number inserted, avg = 0 \n");
  } else {
    printf("Avg = %f\n", sum / n);
  }

  return 0;
}
