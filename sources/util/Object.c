#include <stdlib.h>

#include "Object.h"

#define package_util_start
#include "util.h"

#define CLASS Object
#define INSTANCE_DESCRIPTOR \
    ATTRIBUTE(public, char *, publicAttribute) \
    ATTRIBUTE(public, int, alternativePublicAttribute) \
    ATTRIBUTE(package, char *, packageAttribute) \
    ATTRIBUTE(package, float, alternativePackageAttribute) \
    ATTRIBUTE(protected, char *, protectedAttribute) \
    ATTRIBUTE(protected, char, alternativeProtectedAttribute) \
    ATTRIBUTE(private, char *, privateAttribute) \
    ATTRIBUTE(private, double, alternativePrivateAttribute)
#define CLASS_DESCRIPTOR \
    METHOD_CD(public static, void , setClassName, const char *) \
    METHOD_CD(public static, const char *, getClassName, ...) \
    METHOD_ID(public, void , setPrivateAttribute, char *) \
    METHOD_ID(public, void , setAlternativePrivateAttribute, double) \
    METHOD_ID(public, char *, getPrivateAttribute, ...) \
    METHOD_ID(public, double, getAlternativePrivateAttribute, ...) \
    METHOD_ID(public, void , setProtectedAttribute, char *) \
    METHOD_ID(public, void , setAlternativeProtectedAttribute, char) \
    METHOD_ID(public, char *, getProtectedAttribute, ...) \
    METHOD_ID(public, char, getAlternativeProtectedAttribute, ...) \
    ATTRIBUTE(private static, const char *, className)
#define CLASS_DEFINITION KPLGWrfu
#include "../objectModel.h"

static void manageOverloads(struct Object *, struct KPLGWrfu_overloads *);

struct KPLGWrfu *KPLGWrfu_(struct KPLGWrfu_overloads *args)
{
    if(!self) create();
    if(args == NULL) return NULL;

    try(struct Object *this = malloc(sizeof(struct Object)))
    {
        struct Exception exception = goodAllocationObject(this);
        if(exception.severity != success) goto catch; else goto reprise;
    }
    catch(exception)
    {
        /* Affichage de l'erreur à l'utilisateur */
        exit(0);
    }
    reprise:

    manageOverloads(this, args);
    this->class = self;

    store_instance(this);
    return (struct KPLGWrfu *) this;
}

static void create(void)
{
    try(self = malloc(sizeof(struct Object_)))
    {
        struct Exception thrownException = goodAllocationClass(self);
        if(thrownException.severity != success) goto catch; else goto reprise;
    }
    catch(exception)
    {
        /* Affichage de l'erreur à l'utilisateur */
        exit(0);
    }
    reprise:
    CLASS_DESCRIPTOR
    self->className = __CLASS_NAME__;

    store_instance(self);
    util.Object = self;
}

static void manageOverloads(struct Object *this, struct KPLGWrfu_overloads *args)
{
    switch(args->options)
    {
        case KPLGWrfu_new_o1 :
            this->publicAttribute = args->overloads->new_o1.arg1;
            this->packageAttribute = args->overloads->new_o1.arg2;
            this->protectedAttribute = args->overloads->new_o1.arg3;
            this->privateAttribute = args->overloads->new_o1.arg4;
            break;
        case KPLGWrfu_new_o2 :
            this->alternativePublicAttribute = args->overloads->new_o2.arg1;
            this->alternativePackageAttribute = args->overloads->new_o2.arg2;
            this->alternativeProtectedAttribute = args->overloads->new_o2.arg3;
            this->alternativePrivateAttribute = args->overloads->new_o2.arg4;
            break;
        case KPLGWrfu_none :
            break;
        default:
            break;
    }
}

static void setPrivateAttribute(struct Object *this, char *string)
{
    this->privateAttribute = string;
}

static char *getPrivateAttribute(struct Object *this, ...)
{
    return this->privateAttribute;
}

static void setProtectedAttribute(struct Object *this, char *string)
{
    this->protectedAttribute = string;
}

static char *getProtectedAttribute(struct Object *this, ...)
{
    return this->protectedAttribute;
}

static void setClassName(struct Object_ *self_, const char *string)
{
    self_->className = string;
}

static const char *getClassName(struct Object_ *self_, ...)
{
    return self_->className;
}

static void setAlternativePrivateAttribute(struct Object *this, double floatingNumber)
{
    this->alternativePrivateAttribute = floatingNumber;
}

static double getAlternativePrivateAttribute(struct Object *this,...)
{
    return this->alternativePrivateAttribute;
}

static void setAlternativeProtectedAttribute(struct Object *this, char character)
{
    this->alternativeProtectedAttribute = character;
}

static char getAlternativeProtectedAttribute(struct Object *this, ...)
{
    return this->alternativeProtectedAttribute;
}
