#ifndef UTIL_H
#define UTIL_H

#include "Object.h"

#if defined(package_util_start) && !defined(package_util_stop)

struct util
{
    struct Object_ *Object;
}util;

#define package_util_stop
#else

struct util
{
    struct KPLGWrfu_ *Object;
}util;

#endif

/* declaration of new classes or new OO types for variables */
#define KPLG_Wrfu struct KPLGWrfu *

#endif //UTIL_H