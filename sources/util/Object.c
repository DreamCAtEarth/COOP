#include <stdlib.h>

#define private_util_object_start
#include "Object.h"

#include "util.h"

#include "../objectModel.h"

static struct Object_ *self = NULL;

static struct Object *new(void);
static void setPrivateAttribute(char *,struct Object *);
static char *getPrivateAttribute(struct Object *);
static void setProtectedAttribute(char *,struct Object *);
static char *getProtectedAttribute(struct Object *);
static void setClassName(char *);
static char *getClassName();

void util_Object(void)
{
    self = (struct Object_ *)malloc(sizeof(struct Object_));
    self->Object = (struct util_Object_ *)malloc(sizeof(struct util_Object_));

    self->className = "Object B";

    util.Object = self->Object;
    util.newObject = (void *)new;

    util.Object->setPrivateAttribute = (void *)setPrivateAttribute;
    util.Object->getPrivateAttribute = (void *)getPrivateAttribute;
    util.Object->setProtectedAttribute = (void *)setProtectedAttribute;
    util.Object->getProtectedAttribute = (void *)getProtectedAttribute;
    util.Object->setClassName = (void *)setClassName;
    util.Object->getClassName = (void *)getClassName;

    storePointer(self->Object);
    storePointer(self);
}

static struct Object *new(void)
{
    struct Object *this = (struct Object *)malloc(sizeof(struct Object));
    this->Object = (struct util_Object *)this;

    this->Object->publicAttribute = "B public util";

    this->class = self;

    this->packageAttribute = "B package";
    this->protectedAttribute = "B protected";
    this->privateAttribute = "B private";

    storePointer(this);

    return this;
}

static void setPrivateAttribute(char *string, struct Object *this)
{
    this->privateAttribute = string;
}

static char *getPrivateAttribute(struct Object *this)
{
    return this->privateAttribute;
}

static void setProtectedAttribute(char *string, struct Object *this)
{
    this->protectedAttribute = string;
}

static char *getProtectedAttribute(struct Object *this)
{
    return this->protectedAttribute;
}

static void setClassName(char *string)
{
    self->className = string;
}

static char *getClassName()
{
    return self->className;
}