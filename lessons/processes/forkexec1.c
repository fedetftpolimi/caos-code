#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        execl("args", "args", NULL);
        printf("Error: exec failed");
        return 1;
    } else {
        printf("Waiting for child %d\n", pid);
        pid_t pid2 = wait(NULL);
        printf("Child %d terminated\n", pid2);
        return 0;
    }
}
