#ifndef C_DS_SINGLELY_LINKED_LIST_H
#define C_DS_SINGLELY_LINKED_LIST_H

#include <stdlib.h>

typedef struct sll_node {
  int value;
  struct sll_node* next;
} sll_node;

typedef struct {
  sll_node* head;
  size_t size;
} SinglelyLinkedList;

/* Node Methods */

sll_node* CreateSLLNode(int val);
void DestroySLLNode(sll_node* n);

/* List Methods */

/* Create and Destroy */
SinglelyLinkedList* CreateEmptySLL();
SinglelyLinkedList* CreateSLL(sll_node* h);
void DestroySLL(SinglelyLinkedList* l);

/* Access Methods */
sll_node* SLL_GetNode(SinglelyLinkedList* l, int pos);
void SLL_Print(SinglelyLinkedList* l);

/* Modifier Methods */
SinglelyLinkedList* SLL_AddToHead(SinglelyLinkedList* l, int val);
SinglelyLinkedList* SLL_AddToTail(SinglelyLinkedList* l, int val);
SinglelyLinkedList* SLL_Insert(SinglelyLinkedList* l, int pos, int val);
void SLL_DeleteNode(SinglelyLinkedList* l, int pos);
void SLL_DeleteHead(SinglelyLinkedList* l);
void SLL_DeleteTail(SinglelyLinkedList* l);

#endif /* C_DS_SINGLELY_LINKED_LIST_H */
