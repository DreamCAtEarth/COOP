#ifndef COOP_H
#define COOP_H

#include "Object.h"

struct coop
{
    struct coop_Object_ *Object;
    struct coop_Object *(* newObject)(void);
};

void newClassesFromCoop(void);

struct coop coop;

#define coop_OBJECT struct coop_Object *

//&(coop_Object_OverrideConstructor) { .sentinel = DEFAULT_VA_ARGS_VALUE, __VA_ARGS__ }

#endif //COOP_H
