#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  const char *dirname = "example2";

  // Create a directory (you may want to check for errors in a real-world
  // scenario)
  if (mkdir(dirname, 0777) == -1) {
    printf("Error creating directory\n");
    return 1;
  }
  int fd = creat("example/test.txt", 0644);

  // Use rmdir to remove the directory
  if (rmdir(dirname) == -1) {
    printf("Error removing directory");
    return 1;
  } else {
    printf("Directory removed successfully.\n");
  }

  return 0;
}
