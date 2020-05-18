#define Bool_family
#include "Bool.h"

#define IMPLEMENTS implementTester
#include "ToTest.h"

#define package_nnVYoBNR_start
#include "lang.h"

#define PACKAGE_USER nnVYoBNR
#define CLASS Bool
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID BwXbIZdw
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)
#define IMPLEMENTATION implementTester

#define OBJECT_DESCRIPTOR                                           \
    ATTRIBUTE(private, bool, value)
#define CLASS_DESCRIPTOR                                            \
    METHOD_OD(public, bool, getValue)                               \
    METHOD_OD(public, void, setValue, bool)                         \
    METHOD_IM(public, void, IMPLEMENTATION, wrapperOfBooleans)
#include "../../objectModel.h"

static void defaultConstructor(struct CLASS *);

size_t CAT(CLASS_PUBLIC_ID, _getSize)(struct SELF_PUBLIC_ID **that)
{
    if(!self)
    {
        PACKAGE_USER.CLASS = self = malloc(sizeof(struct SELF));
        *self = (struct SELF)
        {
            .getValue = getValue,
            .setValue = setValue,
            .CAT3(IMPLEMENTATION, _, wrapperOfBooleans) = CAT3(IMPLEMENTATION, _, wrapperOfBooleans)
        };
        #ifdef REFLEXIVITY
        reflex(&reflectInfos);
        #endif
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
    if(self)
    {
        free(self);
        self = NULL;
    }
}

static void defaultConstructor(struct CLASS * this)
{
    (void)this;
}

static bool getValue(struct CLASS *this)
{
    return this->value;
}

static void setValue(struct CLASS *this, bool newValue)
{
    this->value = newValue;
}

static void CAT3(IMPLEMENTATION, _, wrapperOfBooleans)(void *this)
{
    (void)this;
}
