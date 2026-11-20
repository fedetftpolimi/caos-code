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

  ssize_t bytes_read = read(fd, buffer, sizeof(buffer));

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

/*
 * Notes
 * - open() returns a file descriptor: a small int indexing the process's
 *   table of open files, or -1 on error (the reason is in errno, perror()
 *   prints it).
 * - A non-zero return value from main() tells whoever ran the program that
 *   it failed (in the shell: echo $?).
 * - read(fd, buf, n) reads *up to* n bytes from the current file offset and
 *   moves the offset forward. It returns how many bytes it actually read:
 *   fewer than n for the last chunk (347 bytes = 26 * 13 + 9), 0 at end of
 *   file, -1 on error. Hence the loop until read() returns 0.
 * - bytes_read is ssize_t (signed), like read()'s return type: in a size_t
 *   (unsigned) an error (-1) would become a huge positive value and the loop
 *   would not stop.
 * - The buffer is raw bytes with no '\0' at the end, so it can't be printed
 *   with %s: we write exactly bytes_read bytes.
 * - fd 0, 1, 2 are stdin, stdout, stderr (STDIN_FILENO, ...), already open
 *   when the program starts.
 * - printf() writes into a stdio buffer in user space, write() goes straight
 *   to the kernel. The printf string has no '\n', so all the "Bytes read"
 *   labels stay in the buffer and appear at exit, after all the chunks.
 *   fflush(stdout) before write() fixes the order.
 * - close() releases the descriptor.
 */
