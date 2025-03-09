#include <glib.h>

#ifndef LEXER_H 

#define LEXER_H

// KEYWORDS

#define ASSIGNMENT = "<-"

typedef enum STATEMENTS {
  SEMICOLON = ';',
  LEFT_PAREN = '(',
  RIGHT_PAREN = ')',
  WHITE_SPACE = ' ',
  NEW_LINE = '\n',
  EQ = '=',
} STATEMENTS;

typedef struct tokenizer_operations {

} TokenizerOperations;

// Tokenizes the source code into an Array of text.
GArray* tokenize(const char* source);

#endif
