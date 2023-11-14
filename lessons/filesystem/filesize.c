
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void fail(const char *message)
{
    printf("Error: %s\n",message);
    exit(1);
}

int main(int argc, char *argv[])
{
    if(argc!=2) fail("Missing file path");
    int fd=open(argv[1],O_RDONLY);
    if(fd<0) fail("File not found");
    off_t size=lseek(fd,0,SEEK_END);
    close(fd);
    printf("File %s has size %ld bytes\n",argv[1],size);
    return 0;
}
