/* Write a C program that lists all the files and */
/* directories in a specified directory using readdir and closedir. You */
/* should provide the name of the directory as a command-line */
/* argument. */
#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <directory_path>\n", argv[0]);
    return 1;
  }

  char *dirname = argv[1];
  DIR *dir = opendir(dirname);
  if (dir == NULL) {
    printf("opendir failed!");
    return 1;
  }

  struct dirent *entry;
  entry = readdir(dir);
  while (entry != NULL) {
    printf("%s\n", entry->d_name);
    entry = readdir(dir);
  }

  closedir(dir);
  return 0;
}
