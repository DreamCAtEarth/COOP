#ifndef kdzvSGAN_H
#define kdzvSGAN_H

#include "Object.h"

#if defined(package_kdzvSGAN_start) && !defined(package_kdzvSGAN_stop)

struct util
{
    struct Object_ *Object;
}util;

#define package_kdzvSGAN_stop
#else

struct kdzvSGAN
{
    struct KPLGWrfu_ *Object;
}util;

#endif

#endif //kdzvSGAN_H
