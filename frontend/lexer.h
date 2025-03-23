#include <glib.h>
#include "../lib/array-list.h"

#ifndef LEXER_H 

#define LEXER_H


typedef enum TokenType {
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  DOT,
  MINUS,
  PLUS,
  SEMICOLON,
  SLASH,
  STAR,
  ASSIGNMENT,
} TokenType;

// A Token is a structured data which knows its type, the lexeme, the literal value, and a line number.
typedef struct Token {
  const TokenType type;
  const char* lexeme;
  const void* literal;
  const int line;
} Token;

typedef struct Error {
  const int line_number;
  const char* line;
} Error;

// Tokenizes the source code into an Array of text.
ArrayList* tokenize(const char* source);

// Raises an error during runtime.
void raise_error(Error* err);

#endif
