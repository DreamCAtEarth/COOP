#if !defined(_DerivedObject_Public_) && !defined(_DerivedObject_Private_Start_) && !defined(_DerivedObject_Protected_Start_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct DerivedObject_ DerivedObject_;

/* Instance(s) associée(s) */
/*public */typedef struct DerivedObject DerivedObject;

/* Nouveaux types composés */
/*public */typedef struct length length;
/*public */typedef struct height height;

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructorDerivedObject overrideConstructorDerivedObject;

/* Descripteur de classe */
/*public */struct DerivedObject_
{
    /* Héritage d'object */
    /*public */void(*setPrivateAttribute)(char *, DerivedObject *);
    /*public */void(*setProtectedAttribute)(char *, DerivedObject *);
    /*public */char *(*getPrivateAttribute)(DerivedObject *);
    /*public */char *(*getProtectedAttribute)(DerivedObject *);
    /*public static */char *(*getClassName)(DerivedObject_ *);
    /*public static */void(*setClassName)(char *, DerivedObject_ *);

    /* Nouveauté de DerivedObject */
    /*public */float(*getLength)(const char *, DerivedObject *);
    /*public */float(*getHeight)(const char *, DerivedObject *);
    /*public */void(*setLength)(float, float, float, float, DerivedObject *);
    /*public */void(*setHeight)(float, float, float, float, DerivedObject *);
}*derivedObject;

/* Définition d'instance */
/*public */struct DerivedObject
{
    /* Héritage d'object */
    /*public */char *publicAttribute;
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructorDerivedObject
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */DerivedObject *newDerivedObject(overrideConstructorDerivedObject *args);

#define _DerivedObject_Public_

#elif defined(_DerivedObject_Private_Start_) && !defined(_DerivedObject_Private_End_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct DerivedObject_ DerivedObject_;

/* Instance(s) associée(s) */
/*public */typedef struct DerivedObject DerivedObject;

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

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructorDerivedObject overrideConstructorDerivedObject;

/* Descripteur de classe */
/*public */struct DerivedObject_
{
    /* Héritage d'object */
    /*public */void(*setPrivateAttribute)(char *, DerivedObject *);
    /*public */void(*setProtectedAttribute)(char *, DerivedObject *);
    /*public */char *(*getPrivateAttribute)(DerivedObject *);
    /*public */char *(*getProtectedAttribute)(DerivedObject *);
    /*public static */char *(*getClassName)(DerivedObject_ *);
    /*public static */void(*setClassName)(char *, DerivedObject_ *);

    /* Nouveauté de DerivedObject */
    /*public */float(*getLength)(const char *, DerivedObject *);
    /*public */float(*getHeight)(const char *, DerivedObject *);
    /*public */void(*setLength)(float, float, float, float, DerivedObject *);
    /*public */void(*setHeight)(float, float, float, float, DerivedObject *);
    /*private static */char *className;
}*derivedObject;

/* Définition d'instance */
/*public */struct DerivedObject
{
    /* Héritage d'object */
    /*public */char *publicAttribute;
    /*protected */DerivedObject_ *class;
    /*protected */char *protectedAttribute;

    /* Nouveauté de DerivedObject */
    /*private */length length; /* Attribut*/
    /*private */height height; /* Attribut*/
    /*private */char *privateAttribute; /* Attribut*/
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructorDerivedObject
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */DerivedObject *newDerivedObject(overrideConstructorDerivedObject *args);
/*protected */float getLengthDerivedObject(const char *value, DerivedObject *this);
/*protected */float getHeightDerivedObject(const char *value, DerivedObject *this);
/*protected */void setLengthDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                            DerivedObject *this);
/*protected */void setHeightDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                            DerivedObject *this);
/*private */void newClassDerivedObject(void);

#define _DerivedObject_Private_End_

#elif defined(_DerivedObject_Protected_Start_) && !defined(_DerivedObject_Protected_End_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct DerivedObject_ DerivedObject_;

/* Instance(s) associée(s) */
/*public */typedef struct DerivedObject DerivedObject;

/* Nouveaux types composés */
/*public */typedef struct length length;
/*public */typedef struct height height;

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructorDerivedObject overrideConstructorDerivedObject;

/* Descripteur de classe */
/*public */struct DerivedObject_
{
    /* Héritage d'object */
    /*public */void(*setPrivateAttribute)(char *, DerivedObject *);
    /*public */void(*setProtectedAttribute)(char *, DerivedObject *);
    /*public */char *(*getPrivateAttribute)(DerivedObject *);
    /*public */char *(*getProtectedAttribute)(DerivedObject *);
    /*public static */char *(*getClassName)(DerivedObject_ *);
    /*public static */void(*setClassName)(char *, DerivedObject_ *);

    /* Nouveauté de DerivedObject */
    /*public */float(*getLength)(const char *, DerivedObject *);
    /*public */float(*getHeight)(const char *, DerivedObject *);
    /*public */void(*setLength)(float, float, float, float, DerivedObject *);
    /*public */void(*setHeight)(float, float, float, float, DerivedObject *);
}*derivedObject;

/* Définition d'instance */
/*public */struct DerivedObject
{
    /* Héritage d'object */
    /*public */char *publicAttribute;
    /*protected */DerivedObject_ *class;
    /*protected */char *protectedAttribute;
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructorDerivedObject
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */DerivedObject *newDerivedObject(overrideConstructorDerivedObject *args);
/*protected */float getLengthDerivedObject(const char *value, DerivedObject *this);
/*protected */float getHeightDerivedObject(const char *value, DerivedObject *this);
/*protected */void setLengthDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                            DerivedObject *this);
/*protected */void setHeightDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                            DerivedObject *this);

#define _DerivedObject_Protected_End_

#elif defined(_DerivedObject_Private_End_) && defined(_DerivedObject_Protected_End_) && defined(_DerivedObject_Public_)
#pragma once
#endif
