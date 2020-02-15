#ifndef BwXbIZdw_H
#define BwXbIZdw_H

#define _CLASS_PUBLIC_ID_ BwXbIZdw
#define __CLASS_PUBLIC_ID__ CAT(_CLASS_PUBLIC_ID_,_)

#define CLASS _CLASS_PUBLIC_ID_
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, ENCAPSULATED, value)
#define CLASS_DESCRIPTOR \
    METHOD_OD(public, bool , getValue, ...) \
    METHOD_OD(public, void , setValue, bool) \
    ATTRIBUTE(public_interface, struct implementTester *, ToTest)
#include "../../objectModel.h"

#if defined(protected_BwXbIZdw_start) && !defined(protected_BwXbIZdw_stop)

#define CLASS Bool
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, ENCAPSULATED, value)
#define CLASS_DESCRIPTOR \
    METHOD_OD(public, bool , getValue, ...) \
    METHOD_OD(public, void , setValue, bool) \
    ATTRIBUTE(public_interface, struct implementTester *, ToTest)
#include "../../objectModel.h"

#define protected_BwXbIZdw_stop
#elif (defined(package_BwXbIZdw_start) && !defined(package_BwXbIZdw_stop)) || (defined(package_nnVYoBNR_start) && !defined(package_nnVYoBNR_stop))

#define CLASS Bool
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, ENCAPSULATED, value)
#define CLASS_DESCRIPTOR \
    METHOD_OD(public, bool , getValue, ...) \
    METHOD_OD(public, void , setValue, bool) \
    ATTRIBUTE(public_interface, struct implementTester *, ToTest)
#include "../../objectModel.h"

#define package_BwXbIZdw_stop
#endif

struct _CLASS_PUBLIC_ID_ *(_CLASS_PUBLIC_ID_)(bool, bool, struct __CLASS_PUBLIC_ID__ *);

#undef _CLASS_PUBLIC_ID_
#undef __CLASS_PUBLIC_ID__

#define BwXbIZdw() (BwXbIZdw)(FC_WITHOUT_OV, $YES, NULL)

#endif //BwXbIZdw_H
