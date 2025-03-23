#ifndef TOKEN

#define TOKEN
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
  ASSIGNMENT
} TokenType;

// A Token is a structured data which knows its type, the lexeme, the literal value, and a line number.
typedef struct Token {
  const TokenType type;
  const char* lexeme;
  const void* literal;
  const int line;
} Token;

#endif
