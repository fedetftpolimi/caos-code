#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  float sum = 0;
  int n = 1;
  float x;
  do {
    printf("Insert number\n");
    scanf("%f", &x);
    sum += x;
    n += 1;
  }  while (x != 0);

  n--;

  if (n == 0) {
    printf("No number inserted, avg = 0 \n");
  } else {
    printf("Avg = %f\n", sum / n);
  }

  return 0;
}
