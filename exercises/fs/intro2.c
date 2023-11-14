#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  /* Assuming intro(n-1).c executed */
  int fd = open("dir/test2.txt", O_RDONLY);
  if (fd == -1) {
    perror("Error opening file");
    return 1;
  }
  printf("Succesfully opened symlink\n");

  unlink("test.txt");
  fd = open("dir/test2.txt", O_RDONLY);
  if (fd == -1) {
    printf("Cannot open symlink\n");
  }

  int fd2 = creat("test.txt", 0644);
  fd = open("dir/test2.txt", O_RDONLY);
  if (fd == -1) {
    perror("Error opening file");
    return 1;
  }
  printf("Succesfully opened symlink\n");
  return 0;
}
