#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid1=fork();
    if(pid1==0)
    {
        // First child
        printf("Child 1: PID = %d\n", getpid());
        exit(0);
    } else {
        // Parent
        pid_t pid2=fork();
        if(pid2==0)
        {
            // Second child
            printf("Child 2: PID = %d\n", getpid());
            exit(0);
        } else {
            // Parent
            printf("Parent: PID = %d\n", getpid());
            printf("Parent: PID of child 1 = %d\n", pid1);
            printf("Parent: PID of child 2 = %d\n", pid2);
            exit(0);
        }
    }
}
