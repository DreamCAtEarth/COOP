#include "Bool.h"

#define IMPLEMENTS implementTester
#include "ToTest.h"

#define package_nnVYoBNR_start
#include "lang.h"

#define PACKAGE lang
#define CLASS Bool
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID BwXbIZdw
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)

#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, bool, value)
#define CLASS_DESCRIPTOR \
    METHOD_OD(public, bool , getValue, ...) \
    METHOD_OD(public, void , setValue, bool) \
    ATTRIBUTE(public_interface, struct implementTester *, ToTest)
#include "../../objectModel.h"

struct CLASS_PUBLIC_ID *(CLASS_PUBLIC_ID)(bool arg, bool lastLevelH, struct SELF_PUBLIC_ID *that)
{
    if(!that && !lastLevelH) that = new(SELF);
    create((struct SELF *) that);
    if(!arg) return (void *) that;

    struct CLASS *this = new(CLASS);

    return (struct CLASS_PUBLIC_ID *) this;
}

static void create(struct SELF *that)
{
    if(!self)
    {
        PACKAGE.CLASS = self = new(SELF);
        CLASS_DESCRIPTOR
        self->ToTest = new(implementTester);
        self->ToTest->wrapperOfBooleans = wrapperOfBooleans;
    }
    if(that != NULL && that != NOTNULL)
    {

    }
    #ifdef REFLEXIVITY
        integrate_reflexivity(&reflectInfos);
    #endif
}

static bool getValue(struct CLASS *this, ...)
{
    return this->value;
}

static void setValue(struct CLASS *this, bool newValue)
{
    this->value = newValue;
}

static void wrapperOfBooleans(void)
{

}/**/
