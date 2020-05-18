#define Square_family
#include "Square.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define PACKAGE_USER vlDzoKUd
#define CLASS Square
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID UQZwMHfN
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)

#define OBJECT_DESCRIPTOR           \
    ATTRIBUTE(private, int, length) \
    ATTRIBUTE(private, int, width)
#define CLASS_DESCRIPTOR            \
    METHOD_OD(public, int, area)
#include "../objectModel.h"

static void defaultConstructor(struct CLASS *);

size_t CAT(CLASS_PUBLIC_ID, _getSize)(struct SELF_PUBLIC_ID **that)
{
    if(!self)
    {
        PACKAGE_USER.CLASS = self = malloc(sizeof(struct SELF));
        *self = (struct SELF)
        {
            .area = area
        };
    #ifdef REFLEXIVITY
        reflex(&reflectInfos);
    #endif
    }
    if(that != NULL) *that = (struct SELF_PUBLIC_ID *) self;
    return sizeof(struct CLASS);
}

void (CLASS_PUBLIC_ID)(struct CLASS_PUBLIC_ID *this, void *args)
{
    defaultConstructor((struct CLASS *) this);
    (void)args;
}

void CAT(CLASS_PUBLIC_ID,_)(void)
{
    if(self) free(self);
    self = NULL;
}

static void defaultConstructor(struct CLASS * this)
{
    this->length = 4;
    this->width = 4;
    (void)this;
}

static int area(struct CLASS *this)
{
    return this->length * this->width;
}
