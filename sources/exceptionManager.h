#ifndef EXCEPTION_MANAGER_H
#define EXCEPTION_MANAGER_H

#include <setjmp.h>

struct exception
{
    enum exception_type
    {
        /* success case */
        successException,
        /* interruption cases */
        badAllocationException,
        objectMetadataNotFoundException,

        /* error cases */

        /* warning cases */

        /* note cases */

        /* number of exceptions */
        numberOfException
    } id;
    jmp_buf context;
    const char *message;
};

void allocationWellDone(struct exception *, void *);
void objectWellFound(struct exception *, void *, void *);

#define try do { switch( setjmp(exception.context) ) { case successException: while(1) {
#define throws(exceptionType) longjmp(throw->context, exceptionType)
#define catch(exceptionType) break; case exceptionType:
#define finally break; } default: {
#define endTry break; } } } while(0);

#endif //EXCEPTION_MANAGER_H
