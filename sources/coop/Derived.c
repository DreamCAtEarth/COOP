#include "Derived.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define PACKAGE coop
#define CLASS Derived
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID ddUKsuMN
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)
#define SUPER Object
#define PARENT CAT(SUPER,_)
#define SUPER_PUBLIC_ID kGAzHwmx
#define PARENT_PUBLIC_ID CAT(SUPER_PUBLIC_ID,_)
#define CLASS_PUBLIC_ID_OV CAT(CLASS_PUBLIC_ID,_overloads)

#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(SUPER, SUPER)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(SUPER, SUPER) \
    METHOD_OD(public, char *, getProtectedAttribute, ...) \
    METHOD_CD(package_static, void, absCustom, ...) \
    METHOD_CD(protected_static, void, useCustom, ...)
#include "../objectModel.h"

static char *getProtectedAttribute(struct CLASS *this, ...);
static void manageOverloads(struct CLASS *, struct CLASS_PUBLIC_ID_OV *);

struct CLASS_PUBLIC_ID *(CLASS_PUBLIC_ID)(struct CLASS_PUBLIC_ID_OV *args, bool lastLevelH, struct SELF_PUBLIC_ID *that)
{
    if(!that && !lastLevelH)
    {
        that = new(SELF);
        that->SUPER = (struct PARENT_PUBLIC_ID *)(SUPER_PUBLIC_ID)(PC_WITH_OV, $NO, NULL);
    }
    create((struct SELF *) that);
    if(args == NULL) return (void *) that;

    struct CLASS *this = new(CLASS);
    this->SUPER = (struct SUPER *)(SUPER_PUBLIC_ID)(FC_WITH_OV(SUPER_PUBLIC_ID), $NO, NOTNULL);
    manageOverloads(this, args);

    return (struct CLASS_PUBLIC_ID *) this;
}

static void create(struct SELF *that)
{
    if(!self)
    {
        PACKAGE.CLASS = self = new(SELF);
        CLASS_DESCRIPTOR
        self->SUPER = (struct PARENT *)(SUPER_PUBLIC_ID)(PC_WITH_OV, $NO, NULL);
        self->SUPER->setClassName(self->SUPER, __CLASS_NAME__);
    }
    if(that != NULL && that != NOTNULL)
    {
        that->getProtectedAttribute = getProtectedAttribute;
        that->absCustom = absCustom;
        that->useCustom = useCustom;
    }
    #ifdef REFLEXIVITY
        integrate_reflexivity(&reflectInfos);
    #endif
}

static void manageOverloads(struct CLASS *this, struct CLASS_PUBLIC_ID_OV *args)
{
    switch(args->options)
    {
        case CAT(CLASS_PUBLIC_ID,_new_o1) :
            this->SUPER->publicAttribute = args->new_o1.arg1;
            this->SUPER->packageAttribute = args->new_o1.arg2;
            this->SUPER->protectedAttribute = args->new_o1.arg3;
            break;
        case CAT(CLASS_PUBLIC_ID,_new_o2) :
            this->SUPER->alternativePublicAttribute = args->new_o2.arg1;
            this->SUPER->alternativePackageAttribute = args->new_o2.arg2;
            this->SUPER->alternativeProtectedAttribute = args->new_o2.arg3;
            break;
        default:
            args->new_ = args->new_;
            break;
    }
}

static void absCustom(struct SELF *that, ...)
{
    if(that){}
}

static void useCustom(struct SELF *that, ...)
{
    if(that){}
}

static char *getProtectedAttribute(struct CLASS *this, ...)
{
    this->SUPER->protectedAttribute = "p r o t e c t e d  a t t r i b u t e !";
    return this->SUPER->protectedAttribute;
}
