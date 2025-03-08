#ifndef AST_H

#define AST_H

enum AST_TYPE { AST_INTEGER, AST_ADD };

typedef struct AST_NODE {
  enum AST_TYPE type;
  char val;
} AST_NODE;

typedef struct BIN_AST {
  struct AST_NODE* node;
  struct BIN_AST* left;
  struct BIN_AST* right;
} BIN_AST;

// Create a Binary AST
BIN_AST *create_bin_ast(AST_NODE* root);

#endif
