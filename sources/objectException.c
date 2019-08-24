#include <stdio.h>

#include "objectException.h"

static Exception exceptionToThrow;

Exception *tryToNotHaveNotAllocatedClassException(void *class)
{
    if(!class) /*thrown or throws*/
    {
        exceptionToThrow.id = 0xFA1;
        exceptionToThrow.severityLevel = interruption;
        exceptionToThrow.name = "Class not allocated";
        exceptionToThrow.description = "The Class of the Object was not allocated properly or not allocated at all by the operating system.";
    }
    else /*notThrown*/
    {
        exceptionToThrow.id = 0x0;
        exceptionToThrow.severityLevel = success;
        exceptionToThrow.name = "Class is allocated";
        exceptionToThrow.description = "The Class of the Object was well allocated by the operating system.";
    }
    return &exceptionToThrow;
}

Exception *tryToNotHaveNotAllocatedInstanceException(void *instance)
{
    if(!instance) /*thrown or throws*/
    {
        exceptionToThrow.id = 0xFA2;
        exceptionToThrow.severityLevel = interruption;
        exceptionToThrow.name = "Instance not allocated";
        exceptionToThrow.description = "The Instance of the Object was not allocated properly or not allocated at all by the operating system.";
    }
    else /*notThrown*/
    {
        exceptionToThrow.id = 0x0;
        exceptionToThrow.severityLevel = success;
        exceptionToThrow.name = "Instance is allocated";
        exceptionToThrow.description = "The Instance of the Object was well allocated by the operating system.";
    }
    return &exceptionToThrow;
}

/* Exception *tryToNotHaveDivisionByZeroException(float divisorValue)
{
    if(divisorValue == 0.0f) // throw
    {
        exceptionToThrow.id = 0xFA3;
        exceptionToThrow.severityLevel = error;
        exceptionToThrow.name = "Division by zero intended.";
        exceptionToThrow.description = "The divisor of the operation is equal to zero. The result couldn't be determined.";
        return &exceptionToThrow;
    }
    else
    {
        return NULL;
    }
}*/

void throwAbnormalProgramTermination(char * fileName, int line)
{
    printf("Abnormal program termination in %s at line %d\n", fileName, line);
}
