#define Object_family
#include "Geometric.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define PACKAGE_USER vlDzoKUd
#define CLASS Geometric
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID YPnOLrQT
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)
#define SUPER_A Derived
#define SUPER_B Another
#define SUPER_PUBLIC_ID_A ddUKsuMN
#define SUPER_PUBLIC_ID_B lbdtYEkR
#define PARENT_PUBLIC_ID_A CAT(SUPER_PUBLIC_ID_A,_)
#define PARENT_PUBLIC_ID_B CAT(SUPER_PUBLIC_ID_B,_)

#define OBJECT_DESCRIPTOR           \
    EXTENDS_OD(SUPER_A, SUPER_A)    \
    EXTENDS_OD(SUPER_B, SUPER_B)
#define CLASS_DESCRIPTOR            \
    EXTENDS_CD(SUPER_A, SUPER_A)    \
    EXTENDS_CD(SUPER_B, SUPER_B)
#include "../objectModel.h"

size_t CAT(CLASS_PUBLIC_ID, _getSize)(struct SELF_PUBLIC_ID **that)
{
    if(!self)
    {
        try {
            PACKAGE_USER.CLASS = self = malloc(sizeof(struct SELF));
            allocationWellDone(&exception, self);
        }
        catch(badAllocationException)
        {
            printf("%s\n", exception.message);
			garbageCollector();
            exit(0);
        } endTry
        *self = (struct SELF)
        {


        };
        #ifdef REFLEXIVITY
        reflex(&reflectInfos);
        #endif
        CAT(SUPER_PUBLIC_ID_A,_getSize)((struct PARENT_PUBLIC_ID_A **) &self->Derived);
        CAT(SUPER_PUBLIC_ID_B,_getSize)((struct PARENT_PUBLIC_ID_B **) &self->Another);
    }
    *that = (struct SELF_PUBLIC_ID *) self;
    return sizeof(struct CLASS);
}

void (CLASS_PUBLIC_ID)(struct CLASS_PUBLIC_ID *this_, void *args)
{
    struct CLASS * this = (struct CLASS *) this_;
    size_t numberOfElements = getLength(this);
    for(size_t i=0; i < numberOfElements; ++i)
    {
        (this + i)->Derived.Object.protectedAttribute = "salut la compagnie !";
        (this + i)->Another.Object.protectedAttribute = "salut la compagnie 2 !";
    }
    (void)args;
}

void CAT(CLASS_PUBLIC_ID,_)(void)
{
    PARENT_PUBLIC_ID_A();
    PARENT_PUBLIC_ID_B();
    if(self)
    {
        free(self);
        self = NULL;
    }
}
