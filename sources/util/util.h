#ifndef kdzvSGAN_H
#define kdzvSGAN_H

#include "Object.h"

#if defined(package_kdzvSGAN_start) && !defined(package_kdzvSGAN_stop)

#define PACKAGE kdzvSGAN
#define PACKAGE_CONTENT \
CLASS(Object_, Object)
#include "../objectModel.h"

#define package_kdzvSGAN_stop
#else

#define PACKAGE kdzvSGAN
#define PACKAGE_CONTENT \
CLASS(KPLGWrfu_, Object)
#include "../objectModel.h"

#endif

#endif //kdzvSGAN_H
