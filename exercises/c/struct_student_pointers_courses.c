#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50
#define MAX_COURSES 50

typedef struct {
  unsigned id;
  char name[MAX_STR_LEN];
} Course;

typedef struct {
  unsigned id;
  char name[MAX_STR_LEN];
  char surname[MAX_STR_LEN];

  Course courses[MAX_COURSES];
  int grades[MAX_COURSES];
  int courseCount;
} Student;

Course *createCourse(unsigned id, const char *name) {
  Course *c = malloc(sizeof(Course));
  c->id = id;
  strncpy(c->name, name, MAX_STR_LEN - 1);
  c->name[MAX_STR_LEN - 1] = '\0';
  return c;
}

Student *createStudent(unsigned id, const char *name, const char *surname,
                       Course *courseList[], int gradeList[], int count) {

  Student *s = malloc(sizeof(Student));

  s->id = id;
  strncpy(s->name, name, MAX_STR_LEN - 1);
  s->name[MAX_STR_LEN - 1] = '\0';

  strncpy(s->surname, surname, MAX_STR_LEN - 1);
  s->surname[MAX_STR_LEN - 1] = '\0';

  if (count > MAX_COURSES)
    count = MAX_COURSES;

  s->courseCount = count;

  for (int i = 0; i < count; i++) {
    s->courses[i] = *(courseList[i]);   // copy Course content
    s->grades[i] = gradeList[i];
  }

  return s;
}

int main() {
  // Create some courses
  Course *math = createCourse(101, "Mathematics");
  Course *physics = createCourse(102, "Physics");
  Course *programming = createCourse(103, "Programming");

  // Student #1 courses
  Course *courseList1[] = { math, physics, programming };
  int grades1[] = { 28, 26, 30 };
  int count1 = 3;

  Student *s1 =
    createStudent(1, "Alice", "Brown", courseList1, grades1, count1);

  // Student #2 courses
  Course *courseList2[] = { math, physics };
  int grades2[] = { 28, 30 };
  int count2 = 2;

  Student *s2 =
    createStudent(2, "Bob", "White", courseList2, grades2, count2);

  // Print student 1
  printf("\n=== Student 1 ===\n");
  printf("ID: %u\nName: %s %s\n", s1->id, s1->name, s1->surname);
  for (int i = 0; i < s1->courseCount; i++) {
    printf("Course: %-12s (ID %u)  Grade: %d\n",
        s1->courses[i].name, s1->courses[i].id, s1->grades[i]);
  }

  // Print student 2
  printf("\n=== Student 2 ===\n");
  printf("ID: %u\nName: %s %s\n", s2->id, s2->name, s2->surname);
  for (int i = 0; i < s2->courseCount; i++) {
    printf("Course: %-12s (ID %u)  Grade: %d\n",
        s2->courses[i].name, s2->courses[i].id, s2->grades[i]);
  }

  return 0;
}

