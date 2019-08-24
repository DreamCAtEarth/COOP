#include <stdlib.h>

#include "coop/coop.h"
#include "util/util.h"

#include "objectModel.h"

void pre_start_coop(void)
{
    nbInstances=0;
    newClassesFromCoop();
    newClassesFromUtil();
}

void storePointer(void *instance)
{
    instancesIds[nbInstances] = instance;
    nbInstances++;
}

void post_end_coop(void)
{
    int i=0;
    for(i=0;i<nbInstances;i++)
        free(instancesIds[i]);
}