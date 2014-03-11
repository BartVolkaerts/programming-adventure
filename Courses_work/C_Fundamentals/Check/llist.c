#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>

typedef struct node
{
  struct node *prev;
  struct node *next;
  void* value;
} Node;

typedef void (*list_callback_fn)(void*);


Node* list_insert_after(Node *ref, void* value) 
{

  Node *n = (Node*)malloc(sizeof(Node));

  n->value = value;
  
  if(ref==NULL)
  {
    n->next = NULL;
    n->prev = NULL;
  }
  else
  {
    n->next = ref->next;
    n->prev = ref;
    ref->next = n;
    if(n->next != NULL)
      n->next->prev = n;
  }
  return n;
}

Node * list_insert_before(Node *ref, void* value)
{
  Node *n = (Node*)malloc(sizeof(Node));
  n->value = value;

  if(NULL == ref)
  {
    n->next = NULL;
    n->prev = NULL;
  }
  else
  {
    n->prev = ref->prev;
    ref->prev = n;
    n->next = ref;
    if(n->prev != NULL)
      n->prev->next = n;
  }
  return n;
}

Node* list_get_node(Node *node, int index)
{
  while(NULL != node->prev)
    node = node->prev;

  while(NULL != node && 0 != index)
  {
    node = node->next;
    index--;
  }

  return node;
}

int list_count(Node *node)
{
  if(NULL != node)
    node = list_get_node(node,0);
  int counter=0;
  while(node != NULL)
  {
    node = node->next;
    counter++;
  }
  return counter;
}

Node* list_get_end(Node *node)
{
  while(node->next != NULL)
  {
    node = node->next;
  }
  return node;
}

void list_remove(Node *node)
{
  if(node->prev != NULL)
    node->prev->next = node->next;
  if (node->next != NULL)
    node->next->prev = node->prev;

  free(node);
}

void list_print(Node *node)
{
  int i=0;
  node = list_get_node(node, 0);
  while(node != NULL)
  {
    printf("Value #%d = %d\n", i, *(int*)(node->value));
    i++;
    node = node->next;
  }
}

void list_lfree(Node *node)
{
  int i=0;
  node = list_get_node(node,0);
  Node* tmp;
  while(node!=NULL)
  {
    tmp = node;
    node = node->next;
    free(tmp);
    i++;
  }
  printf("I freed %d elements\n",i);
}

Node* list_copy(Node* node)
{
  Node* n = NULL;
  node = list_get_node(node,0);
  while(NULL != node)
  {
    n = list_insert_after(n,node->value);
    node=node->next;
  }
  return list_get_node(n,0);
}

Node *list_deepcopy(Node* node, size_t size)
{
  Node* n = NULL;
  node = list_get_node(node,0);
  while(NULL != node)
  {
    void *value = malloc(size);
    memcpy(value,node->value,size);
    n = list_insert_after(n,value);
    node = node->next;
  }

  return list_get_node(n,0);
}

void list_callback(Node* node, list_callback_fn func)
{
  node = list_get_node(node,0);
  while(NULL != node)
  {
    func(node->value);
    node = node->next;
  }
}

START_TEST(test_something)
{
  Node* node = NULL;
  ck_assert_ptr_ne(NULL,node);  
}
END_TEST

Suite* stack_suite()
{
  Suite* s = suite_create("Stack");
  TCase* core = tcase_create("Core");
  tcase_add_test(core, test_something); // <--
  suite_add_tcase(s, core);
  return s;
}

int main(int argc, char **argv)
{
  int number_failed;
  Suite *s = stack_suite (); // <--
  SRunner *sr = srunner_create (s);
  srunner_run_all (sr, CK_NORMAL);
  number_failed = srunner_ntests_failed (sr);
  srunner_free (sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
