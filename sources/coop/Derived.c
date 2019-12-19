#include <stdlib.h>

#include "Derived.h"
#define DIRECT_SUPER_CLASS kGAzHwmx

#define package_coop_start
#include "coop.h"

#define CLASS Derived
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
#define CLASS_DEFINITION ddUKsuMN
#include "../objectModel.h"

static void manageOverloads(struct Derived *, struct ddUKsuMN_overloads *);

struct ddUKsuMN *ddUKsuMN_(struct ddUKsuMN_overloads *args)
{
    if(!self)
    {
        super(NULL);
        create();
    }
    if(args == NULL) return NULL;

    try(struct Derived *this = malloc(sizeof(struct Derived)))
    {
        struct Exception exception = goodAllocationInstance(this);
        if(exception.severity != success) goto catch; else goto reprise;
    }
    catch:
    {
        /* Affichage de l'erreur à l'utilisateur */
        exit(0);
    }
    reprise:

    manageOverloads(this, args);
    this->class = self;

    store_instance(this);
    return (struct ddUKsuMN *) this;
}

static void create(void)
{
    try(self = malloc(sizeof(struct Derived_)))
    {
        struct Exception thrownException = goodAllocationInstance(self);
        if(thrownException.severity != success) goto catch; else goto reprise;
    }
    catch:
    {
        /* Affichage de l'erreur à l'utilisateur */
        exit(0);
    }
    reprise:
    CLASS_DESCRIPTOR

    store_instance(self);
    coop.Derived = self;
    coop.Derived->setClassName(self, __CLASS_NAME__);
}

static void manageOverloads(struct Derived *this, struct ddUKsuMN_overloads *args)
{
    switch(args->options)
    {
        case ddUKsuMN_new_o1 :
            this->publicAttribute = args->overloads->new_o1.arg1;
            this->packageAttribute = args->overloads->new_o1.arg2;
            this->protectedAttribute = args->overloads->new_o1.arg3;
            break;
        case ddUKsuMN_new_o2 :
            this->alternativePublicAttribute = args->overloads->new_o2.arg1;
            this->alternativePackageAttribute = args->overloads->new_o2.arg2;
            this->alternativeProtectedAttribute = args->overloads->new_o2.arg3;
            break;
        case ddUKsuMN_none :
            break;
        default:
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
