#include <stdlib.h>

#include "objectModel.h"

#define NB_MAX_INSTANCES 100

static int nbInstances = 0;
static void *instancesIds[NB_MAX_INSTANCES];

void store_instance(void *instance)
{
    instancesIds[nbInstances] = instance;
    nbInstances++;
}

void garbage_collector(void)
{
    for (int i = 0; i < nbInstances; i++)
        free(instancesIds[i]);
    nbInstances = 0;
}