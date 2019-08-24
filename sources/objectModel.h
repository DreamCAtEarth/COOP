#ifndef OBJECTMODEL_H
#define OBJECTMODEL_H

#define NB_MAX_INSTANCES 100

static int nbInstances;
static void *instancesIds[NB_MAX_INSTANCES];

void pre_start_coop(void);
void storePointer(void *instance);
void post_end_coop(void);

#endif //OBJECTMODEL_H
