#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  /* Assuming intro(n-1).c created dir */
  int fd = creat("dir/test3.txt", 0644);
  if (fd == -1) {
    printf("Error opening file");
    return 1;
  }
  fd = open("dir/test3.txt", O_RDWR);

  const char *content = "Hello world\n";
  ssize_t bytes_written = write(fd, content, strlen(content));
  printf("%zd bytes written to the file.\n", bytes_written);

  char buffer[100];
  for (int i = 0; i < 10; i++) {
    // Use sprintf to format the string
    sprintf(buffer, "Hello world, iteration %d\n", i);

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
