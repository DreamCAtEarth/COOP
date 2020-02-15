#include "Geometric.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define PACKAGE coop
#define CLASS Geometric
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID YPnOLrQT
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)
#define SUPER_A Derived
#define SUPER_B Another
#define PARENT_A CAT(SUPER_A,_)
#define PARENT_B CAT(SUPER_B,_)
#define SUPER_PUBLIC_ID_A ddUKsuMN
#define SUPER_PUBLIC_ID_B lbdtYEkR
#define PARENT_PUBLIC_ID_A CAT(SUPER_PUBLIC_ID_A,_)
#define PARENT_PUBLIC_ID_B CAT(SUPER_PUBLIC_ID_B,_)

#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(SUPER_A, SUPER_A) \
    EXTENDS_OD(SUPER_B, SUPER_B)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(SUPER_A, SUPER_A) \
    EXTENDS_CD(SUPER_B, SUPER_B)
#include "../objectModel.h"

struct CLASS_PUBLIC_ID *(CLASS_PUBLIC_ID)(bool arg, bool lastLevelH, struct SELF_PUBLIC_ID *that)
{
    if(!that && !lastLevelH)
    {
        that = new(SELF);
        that->SUPER_A = (struct PARENT_PUBLIC_ID_A *)(SUPER_PUBLIC_ID_A)(PC_WITH_OV, $NO, NULL);
        that->SUPER_B = (struct PARENT_PUBLIC_ID_B *)(SUPER_PUBLIC_ID_B)(PC_WITHOUT_OV, $NO, NULL);
    }
    create((struct SELF *)that);
    if(!arg) return (void *) that;

    struct CLASS *this = new(CLASS);
    this->SUPER_A = (struct SUPER_A *)(SUPER_PUBLIC_ID_A)(FC_WITH_OV(SUPER_PUBLIC_ID_A), $NO, NOTNULL);
    this->SUPER_B = (struct SUPER_B *)(SUPER_PUBLIC_ID_B)(FC_WITHOUT_OV, $NO, NOTNULL);

    return (struct CLASS_PUBLIC_ID *) this;
}

static void create(struct SELF *that)
{
    if(!self)
    {
        PACKAGE.CLASS = self = new(SELF);
        CLASS_DESCRIPTOR
        self->SUPER_A = (struct PARENT_A *)(SUPER_PUBLIC_ID_A)(PC_WITH_OV, $NO, NULL);
        self->SUPER_B = (struct PARENT_B *)(SUPER_PUBLIC_ID_B)(PC_WITH_OV, $NO, NULL);
        self->SUPER_A->Object->setClassName(self->SUPER_A->Object, __CLASS_NAME__);
        self->SUPER_B->Object->setClassName(self->SUPER_B->Object, __CLASS_NAME__);
    }
    if(that != NULL && that != NOTNULL)
    {

    }
    #ifdef REFLEXIVITY
        integrate_reflexivity(&reflectInfos);
    #endif
}
