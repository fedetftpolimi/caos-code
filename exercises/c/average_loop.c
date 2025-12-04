#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  float acc = 0;
  int n = 1;
  float x;
  do {
    printf("Insert number\n");
    scanf("%f", &x);
    acc += x;
    n += 1;
  } while (x != 0);

  if (n == 1) {
    printf("No number inserted, avg = 0 \n");
  } else {
    n--;
    printf("Avg = %f\n", acc / n);
  }

  return 0;
}
