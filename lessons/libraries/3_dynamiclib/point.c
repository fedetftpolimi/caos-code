#include <stdio.h> //Still needed, as we call printf
#include "point.h" //We need the definition of Point

void print_point(struct Point p)
{
   printf("x=%d y=%d\n", p.x, p.y);
}
