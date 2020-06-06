#define Object_family
#include "Object.h"

#define package_kdzvSGAN_start
#include "util.h"

#define PACKAGE_USER kdzvSGAN
#define CLASS Object
#define SELF CAT(CLASS,_)
#define CLASS_PUBLIC_ID KPLGWrfu
#define SELF_PUBLIC_ID CAT(CLASS_PUBLIC_ID, _)
#define CLASS_PUBLIC_ID_OV CAT(CLASS_PUBLIC_ID,_overloads)
#define REFLEXIVITY

#define OBJECT_DESCRIPTOR                                               \
    ATTRIBUTE(public, char *, publicAttribute)                          \
    ATTRIBUTE(public, int, alternativePublicAttribute)                  \
    ATTRIBUTE(package, char *, packageAttribute)                        \
    ATTRIBUTE(package, float, alternativePackageAttribute)              \
    ATTRIBUTE(protected, char *, protectedAttribute)                    \
    ATTRIBUTE(protected, char, alternativeProtectedAttribute)           \
    ATTRIBUTE(private, char *, privateAttribute)                        \
    ATTRIBUTE(private, double, alternativePrivateAttribute)
#define CLASS_DESCRIPTOR                                                \
    METHOD_CD(public_static, void, setClassName, const char *)          \
    METHOD_CD(public_static, const char *, getClassName)                \
    METHOD_OD(public, void, setPrivateAttribute, char *)                \
    METHOD_OD(public, void, setAlternativePrivateAttribute, double)     \
    METHOD_OD(public, char *, getPrivateAttribute)                      \
    METHOD_OD(public, double, getAlternativePrivateAttribute)           \
    METHOD_OD(public, void, setProtectedAttribute, char *)              \
    METHOD_OD(public, void, setAlternativeProtectedAttribute, char)     \
    METHOD_OD(public, char *, getProtectedAttribute)                    \
    METHOD_OD(public, char, getAlternativeProtectedAttribute)           \
    ATTRIBUTE(private_static, const char *, className)
#include "../objectModel.h"

static void manageOverloads(struct CLASS *, struct CLASS_PUBLIC_ID_OV *);

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
            .setClassName = setClassName,
            .getClassName = getClassName,
            .setPrivateAttribute = setPrivateAttribute,
            .setAlternativePrivateAttribute = setAlternativePrivateAttribute,
            .getPrivateAttribute = getPrivateAttribute,
            .getAlternativePrivateAttribute = getAlternativePrivateAttribute,
            .setProtectedAttribute = setProtectedAttribute,
            .setAlternativeProtectedAttribute = setAlternativeProtectedAttribute,
            .getProtectedAttribute = getProtectedAttribute,
            .getAlternativeProtectedAttribute = getAlternativeProtectedAttribute,
            .className = __CLASS_NAME__
        };
        #ifdef REFLEXIVITY
        reflex(&reflectInfos);
        #endif
    }
    *that = (struct SELF_PUBLIC_ID *) self;
    return sizeof(struct CLASS);
}

void CAT(CLASS_PUBLIC_ID,_)(void)
{
    if(self)
    {
        free(self);
        self = NULL;
    }
}

void (CLASS_PUBLIC_ID)(struct CLASS_PUBLIC_ID *this, struct CLASS_PUBLIC_ID_OV *args)
{
    manageOverloads((struct CLASS *)this, args);
}

static void manageOverloads(struct CLASS *this, struct CLASS_PUBLIC_ID_OV *args)
{
    size_t numberOfElements = getLength(this);
    for(size_t i=0; i < numberOfElements; ++i)
    {
        switch(args->options)
        {
            case CAT(CLASS_PUBLIC_ID,_new_o1) :
                (this+i)->publicAttribute = args->new_o1.arg1;
                (this+i)->packageAttribute = args->new_o1.arg2;
                (this+i)->protectedAttribute = args->new_o1.arg3;
                (this+i)->privateAttribute = args->new_o1.arg4;
                break;
            case CAT(CLASS_PUBLIC_ID,_new_o2) :
                (this+i)->alternativePublicAttribute = args->new_o2.arg1;
                (this+i)->alternativePackageAttribute = args->new_o2.arg2;
                (this+i)->alternativeProtectedAttribute = args->new_o2.arg3;
                (this+i)->alternativePrivateAttribute = args->new_o2.arg4;
                break;
            case CAT(CLASS_PUBLIC_ID,_new_) :
                *(this+i) = (struct CLASS)
                {
                    .publicAttribute = "default public",
                    .packageAttribute = "default package",
                    .protectedAttribute = "default protected",
                    .privateAttribute = "default private",
                    .alternativePublicAttribute = 2,
                    .alternativePackageAttribute = 2.4f,
                    .alternativeProtectedAttribute = 'c',
                    .alternativePrivateAttribute = 3.6
                };
                break;
            default:
                break;
        }
    }
}

static void setPrivateAttribute(struct CLASS *this, char *string)
{
    this->privateAttribute = string;
}

static char *getPrivateAttribute(struct CLASS *this)
{
    return this->privateAttribute;
}

static void setProtectedAttribute(struct CLASS *this, char *string)
{
    this->protectedAttribute = string;
}

static char *getProtectedAttribute(struct CLASS *this)
{
    return this->protectedAttribute;
}

static void setClassName(struct SELF *that, const char *string)
{
    that->className = string;
}

static const char *getClassName(struct SELF *that)
{
    return that->className;
}

static void setAlternativePrivateAttribute(struct CLASS *this, double floatingNumber)
{
    this->alternativePrivateAttribute = floatingNumber;
}

static double getAlternativePrivateAttribute(struct CLASS *this)
{
    return this->alternativePrivateAttribute;
}

static void setAlternativeProtectedAttribute(struct CLASS *this, char character)
{
    this->alternativeProtectedAttribute = character;
}

static char getAlternativeProtectedAttribute(struct CLASS *this)
{
    return this->alternativeProtectedAttribute;
}
