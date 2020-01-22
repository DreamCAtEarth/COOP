#include <stdio.h>

#include "coop/coop.h"

int main()
{
    main_coop();
    garbage_collector();
    return 0;
}

void main_coop(void)
{
    struct UQZwMHfN *aSquare = UQZwMHfN();
    struct kGAzHwmx *aLotOfObjects[20];
    for(register int i = 0 ; i < 20; ++i)
    {
        aLotOfObjects[i] = kGAzHwmx(o1,"lol 1","lol 2","lol 3","lol 4", aSquare);
        aLotOfObjects[i] = kGAzHwmx(o1,"lol");
        aLotOfObjects[i] = kGAzHwmx();
    }
    coop.Object->setClassName(aLotOfObjects[2]->class, "LOL");
    printf("%s",coop.Object->getClassName(coop.Object));
}
