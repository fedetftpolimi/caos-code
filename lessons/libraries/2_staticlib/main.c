#include "point.h" //We need the definition of Point and print_point

int main()
{
    struct Point point;
    point.x=10;
    point.y=15;
    print_point(point);
    return 0;
}
