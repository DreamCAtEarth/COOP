#ifndef UQZwMHfN_H
#define UQZwMHfN_H

#define _CLASS_PUBLIC_ID_ UQZwMHfN
#define __CLASS_PUBLIC_ID__ CAT(UQZwMHfN,_)

#define CLASS _CLASS_PUBLIC_ID_
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, ENCAPSULATED, length) \
    ATTRIBUTE(private, ENCAPSULATED, width)
#define CLASS_DESCRIPTOR \
    METHOD_OD(public, int , area, ...)
#include "../objectModel.h"

#if defined(protected_UQZwMHfN_start) && !defined(protected_UQZwMHfN_stop)

#define CLASS Square
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, ENCAPSULATED, length) \
    ATTRIBUTE(private, ENCAPSULATED, width)
#define CLASS_DESCRIPTOR \
    METHOD_OD(public, int , area, ...)
#include "../objectModel.h"

#define protected_UQZwMHfN_stop
#elif (defined(package_UQZwMHfN_start) && !defined(package_UQZwMHfN_stop)) || (defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop))

#define CLASS Square
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, ENCAPSULATED, length) \
    ATTRIBUTE(private, ENCAPSULATED, width)
#define CLASS_DESCRIPTOR \
    METHOD_OD(public, int , area, ...)
#include "../objectModel.h"

#define package_UQZwMHfN_stop
#endif

struct _CLASS_PUBLIC_ID_ *(_CLASS_PUBLIC_ID_)(bool, bool, struct __CLASS_PUBLIC_ID__ *);

#undef _CLASS_PUBLIC_ID_
#undef __CLASS_PUBLIC_ID__

#define UQZwMHfN() (UQZwMHfN)(FC_WITHOUT_OV, $YES, NULL)

#endif //UQZwMHfN_H
