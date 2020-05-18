#ifndef vlDzoKUd_H
#define vlDzoKUd_H

#include "Object.h"
#include "Derived.h"
#include "Another.h"
#include "Geometric.h"
#include "Square.h"

#include "lang/lang.h"

#if defined(package_vlDzoKUd_start) && !defined(package_vlDzoKUd_stop)

#define PACKAGE vlDzoKUd
#define PACKAGE_CONTENT         \
CLASS(Object_, Object)          \
CLASS(Derived_, Derived)        \
CLASS(Another_, Another)        \
CLASS(Geometric_, Geometric)    \
CLASS(Square_, Square)          \
SUBPACKAGE(nnVYoBNR, lang)
#include "../objectModel.h"

#define package_vlDzoKUd_stop
#else

#define PACKAGE vlDzoKUd
#define PACKAGE_CONTENT         \
CLASS(kGAzHwmx_, Object)        \
CLASS(ddUKsuMN_, Derived)       \
CLASS(lbdtYEkR_, Another)       \
CLASS(YPnOLrQT_, Geometric)     \
CLASS(UQZwMHfN_, Square)        \
SUBPACKAGE(nnVYoBNR, lang)
#include "../objectModel.h"

#endif

void import_vlDzoKUd(void);

#endif //vlDzoKUd_H
