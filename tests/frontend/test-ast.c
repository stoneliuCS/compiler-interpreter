#include "../../frontend/ast.h"
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdlib.h>

static void test_create_ast(void) {
  AST_NODE node = {.type = AST_INTEGER, .val = '1'};
  AST_NODE *node_ptr = &node;
  BIN_AST *ast = create_bin_ast(node_ptr);
  ast->left = &(BIN_AST){.node = &(AST_NODE){.type = AST_INTEGER, .val = '2'},
                         .left = NULL,
                         .right = NULL};
  CU_ASSERT(ast != NULL);
  CU_ASSERT(ast->node->val == '1');
  CU_ASSERT(ast->left != NULL);
  CU_ASSERT(ast->right == NULL);
  free(ast);
}
