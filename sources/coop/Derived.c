#include <stddef.h>

#include "Derived.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define CLASS Derived
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(public, char *, publicAttribute) \
    ATTRIBUTE(public, int, alternativePublicAttribute) \
    ATTRIBUTE(package, char *, packageAttribute) \
    ATTRIBUTE(package, float, alternativePackageAttribute) \
    ATTRIBUTE(protected, char *, protectedAttribute) \
    ATTRIBUTE(protected, char, alternativeProtectedAttribute) \
    ATTRIBUTE(private, ENCAPSULATED, privateAttribute) \
    ATTRIBUTE(private, ENCAPSULATED, alternativePrivateAttribute)
#define CLASS_DESCRIPTOR \
    PARENT_METHOD_CD(public_static, coop.Object, void , setClassName, const char *) \
    PARENT_METHOD_CD(public_static, coop.Object, const char *, getClassName, ...) \
    PARENT_METHOD_ID(public, coop.Object, void , setPrivateAttribute, char *) \
    PARENT_METHOD_ID(public, coop.Object, void , setAlternativePrivateAttribute, double) \
    PARENT_METHOD_ID(public, coop.Object ,char *, getPrivateAttribute, ...) \
    PARENT_METHOD_ID(public, coop.Object, double, getAlternativePrivateAttribute, ...) \
    PARENT_METHOD_ID(public, coop.Object, void , setProtectedAttribute, char *) \
    PARENT_METHOD_ID(public, coop.Object, void , setAlternativeProtectedAttribute, char) \
    METHOD_ID(public, char *, getProtectedAttribute, ...) \
    PARENT_METHOD_ID(public, coop.Object, char, getAlternativeProtectedAttribute, ...) \
    ATTRIBUTE(private_method, ENCAPSULATED, aMethod) \
    ATTRIBUTE(private_static, ENCAPSULATED, className) \
    METHOD_CD(package_static, void, absCustom, ...) \
    METHOD_CD(protected_static, void, useCustom, ...)
#define CLASS_DEFINITION ddUKsuMN
#include "../objectModel.h"

static void manageOverloads(struct Derived *, struct CAT(CLASS_DEFINITION,_overloads) *);

struct CLASS_DEFINITION *(CLASS_DEFINITION)(struct CAT(CLASS_DEFINITION,_overloads) *args)
{
    if(!self)
    {
        (kGAzHwmx)(NULL);
        create();
    }
    if(args == NULL) return NULL;

    struct Derived *this = new(Derived);
    manageOverloads(this, args);
    this->class = self;

    return (struct CLASS_DEFINITION *) this;
}

static void create(void)
{
    self = new(Derived_);
    CLASS_DESCRIPTOR

    coop.Derived = self;
    coop.Derived->setClassName(self, __CLASS_NAME__);
}

static void manageOverloads(struct Derived *this, struct CAT(CLASS_DEFINITION,_overloads) *args)
{
    switch(args->options)
    {
        case CAT(CLASS_DEFINITION,_new_o1) :
            this->publicAttribute = args->new_o1.arg1;
            this->packageAttribute = args->new_o1.arg2;
            this->protectedAttribute = args->new_o1.arg3;
            break;
        case CAT(CLASS_DEFINITION,_new_o2) :
            this->alternativePublicAttribute = args->new_o2.arg1;
            this->alternativePackageAttribute = args->new_o2.arg2;
            this->alternativeProtectedAttribute = args->new_o2.arg3;
            break;
        default:
            args->new_ = args->new_;
            break;
    }
}

static void absCustom(struct Derived_ *self_, ...)
{
    if(self_){}
}

static void useCustom(struct Derived_ *self_, ...)
{
    if(self_){}
}

static char *getProtectedAttribute(struct Derived *this, ...)
{
    this->protectedAttribute = "p r o t e c t e d  a t t r i b u t e !";
    return this->protectedAttribute;
}
