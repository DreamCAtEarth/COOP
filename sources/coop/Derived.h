#ifndef ddUKsuMN_H
#define ddUKsuMN_H

#define protected_kGAzHwmx_start
#include "Object.h"

#if defined(protected_ddUKsuMN_start) && !defined(protected_ddUKsuMN_stop)

#define CLASS Derived
#define INSTANCE_DESCRIPTOR \
    ATTRIBUTE(public, char *, publicAttribute) \
    ATTRIBUTE(public, int, alternativePublicAttribute) \
    ATTRIBUTE(package, char *, packageAttribute) \
    ATTRIBUTE(package, float, alternativePackageAttribute) \
    ATTRIBUTE(protected, char *, protectedAttribute) \
    ATTRIBUTE(protected, char, alternativeProtectedAttribute) \
    ATTRIBUTE(private, ENCAPSULATED, privateAttribute) \
    ATTRIBUTE(private, ENCAPSULATED, alternativePrivateAttribute)
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
    ATTRIBUTE(private_static, ENCAPSULATED, className) \
    METHOD_CD(package_static, void, absCustom, ...) \
    METHOD_CD(protected_static, void, useCustom, ...)
#include "../objectModel.h"

#define protected_ddUKsuMN_stop
#elif (defined(package_ddUKsuMN_start) && !defined(package_ddUKsuMN_stop)) || (defined(coop_package_start) && !defined(coop_package_stop))

#define CLASS Derived
#define INSTANCE_DESCRIPTOR \
    ATTRIBUTE(public, char *, publicAttribute) \
    ATTRIBUTE(public, int, alternativePublicAttribute) \
    ATTRIBUTE(package, char *, packageAttribute) \
    ATTRIBUTE(package, float, alternativePackageAttribute) \
    ATTRIBUTE(protected, ENCAPSULATED, protectedAttribute) \
    ATTRIBUTE(protected, ENCAPSULATED, alternativeProtectedAttribute) \
    ATTRIBUTE(private, ENCAPSULATED, privateAttribute) \
    ATTRIBUTE(private, ENCAPSULATED, alternativePrivateAttribute)
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
    ATTRIBUTE(private_static, ENCAPSULATED, className) \
    METHOD_CD(package_static, void, absCustom, ...) \
    METHOD_CD(protected_static, void, useCustom, ...)
#include "../objectModel.h"

#define package_ddUKsuMN_stop
#endif

#define CLASS ddUKsuMN
#define INSTANCE_DESCRIPTOR \
    ATTRIBUTE(public, char *, publicAttribute) \
    ATTRIBUTE(public, int, alternativePublicAttribute) \
    ATTRIBUTE(package, ENCAPSULATED, packageAttribute) \
    ATTRIBUTE(package, ENCAPSULATED, alternativePackageAttribute) \
    ATTRIBUTE(protected, ENCAPSULATED, protectedAttribute) \
    ATTRIBUTE(protected, ENCAPSULATED, alternativeProtectedAttribute) \
    ATTRIBUTE(private, ENCAPSULATED, privateAttribute) \
    ATTRIBUTE(private, ENCAPSULATED, alternativePrivateAttribute)
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
    ATTRIBUTE(private_static, ENCAPSULATED, className) \
    METHOD_CD(package_static, void, absCustom, ...) \
    METHOD_CD(protected_static, void, useCustom, ...)
#include "../objectModel.h"

struct ddUKsuMN_overloads
{
    enum ddUKsuMN_options
    {
        ddUKsuMN_new_o1,
        ddUKsuMN_new_o2,
        ddUKsuMN_none
    }options;
    union ddUKsuMN_args
    {
        struct ddUKsuMN_new_o1
        {
            char *arg1;
            char *arg2;
            char *arg3;
        }new_o1;
        struct ddUKsuMN_new_o2
        {
            int arg1;
            float arg2;
            char arg3;
        }new_o2;
    }*overloads;
};

struct ddUKsuMN *ddUKsuMN_(struct ddUKsuMN_overloads *);

/* overloading of methods without parameters */
/* default constructor */
#define ddUKsuMN_new_() \
ddUKsuMN_ \
(&(struct ddUKsuMN_overloads) \
{ \
    .options = ddUKsuMN_none, \
    &(union ddUKsuMN_args) \
    { \
        NULL \
    } \
})

/* overloading of methods with parameters */
/* parametred constructor */
#define ddUKsuMN_new(option, ...) \
ddUKsuMN_ \
(&(struct ddUKsuMN_overloads) \
{ \
    .options = CAT(ddUKsuMN_new_,option), \
    &(union ddUKsuMN_args) \
    { \
        .CAT(new_,option)= {__VA_ARGS__} \
    } \
})

#endif //ddUKsuMN_H