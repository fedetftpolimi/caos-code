#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  /* const char *dirname = "example"; */
  if (argc != 2) {
    printf("Usage: %s <directory_path>\n", argv[0]);
    return 1;
  }
  char *dirname = argv[1];

  // Create a directory
  int rc = mkdir(dirname, S_IRWXU);
  if (rc == -1) {
    /* if (errno == EEXIST) */
    /*   printf("Dir existing\n"); */
    printf("Error creating directory\n");
    return 1;
  }

  printf("Directory created successfully.\n");
  return 0;
}
