#include "../include/constants.h"
#include <ncurses.h>
#include <stdio.h>

void display_text(WINDOW *text_area, char **file_data, int lines);
void handle_keypress(WINDOW *text_area, char character, enum Mode mode);
void handle_user_exit();
