#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        printf("Error\n");
        return 1;
    }
    int a;
    int b;
    sscanf(argv[1],"%d",&a);
    sscanf(argv[2],"%d",&b);
    int c = a + b;
    printf("The sum is %d\n", c);
    return 0;
}
