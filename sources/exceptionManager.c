#include "exceptionManager.h"

struct Exception goodAllocation(void *instance)
{
    struct Exception exceptionsToThrow[2];

    exceptionsToThrow[0].severity = success;

    //exceptionsToThrow[1].id = 0x0001;
    exceptionsToThrow[1].severity = interruption;
    exceptionsToThrow[1].name = "Instance allocation failed";
    //exceptionsToThrow[1].description = "The instance was not allocated properly or not allocated at all by the operating system.";

    return (!instance) ? exceptionsToThrow[1] : exceptionsToThrow[0];
}

/*
struct Exception arrayInBounds(int currentIndexOrValue, int maxBound, ...)
{
    struct Exception exceptionsToThrow[2];

    exceptionsToThrow[0].severity = success;

    exceptionsToThrow[1].id = 0x0003;
    exceptionsToThrow[1].severity = interruption;
    exceptionsToThrow[1].name = "Array out of Bounds";
    exceptionsToThrow[1].description = "The array is about to be out of its bounds, the program must exit because this array store critical data and if it's not possible to store more of them, the program can't proceed.";

    return (currentIndexOrValue > maxBound) ? exceptionsToThrow[1] : exceptionsToThrow[0];
}

Exception *coherentDivision(float divisorValue)
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
}
 */
