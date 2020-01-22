#ifndef UTIL_H
#define UTIL_H

#include "Object.h"

#if defined(package_kdzvSGAN_start) && !defined(package_kdzvSGAN_stop)

struct util
{
    struct Object_ *Object;
}util;

#define package_kdzvSGAN_stop
#else

struct util
{
    struct KPLGWrfu_ *Object;
}util;

#endif

#endif //UTIL_H
