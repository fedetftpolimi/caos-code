/*
 * An example to check if a directory exists or not. Note that, in real-life
 * scenarios, you may want to use more efficient techniques to detect for the
 * existance of a directory (not seen in this course).
 */
#include <dirent.h>
#include <stdio.h>

int directory_exists(const char *path) {
  DIR *dir = opendir(path);

  if (dir != NULL) {
    closedir(dir);
    // arbitrary return code
    return -2; // Directory exists
  } else {
    return 0; // Directory does not exist
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <directory_path>\n", argv[0]);
    return -1;
  }
  char *dirname = argv[1];

  if (directory_exists(dirname)) {
    printf("Directory '%s' already exists.\n", dirname);
    // Handle the case where the directory already exists
  } else {
    printf("Directory '%s' does not exist.\n", dirname);
    // Proceed with creating the directory or handle accordingly
  }

  return 0;
}
