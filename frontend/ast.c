#include <stdlib.h>
#include "ast.h"

BIN_AST* create_bin_ast(AST_NODE* root) {
  BIN_AST* binary_ast = malloc(sizeof(BIN_AST));

  if (binary_ast != NULL) {
    binary_ast->node = root;
    binary_ast->left = NULL;
    binary_ast->right = NULL;
  }
  return binary_ast;
}

