#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("About to perform the exec call\n");
    execl("args", "args", "parameter1", "parameter2", NULL);
    printf("Something went wrong\n");
}
