#include "../../lib/doubly-linked-list.h"
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Returns a doubly linked list of exactly size 3.
static LinkedListNode* construct_basic_linked_list(void) {
  LinkedListNode* n1 = create_node(NULL, NULL, "1");
  LinkedListNode* n2 = create_node(NULL, NULL, "2");
  LinkedListNode* n3 = create_node(NULL, NULL, "3");
  LinkedListNode* head = insert_node_at_idx(n3, n2, 0);
  head = insert_node_at_idx(head, n1, 0);
  assert(get_length_node(head) == 3);
  return head;
}

static void test_insert_node_at_idx(void) {
  LinkedListNode* n1 = create_node(NULL, NULL, "1");
  LinkedListNode* n2 = create_node(NULL, NULL, "2");
  LinkedListNode* n3 = create_node(NULL, NULL, "3");
  LinkedListNode* head = insert_node_at_idx(n1, n2, 0);
  CU_ASSERT(get_length_node(head) == 2);
  CU_ASSERT_PTR_EQUAL(n2, find_node_at_idx(head, 0));
  CU_ASSERT_PTR_EQUAL(n1, find_node_at_idx(head, 1));
  head = insert_node_at_idx(head, n3, 1);
  CU_ASSERT_PTR_EQUAL(n3, find_node_at_idx(head, 1));
  CU_ASSERT_PTR_EQUAL(n1, find_node_at_idx(head, 2));
  CU_ASSERT_PTR_EQUAL(n2, find_node_at_idx(head, 0));
  free(n1);
  free(n2);
  free(n3);
}

static void test_get_linked_list_idx(void) {
  LinkedListNode* head = construct_basic_linked_list();
  LinkedListNode* n1 = find_node_at_idx(head, 0);
  LinkedListNode* n2 = find_node_at_idx(head, 1);
  LinkedListNode* n3 = find_node_at_idx(head, 2);
  CU_ASSERT(n1 != NULL);
  CU_ASSERT(n2 != NULL);
  CU_ASSERT(n3 != NULL);
  CU_ASSERT_TRUE(strcmp(n1->val, "1") == 0);
  CU_ASSERT_TRUE(strcmp(n2->val, "2") == 0);
  CU_ASSERT_TRUE(strcmp(n3->val, "3") == 0);
  free(n1);
  free(n2);
  free(n3);
}

void run_double_linked_list_tests(void) {
  CU_pSuite suite = CU_add_suite("Doubly Linked List Tests", 0, 0);
  CU_add_test(suite, "testing geting linked list at idx", test_get_linked_list_idx);
  CU_add_test(suite, "testing inserting node at idx.", test_insert_node_at_idx);
}
