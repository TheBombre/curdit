#include "../include/editor.h"
#include "../include/file_operations.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void clean_up(void);
void parse_keypress(char character);
void change_mode_to(enum Mode mode);
