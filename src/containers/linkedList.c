#include <objectModel.h>

static void addOnHead(struct linkedList *list, struct linkedListNode *node, struct object *object);
static void delOnHead(struct linkedList *list);
static void delOnNode(struct linkedList *list, struct linkedListNode *node);
static struct linkedListNode *getNodeFromObject(struct linkedList *list, struct object *object);

void initLinkedList(struct linkedList *list)
{
    if(list->size < 0)
    {
        *list = (struct linkedList)
        {
            0,
            NULL,
            addOnHead,
            delOnHead,
            delOnNode,
            getNodeFromObject
        };
    }
}

static void addOnHead(struct linkedList *list, struct linkedListNode *node, struct object *object)
{
    *node = (struct linkedListNode)
    {
        object,
        list->first
    };
    list->first = node;
    list->size++;
}

static void delOnHead(struct linkedList *list)
{
    list->first = list->first->next;
    list->size--;
}

static void delOnNode(struct linkedList *list, struct linkedListNode *node)
{
    struct linkedListNode *nodePrevious;
    if(node == list->first)
        list->first = list->first->next;
    else
    {
        nodePrevious = list->first;
        while(nodePrevious->next != node)
            nodePrevious = nodePrevious->next;
        nodePrevious->next = node->next;
    }
    list->size--;
}

static struct linkedListNode *getNodeFromObject(struct linkedList *list, struct object *object)
{
    bool found = false;
    struct linkedListNode *node = list->first;
    while(node && !found)
    {
        if(node->object == object)
            found = true;
        else
            node = node->next;
    }
    return node;
}
