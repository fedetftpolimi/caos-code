#include <stdio.h>

int main(int argc, char *argv[]) {
  int m = 20, n, o;
  int *z = &m;

  printf("\n &m stores the address of n = %p\n", &m);
  printf("\n &n stores the address of n = %p\n", &n);
  printf("\n &o  stores the address of o = %p\n", &o);
  printf("\n &z stores the address of z = %p\n\n", &z);
  // z is a pointer so %p would print the address
  printf("\n z stores the address of m  = %p\n", z);
  printf("\n *z stores the value of m = %d\n", *z);
}
