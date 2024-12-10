#include <stdio.h>
#include <string.h>

int main() {
  // Define a string to be tokenized
  char sentence[] = "Hello, how are you doing today?";

  // Define the delimiter (space character)
  const char *delim = " ";

  // Get the first token
  char *token = strtok(sentence, delim);

  // Print the tokens one by one
  while (token != NULL) {
    printf("Token: %s\n", token);

    // Get the next token
    token = strtok(NULL, delim);
  }

  return 0;
}
