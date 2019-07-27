#if !defined(_AnotherObject_Public_) && !defined(_AnotherObject_Private_Start_) && !defined(_AnotherObject_Protected_Start_)

#include "Object.h"

/* Nouvelle(s) classe(s) */
/*public */typedef struct AnotherObjectClass AnotherObjectClass;

/* Instance(s) associée(s) */
/*public */typedef struct AnotherObjectInstance AnotherObjectInstance;

/* Descripteur de classe */
struct AnotherObjectClass
{
	/* Héritage d'object */
	/*public */void(*setPrivateAttribute)(char *, AnotherObjectInstance *); /* Mutateur*/
	/*public */void(*setProtectedAttribute)(char *, AnotherObjectInstance *); /* Mutateur*/
	/*public */char *(*getPrivateAttribute)(AnotherObjectInstance *); /* Accesseur*/
	/*public */char *(*getProtectedAttribute)(AnotherObjectInstance *); /* Accesseur*/
	/*public */void(*delete)(AnotherObjectInstance *); /* Destructeur*/
	/*public static */char *(*getClassName)(AnotherObjectClass *); /* Méthode statique*/
	/*public static */void(*setClassName)(char *, AnotherObjectClass *); /* Méthode statique*/

	/* Nouveauté d'AnotherObject */
	/*public */double(*getAverageOfReport)(AnotherObjectInstance *); /* Méthode*/
	/*public */void(*setSeed)(bool, AnotherObjectInstance *); /* Mutateur*/
	/*public */bool(*isSeedSet)(AnotherObjectInstance *); /* Accesseur*/
}*AnotherObject;

/* Définition d'instance */
struct AnotherObjectInstance
{
	/* Héritage d'object */
	/*public */char *publicAttribute; /* Attribut*/
};

/* Fonctions implémentatrices appelables partout */
AnotherObjectInstance *NewAnotherObject(void); /* Constructeur*/

#define _AnotherObject_Public_

#elif defined(_AnotherObject_Private_Start_) && !defined(_AnotherObject_Private_End_)

#include "Object.h"

/* Nouvelle(s) classe(s) */
/*public */typedef struct AnotherObjectClass AnotherObjectClass;

/* Instance(s) associée(s) */
/*public */typedef struct AnotherObjectInstance AnotherObjectInstance;

/* Descripteur de classe */
struct AnotherObjectClass
{
	/* Héritage d'object */
	/*public */void(*setPrivateAttribute)(char *, AnotherObjectInstance *); /* Mutateur*/
	/*public */void(*setProtectedAttribute)(char *, AnotherObjectInstance *); /* Mutateur*/
	/*public */char *(*getPrivateAttribute)(AnotherObjectInstance *); /* Accesseur*/
	/*public */char *(*getProtectedAttribute)(AnotherObjectInstance *); /* Accesseur*/
	/*public */void(*delete)(AnotherObjectInstance *); /* Destructeur*/
	/*public static */char *(*getClassName)(AnotherObjectClass *); /* Méthode statique*/
	/*public static */void(*setClassName)(char *, AnotherObjectClass *); /* Méthode statique*/

	/* Nouveauté d'AnotherObject */
	/*public */double(*getAverageOfReport)(AnotherObjectInstance *); /* Méthode*/
	/*public */char *(*displayReport)(AnotherObjectInstance *); /* Méthode*/
	/*public static */bool(*isSeedSet)(AnotherObjectClass *); /* Accesseur*/
	/*protected */float(*sumOfMarks)(AnotherObjectInstance *); /* Méthode*/
	/*protected */int(*sizeOfReport)(); /* Méthode*/
	/*protected static */void(*setSeed)(bool, AnotherObjectClass *); /* Mutateur*/
	/*private */void (*recordMarks)(AnotherObjectInstance *); /* Méthode*/
	/*private static */float(*preciseDivision)(float, float); /* Méthode statique*/
    /*private static */int nbInstances; /* Attribut de classe*/
	/*private static */char *className; /* Attribut de classe*/
	/*private static */bool seed; /* Attribut de classe*/
}*AnotherObject;

/* Définition d'instance */
struct AnotherObjectInstance
{
	/*protected */AnotherObjectClass *class; /* polymorphiseur*/

	/* Héritage d'object */
	/*public */char *publicAttribute; /* Attribut*/
	/*protected */char *protectedAttribute; /* Attribut*/

	/* Nouveauté d'AnotherObject */
	/*private */float mark[numberOfMarks]; /* Attribut*/
    /*private */char *marksToDisplay; /* Attribut*/
	///*private */float *next; /* Attribut*/
};

/* Fonctions implémentatrices appelables partout */
AnotherObjectInstance *NewAnotherObject(void); /* Constructeur*/

/* Fonctions implémentatrices appelables par héritage */
double averageOfMarksAnotherObject(AnotherObjectInstance *this);
char * displayReportAnotherObject(AnotherObjectInstance *this);
void setSeedAnotherObject(bool seed, AnotherObjectClass *self);
bool isSeedSetAnotherObject(AnotherObjectClass *self);
float sumOfMarksAnotherObject(AnotherObjectInstance *this);
int sizeOfReportAnotherObject();

/* Fonctions implémentatrices appelables uniquement dans la classe */
void NewAnotherObjectClass(void);
void recordMarksAnotherObject(AnotherObjectInstance *this);
float preciseDivisionAnotherObject(float numerator, float divisor);

#define _AnotherObject_Private_End_

#elif defined(_AnotherObject_Protected_Start_) && !defined(_AnotherObject_Protected_End_)

#include "object.h"

/* Nouvelle(s) classe(s) */
/*public */typedef struct AnotherObjectClass AnotherObjectClass;

/* Instance(s) associée(s) */
/*public */typedef struct AnotherObjectInstance AnotherObjectInstance;

/* Descripteur de classe */
struct AnotherObjectClass
{
	/* Héritage d'object */
	/*public */void(*setPrivateAttribute)(char *, AnotherObjectInstance *); /* Mutateur*/
	/*public */void(*setProtectedAttribute)(char *, AnotherObjectInstance *); /* Mutateur*/
	/*public */char *(*getPrivateAttribute)(AnotherObjectInstance *); /* Accesseur*/
	/*public */char *(*getProtectedAttribute)(AnotherObjectInstance *); /* Accesseur*/
	/*public */void(*delete)(AnotherObjectInstance *); /* Destructeur*/
	/*public static */char *(*getClassName)(AnotherObjectClass *); /* Méthode statique*/
	/*public static */void(*setClassName)(char *, AnotherObjectClass *); /* Méthode statique*/

	/* Nouveauté d'AnotherObject */
	/*public */double(*getAverageOfReport)(AnotherObjectInstance *); /* Méthode*/
	/*public */void(*setSeed)(bool, AnotherObjectInstance *); /* Mutateur*/
	/*public */bool(*isSeedSet)(AnotherObjectInstance *); /* Accesseur*/
	/*protected */float(*sumOfMarks)(AnotherObjectInstance *); /* Méthode*/
	/*protected */int(*sizeOfReport)(); /* Méthode*/
}*AnotherObject;

/* Définition d'instance */
struct AnotherObjectInstance
{
	/*protected */AnotherObjectClass *class; /* polymorphiseur*/

	/* Héritage d'object */
	/*public */char *publicAttribute; /* Attribut*/
	/*protected */char *protectedAttribute; /* Attribut*/
};

/* Fonctions implémentatrices appelables partout */
AnotherObjectInstance *NewAnotherObject(void); /* Constructeur*/

/* Fonctions implémentatrices appelables par héritage */
double averageOfMarksAnotherObject(AnotherObjectInstance *this);
void setSeedAnotherObject(bool seed, AnotherObjectInstance *this);
bool isSeedSetAnotherObject(AnotherObjectInstance *this);
float sumOfMarksAnotherObject(AnotherObjectInstance *this);
int sizeOfReportAnotherObject();

#define _AnotherObject_Protected_End_

#elif defined(_AnotherObject_Private_End_) && defined(_AnotherObject_Protected_End_) && defined(_AnotherObject_Public_)
#pragma once
#endif