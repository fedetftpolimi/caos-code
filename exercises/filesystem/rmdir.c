#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  /* const char *dirname = "example"; */
  if (argc != 2) {
    printf("Usage: %s <directory_path>\n", argv[0]);
    return 1;
  }
  char *dirname = argv[1];

  // Use rmdir to remove the directory
  if (rmdir(dirname) == -1) {
    printf("Error removing directory\n");
    return 1;
  } 
  printf("Directory removed successfully.\n");
  return 0;
}
