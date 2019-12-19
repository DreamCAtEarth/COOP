#include <stdlib.h>

#include "objectModel.h"

#define NB_MAX_INSTANCES 100

static int nbInstances = 0;
static void *instancesIds[NB_MAX_INSTANCES];

void store_instance(void *instance)
{
    try(struct Exception exception = arrayInBounds(nbInstances + 1, NB_MAX_INSTANCES))
        if(exception.severity != success) goto catch; else goto reprise;
    catch:
        exit(0);
    reprise:
        instancesIds[nbInstances] = instance;
        nbInstances++;
}

void garbage_collector(void)
{
    for (int i = 0; i < nbInstances; i++)
        free(instancesIds[i]);
    nbInstances = 0;
}