#include "../../frontend/ast.h"
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

static void test_create_ast(void) {
  BIN_AST *ast = create_bin_ast(&(AST_NODE){ 
    .type = AST_INTEGER,
    .val = '1'
  });
  CU_ASSERT(ast != NULL);
  CU_ASSERT(ast->node->val == '1');
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
