#include <stdlib.h>

#ifndef DOUBLY_LINKED_LIST_H

#define DOUBLY_LINKED_LIST_H

// A LinkedListNode is a 
// struct LinkedListNode { LinkedListNode, LinkedListNode, char* }
// Interpretation, LinkedListNode contains pointers to both the previous and next.
typedef struct LinkedListNode {
  struct LinkedListNode* previous;
  struct LinkedListNode* next;
  const char* val;
} LinkedListNode;

// Inserts the node at the back of the list.
// Mutates the underlying list to point the last node to the given node.
void insert_node(LinkedListNode* list, LinkedListNode* node);

// Finds the node at the given index in the list.
void find_node(LinkedListNode* list, const int idx);

// Deletes the node at the given index in the list.
void delete_node(LinkedListNode* list, const int idx);

// Returns the length of that linked list.
int list_length(LinkedListNode* list);

#endif

