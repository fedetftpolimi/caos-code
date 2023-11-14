
#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("This goes to the screen\n");
    close(1);
    int fd=creat("log.txt",0660);
    assert(fd==1); //Kernel should reuse entry 1 of file descriptor table
    printf("This goes to a file instead\n");
    fprintf(stderr,"This still goes to the screen\n");
    return 0;
}
