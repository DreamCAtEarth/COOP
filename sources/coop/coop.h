#ifndef COOP_H
#define COOP_H

#include "Object.h"
#include "Derived.h"

#if defined(package_coop_start) && !defined(package_coop_stop)

struct coop
{
    struct Object_ *Object;
    struct Derived_ *Derived;
}coop;

#define package_coop_stop
#else

struct coop
{
    struct kGAzHwmx_ *Object;
    struct ddUKsuMN_ *Derived;
}coop;

#endif

/* declaration of new classes or new OO types for variables */
#define kGAz_Hwmx struct kGAzHwmx *
#define ddUK_suMN struct ddUKsuMN *

#endif //COOP_H