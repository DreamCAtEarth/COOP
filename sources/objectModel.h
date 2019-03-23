#if !defined(_objectModel_BasicMode_) && !defined(_objectModel_ExpertMode_Enabled_)

void start(void);
void end(void);

/* Surcharges autorisées pour ces méthodes */
#define newObject(...) newObject(&(overrideConstructorObject) { .sentinel = 0, __VA_ARGS__ })
#define newDerivedObject(...) newDerivedObject(&(overrideConstructorDerivedObject) { .sentinel = 0, __VA_ARGS__ })

#define _objectModel_BasicMode_

#elif defined(_objectModel_ExpertMode_Enabled_) && !defined(_objectModel_ExpertMode_Disabled_)

/* Table des classes à polymorphiser */
typedef enum classes
{
    OBJECT,
    DERIVEDOBJECT,
    /*ANOTHEROBJECT,
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
static void *classIds[NUMBEROFCLASSES];
static void *instanceIds[100];
static char *classNameToken = NULL;

/* Nombre de classes et d'instances */
static unsigned int nbInstances = 0;
static unsigned int nbClasses = 0;

void start(void);
void *dynamicLink(void *class, void *instance, methodIds methodToPolymorph, void *newValueToSet);
void end(void);
void storeClassPointer(ClassesIds value, void *class);
void storeInstancePointer(void *instance);

#ifndef __CLASSNAME__
#define __CLASSNAME__ strtok_s((strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__), ".", &classNameToken)
#endif

#define _objectModel_ExpertMode_Disabled_

#elif defined(_objectModel_ExpertMode_Disabled_) && defined(_objectModel_BasicMode_)
#pragma once
#endif