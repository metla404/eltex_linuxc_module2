#include <stdio.h>
#include "queuefunc.h"

void init(PriorityQueue* queue)
{
    queue->head = NULL;
}

void add(PriorityQueue* queue, int data, int priority)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (queue->head == NULL || priority < queue->head->priority)
    {
        newNode->next = queue->head;
        queue->head = newNode;
    }
    else
    {
        Node* current = queue->head;
        while (current->next != NULL && current->next->priority <= priority)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}

Node* removeFirst(PriorityQueue* queue)
{
    if (queue->head == NULL)
        return NULL;

    Node* temp = queue->head;
    queue->head = queue->head->next;
    temp->next = NULL;
    return temp;
}

Node* removeWithPriority(PriorityQueue* queue, int priority)
{
    if (queue->head == NULL)
        return NULL;

    if (queue->head->priority == priority)
        return removeFirst(queue);

    Node* current = queue->head;
    while (current->next != NULL && current->next->priority != priority)
        current = current->next;

    if (current->next == NULL)
        return NULL;

    Node* temp = current->next;
    current->next = current->next->next;
    temp->next = NULL;
    return temp;
}

Node* removeWithPriorityOrHigher(PriorityQueue* queue, int priority)
{
    if (queue->head == NULL)
        return NULL;

    if (queue->head->priority >= priority)
        return removeFirst(queue);

    Node* current = queue->head;
    while (current->next != NULL && current->next->priority < priority)
        current = current->next;

    if (current->next == NULL)
        return NULL;

    Node* temp = current->next;
    current->next = current->next->next;
    temp->next = NULL;
    return temp;
}
