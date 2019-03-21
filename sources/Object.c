#include <stdio.h>
#include <stdlib.h>

#define _Object_Private_Start_
#include "Object.h"

#define _objectModel_ExpertMode_Enabled_
#include "objectModel.h"

#include "objectException.h"

void newClassObject(void)
{
    object = (Object_ *)malloc(sizeof(Object_));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedClassException(object);
        if (catchNotAllocatedClassInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }

    object->setPrivateAttribute = setPrivateAttributeObject;
    object->setProtectedAttribute = setProtectedAttributeObject;
    object->getPrivateAttribute = getPrivateAttributeObject;
    object->getProtectedAttribute = getProtectedAttributeObject;
    object->getClassName = getClassNameObject;
    object->setClassName = setClassNameObject;

    storeClassPointer(OBJECT, object);
}

Object *newObject(overrideConstructorObject *args)
{
    Object *this = (Object *)malloc(sizeof(Object));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedInstanceException(this);
        if (catchNotAllocatedInstanceInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }
    this->class = object;

    if(args->publicAttribute == 0)
        this->publicAttribute = "public";
    else
        this->publicAttribute = args->publicAttribute;

    if(args->protectedAttribute == 0)
        this->protectedAttribute = "protected";
    else
        this->protectedAttribute = args->protectedAttribute;

    if(args->privateAttribute == 0)
        this->privateAttribute = "private";
    else
        this->privateAttribute = args->privateAttribute;

    storeInstancePointer(this);

    nbInstances++;

    return this;
}

void setPrivateAttributeObject(char *string, Object *this)
{
    if(this->class != object)
        this->privateAttribute = dynamicLink(this->class, this, SETPRIVATT, string);
    else
        this->privateAttribute = string;
}

void setProtectedAttributeObject(char *string, Object *this)
{
    this->protectedAttribute = string;
}

char *getPrivateAttributeObject(Object *this)
{
    if(this->class != object)
        return dynamicLink(this->class, this, GETPRIVATT, NULL);
    else
        return this->privateAttribute;
}

char *getProtectedAttributeObject(Object *this)
{
    return this->protectedAttribute;
}

void setClassNameObject(char *string, Object_ *self)
{
    if(self != object)
        self->className = dynamicLink(self, NULL, SETCLASSNAME, string);
    else
        self->className = string;
}

char *getClassNameObject(Object_ *self)
{
    if(self != object)
        return dynamicLink(self, NULL, GETCLASSNAME, NULL);
    else
        return self->className;
}
