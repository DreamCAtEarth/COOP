#ifndef BwXbIZdw_H
#define BwXbIZdw_H

#define _CLASS_PUBLIC_ID_ BwXbIZdw
#define __CLASS_PUBLIC_ID__ CAT(_CLASS_PUBLIC_ID_,_)
#define IMPLEMENTATION implementTester

#define CLASS _CLASS_PUBLIC_ID_
#define OBJECT_DESCRIPTOR                                           \
    ATTRIBUTE(private, ENCAPSULATED, value)
#define CLASS_DESCRIPTOR                                            \
    METHOD_OD(public, bool , getValue)                              \
    METHOD_OD(public, void , setValue, bool)                        \
    METHOD_IM(public, void, IMPLEMENTATION, wrapperOfBooleans)
#include "../../objectModel.h"

size_t CAT(_CLASS_PUBLIC_ID_, _getSize)(struct __CLASS_PUBLIC_ID__ **);
void (_CLASS_PUBLIC_ID_)(struct _CLASS_PUBLIC_ID_ *, void *);
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

#if defined(protected_BwXbIZdw_start) && !defined(protected_BwXbIZdw_stop)

#define _CLASS_PROTECTED_ Bool
#define __CLASS_PROTECTED__ CAT(_CLASS_PROTECTED_,_)

#define CLASS _CLASS_PROTECTED_
#define OBJECT_DESCRIPTOR                                           \
    ATTRIBUTE(private, ENCAPSULATED, value)
#define CLASS_DESCRIPTOR                                            \
    METHOD_OD(public, bool , getValue)                              \
    METHOD_OD(public, void , setValue, bool)                        \
    METHOD_IM(public, void, IMPLEMENTATION, wrapperOfBooleans)
#include "../../objectModel.h"

#undef _CLASS_PROTECTED_
#undef __CLASS_PROTECTED__

#define protected_BwXbIZdw_stop
#elif (defined(package_nnVYoBNR_start) && !defined(package_nnVYoBNR_stop)) && !defined(Bool_family)

#define _CLASS_PACKAGED_ Bool
#define __CLASS_PACKAGED__ CAT(_CLASS_PACKAGED_,_)

#define CLASS _CLASS_PACKAGED_
#define OBJECT_DESCRIPTOR                                           \
    ATTRIBUTE(private, ENCAPSULATED, value)
#define CLASS_DESCRIPTOR                                            \
    METHOD_OD(public, bool , getValue)                              \
    METHOD_OD(public, void , setValue, bool)                        \
    METHOD_IM(public, void, IMPLEMENTATION, wrapperOfBooleans)
#include "../../objectModel.h"

#undef _CLASS_PACKAGED_
#undef __CLASS_PACKAGED__

#endif

#undef IMPLEMENTATION

#endif //BwXbIZdw_H
