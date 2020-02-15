#include "objectModel.h"

static struct list list = {.first = NULL, .size = 0};

static void print_buffer(unsigned char *, size_t);
static size_t pack(void *, unsigned char *, struct class *);
static size_t unpack(unsigned char *, void *, struct class *);
static void print_all(void *, struct class *);

void *(new)(size_t size)
{
    try(struct entity *entity = malloc(sizeof(struct entity)))
    try(void *instance = malloc(size))
    {
        struct Exception exception1 = goodAllocation(entity);
        struct Exception exception2 = goodAllocation(instance);
        if(exception1.severity != success || exception2.severity != success) goto catch;
        else goto reprise;
    }
    catch:
    exit(0);

    reprise:
    entity->instance = instance;
    entity->next = list.first;
    list.first = entity;
    list.size++;

    return instance;
}

void *(new_)(size_t size)
{
    try(void *primitive = malloc(size))
    {
        struct Exception exception = goodAllocation(primitive);
        if(exception.severity != success) goto catch;
        else return primitive;
    }
    catch:
    exit(0);
}

void integrate_reflexivity(struct class *elementsToReflect)
{
    elementsToReflect->print_buffer = print_buffer;
    elementsToReflect->pack = pack;
    elementsToReflect->unpack = unpack;
    elementsToReflect->print_all = print_all;
}

static void print_buffer(unsigned char *buffer, size_t size)
{
    for (size_t j = 0; j < size; j++)
        printf(" %02x", buffer[j]);
}

static size_t pack(void *class, unsigned char *buffer, struct class *elementsToReflect)
{
    size_t pos = 0, num_members = elementsToReflect->num_attributes + elementsToReflect->num_methods;
    for (size_t i = 0; i < num_members; i++)
    {
        memcpy(buffer+pos, ((unsigned char*)class)+elementsToReflect->offsets[i], elementsToReflect->sizes[i]);
        pos += elementsToReflect->sizes[i];
    }
    return pos;
}

static size_t unpack(unsigned char *buffer, void *class, struct class *elementsToReflect)
{
    size_t pos = 0, num_members = elementsToReflect->num_attributes + elementsToReflect->num_methods;
    for (size_t i = 0; i < num_members; i++)
    {
        memcpy(((unsigned char*)class)+elementsToReflect->offsets[i], buffer+pos, elementsToReflect->sizes[i]);
        pos += elementsToReflect->sizes[i];
    }
    return pos;
}

static void print_all(void *class, struct class *elementsToReflect)
{
    size_t num_members = elementsToReflect->num_attributes + elementsToReflect->num_methods;
    printf("%s:\n", elementsToReflect->name);
    for (size_t i = 0; i < num_members; i++)
    {
        // %I64u for minGW using unsigned int of 64 bits
        // %zu or %llu for gcc in a real linux machine
        //printf("\t%s: %I64u %I64u =", elementsToReflect->names[i], elementsToReflect->offsets[i], elementsToReflect->sizes[i]);
        print_buffer(((unsigned char*)class)+elementsToReflect->offsets[i], elementsToReflect->sizes[i]);
        printf("\n");
    }
}

void garbage_collector(void)
{
    while(list.first != NULL)
    {
        struct entity *toDel = list.first;
        free(toDel->instance);
        list.first = list.first->next;
        free(toDel);
        list.size--;
    }
}
