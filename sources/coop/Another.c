#define Object_family
#include "Another.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define PACKAGE_USER vlDzoKUd
#define CLASS Another
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID lbdtYEkR
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)
#define SUPER Object
#define SUPER_PUBLIC_ID kGAzHwmx
#define PARENT_PUBLIC_ID CAT(SUPER_PUBLIC_ID,_)
#define CLASS_PUBLIC_ID_OV CAT(CLASS_PUBLIC_ID,_overloads)

#define OBJECT_DESCRIPTOR                               \
    EXTENDS_OD(SUPER, SUPER)
#define CLASS_DESCRIPTOR                                \
    EXTENDS_CD(SUPER, SUPER)                            \
    METHOD_CD(package_static, void, absCustom)          \
    METHOD_CD(protected_static, void, useCustom)        \
    METHOD_SA(private_standalone, void, testCustom, void)
#include "../objectModel.h"

static void defaultConstructor(struct CLASS *);

size_t CAT(CLASS_PUBLIC_ID, _getSize)(struct SELF_PUBLIC_ID **that)
{
    if(!self)
    {
        PACKAGE_USER.CLASS = self = malloc(sizeof(struct SELF));
        *self = (struct SELF)
        {

            .absCustom = absCustom,
            .useCustom = useCustom,
            .testCustom = testCustom
        };
    #ifdef REFLEXIVITY
        reflex(&reflectInfos);
    #endif
        CAT(SUPER_PUBLIC_ID,_getSize)((struct PARENT_PUBLIC_ID **) &self->Object);
    }
    if(that != NULL) *that = (struct SELF_PUBLIC_ID *) self;
    return sizeof(struct CLASS);
}

void (CLASS_PUBLIC_ID)(struct CLASS_PUBLIC_ID *this, void *args)
{
    defaultConstructor((struct CLASS *) this);
    (void)args;
}

void CAT(CLASS_PUBLIC_ID,_)(void)
{
    PARENT_PUBLIC_ID();
    if(self) free(self);
    self = NULL;
}

static void absCustom(struct SELF *that)
{
    (void)that;
}

static void useCustom(struct SELF *that)
{
    (void)that;
}

static void defaultConstructor(struct CLASS * this)
{
    this->Object.protectedAttribute = "salut la compagnie 3 !";
    this->Object.protectedAttribute = "salut la compagnie 4 !";
}

static void testCustom(void)
{

}
