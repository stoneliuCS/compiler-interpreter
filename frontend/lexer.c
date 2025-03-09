#include "lexer.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

GArray* tokenize(const char* source) {
  for (int i = 0; i < strlen(source); i++) {
    char c = source[i];
    if (c == ' ' || c == '\n') continue; //Skip over any whitespace or new lines.
    printf("%c\n", c);
  }
  return NULL;
}
