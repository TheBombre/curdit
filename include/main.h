#include "../include/editor.h"
#include "../include/file_operations.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void clean_up(void);
void change_mode_to(enum Mode mode);
void populate_status_window(void);
char *mode_to_text(enum Mode mode);
