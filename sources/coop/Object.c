#include <stdio.h>
#include <stdlib.h>

#define _coop_Object_Private_Start_
#include "Object.h"

#define _objectModel_ExpertMode_Enabled_
#include "../objectModel.h"

#include "../objectException.h"

void newClass_coop_Object(void)
{
    coopObject = (coopObject_ *)malloc(sizeof(coopObject_));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedClassException(coopObject);
        if (catchNotAllocatedClassInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }

    coopObject->setPrivateAttribute = setPrivateAttribute_coop_Object;
    coopObject->getPrivateAttribute = getPrivateAttribute_coop_Object;
    coopObject->setProtectedAttribute = setProtectedAttribute_coop_Object;
    coopObject->getProtectedAttribute = getProtectedAttribute_coop_Object;
    coopObject->setClassName = setClassName_coop_Object;
    coopObject->getClassName = getClassName_coop_Object;

    coopObject->className = __CLASSNAME__;

    storeClassPointer(COOP_OBJECT, coopObject);
}

coop_Object *new_coop_Object(overrideConstructor_coop_Object *args)
{
    coop_Object *this = (coop_Object *)malloc(sizeof(coop_Object));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedInstanceException(this);
        if (catchNotAllocatedInstanceInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }
    this->class = coopObject;

    if(args->publicAttribute == DEFAULT_VA_ARGS_VALUE)
        this->publicAttribute = "public";
    else
    {
        this->publicAttribute = args->publicAttribute;
        if(args->protectedAttribute == DEFAULT_VA_ARGS_VALUE)
            this->protectedAttribute = "protected";
        else
        {
            this->protectedAttribute = args->protectedAttribute;
            if (args->privateAttribute == DEFAULT_VA_ARGS_VALUE)
                this->privateAttribute = "private";
            else
                this->privateAttribute = args->privateAttribute;
        }
    }

    storeInstancePointer(this);
    return this;
}

void setPrivateAttribute_coop_Object(char *string, coop_Object *this)
{
    if(this->class != coopObject)
        this->privateAttribute = dynamicLink(this->class, this, COOP_OBJECT_SETPRIVATEATTRIBUTE, string);
    else
        this->privateAttribute = string;
}

char *getPrivateAttribute_coop_Object(coop_Object *this)
{
    if(this->class != coopObject)
        return dynamicLink(this->class, this, COOP_OBJECT_GETPRIVATEATTRIBUTE, NULL);
    else
        return this->privateAttribute;
}

void setProtectedAttribute_coop_Object(char *string, coop_Object *this)
{
    this->protectedAttribute = string;
}

char *getProtectedAttribute_coop_Object(coop_Object *this)
{
    return this->protectedAttribute;
}

void setClassName_coop_Object(char *string, coopObject_ *self)
{
    if(self != coopObject)
        self->className = dynamicLink(self, NULL, COOP_OBJECT_SETCLASSNAME, string);
    else
        self->className = string;
}

char *getClassName_coop_Object(coopObject_ *self)
{
    if(self != coopObject)
        return dynamicLink(self, NULL, COOP_OBJECT_GETCLASSNAME, NULL);
    else
        return self->className;
}
