#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#if !defined numberOfMarks || numberOfMarks < 1
#define	numberOfMarks 10
#endif

#if !defined lengthOfAMark
#define	lengthOfAMark 5
#endif

#define _AnotherObject_Private_Start_
#define _Object_Protected_Start_
#include "AnotherObject.h"

#include "../objectException.h"

void NewAnotherObjectClass(void)
{
    AnotherObject = (AnotherObjectClass *)malloc(sizeof(AnotherObjectClass));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedClassException(AnotherObject);
        if(catchNotAllocatedClassInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }

    AnotherObject->setPrivateAttribute = (void *)setPrivateAttributeObject;
    AnotherObject->setProtectedAttribute = (void *)setProtectedAttributeObject;
    AnotherObject->getPrivateAttribute = (void *)getPrivateAttributeObject;
    AnotherObject->getProtectedAttribute = (void *)getProtectedAttributeObject;
    AnotherObject->delete = (void *)deleteObject;
    AnotherObject->getClassName = (void *)getClassNameObject;
    AnotherObject->setClassName = (void *)setClassNameObject;

    AnotherObject->getAverageOfReport = averageOfMarksAnotherObject;
    AnotherObject->displayReport = displayReportAnotherObject;
    AnotherObject->setSeed = setSeedAnotherObject;
    AnotherObject->isSeedSet = isSeedSetAnotherObject;
    AnotherObject->sumOfMarks = sumOfMarksAnotherObject;
    AnotherObject->sizeOfReport = sizeOfReportAnotherObject;
    AnotherObject->recordMarks = recordMarksAnotherObject;
    AnotherObject->preciseDivision = preciseDivisionAnotherObject;

    AnotherObject->className = "AnotherObject";
    AnotherObject->seed = false;
}

AnotherObjectInstance *NewAnotherObject(void)
{
    if (AnotherObject == NULL)
    {
        NewAnotherObjectClass();
    }

    AnotherObjectInstance *this = (AnotherObjectInstance *)malloc(sizeof(AnotherObjectInstance));
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveNotAllocatedInstanceException(this);
        if(catchNotAllocatedInstanceInterruption(toCatch) != NULL)
        {
            exit(toCatch->id);
        }
    }

    this->class = AnotherObject;

    this->protectedAttribute = "protected";
    this->publicAttribute = "public";
    this->class->recordMarks(this);

    return this;
}

double averageOfMarksAnotherObject(AnotherObjectInstance *this)
{
    return this->class->preciseDivision
    (
        this->class->sumOfMarks(this),
        this->class->sizeOfReport()
    );
}

char *displayReportAnotherObject(AnotherObjectInstance *this)
{
    int i=0, ret=0;
    this->marksToDisplay = (char *) malloc(sizeof(char) * numberOfMarks * lengthOfAMark + 30);
    char report[numberOfMarks][lengthOfAMark];

    strcpy(this->marksToDisplay, "Report :");
    for(;i<numberOfMarks;i++)
    {
        ret = snprintf(report[i], sizeof report[i], "%f", this->mark[i]);
        if (ret < 0)
        {
            exit(EXIT_FAILURE);
        }
        if (ret >= sizeof report[i])
        {
            /* Result was truncated - resize the report[i] and retry.*/
        }
        strcat(this->marksToDisplay, " ");
        strcat(this->marksToDisplay, report[i]);
    }
    return this->marksToDisplay;
}

void setSeedAnotherObject(bool seed, AnotherObjectClass *self)
{
    self->seed = seed;
}
bool isSeedSetAnotherObject(AnotherObjectClass *self)
{
    return self->seed;
}

float sumOfMarksAnotherObject(AnotherObjectInstance *this)
{
    int i=0;
    float sum =0.0f;
    for(;i<numberOfMarks;i++)
    {
        sum+=this->mark[i];
    }
    return sum;
}

int sizeOfReportAnotherObject()
{
    return numberOfMarks;
}

void recordMarksAnotherObject(AnotherObjectInstance *this)
{
    int i=0;
    if(!AnotherObject->seed)
    {
        srand((unsigned int)time(NULL));
        AnotherObject->setSeed(true,AnotherObject);
    }

    for(;i<numberOfMarks;i++)
    {
        this->mark[i] = ((float)rand()/(float)(RAND_MAX)) * 20.0f;
    }
}

float preciseDivisionAnotherObject(float numerator, float divisor)
{
    /*try / catch */
    {
        Exception *toCatch = tryToNotHaveDivisionByZeroException(divisor);
        if(catchDivisionByZeroError(toCatch) != NULL)
        {
            return 0.0f;
        }
    }
    return numerator / divisor;
}
