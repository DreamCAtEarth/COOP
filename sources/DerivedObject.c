#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _Object_Protected_Start_
#define _DerivedObject_Private_Start_
#include "Object.h"
#include "DerivedObject.h"

#define _objectModel_ExpertMode_Enabled_
#include "objectModel.h"

#include "objectException.h"

void newClassDerivedObject(void)
{
    derivedObject = (DerivedObject_ *)malloc(sizeof(DerivedObject_));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedClassException(object);
        if (catchNotAllocatedClassInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }

    derivedObject->setPrivateAttribute = (void *)setPrivateAttributeObject;
    derivedObject->setProtectedAttribute = (void *)setProtectedAttributeObject;
    derivedObject->getPrivateAttribute = (void *)getPrivateAttributeObject;
    derivedObject->getProtectedAttribute = (void *)getProtectedAttributeObject;
    derivedObject->getClassName = (void *)getClassNameObject;
    derivedObject->setClassName = (void *)setClassNameObject;

    derivedObject->getLength = getLengthDerivedObject;
    derivedObject->getHeight = getHeightDerivedObject;
    derivedObject->setLength = setLengthDerivedObject;
    derivedObject->setHeight = setHeightDerivedObject;

    derivedObject->className = __CLASSNAME__;

    storeClassPointer(DERIVEDOBJECT, derivedObject);
}

DerivedObject *newDerivedObject(overrideConstructorDerivedObject *args)
{
    DerivedObject *this = (DerivedObject *)malloc(sizeof(DerivedObject));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedInstanceException(this);
        if(catchNotAllocatedInstanceInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }
    this->class = derivedObject;

    if(args->publicAttribute == 0)
        this->publicAttribute = "DA public";
    else
    {
        this->publicAttribute = args->publicAttribute;
        if(args->protectedAttribute == 0)
            this->protectedAttribute = "DA protected";
        else
        {
            this->protectedAttribute = args->protectedAttribute;
            if (args->privateAttribute == 0)
                this->privateAttribute = "DA private";
            else
                this->privateAttribute = args->privateAttribute;
        }
    }

    this->length.x1 = 8.5f;
    this->length.y1 = 7.5f;
    this->length.x2 = 8.0f;
    this->length.y2 = 8.0f;

    this->height.x1 = 6.0f;
    this->height.y1 = 5.0f;
    this->height.x2 = 4.2f;
    this->height.y2 = 7.8f;

    storeInstancePointer(this);

    return this;
}

float getLengthDerivedObject(const char *value, DerivedObject *this)
{
    switch(value[0])
    {
        case 'x': switch(value[1]) {case '1': return this->length.x1; case '2': return this->length.x2; default: return 0.0f;}
        case 'y': switch(value[1]) {case '1': return this->length.y1; case '2': return this->length.y2; default: return 0.0f;}
        default: return 0.0f;
    }
}

float getHeightDerivedObject(const char *value, DerivedObject *this)
{
    switch(value[0])
    {
        case 'x': switch(value[1]) {case '1': return this->height.x1; case '2': return this->height.x2; default: return 0.0f;}
        case 'y': switch(value[1]) {case '1': return this->height.y1; case '2': return this->height.y2; default: return 0.0f;}
        default: return 0.0f;
    }
}

void setLengthDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                            DerivedObject *this)
{
    this->length.x1 = lineStartX;
    this->length.y1 = lineStartY;
    this->length.x2 = lineEndX;
    this->length.y2 = lineEndY;
}

void setHeightDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                            DerivedObject *this)
{
    this->height.x1 = lineStartX;
    this->height.y1 = lineStartY;
    this->height.x2 = lineEndX;
    this->height.y2 = lineEndY;
}