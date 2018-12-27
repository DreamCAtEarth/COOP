#if !defined(_Object_Public_) && !defined(_Object_Private_Start_) && !defined(_Object_Protected_Start_)

/* Nouvelle(s) classe(s) */
typedef struct ObjectClass ObjectClass;

/* Instance(s) associée(s) */
typedef struct ObjectInstance ObjectInstance;

struct ObjectClass
{
    /* Méthodes d'instances publiques */
    void(*setPrivateAttribute)(char *, ObjectInstance *);
    void(*setProtectedAttribute)(char *, ObjectInstance *);
    char *(*getPrivateAttribute)(ObjectInstance *);
    char *(*getProtectedAttribute)(ObjectInstance *);
    void(*delete)(ObjectInstance *);

    /* Méthodes de classe publiques */
    char *(*getClassName)(void);
    void(*setClassName)(char *);
}*Object;

/* Définition de l'instance */
struct ObjectInstance
{
    /* Classe de l'instance */
    ObjectClass *class;

    /* Attributs publics */
    char *publicAttribute;
};

/* Fonctions implémentatrices publiques */
ObjectInstance *NewObject(void); // Constructeur

#define _Object_Public_

#elif defined(_Object_Private_Start_) && !defined(_Object_Private_End_)

/* Nouvelle(s) classe(s) */
typedef struct ObjectClass ObjectClass;

/* Instance(s) associée(s) */
typedef struct ObjectInstance ObjectInstance;

struct ObjectClass
{
    /* Méthodes d'instances publiques */
    void(*setPrivateAttribute)(char *, ObjectInstance *);
    void(*setProtectedAttribute)(char *, ObjectInstance *);
    char *(*getPrivateAttribute)(ObjectInstance *);
    char *(*getProtectedAttribute)(ObjectInstance *);
    void(*delete)(ObjectInstance *);

    /* Méthodes d'instances protégées */
    void(*protectedMethod)(ObjectInstance *);

    /* Méthodes d'instances privées */
    void(*privateMethod)(ObjectInstance *);

    /* Méthodes de classe publiques */
    char *(*getClassName)(void);
    void(*setClassName)(char *);

    /* Attributs de classe privés */
    char *className;
}*Object;

/* Définition de l'instance */
struct ObjectInstance
{
    /* Classe de l'instance */
    ObjectClass *class;

    /* Attributs publics */
    char *publicAttribute;

    /* Attributs protégés */
    char *protectedAttribute;

    /* Attributs privés */
    char *privateAttribute;

    /* Liaison de liste */
    ObjectInstance *next;
};
/* Listeur interne */
ObjectInstance *listOfObjects;

/* Fonctions implémentatrices publiques */
ObjectInstance *NewObject(void); // Constructeur
void setPrivateAttribute(char *string, ObjectInstance *this); // Mutateur
void setProtectedAttribute(char *string, ObjectInstance *this); // Mutateur
char *getPrivateAttribute(ObjectInstance *this); // Accesseur
char *getProtectedAttribute(ObjectInstance *this); // Accesseur
void deleteObject(ObjectInstance *this); // Destructeur

/* Fonctions implémentatrices protégées */
void protectedMethod(ObjectInstance *this); // Méthode dynamique d'instance

/* Fonctions implémentatrices privées */
void privateMethod(ObjectInstance *this); // Méthode dynamique d'instance

/* Fonctions implémentatrices statiques publiques */
char *getClassName(void); // Méthode statique de classe
void setClassName(char *string); // Méthode statique de classe

#define _Object_Private_End_

#elif defined(_Object_Protected_Start_) && !defined(_Object_Protected_End_)

/* Nouvelle(s) classe(s) */
typedef struct ObjectClass ObjectClass;

/* Instance(s) associée(s) */
typedef struct ObjectInstance ObjectInstance;

struct ObjectClass
{
    /* Méthodes d'instances publiques */
    void(*setPrivateAttribute)(char *, ObjectInstance *);
    void(*setProtectedAttribute)(char *, ObjectInstance *);
    char *(*getPrivateAttribute)(ObjectInstance *);
    char *(*getProtectedAttribute)(ObjectInstance *);
    void(*delete)(ObjectInstance *);

    /* Méthodes d'instances protégées */
    void(*protectedMethod)(ObjectInstance *);

    /* Méthodes de classe publiques */
    char *(*getClassName)(void);
    void(*setClassName)(char *);
}*Object;

/* Définition de l'instance */
struct ObjectInstance
{
    /* Classe de l'instance */
    ObjectClass *class;

    /* Attributs publics */
    char *publicAttribute;

    /* Attributs protégés */
    char *protectedAttribute;

    /* Liaison de liste */
    ObjectInstance *next;
};
/* Listeur interne */
ObjectInstance *listOfObjects;

/* Fonctions implémentatrices publiques */
ObjectInstance *NewObject(void); // Constructeur
void setPrivateAttribute(char *string, ObjectInstance *super); // Mutateur
void setProtectedAttribute(char *string, ObjectInstance *super); // Mutateur
char *getPrivateAttribute(ObjectInstance *super); // Accesseur
char *getProtectedAttribute(ObjectInstance *super); // Accesseur
void deleteObject(ObjectInstance *super); // Destructeur

/* Fonctions implémentatrices protégées */
void protectedMethod(ObjectInstance *super); // Méthode dynamique d'instance

/* Fonctions implémentatrices statiques publiques */
char *getClassName(void); // Méthode statique de classe
void setClassName(char *string); // Méthode statique de classe

#define _Object_Protected_End_

#elif defined(_Object_Private_End_) && defined(_Object_Protected_End_) && defined(_Object_Public_)
#pragma once
#endif
