#if !defined(_DerivedObject_Public_) && !defined(_DerivedObject_Private_Start_) && !defined(_DerivedObject_Protected_Start_)

#include "object.h"

/* Importation(s) de classe(s) */
/*public */typedef struct DerivedObjectClass DerivedObjectClass;

/* Instance(s) associée(s) */
/*public */typedef struct DerivedObjectInstance DerivedObjectInstance;

/* Nouveaux types composés */
/*public */typedef struct length length;
/*public */typedef struct height height;

/* Descripteur de classe */
struct DerivedObjectClass
{
    /* Héritage d'object */
    /*public */void(*setPrivateAttribute)(char *, DerivedObjectInstance *); /* Mutateur*/
    /*public */void(*setProtectedAttribute)(char *, DerivedObjectInstance *); /* Mutateur*/
    /*public */char *(*getPrivateAttribute)(DerivedObjectInstance *); /* Accesseur*/
    /*public */char *(*getProtectedAttribute)(DerivedObjectInstance *); /* Accesseur*/
    /*public */void(*delete)(DerivedObjectInstance *); /* Destructeur*/
    /*public static */char *(*getClassName)(DerivedObjectClass *); /* Méthode statique*/
    /*public static */void(*setClassName)(char *, DerivedObjectClass *); /* Méthode statique*/

    /* Nouveauté de DerivedObject */
    /*public */float(*getLength)(char *, DerivedObjectInstance *); /* Méthode*/
    /*public */float(*getHeight)(char *, DerivedObjectInstance *); /* Méthode*/
    /*public */void(*setLength)(float, float, float, float, DerivedObjectInstance *); /* Méthode*/
    /*public */void(*setHeight)(float, float, float, float, DerivedObjectInstance *); /* Méthode*/
}*DerivedObject;

/* Définition d'instance */
struct DerivedObjectInstance
{
    /* Héritage d'object */
    /*public */char *publicAttribute; /* Attribut*/
};

/* Fonctions implémentatrices appelables partout */
DerivedObjectInstance *NewDerivedObject(void); /* Constructeur*/

#define _DerivedObject_Public_

#elif defined(_DerivedObject_Private_Start_) && !defined(_DerivedObject_Private_End_)

#include "Object.h"

/* Nouvelle(s) classe(s) */
/*public */typedef struct DerivedObjectClass DerivedObjectClass;

/* Instance(s) associée(s) */
/*public */typedef struct DerivedObjectInstance DerivedObjectInstance;

/* Nouveaux types composés */
/*public */typedef struct length length;
/*public */typedef struct height height;

/* Définition des membres des types composés */
/*private */struct length
{
    float x1;
    float y1;
    float x2;
    float y2;
};
/*private */struct height
{
    float x1;
    float y1;
    float x2;
    float y2;
};

/* Descripteur de classe */
struct DerivedObjectClass
{
    /* Héritage d'object */
    /*public */void(*setPrivateAttribute)(char *, DerivedObjectInstance *); /* Mutateur*/
    /*public */void(*setProtectedAttribute)(char *, DerivedObjectInstance *); /* Mutateur*/
    /*public */char *(*getPrivateAttribute)(DerivedObjectInstance *); /* Accesseur*/
    /*public */char *(*getProtectedAttribute)(DerivedObjectInstance *); /* Accesseur*/
    /*public */void(*delete)(DerivedObjectInstance *); /* Destructeur*/
    /*public static */char *(*getClassName)(DerivedObjectClass *); /* Méthode statique*/
    /*public static */void(*setClassName)(char *, DerivedObjectClass *); /* Méthode statique*/

    /* Nouveauté de DerivedObject */
    /*public */float(*getLength)(char *, DerivedObjectInstance *); /* Méthode*/
    /*public */float(*getHeight)(char *, DerivedObjectInstance *); /* Méthode*/
    /*public */void(*setLength)(float, float, float, float, DerivedObjectInstance *); /* Méthode*/
    /*public */void(*setHeight)(float, float, float, float, DerivedObjectInstance *); /* Méthode*/
    /*private static */char *className; /* Attribut de classe*/
    /*private static */int nbInstances; /* Attribut de classe*/
}*DerivedObject;

/* Définition d'instance */
struct DerivedObjectInstance
{
    /*protected */DerivedObjectClass *class; /* polymorphiseur*/

    /* Héritage d'object */
    /*public */char *publicAttribute; /* Attribut*/
    /*protected */char *protectedAttribute; /* Attribut*/

    /* Nouveauté de DerivedObject */
    /*private */length length; /* Attribut*/
    /*private */height height; /* Attribut*/
    /*private */char *privateAttribute; /* Attribut*/
};

/* Fonctions implémentatrices appelables partout */
DerivedObjectInstance *NewDerivedObject(void); /* Constructeur*/

/* Fonctions implémentatrices appelables par héritage */
float getLengthDerivedObject(char *value, DerivedObjectInstance *this);
float getHeightDerivedObject(char *value, DerivedObjectInstance *this);
void setLengthDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                            DerivedObjectInstance *this);
void setHeightDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                            DerivedObjectInstance *this);

/* Fonctions implémentatrices appelables uniquement dans la classe */
void NewDerivedObjectClass(void);

#define _DerivedObject_Private_End_

#elif defined(_DerivedObject_Protected_Start_) && !defined(_DerivedObject_Protected_End_)

#include "object.h"

/* Nouvelle(s) classe(s) parente(s) */
/*public */typedef struct DerivedObjectClass DerivedObjectClass;

/* Instance(s) associée(s) */
/*public */typedef struct DerivedObjectInstance DerivedObjectInstance;

/* Types composés hérités */
/*public */typedef struct length length;
/*public */typedef struct height height;

/* Descripteur de superclasse */
struct DerivedObjectClass
{
    /* Héritage d'object */
    /*public */void(*setPrivateAttribute)(char *, DerivedObjectInstance *); /* Mutateur*/
    /*public */void(*setProtectedAttribute)(char *, DerivedObjectInstance *); /* Mutateur*/
    /*public */char *(*getPrivateAttribute)(DerivedObjectInstance *); /* Accesseur*/
    /*public */char *(*getProtectedAttribute)(DerivedObjectInstance *); /* Accesseur*/
    /*public */void(*delete)(DerivedObjectInstance *); /* Destructeur*/
    /*public static */char *(*getClassName)(DerivedObjectClass *); /* Méthode statique*/
    /*public static */void(*setClassName)(char *, DerivedObjectClass *); /* Méthode statique*/

    /* Nouveauté de DerivedObject */
    /*public */float(*getLength)(char *, DerivedObjectInstance *); /* Méthode*/
    /*public */float(*getHeight)(char *, DerivedObjectInstance *); /* Méthode*/
    /*public */void(*setLength)(float, float, float, float, DerivedObjectInstance *); /* Méthode*/
    /*public */void(*setHeight)(float, float, float, float, DerivedObjectInstance *); /* Méthode*/
}*DerivedObject;

/* Définition d'instance */
struct DerivedObjectInstance
{
    /*protected */DerivedObjectClass *class; /* polymorphiseur*/

    /* Héritage d'object */
    /*public */char *publicAttribute; /* Attribut*/
    /*protected */char *protectedAttribute; /* Attribut*/
};

/* Fonctions implémentatrices appelables partout */
DerivedObjectInstance *NewDerivedObject(void); /* Constructeur*/

/* Fonctions implémentatrices appelables par héritage */
float getLengthDerivedObject(char *value, DerivedObjectInstance *super);
float getHeightDerivedObject(char *value, DerivedObjectInstance *super);
void setLengthDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY, DerivedObjectInstance *super);
void setHeightDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY, DerivedObjectInstance *super);

#define _DerivedObject_Protected_End_

#elif defined(_DerivedObject_Private_End_) && defined(_DerivedObject_Protected_End_) && defined(_DerivedObject_Public_)
#pragma once
#endif
