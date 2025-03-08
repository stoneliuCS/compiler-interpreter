#include "ast.h"
#include <stdlib.h>

AST* create_ast(AST ast) {
  AST* ast_ptr = malloc(sizeof(AST));
  if (ast_ptr) {
    *ast_ptr = ast;
  } 
  return ast_ptr;
} 
