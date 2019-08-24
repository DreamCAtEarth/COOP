#pragma once

typedef struct Exception Exception;

typedef enum ExceptionSeverity
{
    interruption,
    error,
    warning,
    info,
    success
}ExceptionSeverity;

struct Exception
{
    int id;
    ExceptionSeverity severityLevel;
    char *name;
    char *description;
};

Exception *tryToNotHaveNotAllocatedClassException(void *class);
Exception *tryToNotHaveNotAllocatedInstanceException(void *instance);
// Exception *tryToNotHaveDivisionByZeroException(float divisorValue);
// Exception *catchDivisionByZeroError(Exception *exceptionCaught);

void throwAbnormalProgramTermination(char * fileName, int line);