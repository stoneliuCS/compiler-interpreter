#include "../../frontend/ast.h"
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

static void test_create_ast(void) {
  AST_NODE node = {
    .type = AST_INTEGER,
    .val = '1'
  };
  AST_NODE* node_ptr = &node;
  BIN_AST *ast = create_bin_ast(node_ptr);
  ast->left = &(BIN_AST){
    .node = &(AST_NODE){
      .type = AST_INTEGER,
      .val = '2'
    },
    .left = NULL,
    .right = NULL
  };
  CU_ASSERT(ast != NULL);
  CU_ASSERT(ast->node->val == '1');
  CU_ASSERT(ast->left != NULL);
  CU_ASSERT(ast->right == NULL);
}

static void test_simple_pass1(void) { CU_ASSERT_FATAL(1 == 1); }

int main() {
  // Intialize a registry.
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("AST_TEST", 0, 0);
  CU_add_test(suite, "AST_EXAMPLE_TEST", test_create_ast);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
