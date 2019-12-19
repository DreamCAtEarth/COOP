#ifndef COOP_H
#define COOP_H

#include "Object.h"
#include "Derived.h"
#include "Another.h"
#include "Geometric.h"

#if defined(package_coop_start) && !defined(package_coop_stop)

struct coop
{
    struct Object_ *Object;
    struct Derived_ *Derived;
    struct Another_ *Another;
    struct Geometric_ *Geometric;
}coop;

#define package_coop_stop
#else

struct coop
{
    struct kGAzHwmx_ *Object;
    struct ddUKsuMN_ *Derived;
    struct lbdtYEkR_ *Another;
    struct YPnOLrQT_ *Geometric;
}coop;

#endif

/* declaration of new classes or new OO types for variables */
#define kGAz_Hwmx struct kGAzHwmx *
#define ddUK_suMN struct ddUKsuMN *
#define lbdt_YEkR struct lbdtYEkR *
#define YPnO_LrQT struct YPnOLrQT *

#endif //COOP_H