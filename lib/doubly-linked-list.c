#include "doubly-linked-list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static LinkedListNode *find_node_at_idx_impl(LinkedListNode *head,
                                             const int idx) {
  int counter = 0;
  LinkedListNode *current = head;

  while (current->next != NULL && counter < idx) {
    current = current->next;
    counter = counter + 1;
  }

  return current;
}

// Given a doubly-linked-list node, walks back to the head of the list.
static LinkedListNode *walk_back(LinkedListNode *node) {
  LinkedListNode *current = node;
  while (current->previous != NULL) {
    current = current->previous;
  }
  return current;
}

static LinkedListNode *insert_node_at_idx_impl(LinkedListNode *head,
                                               LinkedListNode *node,
                                               const int idx) {
  int counter = 0;
  LinkedListNode *current = head;
  while (current->next != NULL && counter < idx) {
    current = current->next;
    counter = counter + 1;
  }
  assert(current != NULL);
  // We always insert the node to be before the current.
  if (current->previous != NULL) {
    current->previous->next = node;
    node->previous = current->previous;
  }
  node->next = current;
  current->previous = node;
  return walk_back(current);
}

LinkedListNode *create_node(LinkedListNode *previous, LinkedListNode *next,
                            const char *val) {
  LinkedListNode *node = malloc(sizeof(LinkedListNode));
  node->previous = previous;
  node->next = next;
  node->val = val;
  return node;
}

void free_node(LinkedListNode *head) {
  LinkedListNode *current = head;
  while (current->next != NULL) {
    free(current);
    current = current->next;
  }
}

void pretty_print_node(LinkedListNode *head) {
  assert(head != NULL);
  LinkedListNode *current = head;
  printf("NULL");
  printf(" <=> ");
  while (current != NULL) {
    printf("%s", current->val);
    printf(" <=> ");
    current = current->next;
  }
  printf("NULL");
}

int get_length_node(LinkedListNode *head) {
  assert(head != NULL);
  LinkedListNode *current = head;
  int length = 0;
  while (current != NULL) {
    current = current->next;
    length += 1;
  }
  return length;
}

LinkedListNode *find_node_at_idx(LinkedListNode *head, const int idx) {
  assert(head != NULL);
  assert(idx < get_length_node(head));
  return find_node_at_idx_impl(head, idx);
}

LinkedListNode *insert_node_at_idx(LinkedListNode *head, LinkedListNode *node,
                                   const int idx) {
  assert(head != NULL && "Head pointer cannot be null.");
  assert(node != NULL && "Node to be inserted cannot be null.");
  assert(idx < get_length_node(head) &&
         "Cannot insert a node if the idx is greater the"
         "length of the list.");
  return insert_node_at_idx_impl(head, node, idx);
}
