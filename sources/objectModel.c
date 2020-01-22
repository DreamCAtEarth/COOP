#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "objectModel.h"

static struct list
{
    struct entity *first;
    int size;
}list = {.first = NULL, .size = 0};

static void print_buffer(unsigned char *buffer, size_t size);
static size_t pack(void *class, unsigned char *buffer);
static size_t unpack(unsigned char *buffer, void *class);
static void print_all(void *class);

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
    list.first->reflexivity = (struct class)
    {
         elementsToReflect->name,
         elementsToReflect->num_objects,
         elementsToReflect->num_attributes,
         elementsToReflect->num_methods,
         elementsToReflect->unpacked_size,
         elementsToReflect->packed_size,
         elementsToReflect->offsets,
         elementsToReflect->sizes,
         elementsToReflect->names
    };
    list.first->print_buffer = print_buffer;
    list.first->pack = pack;
    list.first->unpack = unpack;
    list.first->print_all = print_all;
}

static void print_buffer(unsigned char *buffer, size_t size)
{
    for (size_t j = 0; j < size; j++)
        printf(" %02x", buffer[j]);
}

static size_t pack(void *class, unsigned char *buffer)
{
    size_t pos = 0, num_members = list.first->reflexivity.num_attributes + list.first->reflexivity.num_methods;
    for (size_t i = 0; i < num_members; i++)
    {
        memcpy(buffer+pos, ((unsigned char*)class)+list.first->reflexivity.offsets[i], list.first->reflexivity.sizes[i]);
        pos += list.first->reflexivity.sizes[i];
    }
    return pos;
}

static size_t unpack(unsigned char *buffer, void *class)
{
    size_t pos = 0, num_members = list.first->reflexivity.num_attributes + list.first->reflexivity.num_methods;
    for (size_t i = 0; i < num_members; i++)
    {
        memcpy(((unsigned char*)class)+list.first->reflexivity.offsets[i], buffer+pos, list.first->reflexivity.sizes[i]);
        pos += list.first->reflexivity.sizes[i];
    }
    return pos;
}

static void print_all(void *class)
{
    size_t num_members = list.first->reflexivity.num_attributes + list.first->reflexivity.num_methods;
    printf("%s:\n", list.first->reflexivity.name);
    for (size_t i = 0; i < num_members; i++)
    {
        printf("\t%s: %zu %zu =", list.first->reflexivity.names[i], list.first->reflexivity.offsets[i], list.first->reflexivity.sizes[i]);
        print_buffer(((unsigned char*)class)+list.first->reflexivity.offsets[i], list.first->reflexivity.sizes[i]);
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
