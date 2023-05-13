#ifndef BwXbIZdw_H
#define BwXbIZdw_H

#define CLASS BwXbIZdw
#define OBJECT_DESCRIPTOR                       \
    attribute(private, bool, value)
#define CLASS_DESCRIPTOR                        \
    method(public, bool, getValue, this)        \
    method(public, void, setValue, this, bool)
#include <objectModel.h>

#endif
