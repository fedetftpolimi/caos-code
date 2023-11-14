#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("About to perform the exec call\n");
    char *args[4];
    args[0]="args";
    args[1]="parameter1";
    args[2]="parameter2";
    args[3]=NULL;
    execv(args[0], args);
    printf("Something went wrong\n");
}
