// On the usage of void* pointers
#include <stdio.h>

void print_value(void *ptr, char type) {
  if (type == 'i') {
    int *i_ptr = (int *)ptr;
    printf("Integer: %d\n", *i_ptr);
  } else if (type == 'f') {
    // Same as before, but in one line
    printf("Float: %.2f\n", *(float *)ptr);
  } else {
    printf("Unknown type\n");
  }
}

int main() {
  int a = 10;
  float b = 3.14;
  print_value(&a, 'i');
  print_value(&b, 'f');
  return 0;
}
