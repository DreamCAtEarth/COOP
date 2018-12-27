#if !defined(_DerivedObject_Public_) && !defined(_DerivedObject_Private_Start_) && !defined(_DerivedObject_Protected_Start_)

#include "Object.h"

/* Nouvelle(s) classe(s) */
typedef struct DerivedObjectClass DerivedObjectClass;

/* Instance(s) associée(s) */
typedef struct DerivedObjectInstance DerivedObjectInstance;

/* Nouveaux types composés */
typedef struct length length;
typedef struct height height;

struct DerivedObjectClass
{
    /* Méthodes d'instances publiques héritées d'Object */
    void(*setPrivateAttribute)(char *, DerivedObjectInstance *);
    void(*setProtectedAttribute)(char *, DerivedObjectInstance *);
    char *(*getPrivateAttribute)(DerivedObjectInstance *);
    char *(*getProtectedAttribute)(DerivedObjectInstance *);
    void(*delete)(DerivedObjectInstance *);

    /* Méthodes de classe publiques héritées d'Object */
    char *(*getClassName)(void);
    void(*setClassName)(char *);

    // Nouvelles méthodes d'instances publiques
    float(*getLength)(char *, DerivedObjectInstance *);
    float(*getHeight)(char *, DerivedObjectInstance *);
    void(*setLength)(float, float, float, float, DerivedObjectInstance *);
    void(*setHeight)(float, float, float, float, DerivedObjectInstance *);
}*DerivedObject;

struct DerivedObjectInstance
{
    DerivedObjectClass *class;

    // Attributs publics hérités d'Object
    char *publicAttribute;
};

/* Fonctions implémentatrices publiques */
DerivedObjectInstance *NewDerivedObject(void); // Constructeurs

#define _DerivedObject_Public_

#elif defined(_DerivedObject_Private_Start_) && !defined(_DerivedObject_Private_End_)

#include "Object.h"

/* Nouvelle(s) classe(s) */
typedef struct DerivedObjectClass DerivedObjectClass;

/* Instance(s) associée(s) */
typedef struct DerivedObjectInstance DerivedObjectInstance;

/* Nouveaux types composés */
typedef struct length length;
typedef struct height height;

/* Nouvelle définition privée des membres des types composés */
struct length
{
    float x1;
    float y1;
    float x2;
    float y2;
};

struct height
{
    float x1;
    float y1;
    float x2;
    float y2;
};

struct DerivedObjectClass
{
    /* Méthodes d'instances publiques héritées d'Object */
    void(*setPrivateAttribute)(char *, DerivedObjectInstance *);
    void(*setProtectedAttribute)(char *, DerivedObjectInstance *);
    char *(*getPrivateAttribute)(DerivedObjectInstance *);
    char *(*getProtectedAttribute)(DerivedObjectInstance *);
    void(*delete)(DerivedObjectInstance *);

    /* Méthodes d'instances protégées héritées d'Object */
    void(*protectedMethod)(DerivedObjectInstance *);

    /* Méthodes de classe publiques héritées d'Object */
    char *(*getClassName)(void);
    void(*setClassName)(char *);

    // Nouvelles méthodes d'instances publiques
    float(*getLength)(char *, DerivedObjectInstance *);
    float(*getHeight)(char *, DerivedObjectInstance *);
    void(*setLength)(float, float, float, float, DerivedObjectInstance *);
    void(*setHeight)(float, float, float, float, DerivedObjectInstance *);

    /* Nouveaux Attributs de classe privés */
    char *className;
}*DerivedObject;

struct DerivedObjectInstance
{
    DerivedObjectClass *class;

    // Attributs publics hérités d'Object
    char *publicAttribute;

    // Attributs protégés hérités d'Object
    char *protectedAttribute;

    // Nouveaux attributs privés
    length length;
    height height;

    /* Liaison de liste */
    DerivedObjectInstance *next;
};
/* Listeur interne */
DerivedObjectInstance *listOfDerivedObjects;

/* Fonctions implémentatrices publiques */
DerivedObjectInstance *NewDerivedObject(void); // Constructeurs
float getLength(char *value, DerivedObjectInstance *this); // Accesseurs
float getHeight(char *value, DerivedObjectInstance *this); // Accesseurs
void setLength(float lineStartX, float lineStartY, float lineEndX, float lineEndY, DerivedObjectInstance *this); // Mutateurs
void setHeight(float lineStartX, float lineStartY, float lineEndX, float lineEndY, DerivedObjectInstance *this); // Mutateurs
void deleteDerivedObject(DerivedObjectInstance *this); // Destructeurs

#define _DerivedObject_Private_End_

#elif defined(_DerivedObject_Protected_Start_) && !defined(_DerivedObject_Protected_End_)

#include "Object.h"

/* Nouvelle(s) classe(s) */
typedef struct DerivedObjectClass DerivedObjectClass;

/* Instance(s) associée(s) */
typedef struct DerivedObjectInstance DerivedObjectInstance;

/* Nouveaux types composés */
typedef struct length length;
typedef struct height height;

struct DerivedObjectClass
{
    /* Méthodes d'instances publiques héritées d'Object */
    void(*setPrivateAttribute)(char *, DerivedObjectInstance *);
    void(*setProtectedAttribute)(char *, DerivedObjectInstance *);
    char *(*getPrivateAttribute)(DerivedObjectInstance *);
    char *(*getProtectedAttribute)(DerivedObjectInstance *);
    void(*delete)(DerivedObjectInstance *);

    /* Méthodes d'instances protégées héritées d'Object */
    void(*protectedMethod)(DerivedObjectInstance *);

    /* Méthodes de classe publiques héritées d'Object */
    char *(*getClassName)(void);
    void(*setClassName)(char *);

    // Nouvelles méthodes d'instances publiques
    float(*getLength)(char *, DerivedObjectInstance *);
    float(*getHeight)(char *, DerivedObjectInstance *);
    void(*setLength)(float, float, float, float, DerivedObjectInstance *);
    void(*setHeight)(float, float, float, float, DerivedObjectInstance *);
}*DerivedObject;

struct DerivedObjectInstance
{
    DerivedObjectClass *class;

    // Attributs publics hérités d'Object
    char *publicAttribute;

    // Attributs protégés hérités d'Object
    char *protectedAttribute;

    /* Liaison de liste */
    DerivedObjectInstance *next;
};
/* Listeur interne */
DerivedObjectInstance *listOfDerivedObjects;

/* Fonctions implémentatrices publiques */
DerivedObjectInstance *NewDerivedObject(void); // Constructeurs
float getLength(char *value, DerivedObjectInstance *this); // Accesseurs
float getHeight(char *value, DerivedObjectInstance *this); // Accesseurs
void setLength(float lineStartX, float lineStartY, float lineEndX, float lineEndY, DerivedObjectInstance *this); // Mutateurs
void setHeight(float lineStartX, float lineStartY, float lineEndX, float lineEndY, DerivedObjectInstance *this); // Mutateurs
void deleteDerivedObject(DerivedObjectInstance *this); // Destructeurs

#define _DerivedObject_Protected_End_

#elif defined(_DerivedObject_Private_End_) && defined(_DerivedObject_Protected_End_) && defined(_DerivedObject_Public_)
#pragma once
#endif
