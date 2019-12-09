#include <stdlib.h>

#include "Derived.h"

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
    ATTRIBUTE(private, const void * const, privateAttribute) \
    ATTRIBUTE(private, const void * const, alternativePrivateAttribute)
#define CLASS_DESCRIPTOR \
    PARENT_METHOD_CD(public static, coop.Object, void , setClassName, const char *) \
    PARENT_METHOD_CD(public static, coop.Object, const char *, getClassName, ...) \
    PARENT_METHOD_ID(public, coop.Object, void , setPrivateAttribute, char *) \
    PARENT_METHOD_ID(public, coop.Object, void , setAlternativePrivateAttribute, double) \
    PARENT_METHOD_ID(public, coop.Object, char *, getPrivateAttribute, ...) \
    PARENT_METHOD_ID(public, coop.Object, double, getAlternativePrivateAttribute, ...) \
    PARENT_METHOD_ID(public, coop.Object, void , setProtectedAttribute, char *) \
    PARENT_METHOD_ID(public, coop.Object, void , setAlternativeProtectedAttribute, char) \
    PARENT_METHOD_ID(public, coop.Object, char *, getProtectedAttribute, ...) \
    PARENT_METHOD_ID(public, coop.Object, char, getAlternativeProtectedAttribute, ...) \
    ATTRIBUTE(private static, const void * const, className)
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

    struct Derived *this = malloc(sizeof(struct Derived));

    manageOverloads(this, args);
    this->class = self;

    store_instance(this);
    return (struct ddUKsuMN *) this;
}

static void create(void)
{
    self = malloc(sizeof(struct Derived_));

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
