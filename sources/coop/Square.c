#include <stddef.h>

#include "Square.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define CLASS Square
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, int, length) \
    ATTRIBUTE(private, int, width)
#define CLASS_DESCRIPTOR \
    METHOD_ID(public, int , area, ...)
#define CLASS_DEFINITION UQZwMHfN
#include "../objectModel.h"

struct CLASS_DEFINITION *(CLASS_DEFINITION)(void *arg)
{
    if(!self) create();
    if(arg == NULL) return arg;

    struct Square *this = new(Square);
    this->length = 4;
    this->width = 4;
    this->class = self;

    return (struct CLASS_DEFINITION *) this;
}

static void create(void)
{
    self = new(Square_);
    CLASS_DESCRIPTOR

    coop.Square = self;
}

static int area(struct Square *this, ...)
{
    /*struct Object *object = new(Object);
    object->packageAttribute = "lol";
    object->alternativeProtectedAttribute = "lol";*/
    return this->length * this->width;
}

/*static float division(struct Square *this, int numerator, int divisor)
{
    this->width = numerator;
    this->length = divisor;
    return this->width / this->length;
}*/
