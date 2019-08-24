#ifndef UTIL_H
#define UTIL_H

#include "Object.h"

struct util
{
    struct util_Object_ *Object;
    struct util_Object *(* newObject)(void);
};

void newClassesFromUtil(void);

struct util util;

#define util_OBJECT struct util_Object *

//&(coop_Object_OverrideConstructor) { .sentinel = DEFAULT_VA_ARGS_VALUE, __VA_ARGS__ }

#endif // UTIL_H
