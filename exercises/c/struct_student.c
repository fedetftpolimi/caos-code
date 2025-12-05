#include <string.h>
#include <stdio.h>

#define MAX_COURSES 50
#define MAX_NAME_LEN 50

typedef struct {
  int id;
  char name[MAX_NAME_LEN];
  char surname[MAX_NAME_LEN];
} Student;

Student createStudent(int id, const char *name, const char *surname) {
  Student s;
  s.id = id;
  strcpy(s.name, name);
  strcpy(s.surname, surname);
  return s;
}

int main() {
  Student s1 = createStudent(1, "John", "Doe");
  printf("%d %s %s\n", s1.id, s1.name, s1.surname);
  return 0;
}
