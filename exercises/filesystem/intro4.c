#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  /* Assuming intro(n-1).c succeeded */
  int fd = open("dir/test3.txt", O_RDONLY);
  if (fd == -1) {
    /* Why 2? */
    printf("Error opening file");
    return 1;
  }
  char buffer[10];
  int i = 0;
  
  size_t bytes_read = read(fd, buffer, sizeof(buffer));

  while (bytes_read > 0) {
    // Process the chunk (in this example, just print it)
    printf("Read chunk %d: ", i);
    write(1, buffer, bytes_read);
    bytes_read = read(fd, buffer, sizeof(buffer));
    i++;
  }

  close(fd);

  return 0;
}
