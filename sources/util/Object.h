#ifndef KPLGWrfu_H
#define KPLGWrfu_H

#define _CLASS_PUBLIC_ID_ KPLGWrfu
#define __CLASS_PUBLIC_ID__ CAT(_CLASS_PUBLIC_ID_,_)

#define CLASS _CLASS_PUBLIC_ID_
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
    METHOD_OD(public, void , setPrivateAttribute, char *) \
    METHOD_OD(public, void , setAlternativePrivateAttribute, double) \
    METHOD_OD(public, char *, getPrivateAttribute, ...) \
    METHOD_OD(public, double, getAlternativePrivateAttribute, ...) \
    METHOD_OD(public, void , setProtectedAttribute, char *) \
    METHOD_OD(public, void , setAlternativeProtectedAttribute, char) \
    METHOD_OD(public, char *, getProtectedAttribute, ...) \
    METHOD_OD(public, char, getAlternativeProtectedAttribute, ...) \
    ATTRIBUTE(private_method, ENCAPSULATED, aMethod) \
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

struct CAT(_CLASS_PUBLIC_ID_,_overloads)
{
    enum CAT(_CLASS_PUBLIC_ID_,_options)
    {
        CAT(_CLASS_PUBLIC_ID_,_new_o1),
        CAT(_CLASS_PUBLIC_ID_,_new_o2),
        CAT(_CLASS_PUBLIC_ID_,_new_),
        CAT(_CLASS_PUBLIC_ID_,_aMethod_o1),
        CAT(_CLASS_PUBLIC_ID_,_aMethod_o2),
        CAT(_CLASS_PUBLIC_ID_,_aMethod_)
    }options;
    union
    {
        struct CAT(_CLASS_PUBLIC_ID_,_new_o1)
        {
            char *arg1;
            char *arg2;
            char *arg3;
            char *arg4;
            struct UQZwMHfN *arg5;
        }new_o1;
        struct CAT(_CLASS_PUBLIC_ID_,_new_o2)
        {
            int arg1;
            float arg2;
            char arg3;
            double arg4;
        }new_o2;
        struct CAT(_CLASS_PUBLIC_ID_,_aMethod_o1)
        {
            float arg1;
            float arg2;
        }aMethod_o1;
        struct CAT(_CLASS_PUBLIC_ID_,_aMethod_o2)
        {
            int arg1;
            int arg2;
        }aMethod_o2;
        struct CAT(_CLASS_PUBLIC_ID_,_new_){}new_;
        struct CAT(_CLASS_PUBLIC_ID_,_aMethod_){}aMethod_;
    };
};

struct _CLASS_PUBLIC_ID_ *(_CLASS_PUBLIC_ID_)(struct CAT(_CLASS_PUBLIC_ID_,_overloads) *, bool, struct __CLASS_PUBLIC_ID__ *);

#undef _CLASS_PUBLIC_ID_
#undef __CLASS_PUBLIC_ID__

#if defined(protected_KPLGWrfu_start) && !defined(protected_KPLGWrfu_stop)

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
    METHOD_OD(public, void , setPrivateAttribute, char *) \
    METHOD_OD(public, void , setAlternativePrivateAttribute, double) \
    METHOD_OD(public, char *, getPrivateAttribute, ...) \
    METHOD_OD(public, double, getAlternativePrivateAttribute, ...) \
    METHOD_OD(public, void , setProtectedAttribute, char *) \
    METHOD_OD(public, void , setAlternativeProtectedAttribute, char) \
    METHOD_OD(public, char *, getProtectedAttribute, ...) \
    METHOD_OD(public, char, getAlternativeProtectedAttribute, ...) \
    ATTRIBUTE(private_method, ENCAPSULATED, aMethod) \
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

#define protected_KPLGWrfu_stop
#elif (defined(package_KPLGWrfu_start) && !defined(package_KPLGWrfu_stop)) || (defined(package_kdzvSGAN_start) && !defined(package_kdzvSGAN_stop))

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
    METHOD_OD(public, void , setPrivateAttribute, char *) \
    METHOD_OD(public, void , setAlternativePrivateAttribute, double) \
    METHOD_OD(public, char *, getPrivateAttribute, ...) \
    METHOD_OD(public, double, getAlternativePrivateAttribute, ...) \
    METHOD_OD(public, void , setProtectedAttribute, char *) \
    METHOD_OD(public, void , setAlternativeProtectedAttribute, char) \
    METHOD_OD(public, char *, getProtectedAttribute, ...) \
    METHOD_OD(public, char, getAlternativeProtectedAttribute, ...) \
    ATTRIBUTE(private_method, ENCAPSULATED, aMethod) \
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

#define package_KPLGWrfu_stop
#endif

#define KPLGWrfu(option, ...) (KPLGWrfu)\
(&(struct KPLGWrfu_overloads) \
{ \
    .options = CAT(KPLGWrfu_new_,option), \
    .CAT(new_,option)= {__VA_ARGS__} \
}, $YES, NULL)

#endif //KPLGWrfu_H
