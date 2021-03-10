#include "../include/constants.h"
#include <ncurses.h>
#include <stdio.h>

void display_text(WINDOW *text_area, char **file_data, int lines);
void handle_keypress(WINDOW *text_area, char character, enum Mode mode);
void display_keyboard_shortcuts(WINDOW *status_window);
void handle_user_exit();
