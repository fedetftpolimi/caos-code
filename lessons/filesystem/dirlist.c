
#include <stdio.h>
#include <dirent.h>

int main()
{
    //NOTE: . is a special relative path meaning "the current directory"
    struct dirent *entry;
    DIR *dir=opendir(".");
    if(dir==NULL) printf("Error reading directory\n");
    else while((entry=readdir(dir))!=NULL)
    {
        if(entry->d_type==DT_DIR)
            printf("Found directory %s\n",entry->d_name);
        else
            printf("Found file %s\n",entry->d_name);
    }
    closedir(dir);
}
