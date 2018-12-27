#include <stdio.h>
#include <stdlib.h>

#define _DerivedObject_Private_Start_
#define _Object_Protected_Start_
#include "DerivedObject.h"

#include "ObjectException.h"

DerivedObjectInstance *NewDerivedObject(void)
{
    if (DerivedObject == NULL)
    {
        DerivedObject = (DerivedObjectClass *)malloc(sizeof(DerivedObjectClass));
        /*try*/
        {
            if (!DerivedObject) throwExceptionNotAllocatedClass();
        }

        DerivedObject->setPrivateAttribute = (void *)setPrivateAttribute;
        DerivedObject->setProtectedAttribute = (void *)setProtectedAttribute;
        DerivedObject->getPrivateAttribute = (void *)getPrivateAttribute;
        DerivedObject->getProtectedAttribute = (void *)getProtectedAttribute;

        DerivedObject->delete = deleteDerivedObject;

        DerivedObject->protectedMethod = (void *)protectedMethod;

        DerivedObject->getClassName = getClassName;
        DerivedObject->setClassName = setClassName;

        DerivedObject->getLength = getLength;
        DerivedObject->getHeight = getHeight;
        DerivedObject->setLength = setLength;
        DerivedObject->setHeight = setHeight;

        DerivedObject->className = "DerivedObject";
        listOfDerivedObjects = NULL;
    }

    DerivedObjectInstance *this = (DerivedObjectInstance *)malloc(sizeof(DerivedObjectInstance));
    /*try*/
    {
        if (!this) throwExceptionNotAllocatedInstance();
    }

    #pragma clang diagnostic push
    #pragma ide diagnostic ignored "OCDFAInspection"
    this->class = DerivedObject;

    this->protectedAttribute = "protected";
    this->publicAttribute = "public";
    #pragma clang diagnostic pop

    if (listOfDerivedObjects == NULL)
    {
        this->next = NULL;
        listOfDerivedObjects = this;
    }
    else
    {
        this->next = listOfDerivedObjects;
        listOfDerivedObjects = this;
    }

    this->length.x1 = 8.5f;
    this->length.y1 = 7.5f;
    this->length.x2 = 8.0f;
    this->length.y2 = 8.0f;

    this->height.x1 = 6.0f;
    this->height.y1 = 5.0f;
    this->height.x2 = 4.2f;
    this->height.y2 = 7.8f;

    return this;
}

void deleteDerivedObject(DerivedObjectInstance *this)
{
    this = listOfDerivedObjects;
    listOfDerivedObjects = this->next;
    if (listOfDerivedObjects == NULL)
    {
        free(this->class);
        printf("Objet dérivé complètement libéré !\n");
    }
    free(this);
    printf("Instance d'Objet dérivé complètement libéré !\n");
}

float getLength(char *value, DerivedObjectInstance *this)
{
    switch(value[0])
    {
        case 'x': switch(value[0]) {case '1': return this->length.x1; case '2': return this->length.x2; default: return 0.0f;}
        case 'y': switch(value[0]) {case '1': return this->length.y1; case '2': return this->length.y2; default: return 0.0f;}
        default: return 0.0f;
    }
}

float getHeight(char *value, DerivedObjectInstance *this)
{
    switch(value[0])
    {
        case 'x': switch(value[0]) {case '1': return this->height.x1; case '2': return this->height.x2; default: return 0.0f;}
        case 'y': switch(value[0]) {case '1': return this->height.y1; case '2': return this->height.y2; default: return 0.0f;}
        default: return 0.0f;
    }
}

void setLength(float lineStartX, float lineStartY, float lineEndX, float lineEndY, DerivedObjectInstance *this)
{
    this->length.x1 = lineStartX;
    this->length.y1 = lineStartY;
    this->length.x2 = lineEndX;
    this->length.y2 = lineEndY;
}

void setHeight(float lineStartX, float lineStartY, float lineEndX, float lineEndY, DerivedObjectInstance *this)
{
    this->height.x1 = lineStartX;
    this->height.y1 = lineStartY;
    this->height.x2 = lineEndX;
    this->height.y2 = lineEndY;
}

void regulatorDerivedObject(char *string, int bool)
{
    string = DerivedObject->className;
    if(!bool)
    {
        regulatorDerivedObject(string, 1);
    }
}