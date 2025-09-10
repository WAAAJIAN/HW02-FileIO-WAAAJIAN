/* PLEASE EDIT THIS FILE */

#include "fileint.h"

#include <stdbool.h>
#include <stdio.h>

bool addFile(char *filename, int *sum) {
  /* BEGIN STUDENT ANSWER */
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return false;
  }
  int num;
  *sum = 0;
  while (fscanf(file, "%d", &num) != EOF) {
    *sum += num;
  }
  fclose(file);
  return true;
}

bool writeSum(char *filename, int sum) {
  /* BEGIN STUDENT ANSWER */
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    return false;
  }
  fprintf(file, "%d\n", sum);
  fclose(file);
  return true;
}
