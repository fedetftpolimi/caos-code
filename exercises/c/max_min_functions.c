#include <stdio.h>

int max(int *numbers, int size) {
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
  printf("Inside function max\n");
  /* int size = 10; */
  int numbers[] = {5, 1, 6, 10, 2, 3, 6, 50, -7, 4};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  printf("The size of the array is %d", size);
  int mx = max(numbers, 10);
  printf("The maximum is %d\n", mx);
  int mn = min(numbers, 10);
  printf("The minimum is %d\n", mn);
  return 0;
}
