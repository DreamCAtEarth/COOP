#include <stdio.h>
#include <stdlib.h>

#define _coop_Object_Protected_Start_
#define _coop_DerivedObject_Private_Start_
#include "Object.h"
#include "DerivedObject.h"

#define _objectModel_ExpertMode_Enabled_
#include "../objectModel.h"

#include "../objectException.h"

void newClass_coop_DerivedObject(void)
{
    coopDerivedObject = (coopDerivedObject_ *)malloc(sizeof(coopDerivedObject_));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedClassException(coopDerivedObject);
        if (catchNotAllocatedClassInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }

    coopDerivedObject->setPrivateAttribute = (void *)setPrivateAttribute_coop_Object;
    coopDerivedObject->getPrivateAttribute = (void *)getPrivateAttribute_coop_Object;
    coopDerivedObject->setProtectedAttribute = (void *)setProtectedAttribute_coop_Object;
    coopDerivedObject->getProtectedAttribute = (void *)getProtectedAttribute_coop_Object;
    coopDerivedObject->setClassName = (void *)setClassName_coop_Object;
    coopDerivedObject->getClassName = (void *)getClassName_coop_Object;

    coopDerivedObject->setLength = setLength_coop_DerivedObject;
    coopDerivedObject->getLength = getLength_coop_DerivedObject;
    coopDerivedObject->setHeight = setHeight_coop_DerivedObject;
    coopDerivedObject->getHeight = getHeight_coop_DerivedObject;

    coopDerivedObject->className = __CLASSNAME__;

    storeClassPointer(COOP_DERIVEDOBJECT, coopDerivedObject);
}

coop_DerivedObject *new_coop_DerivedObject(overrideConstructor_coop_DerivedObject *args)
{
    coop_DerivedObject *this = (coop_DerivedObject *)malloc(sizeof(coop_DerivedObject));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedInstanceException(this);
        if(catchNotAllocatedInstanceInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }
    this->class = coopDerivedObject;

    if(args->publicAttribute == DEFAULT_VA_ARGS_VALUE)
        this->publicAttribute = "DA public";
    else
    {
        this->publicAttribute = args->publicAttribute;
        if(args->protectedAttribute == DEFAULT_VA_ARGS_VALUE)
            this->protectedAttribute = "DA protected";
        else
        {
            this->protectedAttribute = args->protectedAttribute;
            if (args->privateAttribute == DEFAULT_VA_ARGS_VALUE)
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

void setLength_coop_DerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY, coop_DerivedObject *this)
{
    this->length.x1 = lineStartX;
    this->length.y1 = lineStartY;
    this->length.x2 = lineEndX;
    this->length.y2 = lineEndY;
}

float getLength_coop_DerivedObject(const char *value, coop_DerivedObject *this)
{
    switch(value[0])
    {
        case 'x': switch(value[1]) {case '1': return this->length.x1; case '2': return this->length.x2; default: return 0.0f;}
        case 'y': switch(value[1]) {case '1': return this->length.y1; case '2': return this->length.y2; default: return 0.0f;}
        default: return 0.0f;
    }
}

void setHeight_coop_DerivedObject(float lineStartX, float lineStartY, float lineEndX, float lineEndY, coop_DerivedObject *this)
{
    this->height.x1 = lineStartX;
    this->height.y1 = lineStartY;
    this->height.x2 = lineEndX;
    this->height.y2 = lineEndY;
}

float getHeight_coop_DerivedObject(const char *value, coop_DerivedObject *this)
{
    switch(value[0])
    {
        case 'x': switch(value[1]) {case '1': return this->height.x1; case '2': return this->height.x2; default: return 0.0f;}
        case 'y': switch(value[1]) {case '1': return this->height.y1; case '2': return this->height.y2; default: return 0.0f;}
        default: return 0.0f;
    }
}