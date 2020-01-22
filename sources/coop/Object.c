#include <stdio.h>

#include "Object.h"

#define package_vlDzoKUd_start
#include "coop.h"

#define CLASS Object
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(public, char *, publicAttribute) \
    ATTRIBUTE(public, int, alternativePublicAttribute) \
    ATTRIBUTE(package, char *, packageAttribute) \
    ATTRIBUTE(package, float, alternativePackageAttribute) \
    ATTRIBUTE(protected, char *, protectedAttribute) \
    ATTRIBUTE(protected, char, alternativeProtectedAttribute) \
    ATTRIBUTE(private, char *, privateAttribute) \
    ATTRIBUTE(private, double, alternativePrivateAttribute)
#define CLASS_DESCRIPTOR \
    METHOD_CD(public_static, void , setClassName, const char *) \
    METHOD_CD(public_static, const char *, getClassName, ...) \
    METHOD_ID(public, void , setPrivateAttribute, char *) \
    METHOD_ID(public, void , setAlternativePrivateAttribute, double) \
    METHOD_ID(public, char *, getPrivateAttribute, ...) \
    METHOD_ID(public, double, getAlternativePrivateAttribute, ...) \
    METHOD_ID(public, void , setProtectedAttribute, char *) \
    METHOD_ID(public, void , setAlternativeProtectedAttribute, char) \
    METHOD_ID(public, char *, getProtectedAttribute, ...) \
    METHOD_ID(public, char, getAlternativeProtectedAttribute, ...) \
    METHOD_ID(private, float, aMethod, struct kGAzHwmx_overloads *) \
    ATTRIBUTE(private_static, const char *, className)
#define CLASS_DEFINITION kGAzHwmx
#define REFLEXIVITY
#include "../objectModel.h"

#define kGAzHwmx_$_aMethod(option, ...) coop.Object->aMethod \
( this, \
&(struct kGAzHwmx_overloads) \
{ \
    .options = CAT(kGAzHwmx_aMethod_,option), \
    .CAT(aMethod_,option)= {__VA_ARGS__} \
} \
)

static void *manageOverloads(struct Object *, struct CAT(CLASS_DEFINITION,_overloads) *);

struct CLASS_DEFINITION *(CLASS_DEFINITION)(struct CAT(CLASS_DEFINITION,_overloads) *args)
{
    if(!self) create();
    if(args == NULL) return NULL;

    struct Object *this = new(Object);
    manageOverloads(this, args);
    this->class = self;

    float o = kGAzHwmx_$_aMethod(o1, 3.4f, 3.6f);
    int a = (int) kGAzHwmx_$_aMethod(o2, 5, 3);
    printf("%f\n", kGAzHwmx_$_aMethod(o1, o, o));
    printf("%d\n", (int)kGAzHwmx_$_aMethod(o2, a, a));

    struct Square *square = (struct Square *) UQZwMHfN();

    printf("%d\n", square->class->area(square));

    //kGAzHwmx_$_aMethod();

    return (struct CLASS_DEFINITION *) this;
}

static void create(void)
{
    self = new(Object_);
    CLASS_DESCRIPTOR

    self->className = __CLASS_NAME__;
    coop.Object = self;

    #ifdef REFLEXIVITY
    integrate_reflexivity(&reflectInfos);
    #endif
}

static void *manageOverloads(struct Object *this, struct CAT(CLASS_DEFINITION,_overloads) *args)
{
    switch(args->options)
    {
        case CAT(CLASS_DEFINITION,_new_o1) :
            this->publicAttribute = args->new_o1.arg1;
            this->packageAttribute = args->new_o1.arg2;
            this->protectedAttribute = args->new_o1.arg3;
            this->privateAttribute = args->new_o1.arg4;
            args->new_o1.arg5 = args->new_o1.arg5;
            break;
        case CAT(CLASS_DEFINITION,_new_o2) :
            this->alternativePublicAttribute = args->new_o2.arg1;
            this->alternativePackageAttribute = args->new_o2.arg2;
            this->alternativeProtectedAttribute = args->new_o2.arg3;
            this->alternativePrivateAttribute = args->new_o2.arg4;
            break;
        case CAT(CLASS_DEFINITION,_aMethod_o1) :
        {
            float *result = new_(float);
            *result = args->aMethod_o1.arg1 + args->aMethod_o1.arg2;
            return result;
        }
        case CAT(CLASS_DEFINITION,_aMethod_o2) :
        {
            int *result = new_(int);
            *result = args->aMethod_o2.arg1 * args->aMethod_o2.arg2;
            return result;
        }
        default:
            break;
    }
    return NULL;
}

static void setPrivateAttribute(struct Object *this, char *string)
{
    this->privateAttribute = string;
}

static char *getPrivateAttribute(struct Object *this, ...)
{
    return this->privateAttribute;
}

static void setProtectedAttribute(struct Object *this, char *string)
{
    this->protectedAttribute = string;
}

static char *getProtectedAttribute(struct Object *this, ...)
{
    return this->protectedAttribute;
}

static void setClassName(struct Object_ *self_, const char *string)
{
    self_->className = string;
}

static const char *getClassName(struct Object_ *self_, ...)
{
    return self_->className;
}

static void setAlternativePrivateAttribute(struct Object *this, double floatingNumber)
{
    this->alternativePrivateAttribute = floatingNumber;
}

static double getAlternativePrivateAttribute(struct Object *this,...)
{
    return this->alternativePrivateAttribute;
}

static void setAlternativeProtectedAttribute(struct Object *this, char character)
{
    this->alternativeProtectedAttribute = character;
}

static char getAlternativeProtectedAttribute(struct Object *this, ...)
{
    return this->alternativeProtectedAttribute;
}

static float aMethod(struct Object *this, struct CAT(CLASS_DEFINITION,_overloads) *args)
{
    return *(float *) manageOverloads(this, args);
}
