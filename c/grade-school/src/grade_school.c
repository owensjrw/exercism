#include <string.h>
#include "grade_school.h"

roster_t schoolRoster = {.count = 0};

void clear_roster(){
  roster_t freeRoster = {.count = 0, {{}}};
  schoolRoster = freeRoster;
}

bool add_student(char *studentName, uint8_t studentGrade){
  strcpy(schoolRoster.students[schoolRoster.count].name, studentName);
  schoolRoster.students[schoolRoster.count].grade = studentGrade;
  schoolRoster.count += 1;
  return true;
}

roster_t get_roster(){
  qsort(schoolRoster.students, schoolRoster.count, sizeof(student_t), sort_student);
  qsort(schoolRoster.students, schoolRoster.count, sizeof(student_t), sort_grade);
  return schoolRoster;
}

roster_t get_grade(uint8_t classGrade){
  roster_t sortedRoster = get_roster();
  roster_t gradeRoster = {.count = 0};
  int i, s;
  i = s = 0;
  for(i = 0; i < (int)sortedRoster.count; i++){
    if(sortedRoster.students[i].grade == classGrade){
      strcpy(gradeRoster.students[s].name, sortedRoster.students[i].name);
      gradeRoster.students[s].grade = sortedRoster.students[i].grade;
      gradeRoster.count += 1;
      s += 1;
    }
  }
  return gradeRoster;
}


int sort_grade(const void *a, const void *b){
  student_t *ia = (student_t *)a;
  student_t *ib = (student_t *)b;
  return (int)(ia->grade - ib->grade);
}

int sort_student(const void *a, const void *b){
  student_t *ia = (student_t *)a;
  student_t *ib = (student_t *)b;
  return strcmp(ia->name, ib->name);
}
