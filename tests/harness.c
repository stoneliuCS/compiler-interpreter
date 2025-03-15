#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "./lib/test-doubly-linked-list.c"
#include "./frontend/test-ast.c"

static void double_linked_list_tests(void) {
  CU_pSuite suite = CU_add_suite("Test Double Linked List", 0, 0);
  CU_add_test(suite, "test_insert_linked_list_node", test_insert_linked_list_node);
}

static void ast_tests(void) {
  CU_pSuite suite = CU_add_suite("Test Abstract Syntax Tests.", 0, 0);
  CU_add_test(suite, "test_create_ast", test_create_ast);
}

static void run_those_tests() {
  CU_basic_set_mode(CU_BRM_VERBOSE);
  // TEST_SUITES
  double_linked_list_tests();
  ast_tests();
  CU_basic_run_tests();
}

int main() {
  CU_initialize_registry();
  run_those_tests();
  CU_cleanup_registry();
  return 0;
}
