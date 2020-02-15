#ifndef YPnOLrQT_H
#define YPnOLrQT_H

#define protected_ddUKsuMN_start
#include "Derived.h"
#define protected_lbdtYEkR_start
#include "Another.h"

#define _CLASS_PUBLIC_ID_ YPnOLrQT
#define __CLASS_PUBLIC_ID__ CAT(YPnOLrQT,_)

#define CLASS _CLASS_PUBLIC_ID_
#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(ddUKsuMN, Derived) \
    EXTENDS_OD(lbdtYEkR, Another)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(ddUKsuMN, Derived) \
    EXTENDS_CD(lbdtYEkR, Another)
#include "../objectModel.h"

#if defined(protected_YPnOLrQT_start) && !defined(protected_YPnOLrQT_stop)

#define CLASS Geometric
#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(Derived, Derived) \
    EXTENDS_OD(Another, Another)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(Derived, Derived) \
    EXTENDS_CD(Another, Another)
#include "../objectModel.h"

#define protected_YPnOLrQT_stop
#elif (defined(package_YPnOLrQT_start) && !defined(package_YPnOLrQT_stop)) || (defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop))

#define CLASS Geometric
#define OBJECT_DESCRIPTOR \
    EXTENDS_OD(Derived, Derived) \
    EXTENDS_OD(Another, Another)
#define CLASS_DESCRIPTOR \
    EXTENDS_CD(Derived, Derived) \
    EXTENDS_CD(Another, Another)
#include "../objectModel.h"

#define package_YPnOLrQT_stop
#endif

struct _CLASS_PUBLIC_ID_ *(_CLASS_PUBLIC_ID_)(bool, bool, struct __CLASS_PUBLIC_ID__ *);

#undef _CLASS_PUBLIC_ID_
#undef __CLASS_PUBLIC_ID__

#define YPnOLrQT() (YPnOLrQT)(FC_WITHOUT_OV, $YES, NULL)

#endif //YPnOLrQT_H
