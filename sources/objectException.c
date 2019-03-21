#include <stdio.h>

#include "objectException.h"

static Exception exceptionToThrow;

Exception *catchingDefaultDisplayProtocol(Exception *exceptionCaught)
{
    //Display all the informations to the user depending on the context
    if(exceptionCaught->severityLevel == interruption)
    {
        printf("%s Interruption call :\nThe program must shut down !\n",exceptionCaught->name);
        printf("%s\n",exceptionCaught->description);
        //Actions to Perform : manager which call an exit statement to the program after the catch block
    }
    else if(exceptionCaught->severityLevel == error)
    {
        printf("%s Error call :\nThe module of the program must stop and let the program continue.\n",exceptionCaught->name);
        printf("%s\n",exceptionCaught->description);
        //Actions to Perform : manager which call a return statement to the current function after the catch block
    }
    else if(exceptionCaught->severityLevel == warning)
    {
        printf("%s Warning call :\nThe statement have to be corrected.\n",exceptionCaught->name);
        printf("%s\n",exceptionCaught->description);
        //Actions to Perform : manager which call a continue statement to the current scope after the catch block
    }
    else if(exceptionCaught->severityLevel == info)
    {
        printf("%s Info call :\nThe statement is not conform but can continue.\n",exceptionCaught->name);
        printf("%s\n",exceptionCaught->description);
        //Actions to Perform : manager which inform the user of the wrong/not conform result after the catch block
    }
    return exceptionCaught;
}

Exception *tryToNotHaveNotAllocatedClassException(void *class)
{
    if(!class) /*throw*/
    {
        exceptionToThrow.id = 0xFA1;
        exceptionToThrow.severityLevel = interruption;
        exceptionToThrow.name = "Class not allocated";
        exceptionToThrow.description = "The Class of the Object was not allocated properly or not allocated at all by the operating system.";
        return &exceptionToThrow;
    }
    else
    {
        return NULL;
    }
}

Exception *catchNotAllocatedClassInterruption(Exception *exceptionCaught)
{
    if(exceptionCaught != NULL) return catchingDefaultDisplayProtocol(exceptionCaught);
    else return exceptionCaught;
}

Exception *tryToNotHaveNotAllocatedInstanceException(void *instance)
{
    if(!instance) /*throw*/
    {
        exceptionToThrow.id = 0xFA2;
        exceptionToThrow.severityLevel = interruption;
        exceptionToThrow.name = "Instance not allocated";
        exceptionToThrow.description = "The Instance of the Object was not allocated properly or not allocated at all by the operating system.";
        return &exceptionToThrow;
    }
    else
    {
        return NULL;
    }
}

Exception *catchNotAllocatedInstanceInterruption(Exception *exceptionCaught)
{
    if(exceptionCaught != NULL) return catchingDefaultDisplayProtocol(exceptionCaught);
    else return exceptionCaught;
}

Exception *tryToNotHaveDivisionByZeroException(float divisorValue)
{
    if(divisorValue == 0.0f) /*throw*/
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

Exception *catchDivisionByZeroError(Exception *exceptionCaught)
{
    if(exceptionCaught != NULL) return catchingDefaultDisplayProtocol(exceptionCaught);
    else return exceptionCaught;
}

void throwAbnormalProgramTermination(char * fileName, int line)
{
    printf("Abnormal program termination in %s at line %d\n", fileName, line);
}
