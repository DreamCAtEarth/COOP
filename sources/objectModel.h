#if !defined(_objectModel_BasicMode_) && !defined(_objectModel_ExpertMode_Enabled_)

void start(void);
void end(void);

#define _objectModel_BasicMode_

#elif defined(_objectModel_ExpertMode_Enabled_) && !defined(_objectModel_ExpertMode_Disabled_)

/* Table des classes à polymorphiser */
typedef enum classes
{
    OBJECT,
    /*DERIVEDOBJECT,
    ANOTHEROBJECT,
    GEOMETRICOBJECT,*/
    NUMBEROFCLASSES
}ClassesIds;

/* Table des méthodes à polymorphiser */
typedef enum methodsToPolymorph
{
    GETPRIVATT,
    SETPRIVATT,
    GETCLASSNAME,
    SETCLASSNAME,
    DELETE
    // NUMBEROFMETHODS
}methodIds;

/* Nombre maximum d'objets pouvant être instanciés
static const int NUMBERMAXOFINSTANCES = 100; */

/* Table des pointeurs de classes et d'instances */
static void *ClassGraphID[NUMBEROFCLASSES];
static void *InstanceIds[100];

/* Nombre de classes et d'instances */
static unsigned int nbInstances = 0;
static unsigned int nbClasses = 0;

void start(void);
void *dynamicLink(void *class, void *instance, methodIds methodToPolymorph, void *newValueToSet);
void end(void);
void storeClassPointer(ClassesIds value, void *class);
void storeInstancePointer(void *instance);

#define _objectModel_ExpertMode_Disabled_

#elif defined(_objectModel_ExpertMode_Enabled_) && defined(_objectModel_BasicMode_)
#pragma once
#endif