#include "Another.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define PACKAGE coop
#define CLASS Another
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID lbdtYEkR
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)
#define SUPER Object
#define PARENT CAT(SUPER,_)
#define SUPER_PUBLIC_ID kGAzHwmx
#define PARENT_PUBLIC_ID CAT(SUPER_PUBLIC_ID,_)

#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(SUPER, SUPER)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(SUPER, SUPER) \
    METHOD_CD(package_static, void, absCustom, ...) \
    METHOD_CD(protected_static, void, useCustom, ...)
#include "../objectModel.h"

struct CLASS_PUBLIC_ID *(CLASS_PUBLIC_ID)(bool arg, bool lastLevelH, struct SELF_PUBLIC_ID *that)
{
    if(!that && !lastLevelH)
    {
        that = new(SELF);
        that->SUPER = (struct PARENT_PUBLIC_ID *)(SUPER_PUBLIC_ID)(PC_WITH_OV, $NO, NULL);
    }
    create((struct SELF *) that);
    if(!arg) return (void *) that;

    struct CLASS *this = new(CLASS);
    this->SUPER = (struct SUPER *)(SUPER_PUBLIC_ID)(FC_WITH_OV(SUPER_PUBLIC_ID), $NO, NOTNULL);

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
        that->absCustom = absCustom;
        that->useCustom = useCustom;
    }
    #ifdef REFLEXIVITY
        integrate_reflexivity(&reflectInfos);
    #endif
}

static void absCustom(struct SELF *that, ...)
{
    if(that){}
}

static void useCustom(struct SELF *that, ...)
{
    if(that){}
}
