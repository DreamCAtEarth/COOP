#ifndef EXCEPTION_MANAGER_H
#define EXCEPTION_MANAGER_H

struct Exception
{
    //int id;
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
    char *name;
    //char *description;
};

/*enum reasonOfControl
{
    isPossibleToAllocateANewInstance
};

enum sortOfControl
{
    arrayOutOfBounds,
    arrayOutOfIndexLimit
};*/

#define try(riskyThingsToDo) riskyThingsToDo;

struct Exception goodAllocation(void *);
/*Exception *coherentDivision(float);

void throwAbnormalProgramTermination(char *, int);*/

#endif //EXCEPTION_MANAGER_H
