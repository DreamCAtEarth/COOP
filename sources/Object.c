#include <stdio.h>
#include <stdlib.h>

#define _Object_Private_Start_
#include "Object.h"

#include "ObjectException.h"

ObjectInstance *NewObject(void)
{
    if (Object == NULL)
    {
        Object = (ObjectClass *)malloc(sizeof(ObjectClass));
        /*try*/
        {
            if (!Object) throwExceptionNotAllocatedClass();
        }

        Object->setPrivateAttribute = setPrivateAttribute;
        Object->setProtectedAttribute = setProtectedAttribute;
        Object->getPrivateAttribute = getPrivateAttribute;
        Object->getProtectedAttribute = getProtectedAttribute;

        Object->delete = deleteObject;

        Object->protectedMethod = protectedMethod;
        Object->privateMethod = privateMethod;

        Object->getClassName = getClassName;
        Object->setClassName = setClassName;

        Object->className = "Object";
        listOfObjects = NULL;
    }

    ObjectInstance *this = (ObjectInstance *)malloc(sizeof(ObjectInstance));
    /*try*/
    {
        if (!this) throwExceptionNotAllocatedInstance();
    }

    #pragma clang diagnostic push
    #pragma ide diagnostic ignored "OCDFAInspection"
    this->class = Object;

    this->privateAttribute = "private";
    this->protectedAttribute = "protected";
    this->publicAttribute = "public";
    #pragma clang diagnostic pop

    if (listOfObjects == NULL)
    {
        this->next = NULL;
        listOfObjects = this;
    }
    else
    {
        this->next = listOfObjects;
        listOfObjects = this;
    }

    return this;
}

void deleteObject(ObjectInstance *this)
{
    this = listOfObjects;
    listOfObjects = this->next;
    if (listOfObjects == NULL)
    {
        free(this->class);
        printf("Objet complètement libéré !\n");
    }
    free(this);
    printf("Instance d'Objet complètement libéré !\n");
}

void setPrivateAttribute(char *string, ObjectInstance *this)
{
    this->privateAttribute = string;
}

void setProtectedAttribute(char *string, ObjectInstance *this)
{
    this->protectedAttribute = string;
}

char *getPrivateAttribute(ObjectInstance *this)
{
    return this->privateAttribute;
}

char *getProtectedAttribute(ObjectInstance *this)
{
    return this->protectedAttribute;
}

void setClassName(char *string)
{
    Object->className = string;
}

char *getClassName(void)
{
    return Object->className;
}

void protectedMethod(ObjectInstance *this)
{
    printf("%s\n", this->protectedAttribute);
}

void privateMethod(ObjectInstance *this)
{
    printf("%s\n", this->privateAttribute);
}

int regulatorObject(ObjectInstance *this, int bool)
{
    Object->privateMethod(this);
    if(!bool)
    {
        return regulatorObject(this, 1);
    }
    else return 1;
}