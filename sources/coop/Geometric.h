#ifndef YPnOLrQT_H
#define YPnOLrQT_H

#define protected_ddUKsuMN_start
#include "Derived.h"
#define protected_lbdtYEkR_start
#include "Another.h"

#define _CLASS_PUBLIC_ID_ YPnOLrQT
#define __CLASS_PUBLIC_ID__ CAT(YPnOLrQT,_)

#define CLASS _CLASS_PUBLIC_ID_
#define OBJECT_DESCRIPTOR           \
    EXTENDS_OD(ddUKsuMN, Derived)   \
    EXTENDS_OD(lbdtYEkR, Another)
#define CLASS_DESCRIPTOR            \
    EXTENDS_CD(ddUKsuMN, Derived)   \
    EXTENDS_CD(lbdtYEkR, Another)
#include "../objectModel.h"

size_t CAT(_CLASS_PUBLIC_ID_, _getSize)(struct __CLASS_PUBLIC_ID__ **);
void (_CLASS_PUBLIC_ID_)(struct _CLASS_PUBLIC_ID_ *this, void *);
void CAT(_CLASS_PUBLIC_ID_,_)(void);

struct CAT(_CLASS_PUBLIC_ID_,_overloads)
{
    enum CAT(_CLASS_PUBLIC_ID_,_options)
    {
        CAT(_CLASS_PUBLIC_ID_,_new_)
    }options;
    union
    {
        struct CAT(_CLASS_PUBLIC_ID_,_new_){}new_;
    };
};

#undef _CLASS_PUBLIC_ID_
#undef __CLASS_PUBLIC_ID__

#if defined(protected_YPnOLrQT_start) && !defined(protected_YPnOLrQT_stop)

#define _CLASS_PROTECTED_ Geometric
#define __CLASS_PROTECTED__ CAT(_CLASS_PROTECTED_,_)

#define CLASS _CLASS_PROTECTED_
#define OBJECT_DESCRIPTOR           \
    EXTENDS_OD(Derived, Derived)    \
    EXTENDS_OD(Another, Another)
#define CLASS_DESCRIPTOR            \
    EXTENDS_CD(Derived, Derived)    \
    EXTENDS_CD(Another, Another)
#include "../objectModel.h"

#undef _CLASS_PROTECTED_
#undef __CLASS_PROTECTED__

#define protected_YPnOLrQT_stop
#elif (defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop)) && !defined(Object_family)

#define _CLASS_PACKAGED_ Geometric
#define __CLASS_PACKAGED__ CAT(_CLASS_PACKAGED_,_)

#define CLASS _CLASS_PACKAGED_
#define OBJECT_DESCRIPTOR           \
    EXTENDS_OD(Derived, Derived)    \
    EXTENDS_OD(Another, Another)
#define CLASS_DESCRIPTOR            \
    EXTENDS_CD(Derived, Derived)    \
    EXTENDS_CD(Another, Another)
#include "../objectModel.h"

#undef _CLASS_PACKAGED_
#undef __CLASS_PACKAGED__

#endif

#endif //YPnOLrQT_H
