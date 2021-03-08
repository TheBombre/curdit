#include <stdio.h>

typedef struct {
  int line_number_start;
  int line_number_end;
  char *previous; // text being replaced
  char *current;  // what it got changed to
} Change;

// TODO: Look into how often to make changes, see how others have done it on github
