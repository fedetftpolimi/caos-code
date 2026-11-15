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
  /* fd = open("dir2/test3.txt", O_RDWR); */
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

/*
 * Notes
 * - mkdir(path, mode) fails (EEXIST) if the directory already exists: its
 *   return value is not checked. The mode is octal (leading 0) and the umask
 *   is removed from it: 0777 & ~022 = 0755.
 * - creat(path, mode) is open(path, O_WRONLY | O_CREAT | O_TRUNC, mode): it
 *   creates the file if missing and empties it if it exists. open() without
 *   O_CREAT fails if the file does not exist.
 * - write(fd, buf, n) writes n bytes at the current file offset and moves
 *   the offset forward, so consecutive writes end up one after the other.
 *   It returns the number of bytes written (possibly fewer than n), or -1.
 * - strlen(), not sizeof: sizeof(content) is the size of the pointer, and
 *   the final '\0' must not end up in the file.
 * - sprintf() only formats into memory; write() moves the bytes to the file.
 * - write() is a system call with no user-space buffer: when it returns the
 *   data is in the kernel, not necessarily on disk yet (see fsync()).
 * - close(fd) is missing: the kernel closes all descriptors at exit, but
 *   closing them explicitly is good practice.
 */
