#ifndef C_DS_QUEUE_H
#define C_DS_QUEUE_H

#include <stdlib.h>

#include "../doublely-linked-list/list.h"

/* 
* In this queue the head is considered last in the queue
* and the tail is first is the queue
* therefore adding to queue is adding to the head
* and popping off is removing from the tail
* thus Front() returns the tail and Back() returns the head
*/

typedef struct Queue {
  DoublelyLinkedList* data;
} Queue;

Queue* CreateQueue();
void DestroyQueue(Queue* q);

int QueueFront(Queue* q);
int QueueBack(Queue* q);

int QueuePop(Queue* q);
void QueueEnqueue(Queue* q, int val);

#endif 
