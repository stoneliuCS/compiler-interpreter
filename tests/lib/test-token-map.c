#include "../../lib/token-map.h"
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void test_create_token_map(void) {
  token_map_t* map = create_token_map();
  CU_ASSERT_PTR_NOT_NULL(map);
  CU_ASSERT_EQUAL(token_map_capacity(map), 16);
  CU_ASSERT_EQUAL(token_map_size(map), 0);
  free_token_map(map);
}

void run_token_map_tests(void) {
  CU_pSuite suite = CU_add_suite("Token Map Test Suites", 0, 0);
  CU_add_test(suite, "testing creating an empty token list.", test_create_token_map);
}
