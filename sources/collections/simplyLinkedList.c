#include "simplyLinkedList.h"

void addOnHead(struct simplyLinkedList *list, void *object)
{
    struct simplyLinkedListNode *node = malloc(sizeof(struct simplyLinkedListNode));
    assert(node);
    node->object = object;
    node->next = list->first;
    list->first = node;
    list->size++;
}

void deleteOnHead(struct simplyLinkedList *list, void *node)
{
    if(node != list->first) node = list->first;
    list->first = list->first->next;
    free(node);
    list->size--;
}
