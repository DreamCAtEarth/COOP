#include <stdio.h>
#include <stdlib.h>

#include "ObjectException.h"

void throwExceptionNotAllocatedClass(void)
{
    Interruption interruption =
    {
        .id = 4001,
        .name = "Class not allocated",
        .description = "The class of the object was not allocated properly or not allocated at all by the operating system."
    };
    /*catch*/
    {
        exit(interruption.id);
    }
}

void throwExceptionNotAllocatedInstance(void)
{
    Interruption interruption =
    {
        .id = 4002,
        .name = "Instance not allocated",
        .description = "The Instance of the object was not allocated properly or not allocated at all by the operating system."
    };
    /*catch*/
    {
        exit(interruption.id);
    }
}