#ifndef COOP_H
#define COOP_H

#include "Object.h"
#include "Derived.h"
#include "Another.h"
#include "Geometric.h"
#include "Square.h"

#if defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop)

struct coop
{
    struct Object_ *Object;
    struct Derived_ *Derived;
    struct Another_ *Another;
    struct Geometric_ *Geometric;
    struct Square_ *Square;
}coop;

#define package_vlDzoKUd_stop
#else

struct coop
{
    struct kGAzHwmx_ *Object;
    struct ddUKsuMN_ *Derived;
    struct lbdtYEkR_ *Another;
    struct YPnOLrQT_ *Geometric;
    struct UQZwMHfN_ *Square;
}coop;

#endif

#endif //COOP_H
