#if !defined(_coop_Object_Public_) && !defined(_coop_Object_Private_Start_) && !defined(_coop_Object_Protected_Start_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct coopObject_ coopObject_;

/* Instance(s) associée(s) */
/*public */typedef struct coop_Object coop_Object;

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructor_coop_Object overrideConstructor_coop_Object;

/* Descripteur de classe */
/*public */struct coopObject_
{
    /*public */void(* setPrivateAttribute)(char *, coop_Object *);
    /*public */char *(* getPrivateAttribute)(coop_Object *);
    /*public */void(* setProtectedAttribute)(char *, coop_Object *);
    /*public */char *(* getProtectedAttribute)(coop_Object *);
    /*public static */void(* setClassName)(char *, coopObject_ *);
    /*public static */char *(* getClassName)(coopObject_ *);
}*coopObject;

/* Définition d'instance */
/*public */struct coop_Object
{
    /*public */char *publicAttribute;
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructor_coop_Object
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */coop_Object *new_coop_Object(overrideConstructor_coop_Object *args);

#define _coop_Object_Public_

#elif defined(_coop_Object_Private_Start_) && !defined(_coop_Object_Private_End_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct coopObject_ coopObject_;

/* Instance(s) associée(s) */
/*public */typedef struct coop_Object coop_Object;

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructor_coop_Object overrideConstructor_coop_Object;

/* Descripteur de classe */
/*public */struct coopObject_
{
    /*public */void(* setPrivateAttribute)(char *, coop_Object *);
    /*public */char *(* getPrivateAttribute)(coop_Object *);
    /*public */void(* setProtectedAttribute)(char *, coop_Object *);
    /*public */char *(* getProtectedAttribute)(coop_Object *);
    /*public static */void(* setClassName)(char *, coopObject_ *);
    /*public static */char *(* getClassName)(coopObject_ *);
    /*private static */char *className;
}*coopObject;

/* Définition d'instance */
/*public */struct coop_Object
{
    /*public */char *publicAttribute;
    /*protected */coopObject_ *class;
    /*protected */char *protectedAttribute;
    /*private */char *privateAttribute;
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructor_coop_Object
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */coop_Object *new_coop_Object(overrideConstructor_coop_Object *args);
/*protected */void setPrivateAttribute_coop_Object(char *string, coop_Object *this);
/*protected */char *getPrivateAttribute_coop_Object(coop_Object *this);
/*protected */void setProtectedAttribute_coop_Object(char *string, coop_Object *this);
/*protected */char *getProtectedAttribute_coop_Object(coop_Object *this);
/*protected */void setClassName_coop_Object(char *string, coopObject_ *self);
/*protected */char *getClassName_coop_Object(coopObject_ *self);
/*private */void newClass_coop_Object(void);

#define _coop_Object_Private_End_

#elif defined(_coop_Object_Protected_Start_) && !defined(_coop_Object_Protected_End_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct coopObject_ coopObject_;

/* Instance(s) associée(s) */
/*public */typedef struct coop_Object coop_Object;

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructor_coop_Object overrideConstructor_coop_Object;

/* Descripteur de classe */
/*public */struct coopObject_
{
    /*public */void(* setPrivateAttribute)(char *, coop_Object *);
    /*public */char *(* getPrivateAttribute)(coop_Object *);
    /*public */void(* setProtectedAttribute)(char *, coop_Object *);
    /*public */char *(* getProtectedAttribute)(coop_Object *);
    /*public static */void(* setClassName)(char *, coopObject_ *);
    /*public static */char *(* getClassName)(coopObject_ *);
}*coopObject;

/* Définition d'instance */
/*public */struct coop_Object
{
    /*public */char *publicAttribute;
    /*protected */coopObject_ *class;
    /*protected */char *protectedAttribute;
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructor_coop_Object
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */coop_Object *new_coop_Object(overrideConstructor_coop_Object *args);
/*protected */void setPrivateAttribute_coop_Object(char *string, coop_Object *super);
/*protected */char *getPrivateAttribute_coop_Object(coop_Object *super);
/*protected */void setProtectedAttribute_coop_Object(char *string, coop_Object *super);
/*protected */char *getProtectedAttribute_coop_Object(coop_Object *super);
/*protected */void setClassName_coop_Object(char *string, coopObject_ *parent);
/*protected */char *getClassName_coop_Object(coopObject_ *parent);

#define _coop_Object_Protected_End_

#elif defined(_coop_Object_Private_End_) && defined(_coop_Object_Protected_End_) && defined(_coop_Object_Public_)
#pragma once
#endif
