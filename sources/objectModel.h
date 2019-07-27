#if !defined(_objectModel_BasicMode_) && !defined(_objectModel_ExpertMode_Enabled_)

void start(void);
void end(void);

/* Surcharges et règles autorisées pour les méthodes variadiques */
#ifndef OVERRIDES_RULES
    #define DEFAULT_VA_ARGS_VALUE 0
    #define coopObject(...) new_coop_Object(&(overrideConstructor_coop_Object) { .sentinel = DEFAULT_VA_ARGS_VALUE, __VA_ARGS__ })
    #define coopDerivedObject(...) new_coop_DerivedObject(&(overrideConstructor_coop_DerivedObject) { .sentinel = DEFAULT_VA_ARGS_VALUE, __VA_ARGS__ })
#define OVERRIDES_RULES
#endif

#define _objectModel_BasicMode_

#elif defined(_objectModel_ExpertMode_Enabled_) && !defined(_objectModel_ExpertMode_Disabled_)

/* Table des classes à polymorphiser */
typedef enum classes
{
    COOP_OBJECT,
    COOP_DERIVEDOBJECT,
    /*COOP_ANOTHEROBJECT,
    COOP_GEOMETRICOBJECT,*/
    NUMBEROFCLASSES
}ClassesIds;

/* Table des méthodes à polymorphiser */
typedef enum methodsToPolymorph
{
    COOP_OBJECT_SETPRIVATEATTRIBUTE,
    COOP_OBJECT_GETPRIVATEATTRIBUTE,
    COOP_OBJECT_SETCLASSNAME,
    COOP_OBJECT_GETCLASSNAME,
    DELETE
    // NUMBEROFMETHODS
}methodIds;

/* Nombre maximum d'objets pouvant être instanciés
static const int NUMBERMAXOFINSTANCES = 100; */

/* Table des pointeurs de classes et d'instances */
static void *classIds[NUMBEROFCLASSES];
static void *instanceIds[100];

/* Nombre de classes et d'instances */
static unsigned int nbInstances = 0;
static unsigned int nbClasses = 0;

void start(void);
void *dynamicLink(void *class, void *instance, methodIds methodToPolymorph, void *newValueToSet);
void end(void);
void storeClassPointer(ClassesIds value, void *class);
void storeInstancePointer(void *instance);

#ifndef __CLASSNAME__
#define __CLASSNAME__ __FILE__
#endif

/* Surcharges et règles autorisées pour les méthodes variadiques */
#ifndef OVERRIDES_RULES
    #define DEFAULT_VA_ARGS_VALUE 0
    #define coopObject(...) new_coop_Object(&(overrideConstructor_coop_Object) { .sentinel = DEFAULT_VA_ARGS_VALUE, __VA_ARGS__ })
    #define coopDerivedObject(...) new_coop_DerivedObject(&(overrideConstructor_coop_DerivedObject) { .sentinel = DEFAULT_VA_ARGS_VALUE, __VA_ARGS__ })
#define OVERRIDES_RULES
#endif

#define _objectModel_ExpertMode_Disabled_

#elif defined(_objectModel_ExpertMode_Disabled_) && defined(_objectModel_BasicMode_)
#pragma once
#endif