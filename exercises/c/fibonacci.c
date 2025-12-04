/*
 * Write a program that, given an integer $N > 0$ as input, prints the
 * first $N$ Fibonacci numbers.
 * 
 */
#include <stdio.h>

int main(int argc, char *argv[]) {

  // Dichiariamo e acquisiamo il nostro N
  unsigned n;
  printf("Insert a positive number\n");
  scanf("%u", &n);

  // Check if the value is greater than 0
  if (n <= 0) {
    printf("The value should be strictly positive!");
    return 0;
  }

  int prev1, prev2, cur;

  // Print first number
  printf("0 ");

  // If we only wanted the first number, we can return
  if (n == 1) {
    return 0;
  }

  // second number
  printf("1 ");

  // in slides, prev1=a, prev2=b, cur=c
  prev1 = 0;
  prev2 = 1;

  // The loop will be executed n - 2 times, since we already printed the first two numbers
  while (n > 2) {
    // Compute n-th number in fibonacci series
    cur = prev1 + prev2;
    printf("%u ", cur);

    // Update the variables 
    prev1 = prev2;
    prev2 = cur;
    n--; // n -= 1
  }
  printf("\n");

  return 0;
}
