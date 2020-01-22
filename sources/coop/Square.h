#ifndef UQZwMHfN_H
#define UQZwMHfN_H

#define CLASS_DECLARATION UQZwMHfN

#if defined(protected_UQZwMHfN_start) && !defined(protected_UQZwMHfN_stop)

#define CLASS Square
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, ENCAPSULATED, length) \
    ATTRIBUTE(private, ENCAPSULATED, width)
#define CLASS_DESCRIPTOR \
    METHOD_ID(public, int , area, ...)
#include "../objectModel.h"

#define protected_UQZwMHfN_stop
#elif (defined(package_UQZwMHfN_start) && !defined(package_UQZwMHfN_stop)) || (defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop))

#define CLASS Square
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, ENCAPSULATED, length) \
    ATTRIBUTE(private, ENCAPSULATED, width)
#define CLASS_DESCRIPTOR \
    METHOD_ID(public, int , area, ...)
#include "../objectModel.h"

#define package_UQZwMHfN_stop
#endif

#define CLASS CLASS_DECLARATION
#define OBJECT_DESCRIPTOR \
    ATTRIBUTE(private, ENCAPSULATED, length) \
    ATTRIBUTE(private, ENCAPSULATED, width)
#define CLASS_DESCRIPTOR \
    METHOD_ID(public, int , area, ...)
#include "../objectModel.h"

struct CLASS_DECLARATION *(CLASS_DECLARATION)(void *);

#define UQZwMHfN(...) _Generic((__VA_ARGS__+0), void * : (UQZwMHfN)(NULL), default : (UQZwMHfN)((void *) 1))

#undef CLASS_DECLARATION

#endif //UQZwMHfN_H
