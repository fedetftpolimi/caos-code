#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_STR_LEN 100

void search_in_chunk(char **chunk, int size, const char *target, int chunk_id) {
  for (int i = 0; i < size; i++) {
    if (strcmp(chunk[i], target) == 0) {
      printf("Word '%s' found in chunk %d at index %d\n", target, chunk_id, i);
      exit(1); // Found the word
    }
  }
  exit(0); // Word not found in this chunk
}

int main() {
  // Example array and target word
  char *array[] = {"apple",      "banana",     "cherry",     "date",
                   "elderberry", "strawberry", "fig",        "grape",
                   "honeydew",   "melon",      "watermelon", "cantalupe",
                   "orange",     "clementine", "tomato"};
  int array_size = sizeof(array) / sizeof(array[0]);
  const char *target = "horse";
  int chunk_size = 3; // Number of elements per chunk
  int num_chunks = array_size / chunk_size; // integer division, what happens?
  if (array_size % chunk_size != 0) {
    num_chunks++;
  }

  pid_t pids[num_chunks];
  int status;

  // Create processes for each chunk
  for (int i = 0; i < num_chunks; i++) {
    int start = i * chunk_size;
    int end = (i + 1) * chunk_size;
    if (end > array_size)
      end = array_size;

    // Fork a new process
    if ((pids[i] = fork()) == 0) {
      // Child process: search in its chunk
      search_in_chunk(&array[start], end - start, target, i);
    }
  }

  // Parent process: wait for results
  for (int i = 0; i < num_chunks; i++) {
    pid_t pid = waitpid(pids[i], &status, 0);

    // WIFEXITED returns true if the child terminated normally,

    // WEXITSTATUS Decodes the process status value in status to get the exit status of a
    // process as an it.
    if (WIFEXITED(status) && WEXITSTATUS(status) == 1) {
      printf("Process %d reported success. Exiting program.\n", pid);

      // Terminate all other child processes
      for (int j = 0; j < num_chunks; j++) {
        if (pids[j] != pid) {
          kill(pids[j], SIGKILL);
        }
      }
      return 0; // Exit after finding the word
    }
  }

  printf("Word '%s' not found in the array.\n", target);
  return 0;
}
