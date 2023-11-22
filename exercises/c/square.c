#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned n;
  printf("Insert a number greater than or equal to 0\n");
  scanf("%u", &n);
  if (n <= 0) {
    printf("Wrong number\n");
  }
  // Let's proceed by summing the first n odd numbers to calculate the square of
  // the number n. What we want to do is, by iterating i from 0 to n - 1, list
  // all odd numbers using the form: 2*i + 1 == i + i + 1, and accumulate them
  // in our accumulator.

  unsigned accum = 0;
  while ( n > 0) {
    accum += n + n - 1;
    n--;
  }
  printf("Il quadrato del numero %d è %d\n", n, accum);
  return 0;
}
