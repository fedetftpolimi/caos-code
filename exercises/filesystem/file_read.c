#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  /* Assuming file_write.c succeeded */
  int fd = open("dir2/test3.txt", O_RDONLY);
  if (fd == -1) {
    printf("Error opening file");
    /* Why 1? */
    return 1;
  }
  char buffer[13];
  int i = 0;

  size_t bytes_read = read(fd, buffer, sizeof(buffer));

  while (bytes_read > 0) {
    // Process the chunk (in this example, just print it)
    printf("Bytes read: %zd, Read chunk %d: ", bytes_read, i);
    // A flush is required here, printf is buffering!
    /* fflush(stdout); */
    // What is 1?
    write(1, buffer, bytes_read);
    bytes_read = read(fd, buffer, sizeof(buffer));
    i++;
  }

  close(fd);

  return 0;
}
