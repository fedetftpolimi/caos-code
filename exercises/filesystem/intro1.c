#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  /* Execute one instructions at a time to check the expected behavior */
  mkdir("dir", 0777);
  int fd = creat("test.txt", 0644);
  close(fd);
  int val = 1;
  switch (val) {
  case 0:
    symlink("./test.txt", "dir/test2.txt");
    break;
  case 1:
    symlink("../test.txt", "dir/test2.txt");
    break;
  default:
    printf("Wrong case\n");
    return 1;
  }
  fd = open("dir/test2.txt", O_RDONLY);
  if (fd == -1) {
    printf("Error opening file");
    return 1;
  }
  printf("Succesfully opened symlink\n");

  return 0;
}
