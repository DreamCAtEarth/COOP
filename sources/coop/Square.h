#ifndef UQZwMHfN_H
#define UQZwMHfN_H

#define _CLASS_PUBLIC_ID_ UQZwMHfN
#define __CLASS_PUBLIC_ID__ CAT(_CLASS_PUBLIC_ID_,_)

#define CLASS _CLASS_PUBLIC_ID_
#define OBJECT_DESCRIPTOR                       \
    ATTRIBUTE(private, ENCAPSULATED, length)    \
    ATTRIBUTE(private, ENCAPSULATED, width)
#define CLASS_DESCRIPTOR                        \
    METHOD_OD(public, int, area)
#include "../objectModel.h"

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

#if defined(protected_UQZwMHfN_start) && !defined(protected_UQZwMHfN_stop)

#define _CLASS_PROTECTED_ Square
#define __CLASS_PROTECTED__ CAT(_CLASS_PROTECTED_,_)

#define CLASS _CLASS_PROTECTED_
#define OBJECT_DESCRIPTOR                       \
    ATTRIBUTE(private, ENCAPSULATED, length)    \
    ATTRIBUTE(private, ENCAPSULATED, width)
#define CLASS_DESCRIPTOR                        \
    METHOD_OD(public, int, area)
#include "../objectModel.h"

#undef _CLASS_PROTECTED_
#undef __CLASS_PROTECTED__

#define protected_UQZwMHfN_stop
#elif (defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop)) && !defined(Square_family)

#define _CLASS_PACKAGED_ Square
#define __CLASS_PACKAGED__ CAT(_CLASS_PACKAGED_,_)

#define CLASS _CLASS_PACKAGED_
#define OBJECT_DESCRIPTOR                       \
    ATTRIBUTE(private, ENCAPSULATED, length)    \
    ATTRIBUTE(private, ENCAPSULATED, width)
#define CLASS_DESCRIPTOR                        \
    METHOD_OD(public, int, area)
#include "../objectModel.h"

#undef _CLASS_PACKAGED_
#undef __CLASS_PACKAGED__

#endif

#endif //UQZwMHfN_H
