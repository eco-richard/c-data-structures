#include <stdio.h>

#include "singlely-linked-list/list.h"
#include "doublely-linked-list/list.h"
#include "queue/queue.h"

void SLL_TEST();
void DLL_TEST();
void Queue_TEST();

int main(int argc, char* argv[]) {

  // SLL_TEST();
  // DLL_TEST();
  Queue_TEST();

  return 0;
}

void SLL_TEST() {
  sll_node* n = CreateSLLNode(1);
  SinglelyLinkedList* l = CreateSLL(n);

  SLL_AddToHead(l, 2);
  SLL_Print(l);
  SLL_AddToTail(l, 3);
  SLL_Print(l);

  printf("Value at head: %d\n", SLL_GetNode(l, 0)->value);
  printf("Value at pos 1: %d\n", SLL_GetNode(l, 1)->value);

  DestroySLL(l);
}

void DLL_TEST() {
  dll_node* n = CreateDLLNode(1);
  DoublelyLinkedList* l = CreateDLL(n);
  DLL_AddToHead(l, 2);
  DLL_AddToHead(l, 3);
  DLL_AddToTail(l, 4);
  DLL_Print(l);

  DLL_DeleteHead(l);
  DLL_DeleteTail(l);
  DLL_Print(l);
}

void Queue_TEST() {
  Queue* q = CreateQueue();
  Enqueue(q, 1);
  Enqueue(q, 2);
  Enqueue(q, 3);

  printf("Front: %d\n", Front(q));
  printf("Back: %d\n", Back(q)); 

  while(q->data->size > 1) {
    printf("Popped: %d\n", Pop(q));
  }

  printf("Front: %d\n", Front(q));
  printf("Back: %d\n", Back(q)); 

}
