#include "coop/coop.h"

int main()
{
    import_vlDzoKUd_package();
    main_coop();
    garbage_collector();
    return 0;
}

void main_coop(void)
{
    struct YPnOLrQT *aLotOfObjects = YPnOLrQT();
    struct YPnOLrQT *aLotOfObjects2 = YPnOLrQT();
    struct YPnOLrQT *aLotOfObjects3 = YPnOLrQT();
    /*struct ddUKsuMN *aLotOfObjects4 = ddUKsuMN();
    struct lbdtYEkR *aLotOfObjects5 = lbdtYEkR();*/
    printf("Geometric class name from Derived : %s\n", coop.Geometric->Derived->Object->getClassName(coop.Geometric->Derived->Object));
    printf("Geometric class name from Another : %s\n", coop.Geometric->Another->Object->getClassName(coop.Geometric->Another->Object));
    printf("Object class name : %s\n", coop.Object->getClassName(coop.Object));
    printf("Derived class name : %s\n", coop.Derived->Object->getClassName(coop.Derived->Object));
    printf("Another class name : %s\n", coop.Another->Object->getClassName(coop.Another->Object));
    coop.Geometric->Derived->Object->setPrivateAttribute(aLotOfObjects->Derived->Object, "test 3");
    coop.Geometric->Derived->Object->setPrivateAttribute(aLotOfObjects2->Derived->Object, "test 2");
    coop.Geometric->Derived->Object->setPrivateAttribute(aLotOfObjects3->Derived->Object, "test 1");
    printf("%s\n", coop.Geometric->Derived->Object->getPrivateAttribute(aLotOfObjects->Derived->Object));
    printf("%s\n", coop.Geometric->Derived->Object->getPrivateAttribute(aLotOfObjects2->Derived->Object));
    printf("%s\n", coop.Geometric->Derived->Object->getPrivateAttribute(aLotOfObjects3->Derived->Object));
}
