#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned n;
  printf("Insert a number greater than or equal to 0\n");
  scanf("%u", &n);
  if (n <= 0) {
    printf("Wrong number\n");
  }

  unsigned accum = 0;
  while ( n > 0) {
    // acc += ... --> acc = acc + ...
    accum = accum + n + n - 1;
    n--;
  }
  printf("Il quadrato del numero %d è %d\n", n, accum);
  return 0;
}
