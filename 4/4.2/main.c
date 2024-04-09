#include <stdio.h>
#include "queuefunc.h"

int main()
{
    PriorityQueue queue;
    init(&queue);

    add(&queue, 10, 1);
    add(&queue, 20, 3);
    add(&queue, 30, 2);
    add(&queue, 40, 5);

    printf("Удаляем первым: %d\n", removeFirst(&queue)->data);
    printf("Удаляем с приоритетом 3: %d\n", removeWithPriority(&queue, 3)->data);
    printf("Удаляем с приоритетом 2 или выше: %d\n", removeWithPriorityOrHigher(&queue, 2)->data);

    return 0;
}
