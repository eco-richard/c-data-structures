#ifndef C_DS_DOUBLELY_LINKED_LIST_H
#define C_DS_DOUBLELY_LINKED_LIST_H

#include <stdlib.h>

typedef struct dll_node {
  int value;
  struct dll_node* next;
  struct dll_node* previous;
} dll_node;

typedef struct {
  dll_node* head;
  dll_node* tail;
  size_t size;
} DoublelyLinkedList;

/* Node Methods */
dll_node* CreateDLLNode(int val);
void DestroyDLLNode(dll_node* n);

/* List Methods */

/* Create and Destroy */
DoublelyLinkedList* CreateEmptyDLL();
DoublelyLinkedList* CreateDLL(dll_node* h);
void DestroyDLL(DoublelyLinkedList* l);

/* Access Methods */
dll_node* DLL_GetNode(DoublelyLinkedList* l, int pos);
void DLL_Print(DoublelyLinkedList* l);

/* Modifier Methods */
DoublelyLinkedList* DLL_AddToHead(DoublelyLinkedList* l, int val);
DoublelyLinkedList* DLL_AddToTail(DoublelyLinkedList* l, int val);
DoublelyLinkedList* DLL_Insert(DoublelyLinkedList* l,int pos, int val);
void DLL_DeleteNode(DoublelyLinkedList* l, int pos);
void DLL_DeleteHead(DoublelyLinkedList* l);
void DLL_DeleteTail(DoublelyLinkedList* l);

#endif /* C_DS_DOUBLELY_LINKED_LIST_H */
