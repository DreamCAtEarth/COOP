#ifndef ddUKsuMN_H
#define ddUKsuMN_H

#define protected_kGAzHwmx_start
#include "Object.h"

#define _CLASS_PUBLIC_ID_ ddUKsuMN
#define __CLASS_PUBLIC_ID__ CAT(_CLASS_PUBLIC_ID_,_)

#define CLASS _CLASS_PUBLIC_ID_
#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(kGAzHwmx, Object)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(kGAzHwmx, Object) \
    ATTRIBUTE(package_static_method, ENCAPSULATED, absCustom) \
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

struct _CLASS_PUBLIC_ID_ *(_CLASS_PUBLIC_ID_)(struct CAT(_CLASS_PUBLIC_ID_,_overloads) *, bool, struct __CLASS_PUBLIC_ID__ *);

#if defined(protected_ddUKsuMN_start) && !defined(protected_ddUKsuMN_stop)

#define CLASS Derived
#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(Object, Object)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(Object, Object) \
    METHOD_CD(package_static_method, void, absCustom, ...) \
    METHOD_CD(protected_static_method, void, useCustom, ...)
#include "../objectModel.h"

#define protected_ddUKsuMN_stop
#elif (defined(package_ddUKsuMN_start) && !defined(package_ddUKsuMN_stop)) || (defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop))

#define CLASS Derived
#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(Object, Object)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(Object, Object) \
    METHOD_CD(package_static, void, absCustom, ...) \
    ATTRIBUTE(protected_static_method, ENCAPSULATED, useCustom)
#include "../objectModel.h"

#define package_ddUKsuMN_stop
#endif

#undef _CLASS_PUBLIC_ID_
#undef __CLASS_PUBLIC_ID__

#define ddUKsuMN(option, ...) (ddUKsuMN)\
(&(struct ddUKsuMN_overloads) \
{ \
    .options = CAT(ddUKsuMN_new_,option), \
    .CAT(new_,option)= {__VA_ARGS__} \
}, $YES, NULL)

#endif //ddUKsuMN_H
