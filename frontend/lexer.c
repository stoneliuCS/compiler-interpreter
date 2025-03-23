#include "lexer.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void tokenize(const char* source) {
  for (int i = 0; i < strlen(source); i++) {
    char c = source[i];
    printf("%c", c);
  }
}

void raise_error(Error* err) {
  printf("Encountered an error on line: ");
  printf("%d", err->line_number);
  printf("%s", err->line);
}
