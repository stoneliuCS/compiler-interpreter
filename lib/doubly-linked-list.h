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

// Creates a LinkedListNode pointer in memory. Callers must be responsible for freeing it.
LinkedListNode* create_node(LinkedListNode* previous, LinkedListNode* next, const char* val);

// Frees the LinkedListNode.
void free_node(LinkedListNode* head);

// Inserts the node to the desired zero-indexed position. Returns the head of the new list.
// The node will always be inserted behind the current index of the node in the original linked list.
LinkedListNode* insert_node_at_idx(LinkedListNode* head, LinkedListNode* node, const int idx);

// Finds the node at the given index (zero-indexed) in the list.
LinkedListNode* find_node_at_idx(LinkedListNode* head, const int idx);

// Deletes the node at the given (zero-indexed) index in the list.
// Returns the head of the new list.
LinkedListNode* delete_node_at_idx(LinkedListNode* head, const int idx);

// Pretty Prints the linked list head.
void pretty_print_node(LinkedListNode* head);

int get_length_node(LinkedListNode* head);

#endif

