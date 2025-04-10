#ifndef TOKEN_H

#define TOKEN_H
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
  NOT_EQUAL,
  EQUAL,
  EQUAL_EQUAL,
  LESS_THAN,
  GREATER_THAN,
  LESS_THAN_OR_EQUAL,
  GREATER_THAN_OR_EQUAL,
  ASSIGNMENT,
  AND,
  CLASS,
  ELSE,
  FALSE
} TokenType;

// A Token is a structured data which knows its type, the lexeme, the literal
// value, and a line number.
typedef struct Token {
  TokenType type;
  char *lexeme;
  void *literal;
  int line;
} Token;

// Creates a token.
Token *create_token(TokenType type, char *lexeme, void *literal, int line);

const char *match_token_type(TokenType type);
#endif
