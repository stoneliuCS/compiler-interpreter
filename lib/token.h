#include <stdlib.h>
#ifndef TOKEN_LIST_H 

#define TOKEN_LIST_H

typedef struct token_list token_list_t;

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
  BANG,
  NOT_BANG,
  EQUAL,
  EQUAL_EQUAL,
  LESS_THAN,
  GREATER_THAN,
  LESS_THAN_OR_EQUAL,
  GREATER_THAN_OR_EQUAL,
  ASSIGNMENT
} TokenType;

// A Token is a structured data which knows its type, the lexeme, the literal value, and a line number.
typedef struct Token {
  const TokenType type;
  const char* lexeme;
  const void* literal;
  const int line;
} Token;

#define CAPACITY_INCREASE_RATE 2;

// Creates a new token list with the inital capacity.
token_list_t* create_token_list(const int capacity);

// Appends that token to the back of that token_list.
void append_to_token_list(token_list_t* list, Token token);

// Frees all resources from the given token list.
void free_token_list(token_list_t* list);

// Gets the token list capacity.
int get_token_list_capacity(token_list_t* list);

// Gets the token_list current size
int get_token_current_size(token_list_t* list);

#endif
