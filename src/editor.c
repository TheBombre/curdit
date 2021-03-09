#include "../include/editor.h"

/**
 * Rendering text for the user to see
 * @param text_area window in which the text is displayed
 * @param file_data 2D array containing file text
 * @param lines number of lines in file
 * */
void display_text(WINDOW *text_area, char **file_data, int lines) {
  for (int i = 0; i < lines; i++) {
    wprintw(text_area, file_data[i]);
  }
}
