
#include <stdio.h>
#include <unistd.h>

void printCurrentDir()
{
    char string[1024];
    char *result=getcwd(string,1024);
    if(result==NULL) printf("Error getting current directory\n");
    else printf("Current directory is %s\n",string);
}

int main()
{
    printCurrentDir();
    char errorCode=chdir("/");
    if(errorCode!=0) printf("Error changing directory\n");
    printCurrentDir();
}
