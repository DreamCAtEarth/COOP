#include <stdlib.h>

#define _DerivedObject_Private_Start_
#define _Object_Protected_Start_
#include "DerivedObject.h"

#include "objectException.h"
#include "ObjectPolymorphismHelper.h"

void NewDerivedObjectClass(void)
{
    DerivedObject = (DerivedObjectClass *)malloc(sizeof(DerivedObjectClass));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedClassException(DerivedObject);
        if(catchNotAllocatedClassInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }

    DerivedObject->setPrivateAttribute = (void *)setPrivateAttributeObject;
    DerivedObject->setProtectedAttribute = (void *)setProtectedAttributeObject;
    DerivedObject->getPrivateAttribute = (void *)getPrivateAttributeObject;
    DerivedObject->getProtectedAttribute = (void *)getProtectedAttributeObject;
    DerivedObject->delete = (void *)deleteObject;
    DerivedObject->getClassName = (void *)getClassNameObject;
    DerivedObject->setClassName = (void *)setClassNameObject;

    DerivedObject->getLength = getLengthDerivedObject;
    DerivedObject->getHeight = getHeightDerivedObject;
    DerivedObject->setLength = setLengthDerivedObject;
    DerivedObject->setHeight = setHeightDerivedObject;

    DerivedObject->className = "DerivedObject";
    DerivedObject->nbInstances = 0;

    storeClassPointer(DERIVEDOBJECT, DerivedObject);
}

DerivedObjectInstance *NewDerivedObject(void)
{
    if (DerivedObject == NULL)
    {
        NewDerivedObjectClass();
    }
    DerivedObjectInstance *this = (DerivedObjectInstance *)malloc(sizeof(DerivedObjectInstance));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedInstanceException(this);
        if(catchNotAllocatedInstanceInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }
    this->class = DerivedObject;

    this->privateAttribute = "DA private";
    this->protectedAttribute = "DA protected";
    this->publicAttribute = "DA public";

    this->length.x1 = 8.5f;
    this->length.y1 = 7.5f;
    this->length.x2 = 8.0f;
    this->length.y2 = 8.0f;

    this->height.x1 = 6.0f;
    this->height.y1 = 5.0f;
    this->height.x2 = 4.2f;
    this->height.y2 = 7.8f;

    DerivedObject->nbInstances++;

    return this;
}

float getLengthDerivedObject(char *value, DerivedObjectInstance *this)
{
    switch(value[0])
    {
        case 'x': switch(value[1]) {case '1': return this->length.x1; case '2': return this->length.x2; default: return 0.0f;}
        case 'y': switch(value[1]) {case '1': return this->length.y1; case '2': return this->length.y2; default: return 0.0f;}
        default: return 0.0f;
    }
}

float getHeightDerivedObject(char *value, DerivedObjectInstance *this)
{
    switch(value[0])
    {
        case 'x': switch(value[1]) {case '1': return this->height.x1; case '2': return this->height.x2; default: return 0.0f;}
        case 'y': switch(value[1]) {case '1': return this->height.y1; case '2': return this->height.y2; default: return 0.0f;}
        default: return 0.0f;
    }
}

void setLengthDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                            DerivedObjectInstance *this)
{
    this->length.x1 = lineStartX;
    this->length.y1 = lineStartY;
    this->length.x2 = lineEndX;
    this->length.y2 = lineEndY;
}

void setHeightDerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY,
                            DerivedObjectInstance *this)
{
    this->height.x1 = lineStartX;
    this->height.y1 = lineStartY;
    this->height.x2 = lineEndX;
    this->height.y2 = lineEndY;
}