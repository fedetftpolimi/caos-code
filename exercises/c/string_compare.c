#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
  char str1[MAX_LENGTH], str2[MAX_LENGTH];

  int result;
  // Keep asking the user for input until the strings are equal
  do {
    // Prompt the user for two strings
    printf("Enter the first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    printf("Enter the second string: ");
    fgets(str2, MAX_LENGTH, stdin);

    // Compare the two strings
    result = strcmp(str1, str2);
    if (result < 0) {
      printf("String 1 is less than 2. Try again.\n");
    } else if (result > 0) {
      printf("String 2 is less than 1. Try again.\n");
    }
  } while (result != 0); // Continue looping if strings are not equal

  printf("The strings are equal! Exiting the program.\n");
  return 0;
}
