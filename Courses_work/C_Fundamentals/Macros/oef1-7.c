#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  struct node *prev;
  struct node *next;
  int value;
} Node;

Node* list_insert_after(Node *ref) 
{
  Node *n = (Node*)malloc(sizeof(Node));
  n->next = NULL;
  n->prev = NULL;
  n->value = 1;
  
  if(ref==NULL)
    return n; //Head of the newborn list

  n->next = ref->next;
  n->prev = ref;
  ref->next = n;
  if(n->next != NULL)
    n->next->prev = n;

  Node *temp = n;
  while(temp != NULL)
  {
    temp->value = temp->prev->value + 1;
    temp = temp->next;
  }

  return n;
}

Node * list_insert_before(Node *ref)
{
  if(ref == NULL)
  {
    printf("Can not insert node before 0\nReturning..\n");
    return ref;
  }
  Node *n = (Node*)malloc(sizeof(Node));
  n->prev = ref->prev;
  ref->prev = n;
  n->next = ref;
  n->prev->next = n;

  return n;
}

int list_count(Node *head)
{
  int counter=0;
  while(head != NULL)
  {
    head = head->next;
    counter++;
  }
  return counter;
}

Node* list_get_node(Node *head, int index)
{
  for(int i = 0; i < index; i++)
  {
    head = head->next;
  }
  return head;
}

Node* list_get_end(Node *node)
{
  while(node->next != NULL)
  {
    node = node->next;
  }
  return node;
}

void list_remove(Node *head, int index)
{
  for(int i = 0; i < index; i++)
  {
    head = head->next;
  }
}

void list_print(Node* head)
{
  int i=1;
  while(head != NULL)
  {
    printf("Value #%d = %d\n", i, head->value);
    i++;
    head = head->next;
  }
}

void list_free(Node * head)
{
  int i=0;
  Node* tmp;
  while(head!=NULL)
  {
    tmp = head;
    head = head->next;
    free(tmp);
    i++;
  }
  printf("I freed %d elements\n",i);
}


int main(int argc, char *argv[])
{
  Node *head, *node;
  head = list_insert_after(NULL);
  node = list_insert_after(head);
  node = list_insert_after(node);
  node = list_insert_before(head);

  list_print(head);

  list_free(head);
  return 0;
}
