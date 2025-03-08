#ifndef AST_H

#define AST_H

typedef struct AST AST;

// A AST (Abstract Syntax Tree) is one of:
// INTEGER 
// ADD_OP
// ADD_MUL
struct AST {
  // A Node is one of:
  // Integer
  // Addition (+)
  // Multiplication (*)
  enum { INTEGER, ADD_OP, MUL_OP } node;

  union {

    struct INTEGER {
      int number;
    } INTEGER;

    struct ADD_OP {
      AST *left; AST *right;
    } ADD_OP;

    struct ADD_MUL {
      AST *left; AST *right;
    } ADD_MUL;

  } expr;

};

// Creates an an empty AST.
AST* create_ast(AST ast);

#endif
