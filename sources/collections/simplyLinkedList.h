#ifndef SIMPLY_CHAINED_LIST_H
#define SIMPLY_CHAINED_LIST_H

#include <stdlib.h>
#include <assert.h>

struct simplyLinkedListNode
{
    struct object *object;
    struct simplyLinkedListNode *next;
};

struct simplyLinkedList
{
    struct simplyLinkedListNode *first;
    int size;
};

void addOnHead(struct simplyLinkedList *list, void *object);
void deleteOnHead(struct simplyLinkedList *list, void *node);

#endif //SIMPLY_CHAINED_LIST_H
