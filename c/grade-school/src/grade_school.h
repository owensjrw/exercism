#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct{
  uint8_t grade;
  char name[MAX_NAME_LENGTH + 1];
} student_t;

typedef struct{
  size_t count;
  student_t students[MAX_STUDENTS];
} roster_t;

void clear_roster();

bool add_student(char*, uint8_t);

roster_t get_roster();

roster_t get_grade(uint8_t);

int sort_grade(const void *a, const void *b);

int sort_student(const void *a, const void *b);

#endif
