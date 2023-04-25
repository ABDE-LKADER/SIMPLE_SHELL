#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

char* my_getline() {
  static char buffer[BUFFER_SIZE];
  static int pos = 0;
  static int len = 0;

  char* line = NULL;
  int line_len = 0;

  while (1) {
    // If buffer is empty, read more data into it
    if (pos >= len) {
      pos = 0;
      len = fread(buffer, 1, BUFFER_SIZE, stdin);
      if (len == 0) {
        // End of file or error, return NULL
        return NULL;
      }
    }

    // Search for newline character in buffer
    while (pos < len && buffer[pos] != '\n') {
      line_len++;
      pos++;
    }

    // If newline character found, return line
    if (pos < len && buffer[pos] == '\n') {
      line = (char*) malloc(line_len + 1);
      if (line == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
      }
      for (int i = 0; i < line_len; i++) {
        line[i] = buffer[i - line_len + pos + 1];
      }
      line[line_len] = '\0';
      pos++;
      return line;
    }

    // If newline character not found, append buffer to line
    char* new_line = (char*) malloc(line_len + BUFFER_SIZE + 1);
    if (new_line == NULL) {
      fprintf(stderr, "Error: Unable to allocate memory\n");
      exit(EXIT_FAILURE);
    }
    if (line != NULL) {
      for (int i = 0; i < line_len; i++) {
        new_line[i] = line[i];
      }
      free(line);
    }
    for (int i = 0; i < len; i++) {
      new_line[line_len + i] = buffer[i];
    }
    line = new_line;
    line_len += len;
    pos = 0;
    len = 0;
  }
}

int main() {
  char* line = NULL;
  while ((line = my_getline()) != NULL) {
    printf("You entered: %s", line);
    free(line);
  }
  return 0;
}

