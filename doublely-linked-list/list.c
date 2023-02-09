#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

/* Node Methods */

dll_node* CreateDLLNode(int val) {
  dll_node* n = malloc(sizeof(dll_node));
  n->value = val;
  n->next = NULL;
  n->previous = NULL;
  return n;
}

void DestroyDLLNode(dll_node* n) {
  free(n);
}

/* List Methods */

/* Create and Destroy */
DoublelyLinkedList* CreateEmptyDLL() {
  DoublelyLinkedList* l = malloc(sizeof(DoublelyLinkedList));
  l->size = 0;
  l->head = NULL;
  l->tail = NULL;
  return l;
}

DoublelyLinkedList* CreateDLL(dll_node* h) {
  DoublelyLinkedList* l = malloc(sizeof(DoublelyLinkedList));
  l->size = 1;
  l->head = h;
  l->tail = h;
  return l;
}

void DestroyDLL(DoublelyLinkedList *l) {
  dll_node* current = l->head;
  while (current != NULL) {
    dll_node* holder = current->next;
    DestroyDLLNode(current);
    current = holder;
  }
}

/* Access Methods */

dll_node* DLL_GetNode(DoublelyLinkedList* l, int pos) {
  if (pos < 0) {
    printf("Error: Nonnegative index.\n");
    return NULL;
  }
  if (pos >= l->size) {
    printf("Error: Out of range.");
    return NULL;
  }
  if (pos == 0) {
    return l->head;
  }
  if (pos == l->size - 1) {
    return l->tail;
  }

  int counter = 0;
  dll_node* current = l->head;

  for (int i = 0; current != NULL; i++) {
    if (i == pos) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void DLL_Print(DoublelyLinkedList *l) {
  dll_node* current = l->head;

  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }

  printf("\n");
}

/* Modifier Methods */
DoublelyLinkedList* DLL_AddToHead(DoublelyLinkedList* l, int val) {
  dll_node* new_node = CreateDLLNode(val);
  l->size++;
  if (l->head == NULL) {
    l->head = new_node;
    l->tail = new_node;
    return l;
  }
  new_node->next = l->head;
  l->head->previous = new_node;
  l->head = new_node;

  return l;
}

DoublelyLinkedList* DLL_AddToTail(DoublelyLinkedList* l, int val) {
  dll_node* new_node = CreateDLLNode(val);
  l->tail->next = new_node;
  new_node->previous = l->tail;
  l->tail = new_node;

  l->size++;

  return l;
}

DoublelyLinkedList* DLL_Insert(DoublelyLinkedList* l, int pos, int val) {
  if (pos < 0) {
    printf("Error: Negative index\n");
    return NULL;
  }
  if (pos >= l->size) {
    printf("Error: Out of range\n");
    return NULL;
  }
  if (pos == 0) {
    return DLL_AddToHead(l, val);
  }
  if (pos == l->size - 1) {
    return DLL_AddToTail(l, val);
  }

  dll_node* previous = DLL_GetNode(l, pos-1);
  dll_node* new_node = CreateDLLNode(val);

  new_node->next = previous->next;
  previous->next = new_node;
  new_node->previous = previous;

  l->size++;

  return l;
}

void DLL_DeleteTail(DoublelyLinkedList *l) {
  l->size--;
  dll_node* holder = l->tail->previous;
  DestroyDLLNode(l->tail);
  holder->next = NULL;
  l->tail = holder;
}

void DLL_DeleteHead(DoublelyLinkedList *l) {
  l->size--;
  dll_node* holder = l->head->next;
  DestroyDLLNode(l->head);
  l->head = holder;
}
