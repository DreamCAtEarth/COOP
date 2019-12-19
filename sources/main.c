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
    lbdt_YEkR object3 = lbdtYEkR_new();
    printf("%s\n", coop.Another->getProtectedAttribute(object3));
}