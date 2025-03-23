#include "../../lib/token.h"
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static void test_create_token_list(void) {
  token_list_t* list = create_token_list(10);
  CU_ASSERT_PTR_NOT_NULL(list);
  CU_ASSERT_EQUAL(get_token_list_capacity(list), 10);
  CU_ASSERT_EQUAL(get_token_current_size(list), 0);
  free_token_list(list);
}

static void test_append(void) {
  token_list_t* list = create_token_list(10);
  Token t1 = { ASSIGNMENT, "<-", NULL, 0 };
  CU_ASSERT_EQUAL(get_token_list_capacity(list), 10);
  CU_ASSERT_EQUAL(get_token_current_size(list), 0);
  append_to_token_list(list, t1);
  CU_ASSERT_EQUAL(get_token_list_capacity(list), 10);
  CU_ASSERT_EQUAL(get_token_current_size(list), 1);
  free_token_list(list);
}

void run_token_tests(void) {
  CU_pSuite suite = CU_add_suite("Token Test Suites", 0, 0);
  CU_add_test(suite, "testing creating an empty token list.", test_create_token_list);
  CU_add_test(suite, "testing appending to a token list.", test_append);
}
