#include <glib.h>
#include "../lib/token.h"

#ifndef LEXER_H 

#define LEXER_H

typedef struct Error {
  const int line_number;
  const char* line;
} Error;

// Tokenizes the source code into an Array of text.
token_list_t* tokenize(const char* source);

// Raises an error during runtime.
void raise_error(Error* err);

#endif
