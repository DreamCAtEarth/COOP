#include <stdio.h>
#include <stdlib.h>

#define _coop_Object_Private_Start_
#include "coop/Object.h"
#define _coop_DerivedObject_Private_Start_
#include "coop/DerivedObject.h"
/*#define _AnotherObject_Private_Start_
#include "AnotherObject.h"
#define _GeometricObject_Private_Start_
#include "GeometricObject.h"*/

#define _objectModel_ExpertMode_Enabled_
#include "objectModel.h"

#include "objectException.h"

/* Lien tardif et polymorphisme effectués grâce aux casts */
void *dynamicLink(void *class, void *instance, methodIds methodToPolymorph, void *newValueToSet)
{
	coopDerivedObject_ *classA1 = NULL;
	coop_DerivedObject *instanceA1 = NULL;

	/*AnotherObject_ *classA2 = NULL;
	AnotherObject *instanceA2 = NULL;

	GeometricObject_ *classA3 = NULL;
	GeometricObject *instanceA3 = NULL;*/

	void *genericValueToReturn = NULL;

	if(class == classIds[COOP_DERIVEDOBJECT])
	{
		classA1 = (coopDerivedObject_ *) class;
		if(instance != NULL)
			instanceA1 = (coop_DerivedObject *) instance;
	}
	/*else if(class == classIds[ANOTHEROBJECT])
	{
		class2 = (AnotherObject_ *) class;
		if(instance != NULL)
			instance2 = (AnotherObject *) instance;
	}
	else if(class == classIds[GEOMETRICOBJECT])
	{
		class3 = (GeometricObject_ *) class;
		if(instance != NULL)
			instance3 = (GeometricObject *) instance;
	}
	else
	{
		throwAbnormalProgramTermination(__FILE__, __LINE__);
	}*/
	
	switch(methodToPolymorph)
    {
        /*dynamic methods*/
        case COOP_OBJECT_GETPRIVATEATTRIBUTE:
            if(instanceA1 != NULL)
                genericValueToReturn = instanceA1->privateAttribute;
		break;
        case COOP_OBJECT_SETPRIVATEATTRIBUTE:
            if(instanceA1 != NULL)
                genericValueToReturn = instanceA1->privateAttribute = newValueToSet;
		break;/**/
        /*static methods*/
        case COOP_OBJECT_GETCLASSNAME:
            if(classA1 != NULL)
                genericValueToReturn = classA1->className;
		break;
        case COOP_OBJECT_SETCLASSNAME:
            if(classA1 != NULL)
                genericValueToReturn = classA1->className = newValueToSet;
		break;/**/
        /*special methods*/
        case DELETE:
			if(nbInstances == 0)
			{
				free(class);
				class = NULL;
				nbClasses--;
			}
			else
			{
				free(instance);
				instance = NULL;
				nbInstances--;
			}
		break;
		default:
			throwAbnormalProgramTermination(__FILE__, __LINE__);
		break;
    }
	
	return genericValueToReturn;
}

/* Constructeurs de classe : ils sont appelés dans un ordre arbitraire car aucun moyen ne permet d'anticiper à quelle classe on a affaire avant sa création.
 * L'ordre des classes est le suivant (les conventions de noms sont reprises pour la fonction DynamicLink) :
- lettre croissante pour une hiérarchie de classes donnée avec un ordre de lecture allant de la plus grande à la plus petite hiérarchie
- nombre croissant pour une classe donnée avec un ordre de lecture allant de haut en bas et de gauche à droite dans une hiérarchie*/
void start(void)
{
    newClass_coop_Object();
    newClass_coop_DerivedObject();
    /*newAnotherObjectClass();
    newGeometricObjectClass();*/
	nbClasses = NUMBEROFCLASSES;
}

/* Destructeur général, chacune des instances sont désalouées les unes après les autres indistinctement, puis leurs classes respectives */
void end(void)
{
	do
		dynamicLink(classIds[nbClasses - 1], instanceIds[nbInstances], DELETE, NULL);
	while (nbClasses != 0);
}

/* tableau de pointeurs de classes */
void storeClassPointer(ClassesIds value, void *class)
{
	classIds[value] = class;
}

/* tableau de pointeurs d'instances */
void storeInstancePointer(void *instance)
{
    instanceIds[nbInstances] = instance;
	nbInstances++;
}