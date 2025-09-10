/* PLEASE EDIT THIS FILE */

#include "filechar.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

/* BEGIN STUDENT ANSWER HELPER FUNCTIONS */

static inline int char_to_index(char character) {
  // turn both [a-z] and [A-Z] into the index used to increment their spots in
  // the array.
  if (character == ' ') {
    return ALPHABET_SIZE; // index for space
  } else if (isalpha(character)) {
    // case insensitive, so lowercase it, then calibrate it to a = 0 ... z = 25
    return tolower(character) - 'a';
  } else {
    return -1;
  }
}

static inline char index_to_char(int index) {
  // turn the index into [a-z] or ' '
  if (index == ALPHABET_SIZE) {
    return ' ';
  } else {
    return 'a' + index;
  }
}

/* END STUDENT ANSWER HELPER FUNCTIONS */

bool countChar(char *filename, int counts[][ALPHABET_SIZE_W_SPACE]) {
  FILE *file = fopen(filename, "r");
  // error occurs if file is NULL
  if (file == NULL) {
    return false;
  }

  // initialize character
  int c; // current character
  int first_index = -1;
  // loop through each character in the file
  while ((c = fgetc(file)) != EOF) {
    // check if c is alphabetic
    if (!isalpha(c)) {
      continue; // skip non-alphabetic characters
    }
    else if (first_index == -1) {
      // store the value of first character pair
      first_index = char_to_index(c);
      continue; // get the next character
    } else {
      counts[first_index][char_to_index(c)]++;
      first_index = -1; // reset for next pair
    }
  }

  // scenario where there is only one character left unpaired
  if (first_index != -1) {
    // if there's an unmatched first character, count it with space
    counts[first_index][ALPHABET_SIZE]++;
  }
  fclose(file);
  return true;
}

void printCounts(int counts[][ALPHABET_SIZE_W_SPACE]) {
  char pair[3];
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    for (int j = 0; j < ALPHABET_SIZE_W_SPACE; j++) {
      if (counts[i][j] == 0) {
        continue;
      }
      pair[0] = index_to_char(i);
      pair[1] = (j == ALPHABET_SIZE) ? ' ' : index_to_char(j);
      pair[2] = '\0';
      fprintf(stdout, "%d, %d, %s, %d\n", i, j, pair, counts[i][j]);
    }
  }
}
  // complete as described in the README

  /* END STUDENT ANSWER */

