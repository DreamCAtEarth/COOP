#include <stdlib.h>

#include "Another.h"
#define DIRECT_SUPER_CLASS kGAzHwmx

#define package_coop_start
#include "coop.h"

#define CLASS Another
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
    METHOD_CD(package_static, void, absCustom, ...) \
    METHOD_CD(protected_static, void, useCustom, ...)
#define CLASS_DEFINITION lbdtYEkR
#include "../objectModel.h"

struct lbdtYEkR *lbdtYEkR_(void *arg)
{
    if(!self)
    {
        super(NULL);
        create();
    }
    if(arg == NULL) return NULL;

    try(struct Another *this = malloc(sizeof(struct Another)))
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
    return (struct lbdtYEkR *) this;
}

static void create(void)
{
    try(self = malloc(sizeof(struct Another_)))
    {
        struct Exception thrownException = goodAllocationInstance(self);
        if(thrownException.severity != success) goto catch; else goto reprise;
    }
    catch:
        exit(0);
    reprise:
    CLASS_DESCRIPTOR

    store_instance(self);
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