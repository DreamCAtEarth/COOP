#ifndef lbdtYEkR_H
#define lbdtYEkR_H

#define protected_kGAzHwmx_start
#include "Object.h"

#define _CLASS_PUBLIC_ID_ lbdtYEkR
#define __CLASS_PUBLIC_ID__ CAT(_CLASS_PUBLIC_ID_,_)

#define CLASS _CLASS_PUBLIC_ID_
#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(kGAzHwmx, Object)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(kGAzHwmx, Object) \
    ATTRIBUTE(package_static_method, ENCAPSULATED, absCustom) \
    ATTRIBUTE(protected_static_method, ENCAPSULATED, useCustom)
#include "../objectModel.h"

#if defined(protected_lbdtYEkR_start) && !defined(protected_lbdtYEkR_stop)

#define CLASS Another
#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(Object, Object)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(Object, Object) \
    METHOD_CD(package_static_method, void, absCustom, ...) \
    METHOD_CD(protected_static_method, void, useCustom, ...)
#include "../objectModel.h"

#define protected_lbdtYEkR_stop
#elif (defined(package_lbdtYEkR_start) && !defined(package_lbdtYEkR_stop)) || (defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop))

#define CLASS Another
#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(Object, Object)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(Object, Object) \
    METHOD_CD(package_static, void, absCustom, ...) \
    ATTRIBUTE(protected_static_method, ENCAPSULATED, useCustom)
#include "../objectModel.h"

#define package_lbdtYEkR_stop
#endif

struct _CLASS_PUBLIC_ID_ *(_CLASS_PUBLIC_ID_)(bool, bool, struct __CLASS_PUBLIC_ID__ *);

#undef _CLASS_PUBLIC_ID_
#undef __CLASS_PUBLIC_ID__

#define lbdtYEkR() (lbdtYEkR)(FC_WITHOUT_OV, $YES, NULL)

#endif //lbdtYEkR_H
