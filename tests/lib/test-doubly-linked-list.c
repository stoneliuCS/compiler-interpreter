#include "../../lib/doubly-linked-list.h"
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdlib.h>

static LinkedListNode* createLinkedList(void);

static void test_insert_linked_list_node(void) {
  LinkedListNode beginning = {NULL, NULL, "stone"};
  LinkedListNode end = {NULL, NULL, "stone2"};
  insert_node(&beginning, &end);
  // Assert that the node inserted is not null.
  CU_ASSERT_PTR_NOT_NULL(beginning.next);
  // // Assert that nothing has been added to the beginning of the list.
  CU_ASSERT_PTR_NULL(beginning.previous);
  LinkedListNode* beginning_ptr = &beginning;
  LinkedListNode* end_ptr = &end;
  // // Assert that the end of the beginning ptr is the same as the end.
  CU_ASSERT_EQUAL(beginning_ptr->next, end_ptr);
  CU_ASSERT_EQUAL(end_ptr->previous, beginning_ptr);
  CU_ASSERT_EQUAL(list_length(&beginning), 2);

  // Lets get a little crazy and attach another linked list onto it.
  LinkedListNode* list = createLinkedList();
  // insert_node(&beginning,  list);
  CU_ASSERT_EQUAL(list_length(list), 3);
}

static LinkedListNode* createLinkedList(void) {
  // Lets try adding more
  LinkedListNode n1 = { NULL, NULL, "1"};
  LinkedListNode n2 = { NULL, NULL, "1"};
  LinkedListNode n3 = { NULL, NULL, "1"};
  insert_node(&n1, &n2);
  insert_node(&n1, &n3);
  LinkedListNode* list = &n1;
  return list;
}
