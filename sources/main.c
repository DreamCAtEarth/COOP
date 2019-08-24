#include <stdio.h>

#include "coop/coop.h"
#include "util/util.h"

#include "objectModel.h"

void main_coop(void)
{
    coop_OBJECT object1 = coop.newObject();
    printf("|%s|\n", coop.Object->getPrivateAttribute(object1));
    coop.Object->setClassName("MDR A");
    printf("|%s|\n", coop.Object->getClassName());
    printf("|%s|\n", object1->publicAttribute);
    util_OBJECT object2 = util.newObject();
    printf("|%s|\n", util.Object->getPrivateAttribute(object2));
    util.Object->setClassName("MDR B");
    printf("|%s|\n", util.Object->getClassName());
    printf("|%s|\n", object2->publicAttribute);
}

int main()
{
    pre_start_coop();
    main_coop();
    post_end_coop();
    return 0;
}