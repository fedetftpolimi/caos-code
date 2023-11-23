#include <stdio.h>

struct Point { int x; int y; };

void print_point(struct Point p)
{
   printf("x=%d y=%d\n", p.x, p.y);
}

int main()
{
    struct Point point;
    point.x=10;
    point.y=15;
    print_point(point);
    return 0;
}
