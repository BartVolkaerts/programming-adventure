#ifndef LLIST_H
#define LLIST_H

#include <stdlib.h>

typedef struct node
{
  struct node *prev;
  struct node *next;
  void* value;
} Node;

typedef void (*list_callback_fn)(void*);

Node* list_insert_after(Node *ref, void* value); 
Node * list_insert_before(Node *ref, void* value);
Node* list_get_node(Node *node, int index);
int list_count(Node *node);
Node* list_get_end(Node *node);
void list_remove(Node *node);
void list_print(Node *node);
void list_lfree(Node *node);
Node* list_copy(Node* node);
Node *list_deepcopy(Node* node, size_t size);
void list_callback(Node* node, list_callback_fn func);

#endif
