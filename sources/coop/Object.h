#ifndef kGAzHwmx_H
#define kGAzHwmx_H

#define CLASS_DECLARATION kGAzHwmx

#define CLASS CLASS_DECLARATION
#define OBJECT_DESCRIPTOR \
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
    ATTRIBUTE(private_method, ENCAPSULATED, aMethod) \
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

struct CAT(CLASS_DECLARATION,_overloads)
{
    enum CAT(CLASS_DECLARATION,_options)
    {
        CAT(CLASS_DECLARATION,_new_o1),
        CAT(CLASS_DECLARATION,_new_o2),
        CAT(CLASS_DECLARATION,_new_),
        CAT(CLASS_DECLARATION,_aMethod_o1),
        CAT(CLASS_DECLARATION,_aMethod_o2),
        CAT(CLASS_DECLARATION,_aMethod_)
    }options;
    union
    {
        struct CAT(CLASS_DECLARATION,_new_o1)
        {
            char *arg1;
            char *arg2;
            char *arg3;
            char *arg4;
            struct UQZwMHfN *arg5;
        }new_o1;
        struct CAT(CLASS_DECLARATION,_new_o2)
        {
            int arg1;
            float arg2;
            char arg3;
            double arg4;
        }new_o2;
        struct CAT(CLASS_DECLARATION,_aMethod_o1)
        {
            float arg1;
            float arg2;
        }aMethod_o1;
        struct CAT(CLASS_DECLARATION,_aMethod_o2)
        {
            int arg1;
            int arg2;
        }aMethod_o2;
        struct CAT(CLASS_DECLARATION,_new_){}new_;
        struct CAT(CLASS_DECLARATION,_aMethod_){}aMethod_;
    };
};

struct CLASS_DECLARATION *(CLASS_DECLARATION)(struct CAT(CLASS_DECLARATION,_overloads) *);

#undef CLASS_DECLARATION

#if defined(protected_kGAzHwmx_start) && !defined(protected_kGAzHwmx_stop)

#define CLASS Object
#define OBJECT_DESCRIPTOR \
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
    ATTRIBUTE(private_method, ENCAPSULATED, aMethod) \
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

#define protected_kGAzHwmx_stop
#elif (defined(package_kGAzHwmx_start) && !defined(package_kGAzHwmx_stop)) || (defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop))

#define CLASS Object
#define OBJECT_DESCRIPTOR \
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
    ATTRIBUTE(private_method, ENCAPSULATED, aMethod) \
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

#define package_kGAzHwmx_stop
#endif

#define kGAzHwmx(option, ...) (kGAzHwmx)\
(&(struct kGAzHwmx_overloads) \
{ \
    .options = CAT(kGAzHwmx_new_,option), \
    .CAT(new_,option)= {__VA_ARGS__} \
})

#endif //kGAzHwmx_H
