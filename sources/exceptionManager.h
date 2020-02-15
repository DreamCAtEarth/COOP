#ifndef EXCEPTION_MANAGER_H
#define EXCEPTION_MANAGER_H

struct Exception
{
    int id;
    /*enum state
    {
        init,
        try,
        throw,
        catch,
        finally
    }state;*/
    enum severity
    {
        interruption,
        //error,
        //warning,
        //info,
        success
    }severity;
    const char *name;
    const char *description;
};

#define try(riskyThingsToDo) riskyThingsToDo;

struct Exception goodAllocation(void *);
/*
struct Exception arrayInBounds(int, int, ...);
Exception *coherentDivision(float);
void throwAbnormalProgramTermination(char *, int);
*/

#endif //EXCEPTION_MANAGER_H
