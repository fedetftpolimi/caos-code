#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv [])
{
    pid_t pid=fork();
    if(pid==0)
    {
        printf("Child pid is: %d\n", getpid());
        exit(5);
    } else {
        printf("Parent waiting for child with pid %d\n",pid);
        int wstatus;
        pid_t pid2=wait(&wstatus);
        printf("Pid %d terminated with exit code %d\n", pid2, WEXITSTATUS(wstatus));
    }
}
