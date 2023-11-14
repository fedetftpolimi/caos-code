#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int retstatus=0;
    pid_t pid=fork();
    if(pid==0)
    {
        printf("I am the child process\n");
        retstatus=1;
        exit(retstatus);
    } else {
        printf("I am the parent process\n");
        exit(retstatus);
    }
}
