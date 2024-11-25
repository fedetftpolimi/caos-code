#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  /* Execute one instructions at a time to check the expected behavior */
  mkdir("dir", 0666);
  /* What's the goal here? */
  int fd = creat("test.txt", 0666);
  /* What happens after this line of code? */
  close(fd);
  int val = 1;
  /* What's the diff b/w these two cases? */
  switch (val) {
  case 0:
    symlink("./test.txt", "dir/test2.txt");
    break;
  case 1:
    symlink("../test.txt", "dir/test2.txt");
    break;
  default:
    printf("Default case\n");
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
