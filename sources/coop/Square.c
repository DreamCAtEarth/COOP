#include "Square.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define PACKAGE coop
#define CLASS Square
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID UQZwMHfN
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, int, length) \
    ATTRIBUTE(private, int, width)
#define CLASS_DESCRIPTOR \
    METHOD_OD(public, int , area, ...)
#include "../objectModel.h"

struct CLASS_PUBLIC_ID *(CLASS_PUBLIC_ID)(bool arg, bool lastLevelH, struct SELF_PUBLIC_ID *that)
{
    if(!that && !lastLevelH) that = new(SELF);
    create((struct SELF *) that);
    if(!arg) return (void *) that;

    struct CLASS *this = new(CLASS);
    this->length = 4;
    this->width = 4;

    return (struct CLASS_PUBLIC_ID *) this;
}

static void create(struct SELF *that)
{
    if(!self)
    {
        PACKAGE.CLASS = self = new(SELF);
        CLASS_DESCRIPTOR
    }
    if(that != NULL && that != NOTNULL)
    {
        that->area = area;
    }
    #ifdef REFLEXIVITY
        integrate_reflexivity(&reflectInfos);
    #endif
}

static int area(struct CLASS *this, ...)
{
    return this->length * this->width;
}
