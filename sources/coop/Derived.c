#define Object_family
#include "Derived.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define PACKAGE_USER vlDzoKUd
#define CLASS Derived
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID ddUKsuMN
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)
#define SUPER Object
#define SUPER_PUBLIC_ID kGAzHwmx
#define PARENT_PUBLIC_ID CAT(SUPER_PUBLIC_ID,_)
#define CLASS_PUBLIC_ID_OV CAT(CLASS_PUBLIC_ID,_overloads)

#define OBJECT_DESCRIPTOR                               \
    EXTENDS_OD(SUPER, SUPER)
#define CLASS_DESCRIPTOR                                \
    EXTENDS_CD(SUPER, SUPER)                            \
    METHOD_OD(public, char *, getProtectedAttribute)    \
    METHOD_CD(package_static, void, absCustom)          \
    METHOD_CD(protected_static, void, useCustom)
#include "../objectModel.h"

static void manageOverloads(struct CLASS *, struct CLASS_PUBLIC_ID_OV *);

size_t CAT(CLASS_PUBLIC_ID, _getSize)(struct SELF_PUBLIC_ID **that)
{
    if(!self)
    {
        PACKAGE_USER.CLASS = self = malloc(sizeof(struct SELF));
        *self = (struct SELF)
        {

            .getProtectedAttribute = getProtectedAttribute,
            .absCustom = absCustom,
            .useCustom = useCustom
        };
    #ifdef REFLEXIVITY
        reflex(&reflectInfos);
    #endif
        CAT(SUPER_PUBLIC_ID,_getSize)((struct PARENT_PUBLIC_ID **) &self->Object);
    }
    if(that != NULL) *that = (struct SELF_PUBLIC_ID *) self;
    return sizeof(struct CLASS);
}

void CAT(CLASS_PUBLIC_ID,_)(void)
{
    PARENT_PUBLIC_ID();
    if(self) free(self);
    self = NULL;
}

void (CLASS_PUBLIC_ID)(struct CLASS_PUBLIC_ID *this, struct CLASS_PUBLIC_ID_OV *args)
{
    manageOverloads( (struct CLASS *) this, args);
}

static void manageOverloads(struct CLASS *this, struct CLASS_PUBLIC_ID_OV *args)
{
    switch(args->options)
    {
        case CAT(CLASS_PUBLIC_ID,_new_o1) :
            this->SUPER.publicAttribute = args->new_o1.arg1;
            this->SUPER.packageAttribute = args->new_o1.arg2;
            this->SUPER.protectedAttribute = args->new_o1.arg3;
            break;
        case CAT(CLASS_PUBLIC_ID,_new_o2) :
            this->SUPER.alternativePublicAttribute = args->new_o2.arg1;
            this->SUPER.alternativePackageAttribute = args->new_o2.arg2;
            this->SUPER.alternativeProtectedAttribute = args->new_o2.arg3;
            break;
        case CAT(CLASS_PUBLIC_ID,_new_) :
            this->SUPER.publicAttribute = "default public";
            this->SUPER.packageAttribute = "default package";
            this->SUPER.protectedAttribute = "default protected";
            this->SUPER.alternativePublicAttribute = 4;
            this->SUPER.alternativePackageAttribute = 6.99f;
            this->SUPER.alternativeProtectedAttribute = 'u';
            break;
        default:
            break;
    }
}

static void absCustom(struct SELF *that)
{
    (void)that;
}

static void useCustom(struct SELF *that)
{
    (void)that;
}

static char *getProtectedAttribute(struct CLASS *this)
{
    this->SUPER.protectedAttribute = "p r o t e c t e d  a t t r i b u t e !";
    return this->SUPER.protectedAttribute;
}
