#ifndef QUEUEFUNC_H
#define QUEUEFUNC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int priority;
    struct Node* next;
} Node;

typedef struct PriorityQueue
{
    Node* head;
} PriorityQueue;

void init(PriorityQueue* queue);

void add(PriorityQueue* queue, int data, int priority);

Node* removeFirst(PriorityQueue* queue);

Node* removeWithPriority(PriorityQueue* queue, int priority);

Node* removeWithPriorityOrHigher(PriorityQueue* queue, int priority);

#endif