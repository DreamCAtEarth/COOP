#ifndef ddUKsuMN_H
#define ddUKsuMN_H

#define protected_kGAzHwmx_start
#include "Object.h"

#define _CLASS_PUBLIC_ID_ ddUKsuMN
#define __CLASS_PUBLIC_ID__ CAT(_CLASS_PUBLIC_ID_,_)

#define CLASS _CLASS_PUBLIC_ID_
#define OBJECT_DESCRIPTOR                                           \
    EXTENDS_OD(kGAzHwmx, Object)
#define CLASS_DESCRIPTOR                                            \
    EXTENDS_CD(kGAzHwmx, Object)                                    \
    METHOD_OD(public, char *, getProtectedAttribute)                \
    ATTRIBUTE(package_static_method, ENCAPSULATED, absCustom)       \
    ATTRIBUTE(protected_static_method, ENCAPSULATED, useCustom)
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
        }new_o1;
        struct CAT(_CLASS_PUBLIC_ID_,_new_o2)
        {
            int arg1;
            float arg2;
            char arg3;
        }new_o2;
        struct CAT(_CLASS_PUBLIC_ID_,_new_){}new_;
    };
};

size_t CAT(_CLASS_PUBLIC_ID_, _getSize)(struct __CLASS_PUBLIC_ID__ **);
void (_CLASS_PUBLIC_ID_)(struct _CLASS_PUBLIC_ID_ *, struct CAT(_CLASS_PUBLIC_ID_,_overloads) *);
void CAT(_CLASS_PUBLIC_ID_, _)(void);

#undef _CLASS_PUBLIC_ID_
#undef __CLASS_PUBLIC_ID__

#if defined(protected_ddUKsuMN_start) && !defined(protected_ddUKsuMN_stop)

#define _CLASS_PROTECTED_ Derived
#define __CLASS_PROTECTED__ CAT(_CLASS_PROTECTED_,_)

#define CLASS _CLASS_PROTECTED_
#define OBJECT_DESCRIPTOR                               \
    EXTENDS_OD(Object, Object)
#define CLASS_DESCRIPTOR                                \
    EXTENDS_CD(Object, Object)                          \
    METHOD_OD(public, char *, getProtectedAttribute)    \
    METHOD_CD(package_static, void, absCustom)          \
    METHOD_CD(protected_static, void, useCustom)
#include "../objectModel.h"

#undef _CLASS_PROTECTED_
#undef __CLASS_PROTECTED__

#define protected_ddUKsuMN_stop
#elif (defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop)) && !defined(Object_family)

#define _CLASS_PACKAGED_ Derived
#define __CLASS_PACKAGED__ CAT(_CLASS_PACKAGED_,_)

#define CLASS _CLASS_PACKAGED_
#define OBJECT_DESCRIPTOR                                           \
    EXTENDS_OD(Object, Object)
#define CLASS_DESCRIPTOR                                            \
    EXTENDS_CD(Object, Object)                                      \
    METHOD_OD(public, char *, getProtectedAttribute)                \
    METHOD_CD(package_static, void, absCustom)                      \
    ATTRIBUTE(protected_static_method, ENCAPSULATED, useCustom)
#include "../objectModel.h"

#undef _CLASS_PACKAGED_
#undef __CLASS_PACKAGED__

#endif

#endif //ddUKsuMN_H
