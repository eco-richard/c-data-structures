#include <stdlib.h>

#include "queue.h"

Queue* CreateQueue() {
  Queue* q = malloc(sizeof(Queue));
  q->data = CreateEmptyDLL();
  return q;
}

void DestroyQueue(Queue* q) {
  DestroyDLL(q->data);
  free(q);
}

int QueueFront(Queue* q) {
  return DLL_GetNode(q->data, q->data->size - 1)->value;
}

int QueueBack(Queue* q) {
  return DLL_GetNode(q->data, 0)->value;
}

int QueuePop(Queue* q) {
  int value = q->data->tail->value;
  DLL_DeleteTail(q->data);
  return value;
}

void QueueEnqueue(Queue* q, int val) {
  DLL_AddToHead(q->data, val);
}
