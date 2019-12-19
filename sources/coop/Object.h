#ifndef kGAzHwmx_H
#define kGAzHwmx_H

#if defined(protected_kGAzHwmx_start) && !defined(protected_kGAzHwmx_stop)

#define CLASS Object
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
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

#define protected_kGAzHwmx_stop
#elif (defined(package_kGAzHwmx_start) && !defined(package_kGAzHwmx_stop)) || (defined(coop_package_start) && !defined(coop_package_stop))

#define CLASS Object
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
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

#define package_kGAzHwmx_stop
#endif

#define CLASS kGAzHwmx
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
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

struct kGAzHwmx_overloads
{
    enum kGAzHwmx_options
    {
        kGAzHwmx_new_o1,
        kGAzHwmx_new_o2,
        kGAzHwmx_none
    }options;
    union kGAzHwmx_args
    {
        struct kGAzHwmx_new_o1
        {
            char *arg1;
            char *arg2;
            char *arg3;
            char *arg4;
        }new_o1;
        struct kGAzHwmx_new_o2
        {
            int arg1;
            float arg2;
            char arg3;
            double arg4;
        }new_o2;
    }*overloads;
};

struct kGAzHwmx *kGAzHwmx_(struct kGAzHwmx_overloads *);

/* overloading of methods without parameters */
/* default constructor */
#define kGAzHwmx_new_() \
kGAzHwmx_ \
(&(struct kGAzHwmx_overloads) \
{ \
    .options = kGAzHwmx_none, \
    &(union kGAzHwmx_args) \
    { \
        NULL \
    } \
})

/* overloading of methods with parameters */
/* parametred constructor */
#define kGAzHwmx_new(option, ...) \
kGAzHwmx_ \
(&(struct kGAzHwmx_overloads) \
{ \
    .options = CAT(kGAzHwmx_new_,option), \
    &(union kGAzHwmx_args) \
    { \
        .CAT(new_,option)= {__VA_ARGS__} \
    } \
})

#endif //kGAzHwmx_H
