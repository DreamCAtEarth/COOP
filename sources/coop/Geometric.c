#include <stddef.h>

#include "Geometric.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define CLASS Geometric
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
    PARENT_METHOD_ID(public, coop.Derived, char *, getProtectedAttribute, ...) \
    PARENT_METHOD_ID(public, coop.Object, char, getAlternativeProtectedAttribute, ...) \
    ATTRIBUTE(private_method, ENCAPSULATED, aMethod) \
    ATTRIBUTE(private_static, ENCAPSULATED, className) \
    MIMR_CD(package_static, _Derived, coop.Derived, void, absCustom, ...) \
    MIMR_CD(protected_static, _Derived, coop.Derived, void, useCustom, ...) \
    MIMR_CD(package_static, _Another, coop.Another, void, absCustom, ...) \
    MIMR_CD(protected_static, _Another, coop.Another, void, useCustom, ...)
#define CLASS_DEFINITION YPnOLrQT
#include "../objectModel.h"

struct CLASS_DEFINITION *(CLASS_DEFINITION)(void *arg)
{
    if(!self)
    {
        (ddUKsuMN)(NULL);
        (lbdtYEkR)(NULL);
        create();
    }
    if(arg == NULL) return arg;

    struct Geometric *this = new(Geometric);
    this->protectedAttribute = "lol 2";
    this->packageAttribute = "salut 2";
    this->publicAttribute = "mdr !!";
    this->class = self;

    return (struct CLASS_DEFINITION *) this;
}

static void create(void)
{
    self = new(Geometric_);
    CLASS_DESCRIPTOR

    coop.Geometric = self;
    coop.Geometric->setClassName(self, __CLASS_NAME__);
}
