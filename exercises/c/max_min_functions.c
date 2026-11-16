#include <stdio.h>

int max(int *numbers, int size) {
  printf("Inside function max\n");
  int i;
  int max = numbers[0];
  for (i = 0; i < size; i++) {
    printf("Analyzing element numbers[%d] = %d\n", i, numbers[i]);
    if (numbers[i] > max) {
      max = numbers[i];
    } 
  }
  return max;
}

int min(int *numbers, int size) {
  printf("Inside function min\n");
  int i;
  int min = numbers[0];
  for (i = 0; i < size; i++) {
    printf("Analyzing element numbers[%d] = %d\n", i, numbers[i]);
    if (numbers[i] < min) {
      min = numbers[i];
    } 
  }
  return min;
}

int main(int argc, char *argv[]) {
  /* int size = 10; */
  int numbers[] = {5, 1, 6, 10, 2, 3, 6, 50, -7, 4};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  printf("The size of the array is %d\n", size);
  int mx = max(numbers, size);
  printf("The maximum is %d\n", mx);
  int mn = min(numbers, size);
  printf("The minimum is %d\n", mn);
  return 0;
}

/*
 * Notes
 * - When you pass an array to a function, C only passes the address of its
 *   first element: the parameter int *numbers is a pointer (writing
 *   int numbers[] would mean exactly the same thing). The function has no way
 *   to know how many elements there are, so size is passed as a second
 *   parameter.
 * - That's why sizeof is used in main and not inside max() or min(): there,
 *   sizeof(numbers) is the size of a pointer (8 bytes on a 64-bit machine),
 *   not of the array, and 8 / 4 = 2 elements would be wrong. gcc -Wall warns
 *   about it.
 * - numbers[i] works on a pointer too: it means *(numbers + i), the int that
 *   is i positions after the one numbers points to.
 * - Since the function receives an address, it works on the original array,
 *   not on a copy: if it changed numbers[i], main would see the change.
 *   (const int *numbers would forbid changes.)
 * - The functions are written before main, so the compiler already knows
 *   them when main calls them. To define them after main you need a
 *   declaration (prototype) above main: int max(int *numbers, int size);
 * - A function returns a single value, hence one function for the max and
 *   one for the min. The price is going through the array twice (look at the
 *   output), while max_min.c does it in one pass.
 * - Inside max(), the local variable max hides the function with the same
 *   name: it compiles, but it's confusing. Same for min.
 */
