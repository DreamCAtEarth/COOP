#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define B_LINKED_LIST_NODE B_CONTAINER_E_BASE; struct linkedListNode *next
#define B_LINKED_LIST B_CONTAINER_BASE; struct linkedListNode *first;                               \
void (*addOnHead)(struct linkedList *list, struct linkedListNode *, struct object *object);         \
void (*delOnHead)(struct linkedList *list);                                                         \
void (*delOnNode)(struct linkedList *list, struct linkedListNode *node);                            \
struct linkedListNode *(*getNodeFromObject)(struct linkedList *list, struct object *object)

struct linkedListNode { B_LINKED_LIST_NODE; };

struct linkedList { B_LINKED_LIST; };

extern void initLinkedList(struct linkedList *list);
#define C_LINKED_LIST struct linkedList : initLinkedList

#endif
