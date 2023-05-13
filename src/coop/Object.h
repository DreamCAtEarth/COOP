#ifndef kGAzHwmx_H
#define kGAzHwmx_H

#define CLASS kGAzHwmx
#define OBJECT_DESCRIPTOR                                                   \
    attribute(public, char *, publicAttribute)                              \
    attribute(public, int, alternativePublicAttribute)                      \
    attribute(namespace, char *, packageAttribute)                          \
    attribute(namespace, float, alternativePackageAttribute)                \
    attribute(protected, char *, protectedAttribute)                        \
    attribute(protected, char, alternativeProtectedAttribute)               \
    attribute(private, char *, privateAttribute)                            \
    attribute(private, double, alternativePrivateAttribute)
#define CLASS_DESCRIPTOR                                                    \
    method(public, void, setClassName, const char *)                        \
    method(public, const char *, getClassName, void)                        \
    method(public, void, setPrivateAttribute, this, char *)                 \
    method(public, void, setAlternativePrivateAttribute, this, double)      \
    method(public, char *, getPrivateAttribute, this)                       \
    method(public, double, getAlternativePrivateAttribute, this)            \
    method(public, void, setProtectedAttribute, this, char *)               \
    method(public, void, setAlternativeProtectedAttribute, this, char)      \
    method(public, char *, getProtectedAttribute, that, this)               \
    method(public, char, getAlternativeProtectedAttribute, this)            \
    operator(public, 1, (Token, Operand), ^, circonflex, 9)                 \
    attribute(private, const char *, className)
#define OVERLOADING                                                         \
    method(new, o1, char *arg1; char *arg2; char *arg3; char *arg4)         \
    method(new, o2, int arg1; float arg2; char arg3; double arg4)           \
    defaultMethod(new)
#include <objectModel.h>

#endif
