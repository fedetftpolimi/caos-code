#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Before fork: PID = %d\n", getpid());
    pid_t pid=fork();
    if(pid==0)
    {
        printf("Child: PID = %d\n", getpid());
        exit(0);
    } else {
        printf("Parent: PID = %d\n", getpid());
        printf("Parent: child PID = %d\n", pid);
        exit(0);
    }
}
