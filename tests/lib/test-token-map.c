#include "../../lib/token-map.h"
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function type definition
typedef void (*token_test_fn_t)(token_map_t *map);

static void token_compose_fn_impl(token_test_fn_t fn) {
  token_map_t *map = create_token_map();
  fn(map);
  free_token_map(map);
}

static void test_create_token_map_impl(token_map_t* map) {
  CU_ASSERT_PTR_NOT_NULL(map);
  CU_ASSERT_EQUAL(token_map_capacity(map), 16);
  CU_ASSERT_EQUAL(token_map_size(map), 0);
}

static void test_get_token_map_impl(token_map_t* map) {
  Token *null_ptr = token_map_get(map, "nonexistent_key");
  CU_ASSERT_PTR_NULL(null_ptr);
  CU_ASSERT_EQUAL(token_map_capacity(map), 16);
  CU_ASSERT_EQUAL(token_map_size(map), 0);
}

static void test_set_token_map_impl(token_map_t* map) {
  Token* token = create_token(ASSIGNMENT, "<-", "",  1);
  CU_ASSERT_EQUAL(token_map_size(map), 0);
  CU_ASSERT_EQUAL(token_map_capacity(map), 16);
  token_map_put(map, "1", token);
  CU_ASSERT_EQUAL(token_map_size(map), 1);
  Token* token_acc = token_map_get(map, "1");
  CU_ASSERT_PTR_EQUAL(token_acc, token);
  Token* token2 = create_token(SEMICOLON, ";", "",  2);
  token_map_put(map, "2", token2);
  CU_ASSERT_EQUAL(token_map_size(map), 2);
  Token* token_acc_2 = token_map_get(map, "2");
  CU_ASSERT_PTR_EQUAL(token_acc_2, token2);
}

static void test_create_token_map(void) {
  token_compose_fn_impl(test_create_token_map_impl);
}

static void test_get_token_map(void) {
  token_compose_fn_impl(test_get_token_map_impl);
}

static void test_set_token_map(void) {
  token_compose_fn_impl(test_set_token_map_impl);
}

void run_token_map_tests(void) {
  CU_pSuite suite = CU_add_suite("Token Map Test Suites", 0, 0);
  CU_add_test(suite, "testing creating an empty token list.",
              test_create_token_map);
  CU_add_test(suite, "Testing getting token map.", test_get_token_map);
  CU_add_test(suite, "Testing setting the token map.", test_set_token_map);
}
