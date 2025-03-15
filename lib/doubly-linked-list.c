#include "doubly-linked-list.h"
#include <assert.h>
#include <stdio.h>

void insert_node(LinkedListNode* list, LinkedListNode* node) {
  assert(list != NULL);
  assert(node != NULL);
  LinkedListNode* current = list;

  // Traverse the linked list until it reaches the end.
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = node;
  node->previous = current;
}


LinkedListNode* find_node(LinkedListNode* list, const int idx) {
  assert(list != NULL);

  int length = list_length(list);
  int counter = 0;

  LinkedListNode* current = list; 

  while (current->next != NULL && counter < idx) {
    current = current->next;
    counter = counter + 1;
  }
  return current;
}

int list_length(LinkedListNode *list) {
  assert(list != NULL);
  LinkedListNode* current = list;
  int len = 1; // To account for the fact that LinkedListNode is already a node.
  while (current->next != NULL) {
    current = current->next;
    len = len + 1;
  }
  return len;
}
