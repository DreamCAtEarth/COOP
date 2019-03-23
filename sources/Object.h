#if !defined(_Object_Public_) && !defined(_Object_Private_Start_) && !defined(_Object_Protected_Start_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct Object_ Object_;

/* Instance(s) associée(s) */
/*public */typedef struct Object Object;

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructorObject overrideConstructorObject;

/* Descripteur de classe */
/*public */struct Object_
{
    /*public */void(*setPrivateAttribute)(char *, Object *);
    /*public */void(*setProtectedAttribute)(char *, Object *);
    /*public */char *(*getPrivateAttribute)(Object *);
    /*public */char *(*getProtectedAttribute)(Object *);
    /*public static */char *(*getClassName)(Object_ *);
    /*public static */void(*setClassName)(char *, Object_ *);
}*object;

/* Définition d'instance */
/*public */struct Object
{
    /*public */char *publicAttribute;
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructorObject
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */Object *newObject(overrideConstructorObject *args);

#define _Object_Public_

#elif defined(_Object_Private_Start_) && !defined(_Object_Private_End_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct Object_ Object_;

/* Instance(s) associée(s) */
/*public */typedef struct Object Object;

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructorObject overrideConstructorObject;

/* Descripteur de classe */
/*public */struct Object_
{
    /*public */void(*setPrivateAttribute)(char *, Object *);
    /*public */void(*setProtectedAttribute)(char *, Object *);
    /*public */char *(*getPrivateAttribute)(Object *);
    /*public */char *(*getProtectedAttribute)(Object *);
    /*public static */char *(*getClassName)(Object_ *);
    /*public static */void(*setClassName)(char *, Object_ *);
    /*private static */char *className;
}*object;

/* Définition d'instance */
/*public */struct Object
{
    /*public */char *publicAttribute;
    /*protected */Object_ *class;
    /*protected */char *protectedAttribute;
    /*private */char *privateAttribute;
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructorObject
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */Object *newObject(overrideConstructorObject *args);
/*protected */void setPrivateAttributeObject(char *string, Object *this);
/*protected */void setProtectedAttributeObject(char *string, Object *this);
/*protected */char *getPrivateAttributeObject(Object *this);
/*protected */char *getProtectedAttributeObject(Object *this);
/*protected */char *getClassNameObject(Object_ *self);
/*protected */void setClassNameObject(char *string, Object_ *self);
/*private */void newClassObject(void);

#define _Object_Private_End_

#elif defined(_Object_Protected_Start_) && !defined(_Object_Protected_End_)

/* Nouvelle(s) classe(s) */
/*public */typedef struct Object_ Object_;

/* Instance(s) associée(s) */
/*public */typedef struct Object Object;

/* Surchargeur(s) de méthode(s) */
/*public */typedef struct overrideConstructorObject overrideConstructorObject;

/* Descripteur de classe */
/*public */struct Object_
{
    /*public */void(*setPrivateAttribute)(char *, Object *);
    /*public */void(*setProtectedAttribute)(char *, Object *);
    /*public */char *(*getPrivateAttribute)(Object *);
    /*public */char *(*getProtectedAttribute)(Object *);
    /*public static */char *(*getClassName)(Object_ *);
    /*public static */void(*setClassName)(char *, Object_ *);
}*object;

/* Définition d'instance */
/*public */struct Object
{
    /*public */char *publicAttribute;
    /*protected */Object_ *class;
    /*protected */char *protectedAttribute;
};

/* Définition du surchargeur du constructeur */
/*public */struct overrideConstructorObject
{
    /*public */int sentinel;
    /*public */char *publicAttribute;
    /*public */char *protectedAttribute;
    /*public */char *privateAttribute;
};

/* Prototypes des fonctions implémentatrices */
/*public */Object *newObject(overrideConstructorObject *args);
/*protected */void setPrivateAttributeObject(char *string, Object *super);
/*protected */void setProtectedAttributeObject(char *string, Object *super);
/*protected */char *getPrivateAttributeObject(Object *super);
/*protected */char *getProtectedAttributeObject(Object *super);
/*protected */char *getClassNameObject(Object_ *parent);
/*protected */void setClassNameObject(char *string, Object_ *parent);

#define _Object_Protected_End_

#elif defined(_Object_Private_End_) && defined(_Object_Protected_End_) && defined(_Object_Public_)
#pragma once
#endif
