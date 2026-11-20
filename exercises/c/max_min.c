#include <stdio.h>

int main(int argc, char *argv[]) {
  int numbers[] = {5, 1, 6, 10, 2, 3, 6, 50, -7, 4};
  int size = sizeof(numbers)/sizeof(numbers[0]);
  printf("The size of the array is %d\n", size);
  int max = numbers[0], min = numbers[0], i;
  for (i = 0; i < size; i++) {
    printf("Analyzing element numbers[%d] = %d\n", i, numbers[i]);
    if (numbers[i] > max) {
      max = numbers[i];
    }
    else if (numbers[i] < min) {
      min = numbers[i];
    }
  }
  printf("Max %d, Min %d\n", max, min);
  return 0;
}

/*
 * Notes
 * - sizeof is an operator (not a function) that gives the size in bytes of a
 *   variable or of a type; the compiler computes it. sizeof(numbers) is the
 *   size of the whole array (10 ints * 4 bytes = 40 on most machines) and
 *   sizeof(numbers[0]) is the size of one element (4), so dividing them gives
 *   the number of elements: 40 / 4 = 10.
 * - Why not just write 10? If you add or remove a number in the braces, size
 *   updates by itself and the loop (i < size) follows, while a hard-coded 10
 *   has to be fixed by hand everywhere. Dividing by sizeof(numbers[0])
 *   instead of sizeof(int) keeps working even if the type of the elements
 *   changes (e.g. to double).
 * - The trick only works where numbers is a real array, i.e. in the function
 *   where it is declared. Once passed to another function it becomes a
 *   pointer (see max_min_functions.c).
 * - In int numbers[] = {...} the size between [] can be left out: the
 *   compiler counts the values in the braces.
 * - Indexes start at 0, so the valid ones go from 0 to size - 1: hence
 *   i < size and not i <= size. C does not check bounds: numbers[10] reads
 *   whatever is in memory right after the array.
 * - max and min start from numbers[0], not from 0: if all the numbers were
 *   negative, a max starting at 0 would wrongly stay 0. (At i = 0 we compare
 *   numbers[0] with itself, which is harmless; the loop could start at 1.)
 * - else if: a value bigger than max can't also be smaller than min, so the
 *   second check is skipped when the first one is true.
 * - int max = numbers[0], min = numbers[0], i; declares three ints on one
 *   line, but only the first two get an initial value.
 */
