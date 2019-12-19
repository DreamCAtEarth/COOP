#include <stdlib.h>

#include "Geometric.h"

#define package_coop_start
#include "coop.h"

#define CLASS Geometric
#define INSTANCE_DESCRIPTOR \
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
    ATTRIBUTE(private_static, ENCAPSULATED, className) \
    MIMR_CD(package_static, _Derived, coop.Derived, void, absCustom, ...) \
    MIMR_CD(protected_static, _Derived, coop.Derived, void, useCustom, ...) \
    MIMR_CD(package_static, _Another, coop.Another, void, absCustom, ...) \
    MIMR_CD(protected_static, _Another, coop.Another, void, useCustom, ...)
#define CLASS_DEFINITION YPnOLrQT
#include "../objectModel.h"

struct YPnOLrQT *YPnOLrQT_(void *arg)
{
    if(!self)
    {
        /* héritage multiple */
        ddUKsuMN_(NULL);
        lbdtYEkR_(NULL);
        create();
    }
    if(arg == NULL) return NULL;

    try(struct Geometric *this = malloc(sizeof(struct Geometric)))
    {
        struct Exception exception = goodAllocationInstance(this);
        if(exception.severity != success) goto catch; else goto reprise;
    }
    catch:
        exit(0);
    reprise:
    this->protectedAttribute = "lol";
    this->packageAttribute = "salut 2";
    this->publicAttribute = "mdr !!";

    this->class = self;

    store_instance(this);
    return (struct YPnOLrQT *) this;
}

static void create(void)
{
    try(self = malloc(sizeof(struct Geometric_)))
    {
        struct Exception thrownException = goodAllocationInstance(self);
        if(thrownException.severity != success) goto catch; else goto reprise;
    }
    catch:
        exit(0);
    reprise:
    CLASS_DESCRIPTOR

    store_instance(self);
    coop.Geometric = self;
    coop.Geometric->setClassName(self, __CLASS_NAME__);
}