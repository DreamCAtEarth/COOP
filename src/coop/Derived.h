#ifndef ddUKsuMN_H
#define ddUKsuMN_H

#define protected_kGAzHwmx Object
#include "Object.h"

#define CLASS ddUKsuMN
#define INHERITANCE_DESCRIPTION                                                     \
    extends(kGAzHwmx, Object)                                                       \
    override(Object, getProtectedAttribute, struct Object *, char *, struct ME *)
#define OBJECT_DESCRIPTOR
#define CLASS_DESCRIPTOR                                                            \
    method(namespace, void, absCustom, void)                                        \
    method(protected, void, useCustom, void)
#define OVERLOADING                                                                 \
    method(new, o1, char *arg1; char *arg2; char *arg3)                             \
    method(new, o2, int arg1; float arg2; char arg3)                                \
    defaultMethod(new)
#include <objectModel.h>

#endif
