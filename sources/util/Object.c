#include "Object.h"

#define package_kdzvSGAN_start
#include "util.h"

#define PACKAGE util
#define CLASS Object
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID KPLGWrfu
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID,_)
#define CLASS_PUBLIC_ID_OV CAT(CLASS_PUBLIC_ID,_overloads)
#define REFLEXIVITY

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
    METHOD_OD(public, void , setPrivateAttribute, char *) \
    METHOD_OD(public, void , setAlternativePrivateAttribute, double) \
    METHOD_OD(public, char *, getPrivateAttribute, ...) \
    METHOD_OD(public, double, getAlternativePrivateAttribute, ...) \
    METHOD_OD(public, void , setProtectedAttribute, char *) \
    METHOD_OD(public, void , setAlternativeProtectedAttribute, char) \
    METHOD_OD(public, char *, getProtectedAttribute, ...) \
    METHOD_OD(public, char, getAlternativeProtectedAttribute, ...) \
    METHOD_OD(private, float, aMethod, struct KPLGWrfu_overloads *) \
    ATTRIBUTE(private_static, const char *, className)
#include "../objectModel.h"

#define KPLGWrfu_$_aMethod(option, ...) PACKAGE.CLASS->aMethod \
( this, \
&(struct KPLGWrfu_overloads) \
{ \
    .options = CAT(KPLGWrfu_aMethod_,option), \
    .CAT(aMethod_,option)= {__VA_ARGS__} \
} \
)/**/

static void *manageOverloads(struct CLASS *, struct CLASS_PUBLIC_ID_OV *);

struct CLASS_PUBLIC_ID *(CLASS_PUBLIC_ID)(struct CLASS_PUBLIC_ID_OV *args, bool lastLevelH, struct SELF_PUBLIC_ID *that)
{
    if(!that && !lastLevelH) that = new(SELF);
    create((struct SELF *) that);
    if(args == NULL) return (void *) that;

    struct CLASS *this = new(CLASS);
    manageOverloads(this, args);

    float o = KPLGWrfu_$_aMethod(o1, 3.4f, 3.6f);
    int a = (int) KPLGWrfu_$_aMethod(o2, 5, 3);
    printf("%f\n", KPLGWrfu_$_aMethod(o1, o, o));
    printf("%d\n", (int)KPLGWrfu_$_aMethod(o2, a, a));/**/

    return (struct CLASS_PUBLIC_ID *) this;
}

static void create(struct SELF *that)
{
    if(!self)
    {
        PACKAGE.CLASS = self = new(SELF);
        CLASS_DESCRIPTOR
        self->className = __CLASS_NAME__;
    }
    if(that != NULL && that != NOTNULL)
    {
        that->setClassName = setClassName;
        that->getClassName = getClassName;
        that->setPrivateAttribute = setPrivateAttribute;
        that->setAlternativePrivateAttribute = setAlternativePrivateAttribute;
        that->getPrivateAttribute = getPrivateAttribute;
        that->getAlternativePrivateAttribute = getAlternativePrivateAttribute;
        that->setProtectedAttribute = setProtectedAttribute;
        that->setAlternativeProtectedAttribute = setAlternativeProtectedAttribute;
        that->getProtectedAttribute = getProtectedAttribute;
        that->getAlternativeProtectedAttribute = getAlternativeProtectedAttribute;
        that->aMethod = aMethod;
        that->className = self->className;
    }
    #ifdef REFLEXIVITY
        integrate_reflexivity(&reflectInfos);
    #endif
}

static void *manageOverloads(struct CLASS *this, struct CLASS_PUBLIC_ID_OV *args)
{
    switch(args->options)
    {
        case CAT(CLASS_PUBLIC_ID,_new_o1) :
            this->publicAttribute = args->new_o1.arg1;
            this->packageAttribute = args->new_o1.arg2;
            this->protectedAttribute = args->new_o1.arg3;
            this->privateAttribute = args->new_o1.arg4;
            args->new_o1.arg5 = args->new_o1.arg5;
            break;
        case CAT(CLASS_PUBLIC_ID,_new_o2) :
            this->alternativePublicAttribute = args->new_o2.arg1;
            this->alternativePackageAttribute = args->new_o2.arg2;
            this->alternativeProtectedAttribute = args->new_o2.arg3;
            this->alternativePrivateAttribute = args->new_o2.arg4;
            break;
        case CAT(CLASS_PUBLIC_ID,_aMethod_o1) :
        {
            float *result = new_(float);
            *result = args->aMethod_o1.arg1 + args->aMethod_o1.arg2;
            return result;
        }
        case CAT(CLASS_PUBLIC_ID,_aMethod_o2) :
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

static void setPrivateAttribute(struct CLASS *this, char *string)
{
    this->privateAttribute = string;
}

static char *getPrivateAttribute(struct CLASS *this, ...)
{
    return this->privateAttribute;
}

static void setProtectedAttribute(struct CLASS *this, char *string)
{
    this->protectedAttribute = string;
}

static char *getProtectedAttribute(struct CLASS *this, ...)
{
    return this->protectedAttribute;
}

static void setClassName(struct SELF *that, const char *string)
{
    that->className = string;
}

static const char *getClassName(struct SELF *that, ...)
{
    return that->className;
}

static void setAlternativePrivateAttribute(struct CLASS *this, double floatingNumber)
{
    this->alternativePrivateAttribute = floatingNumber;
}

static double getAlternativePrivateAttribute(struct CLASS *this,...)
{
    return this->alternativePrivateAttribute;
}

static void setAlternativeProtectedAttribute(struct CLASS *this, char character)
{
    this->alternativeProtectedAttribute = character;
}

static char getAlternativeProtectedAttribute(struct CLASS *this, ...)
{
    return this->alternativeProtectedAttribute;
}

static float aMethod(struct CLASS *this, struct CLASS_PUBLIC_ID_OV *args)
{
    return *(float *) manageOverloads(this, args);
}
