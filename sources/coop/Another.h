#ifndef lbdtYEkR_H
#define lbdtYEkR_H

#define protected_kGAzHwmx_start
#include "Object.h"

#if defined(protected_lbdtYEkR_start) && !defined(protected_lbdtYEkR_stop)

#define CLASS Another
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

#define protected_lbdtYEkR_stop
#elif (defined(package_lbdtYEkR_start) && !defined(package_lbdtYEkR_stop)) || (defined(coop_package_start) && !defined(coop_package_stop))

#define CLASS Another
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

#define package_lbdtYEkR_stop
#endif

#define CLASS lbdtYEkR
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

struct lbdtYEkR *lbdtYEkR_(void *);

#define lbdtYEkR_new(...) _Generic((__VA_ARGS__+0), void * : lbdtYEkR_(NULL), default : lbdtYEkR_((void *) 1))

#endif
