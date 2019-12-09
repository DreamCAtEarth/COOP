#include <stdio.h>

#include "coop/coop.h"
#include "util/util.h"

int main()
{
    main_coop();
    garbage_collector();
    return 0;
}

void main_coop(void)
{
    kGAz_Hwmx object1 = kGAzHwmx_new(o2,7,7.3f,'v',5.6f);
    printf("%f\n", coop.Object->getAlternativePrivateAttribute(object1));
    printf("%c\n", coop.Object->getAlternativeProtectedAttribute(object1));
    printf("%s\n", coop.Object->getClassName(object1->class));
    ddUK_suMN derived1 = ddUKsuMN_new(o1,"public attribute","package attribute","protected attribute");
    coop.Derived->setPrivateAttribute(derived1,"salut !");
    printf("%s\n", coop.Derived->getPrivateAttribute(derived1));
    KPLG_Wrfu object2 = KPLGWrfu_new(o1,"public attribute","package attribute","protected attribute");
    util.Object->setProtectedAttribute(object2,"nain porte quoi");
    printf("%s\n", util.Object->getClassName(object2->class));
}