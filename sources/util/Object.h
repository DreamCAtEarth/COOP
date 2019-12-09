#ifndef KPLGWrfu_H
#define KPLGWrfu_H

#if defined(protected_KPLGWrfu_start) && !defined(protected_KPLGWrfu_stop)

#define CLASS Object
#define INSTANCE_DESCRIPTOR \
    ATTRIBUTE(public, char *, publicAttribute) \
    ATTRIBUTE(public, int, alternativePublicAttribute) \
    ATTRIBUTE(package, char *, packageAttribute) \
    ATTRIBUTE(package, float, alternativePackageAttribute) \
    ATTRIBUTE(protected, char *, protectedAttribute) \
    ATTRIBUTE(protected, char, alternativeProtectedAttribute) \
    ATTRIBUTE(private, const void * const, privateAttribute) \
    ATTRIBUTE(private, const void * const, alternativePrivateAttribute)
#define CLASS_DESCRIPTOR \
    METHOD_CD(public static, void , setClassName, const char *) \
    METHOD_CD(public static, const char *, getClassName, ...) \
    METHOD_ID(public, void , setPrivateAttribute, char *) \
    METHOD_ID(public, void , setAlternativePrivateAttribute, double) \
    METHOD_ID(public, char *, getPrivateAttribute, ...) \
    METHOD_ID(public, double, getAlternativePrivateAttribute, ...) \
    METHOD_ID(public, void , setProtectedAttribute, char *) \
    METHOD_ID(public, void , setAlternativeProtectedAttribute, char) \
    METHOD_ID(public, char *, getProtectedAttribute, ...) \
    METHOD_ID(public, char, getAlternativeProtectedAttribute, ...) \
    ATTRIBUTE(private static, const void * const, className)
#include "../objectModel.h"

#define protected_KPLGWrfu_stop
#elif defined(package_KPLGWrfu_start) && !defined(package_KPLGWrfu_stop)

#define CLASS Object
#define INSTANCE_DESCRIPTOR \
    ATTRIBUTE(public, char *, publicAttribute) \
    ATTRIBUTE(public, int, alternativePublicAttribute) \
    ATTRIBUTE(package, char *, packageAttribute) \
    ATTRIBUTE(package, float, alternativePackageAttribute) \
    ATTRIBUTE(protected, const void * const, protectedAttribute) \
    ATTRIBUTE(protected, const void * const, alternativeProtectedAttribute) \
    ATTRIBUTE(private, const void * const, privateAttribute) \
    ATTRIBUTE(private, const void * const, alternativePrivateAttribute)
#define CLASS_DESCRIPTOR \
    METHOD_CD(public static, void , setClassName, const char *) \
    METHOD_CD(public static, const char *, getClassName, ...) \
    METHOD_ID(public, void , setPrivateAttribute, char *) \
    METHOD_ID(public, void , setAlternativePrivateAttribute, double) \
    METHOD_ID(public, char *, getPrivateAttribute, ...) \
    METHOD_ID(public, double, getAlternativePrivateAttribute, ...) \
    METHOD_ID(public, void , setProtectedAttribute, char *) \
    METHOD_ID(public, void , setAlternativeProtectedAttribute, char) \
    METHOD_ID(public, char *, getProtectedAttribute, ...) \
    METHOD_ID(public, char, getAlternativeProtectedAttribute, ...) \
    ATTRIBUTE(private static, const void * const, className)
#include "../objectModel.h"

#define package_KPLGWrfu_stop
#endif

#define CLASS KPLGWrfu
#define INSTANCE_DESCRIPTOR \
    ATTRIBUTE(public, char *, publicAttribute) \
    ATTRIBUTE(public, int, alternativePublicAttribute) \
    ATTRIBUTE(package, const void * const, packageAttribute) \
    ATTRIBUTE(package, const void * const, alternativePackageAttribute) \
    ATTRIBUTE(protected, const void * const, protectedAttribute) \
    ATTRIBUTE(protected, const void * const, alternativeProtectedAttribute) \
    ATTRIBUTE(private, const void * const, privateAttribute) \
    ATTRIBUTE(private, const void * const, alternativePrivateAttribute)
#define CLASS_DESCRIPTOR \
    METHOD_CD(public static, void , setClassName, const char *) \
    METHOD_CD(public static, const char *, getClassName, ...) \
    METHOD_ID(public, void , setPrivateAttribute, char *) \
    METHOD_ID(public, void , setAlternativePrivateAttribute, double) \
    METHOD_ID(public, char *, getPrivateAttribute, ...) \
    METHOD_ID(public, double, getAlternativePrivateAttribute, ...) \
    METHOD_ID(public, void , setProtectedAttribute, char *) \
    METHOD_ID(public, void , setAlternativeProtectedAttribute, char) \
    METHOD_ID(public, char *, getProtectedAttribute, ...) \
    METHOD_ID(public, char, getAlternativeProtectedAttribute, ...) \
    ATTRIBUTE(private static, const void * const, className)
#include "../objectModel.h"

struct KPLGWrfu_overloads
{
    enum KPLGWrfu_options
    {
        KPLGWrfu_new_o1,
        KPLGWrfu_new_o2,
        KPLGWrfu_none
    }options;
    union KPLGWrfu_args
    {
        struct KPLGWrfu_new_o1
        {
            char *arg1;
            char *arg2;
            char *arg3;
            char *arg4;
        }new_o1;
        struct KPLGWrfu_new_o2
        {
            int arg1;
            float arg2;
            char arg3;
            double arg4;
        }new_o2;
    }*overloads;
};

struct KPLGWrfu *KPLGWrfu_(struct KPLGWrfu_overloads *);

/* overloading of methods without parameters */
#define KPLGWrfu_new_() \
KPLGWrfu_ \
(&(struct KPLGWrfu_overloads) \
{ \
    .options = KPLGWrfu_none, \
    &(union KPLGWrfu_args) \
    { \
        NULL \
    } \
})

/* overloading of methods with parameters */
#define KPLGWrfu_new(option, ...) \
KPLGWrfu_ \
(&(struct KPLGWrfu_overloads) \
{ \
    .options = CAT(KPLGWrfu_new_,option), \
    &(union KPLGWrfu_args) \
    { \
        .CAT(new_,option)= {__VA_ARGS__} \
    } \
})

#endif //KPLGWrfu_H
