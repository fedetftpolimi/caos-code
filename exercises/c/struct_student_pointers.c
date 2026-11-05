#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char name[50];
  char surname[50];
} Student;

Student *createStudent(int id, const char *name, const char *surname) {
  Student *s = (Student *)malloc(sizeof(Student));
  if (s == NULL) {
    return NULL; // allocation failed
  }

  s->id = id; // = (*s).id
  strcpy(s->name, name);
  strcpy(s->surname, surname);

  return s;
}

int main() {
  Student *s1 = createStudent(1, "John", "Doe");

  if (s1 == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  printf("%d %s %s\n", s1->id, s1->name, s1->surname);

  free(s1); // IMPORTANT: free the allocated memory
  return 0;
}
