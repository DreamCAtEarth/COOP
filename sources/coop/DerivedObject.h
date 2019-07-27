#if !defined(_coop_DerivedObject_Public_) && !defined(_coop_DerivedObject_Private_Start_) && !defined(_coop_DerivedObject_Protected_Start_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct coopDerivedObject_ coopDerivedObject_;

/* Instance(s) associée(s) */
/*public */typedef struct coop_DerivedObject coop_DerivedObject;

/* Nouveaux types composés */
/*public */typedef struct length length;
/*public */typedef struct height height;

/* Définition des membres des types composés */

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructor_coop_DerivedObject overrideConstructor_coop_DerivedObject;

/* Descripteur de classe */
/*public */struct coopDerivedObject_
{
    /* Héritage d'Object */
    /*public */void(* setPrivateAttribute)(char *, coop_DerivedObject *);
    /*public */char *(* getPrivateAttribute)(coop_DerivedObject *);
    /*public */void(* setProtectedAttribute)(char *, coop_DerivedObject *);
    /*public */char *(* getProtectedAttribute)(coop_DerivedObject *);
    /*public static */void(* setClassName)(char *, coopDerivedObject_ *);
    /*public static */char *(* getClassName)(coopDerivedObject_ *);

    /* Nouveauté de DerivedObject */
    /*public */void(* setLength)(float, float, float, float, coop_DerivedObject *);
    /*public */float(* getLength)(const char *, coop_DerivedObject *);
    /*public */void(* setHeight)(float, float, float, float, coop_DerivedObject *);
    /*public */float(* getHeight)(const char *, coop_DerivedObject *);
}*coopDerivedObject;

/* Définition d'instance */
/*public */struct coop_DerivedObject
{
    /* Héritage d'Object */
    /*public */char *publicAttribute;
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructor_coop_DerivedObject
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */coop_DerivedObject *new_coop_DerivedObject(overrideConstructor_coop_DerivedObject *args);

#define _coop_DerivedObject_Public_

#elif defined(_coop_DerivedObject_Private_Start_) && !defined(_coop_DerivedObject_Private_End_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct coopDerivedObject_ coopDerivedObject_;

/* Instance(s) associée(s) */
/*public */typedef struct coop_DerivedObject coop_DerivedObject;

/* Nouveaux types composés */
/*public */typedef struct length length;
/*public */typedef struct height height;

/* Définition des membres des types composés */
/*private */struct length
/*private */{
    /*private */float x1;
    /*private */float y1;
    /*private */float x2;
    /*private */float y2;
/*private */};
/*private */struct height
/*private */{
    /*private */float x1;
    /*private */float y1;
    /*private */float x2;
    /*private */float y2;
/*private */};

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructor_coop_DerivedObject overrideConstructor_coop_DerivedObject;

/* Descripteur de classe */
/*public */struct coopDerivedObject_
{
    /* Héritage d'Object */
    /*public */void(* setPrivateAttribute)(char *, coop_DerivedObject *);
    /*public */char *(* getPrivateAttribute)(coop_DerivedObject *);
    /*public */void(* setProtectedAttribute)(char *, coop_DerivedObject *);
    /*public */char *(* getProtectedAttribute)(coop_DerivedObject *);
    /*public static */void(* setClassName)(char *, coopDerivedObject_ *);
    /*public static */char *(* getClassName)(coopDerivedObject_ *);

    /* Nouveauté de DerivedObject */
    /*public */void(* setLength)(float, float, float, float, coop_DerivedObject *);
    /*public */float(* getLength)(const char *, coop_DerivedObject *);
    /*public */void(* setHeight)(float, float, float, float, coop_DerivedObject *);
    /*public */float(* getHeight)(const char *, coop_DerivedObject *);
    /*private static */char *className;
}*coopDerivedObject;

/* Définition d'instance */
/*public */struct coop_DerivedObject
{
    /* Héritage d'Object */
    /*public */char *publicAttribute;
    /*protected */coopDerivedObject_ *class;
    /*protected */char *protectedAttribute;

    /* Nouveauté de DerivedObject */
    /*private */length length;
    /*private */height height;
    /*private */char *privateAttribute;
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructor_coop_DerivedObject
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */coop_DerivedObject *new_coop_DerivedObject(overrideConstructor_coop_DerivedObject *args);
/*protected */void setLength_coop_DerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                                                coop_DerivedObject *this);
/*protected */float getLength_coop_DerivedObject(const char *value, coop_DerivedObject *this);
/*protected */void setHeight_coop_DerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                                                coop_DerivedObject *this);
/*protected */float getHeight_coop_DerivedObject(const char *value, coop_DerivedObject *this);
/*private */void newClass_coop_DerivedObject(void);

#define _coop_DerivedObject_Private_End_

#elif defined(_coop_DerivedObject_Protected_Start_) && !defined(_coop_DerivedObject_Protected_End_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct coopDerivedObject_ coopDerivedObject_;

/* Instance(s) associée(s) */
/*public */typedef struct coop_DerivedObject coop_DerivedObject;

/* Nouveaux types composés */
/*public */typedef struct length length;
/*public */typedef struct height height;

/* Définition des membres des types composés */

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructor_coop_DerivedObject overrideConstructor_coop_DerivedObject;

/* Descripteur de classe */
/*public */struct coopDerivedObject_
{
    /* Héritage d'Object */
    /*public */void(* setPrivateAttribute)(char *, coop_DerivedObject *);
    /*public */char *(* getPrivateAttribute)(coop_DerivedObject *);
    /*public */void(* setProtectedAttribute)(char *, coop_DerivedObject *);
    /*public */char *(* getProtectedAttribute)(coop_DerivedObject *);
    /*public static */void(* setClassName)(char *, coopDerivedObject_ *);
    /*public static */char *(* getClassName)(coopDerivedObject_ *);

    /* Nouveauté de DerivedObject */
    /*public */void(* setLength)(float, float, float, float, coop_DerivedObject *);
    /*public */float(* getLength)(const char *, coop_DerivedObject *);
    /*public */void(* setHeight)(float, float, float, float, coop_DerivedObject *);
    /*public */float(* getHeight)(const char *, coop_DerivedObject *);
}*coopDerivedObject;

/* Définition d'instance */
/*public */struct coop_DerivedObject
{
    /* Héritage d'Object */
    /*public */char *publicAttribute;
    /*protected */coopDerivedObject_ *class;
    /*protected */char *protectedAttribute;
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructor_coop_DerivedObject
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */coop_DerivedObject *new_coop_DerivedObject(overrideConstructor_coop_DerivedObject *args);
/*protected */void setLength_coop_DerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                                                coop_DerivedObject *super);
/*protected */float getLength_coop_DerivedObject(const char *value, coop_DerivedObject *super);
/*protected */void setHeight_coop_DerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                                                coop_DerivedObject *super);
/*protected */float getHeight_coop_DerivedObject(const char *value, coop_DerivedObject *super);

#define _coop_DerivedObject_Protected_End_

#elif defined(_coop_DerivedObject_Private_End_) && defined(_coop_DerivedObject_Protected_End_) && defined(_coop_DerivedObject_Public_)
#pragma once
#endif
