#include "exceptionManager.h"

struct Exception goodAllocationClass(void *class)
{
    struct Exception exceptionsToThrow[2];

    exceptionsToThrow[0].severity = success;

    exceptionsToThrow[1].id = 0xFA1;
    exceptionsToThrow[1].severity = interruption;
    exceptionsToThrow[1].name = "Class allocation failed";
    exceptionsToThrow[1].description = "The instance of the class was not allocated properly or not allocated at all by the operating system.";

    return (!class) ? exceptionsToThrow[1] : exceptionsToThrow[0];
}

struct Exception goodAllocationObject(void *class)
{
    struct Exception exceptionsToThrow[2];

    exceptionsToThrow[0].severity = success;

    exceptionsToThrow[1].id = 0xFA1;
    exceptionsToThrow[1].severity = interruption;
    exceptionsToThrow[1].name = "Object allocation failed";
    exceptionsToThrow[1].description = "The instance of the object was not allocated properly or not allocated at all by the operating system.";

    return (!class) ? exceptionsToThrow[1] : exceptionsToThrow[0];
}

/*Exception *tryToDoADivision(float divisorValue)
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
}

 void throwAbnormalProgramTermination(char *fileName, int line)
{
    printf("Abnormal program termination in %s at line %d\n", fileName, line);
}*/
