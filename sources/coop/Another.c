#include <stddef.h>

#include "Another.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define CLASS Another
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
    PARENT_METHOD_ID(public, coop.Object, char *, getPrivateAttribute, ...) \
    PARENT_METHOD_ID(public, coop.Object, double, getAlternativePrivateAttribute, ...) \
    PARENT_METHOD_ID(public, coop.Object, void , setProtectedAttribute, char *) \
    PARENT_METHOD_ID(public, coop.Object, void , setAlternativeProtectedAttribute, char) \
    PARENT_METHOD_ID(public, coop.Object, char *, getProtectedAttribute, ...) \
    PARENT_METHOD_ID(public, coop.Object, char, getAlternativeProtectedAttribute, ...) \
    ATTRIBUTE(private_method, ENCAPSULATED, aMethod) \
    ATTRIBUTE(private_static, ENCAPSULATED, className) \
    METHOD_CD(package_static, void, absCustom, ...) \
    METHOD_CD(protected_static, void, useCustom, ...)
#define CLASS_DEFINITION lbdtYEkR
#include "../objectModel.h"

struct CLASS_DEFINITION *(CLASS_DEFINITION)(void *arg)
{
    if(!self)
    {
        (kGAzHwmx)(NULL);
        create();
    }
    if(arg == NULL) return arg;

    struct Another *this = new(Another);
    this->protectedAttribute = "lol 1";
    this->packageAttribute = "salut 1";
    this->publicAttribute = "mdr !";
    this->class = self;

    return (struct CLASS_DEFINITION *) this;
}

static void create(void)
{
    self = new(Another_);
    CLASS_DESCRIPTOR

    coop.Another = self;
    coop.Another->setClassName(self, __CLASS_NAME__);
}

static void absCustom(struct Another_ *self_, ...)
{
    if(self_){}
}

static void useCustom(struct Another_ *self_, ...)
{
    if(self_){}
}
