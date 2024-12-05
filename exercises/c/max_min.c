#include <stdio.h>

int main(int argc, char *argv[]) {
  int numbers[] = {5, 1, 6, 10, 2, 3, 6, 50, -7, 4};
  int size = sizeof(numbers)/sizeof(numbers[0]);
  printf("The size of the array is %d", size);
  int max = numbers[0], min = numbers[0], i;
  for (i = 0; i < 10; i++) {
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
