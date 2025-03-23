#include "./lib/test-doubly-linked-list.c"
#include "./lib/test-token.c"
#include "CUnit/CUError.h"
#include "CUnit/TestDB.h"
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

static void run_those_tests() {
  run_double_linked_list_tests();
  run_token_tests();
}

int main() {
  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }
  run_those_tests();
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
