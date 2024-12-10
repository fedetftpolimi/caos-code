#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <directory_path> <file_name>\n", argv[0]);
    return 1;
  }

  char *dirname = argv[1];
  char *filename = argv[2];

  // Create a directory
  int rc = mkdir(dirname, S_IRWXU);
  if (rc == -1) {
    // different reasons for error, check the manual.
    // One reason is if the directory exists already.

    /* if (errno == EEXIST) */
    /*   printf("Dir existing\n"); */
    printf("Error creating directory");
    return -1;
  }

  // Concatenate directory path and file name
  char filePath[256]; // Adjust the size as needed
  printf("to create: %s/%s\n", dirname, filename);
  snprintf(filePath, sizeof(filePath), "%s/%s", dirname, filename);

  // Create or open a file
  /* int fd = creat(filename, S_IRUSR); */
  int fd = open(filePath, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
  if (fd == -1) {
    // different reasons for error, check the manual
    printf("Error opening or creating file");
    return -1;
  }

  close(fd); // Close the file descriptor
  printf("Successfully created: %s/%s\n", dirname, filename);
  return 0;
}
