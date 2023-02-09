#include <stdlib.h>
#include <stdio.h>

#include "list.h"

/* Node Methods */

sll_node* CreateSLLNode(int val) {
  sll_node* n = malloc(sizeof(sll_node));
  n->value = val;
  n->next = NULL;
  return n;
}

void DestroySLLNode(sll_node *n) {
  free(n);
}

/* List Methods */

/* Create and Destroy */
SinglelyLinkedList* CreateEmptySLL() {
  SinglelyLinkedList* l = malloc(sizeof(SinglelyLinkedList));
  return l;
}

SinglelyLinkedList* CreateSLL(sll_node* h) {
  SinglelyLinkedList* l = malloc(sizeof(SinglelyLinkedList));
  l->head = h;
  l->size = 1;
  return l;
}

void DestroySLL(SinglelyLinkedList *l) {
  sll_node* current = l->head;

  while (current != NULL) {
    sll_node* holder = (sll_node*)current->next;
    DestroySLLNode(current);
    current = holder;
  }

  free(l);
}

/* Access Methods  */
sll_node* SLL_GetNode(SinglelyLinkedList* l, int pos) {
  if (pos < 0) {
    printf("Error: Negative index\n");
    return NULL;
  }
  if (pos == 0) {
    return l->head;
  }
  if (pos >= l->size) {
    printf("Error: Out of range\n");
    return NULL;
  }

  int counter = 0;
  sll_node* current = l->head;

  while (current != NULL) {
    if (counter == pos) {
      return current;
    }
    current = (sll_node*)current->next;
    counter++;
  }

  return current;
}

void SLL_Print(SinglelyLinkedList *l) {
  sll_node* current = l->head;

  while (current != NULL) {
    printf("%d -> ", current->value);
    current = (sll_node*)current->next;
  }

  printf("\n");
}

/* Modifier Methods */
SinglelyLinkedList* SLL_AddToHead(SinglelyLinkedList* l, int val) {
  sll_node* new_node = CreateSLLNode(val);

  new_node->next = (struct sll_node*)l->head;
  l->head = new_node;

  l->size++;

  return l;
}

SinglelyLinkedList* SLL_AddToTail(SinglelyLinkedList* l, int val) {
  sll_node* new_node = CreateSLLNode(val);

  sll_node* tail = SLL_GetNode(l, l->size - 1);
  tail->next = (struct sll_node*)new_node;

  l->size++;

  return l;
}

SinglelyLinkedList* SLL_Insert(SinglelyLinkedList* l, int pos, int val) {
  if (pos < 0) {
    printf("Error: Negative index\n");
    return NULL;
  }
  if (pos >= l->size) {
    printf("Error: Out of range\n");
    return NULL;
  }
  if (pos == 0) {
    return SLL_AddToHead(l, val);
  }
  if (pos == l->size - 1) {
    return SLL_AddToTail(l, val);
  }

  sll_node* previous = SLL_GetNode(l, pos-1);
  sll_node* new_node = CreateSLLNode(val);

  new_node->next = previous->next;
  previous->next = (struct sll_node*)new_node;

  l->size++;

  return l;
}

void SLL_DeleteHead(SinglelyLinkedList* l) {
  sll_node* holder = l->head;
  l->head = (sll_node*)l->head->next;
  DestroySLLNode(holder);
  l->size--;
}

void SLL_DeleteTail(SinglelyLinkedList *l) {
  sll_node* holder = SLL_GetNode(l, l->size - 2);
  DestroySLLNode((sll_node*)holder->next);
  holder->next = NULL;
  l->size--;
}

void SLL_DeleteNode(SinglelyLinkedList *l, int pos) {
  sll_node* previous = SLL_GetNode(l, pos - 1);
  sll_node* current = (sll_node*)previous->next;
  sll_node* next = (sll_node*)current->next;

  previous->next = (struct sll_node*)next;
  DestroySLLNode(current);
  l->size--;
}
