#define Square_family
#include "Square.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define PACKAGE_USER vlDzoKUd
#define CLASS Square
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID UQZwMHfN
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)

#define OBJECT_DESCRIPTOR               \
    ATTRIBUTE(private, int, length)     \
    ATTRIBUTE(private, int, width)
#define CLASS_DESCRIPTOR                \
    METHOD_OD(public, int, area)
#include "../objectModel.h"

size_t CAT(CLASS_PUBLIC_ID, _getSize)(struct SELF_PUBLIC_ID **that)
{
    if(!self)
    {
        try {
            PACKAGE_USER.CLASS = self = malloc(sizeof(struct SELF));
            allocationWellDone(&exception, self);
        }
        catch(badAllocationException)
        {
            printf("%s\n", exception.message);
			garbageCollector();
            exit(0);
        } endTry
        *self = (struct SELF)
        {
            .area = area
        };
        #ifdef REFLEXIVITY
        reflex(&reflectInfos);
        #endif
    }
    *that = (struct SELF_PUBLIC_ID *) self;
    return sizeof(struct CLASS);
}

void (CLASS_PUBLIC_ID)(struct CLASS_PUBLIC_ID *this_, void *args)
{
    struct CLASS * this = (struct CLASS *) this_;
    size_t numberOfElements = getLength(this);
    for(size_t i=0; i < numberOfElements; ++i)
    {
        (this+i)->length = 4;
        (this+i)->width = 4;
    }
    (void)args;
}

void CAT(CLASS_PUBLIC_ID,_)(void)
{
    if(self)
    {
        free(self);
        self = NULL;
    }
}

static int area(struct CLASS *this)
{
    return this->length * this->width;
}
