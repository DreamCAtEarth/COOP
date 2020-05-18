#ifndef kGAzHwmx_H
#define kGAzHwmx_H

#define _CLASS_PUBLIC_ID_ kGAzHwmx
#define __CLASS_PUBLIC_ID__ CAT(_CLASS_PUBLIC_ID_,_)

#define CLASS _CLASS_PUBLIC_ID_
#define OBJECT_DESCRIPTOR                                               \
    ATTRIBUTE(public, char *, publicAttribute)                          \
    ATTRIBUTE(public, int, alternativePublicAttribute)                  \
    ATTRIBUTE(package, ENCAPSULATED, packageAttribute)                  \
    ATTRIBUTE(package, ENCAPSULATED, alternativePackageAttribute)       \
    ATTRIBUTE(protected, ENCAPSULATED, protectedAttribute)              \
    ATTRIBUTE(protected, ENCAPSULATED, alternativeProtectedAttribute)   \
    ATTRIBUTE(private, ENCAPSULATED, privateAttribute)                  \
    ATTRIBUTE(private, ENCAPSULATED, alternativePrivateAttribute)
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
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

struct CAT(_CLASS_PUBLIC_ID_,_overloads)
{
    enum CAT(_CLASS_PUBLIC_ID_,_options)
    {
        CAT(_CLASS_PUBLIC_ID_,_new_o1),
        CAT(_CLASS_PUBLIC_ID_,_new_o2),
        CAT(_CLASS_PUBLIC_ID_,_new_)
    }options;
    union
    {
        struct CAT(_CLASS_PUBLIC_ID_,_new_o1)
        {
            char *arg1;
            char *arg2;
            char *arg3;
            char *arg4;
        }new_o1;
        struct CAT(_CLASS_PUBLIC_ID_,_new_o2)
        {
            int arg1;
            float arg2;
            char arg3;
            double arg4;
        }new_o2;
        struct CAT(_CLASS_PUBLIC_ID_,_new_){}new_;
    };
};

size_t CAT(_CLASS_PUBLIC_ID_, _getSize)(struct __CLASS_PUBLIC_ID__ **);
void (_CLASS_PUBLIC_ID_)(struct _CLASS_PUBLIC_ID_ *, struct CAT(_CLASS_PUBLIC_ID_,_overloads) *);
void CAT(_CLASS_PUBLIC_ID_, _)(void);

#undef _CLASS_PUBLIC_ID_
#undef __CLASS_PUBLIC_ID__

#if defined(protected_kGAzHwmx_start) && !defined(protected_kGAzHwmx_stop)

#define _CLASS_PROTECTED_ Object
#define __CLASS_PROTECTED__ CAT(_CLASS_PROTECTED_,_)

#define CLASS _CLASS_PROTECTED_
#define OBJECT_DESCRIPTOR                                               \
    ATTRIBUTE(public, char *, publicAttribute)                          \
    ATTRIBUTE(public, int, alternativePublicAttribute)                  \
    ATTRIBUTE(package, char *, packageAttribute)                        \
    ATTRIBUTE(package, float, alternativePackageAttribute)              \
    ATTRIBUTE(protected, char *, protectedAttribute)                    \
    ATTRIBUTE(protected, char, alternativeProtectedAttribute)           \
    ATTRIBUTE(private, ENCAPSULATED, privateAttribute)                  \
    ATTRIBUTE(private, ENCAPSULATED, alternativePrivateAttribute)
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
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

#undef _CLASS_PROTECTED_
#undef __CLASS_PROTECTED__

#define protected_kGAzHwmx_stop
#elif (defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop)) && !defined(Object_family)

#define _CLASS_PACKAGED_ Object
#define __CLASS_PACKAGED__ CAT(_CLASS_PACKAGED_,_)

#define CLASS _CLASS_PACKAGED_
#define OBJECT_DESCRIPTOR                                               \
    ATTRIBUTE(public, char *, publicAttribute)                          \
    ATTRIBUTE(public, int, alternativePublicAttribute)                  \
    ATTRIBUTE(package, char *, packageAttribute)                        \
    ATTRIBUTE(package, float, alternativePackageAttribute)              \
    ATTRIBUTE(protected, ENCAPSULATED, protectedAttribute)              \
    ATTRIBUTE(protected, ENCAPSULATED, alternativeProtectedAttribute)   \
    ATTRIBUTE(private, ENCAPSULATED, privateAttribute)                  \
    ATTRIBUTE(private, ENCAPSULATED, alternativePrivateAttribute)
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
    ATTRIBUTE(private_static, ENCAPSULATED, className)
#include "../objectModel.h"

#undef _CLASS_PACKAGED_
#undef __CLASS_PACKAGED__

#endif

#endif //kGAzHwmx_H
