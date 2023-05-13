#ifndef CONTAINERS_H
#define CONTAINERS_H

#define B_CONTAINER_BASE int size
#define B_CONTAINER_E_BASE struct object *object

#include "linkedList.h"

#define C_LISTS C_LINKED_LIST

#define initContainer(container) _Generic(container, C_LISTS)

#endif
