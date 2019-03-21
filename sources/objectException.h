#pragma once

typedef struct Exception Exception;

typedef enum ExceptionType
{
    interruption,
    error,
    warning,
    info
}ExceptionType;

struct Exception
{
    int id;
    ExceptionType severityLevel;
    char *name;
    char *description;
};

Exception *catchingDefaultDisplayProtocol(Exception *exceptionCaught);

Exception *tryToNotHaveNotAllocatedClassException(void *class);
Exception *catchNotAllocatedClassInterruption(Exception *exceptionCaught);
Exception *tryToNotHaveNotAllocatedInstanceException(void *instance);
Exception *catchNotAllocatedInstanceInterruption(Exception *exceptionCaught);
Exception *tryToNotHaveDivisionByZeroException(float divisorValue);
Exception *catchDivisionByZeroError(Exception *exceptionCaught);

void throwAbnormalProgramTermination(char * fileName, int line);