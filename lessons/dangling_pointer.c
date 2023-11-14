#include <stdlib.h>
#include <stdio.h>

int main()
{
    int size = 16;
    int *ptr = malloc(size * sizeof(int));
    *ptr = 42;
    free(ptr);
    printf("The variable value is %d\n", *ptr);
    return 0;
}
