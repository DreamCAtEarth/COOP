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
        /*error,
        warning,
        info,*/
        success
    }severity;
    char *name;
    char *description;
};

#define try(riskyThingToDo,...) riskyThingToDo;
#define catch(...) catch:
//#define finally finally:

struct Exception goodAllocationClass(void *);
struct Exception goodAllocationObject(void *);
/*Exception *tryToDoADivision(float);

void throwAbnormalProgramTermination(char *, int);*/

#endif //EXCEPTION_MANAGER_H