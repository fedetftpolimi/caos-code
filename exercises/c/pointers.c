#include <stdio.h>

int main(int argc, char *argv[]) {
  int m = 20, n, o;
  int *z = &m;

  printf("&m address is = %p\n", &m);
  printf("&n address is = %p\n", &n);
  printf("&o address is = %p\n", &o);
  printf("&z address is = %p\n\n", &z);
  // z is a pointer so %p would print the address
  printf("z stores the address of m  = %p\n", z);
  printf("*z stores the value of m = %d\n", *z);
}
