#include <CUnit/Automated.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

static void test_simple_pass1(void) { CU_ASSERT_FATAL(1 == 1); }

int main() {
  // Intialize a registry.
  CU_initialize_registry();

  CU_pSuite suite = CU_add_suite("AST_TEST", 0, 0);
  CU_add_test(suite, "maxi_fun", test_simple_pass1);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
