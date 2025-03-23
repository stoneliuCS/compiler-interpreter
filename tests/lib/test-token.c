#include "../../lib/token.h"
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void test_create_token_list(void) {
  token_list_t* list = create_token_list(10);
  CU_ASSERT_PTR_NOT_NULL(list);
  free_token_list(list);
}

void run_token_tests(void) {
  CU_pSuite suite = CU_add_suite("Token Test Suites", 0, 0);
  CU_add_test(suite, "testing creating an empty token list.", test_create_token_list);
}
