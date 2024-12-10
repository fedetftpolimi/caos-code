#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  /* What happens? What's missing? */
  mkdir("dir2", 0777); //
  /* What's the difference b/w those two functions? */
  int fd = creat("dir2/test3.txt", 0644);
  /* fd = open("dir/test3.txt", O_RDWR); */
  if (fd == -1) {
    printf("Error opening file");
    return 1;
  }

  char *content = "Hello from the other side!\n";
  ssize_t bytes_written = write(fd, content, strlen(content));
  printf("%zd bytes written to the file.\n", bytes_written);

  char buffer[100];
  for (int i = 0; i < 10; i++) {
    // Use sprintf to format the string
    sprintf(buffer, "Hello world! Iteration number %d\n", i);

    // Use write to write the formatted string to the file
    ssize_t bytes_written = write(fd, buffer, strlen(buffer));
    printf("%zd bytes written to the file.\n", bytes_written);

    if (bytes_written == -1) {
      printf("Error writing to file");
      close(fd);
      return 1;
    }
  }
  return 0;
}
