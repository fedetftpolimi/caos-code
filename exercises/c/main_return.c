/*
 * Toy example to show the relevance of the return address of a function.
 * After building, try to use ./a.out && echo "Sound and safe"
 *
 * The C language standard says that returning from main is equivalent to
 * calling the exit function with the same value. The exit status gets passed
 * back to the operating system, and then what happens from there is
 * OS-dependent.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int x;
  scanf("%d", &x);

  if(x > 0)
    return 0;
  else
    return -1;
}

