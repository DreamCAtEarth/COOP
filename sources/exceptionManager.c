#include "exceptionManager.h"

void allocationWellDone(struct exception *throw, void *instance)
{
    if(instance)
    {
        throw->id = successException;
        throw->message = "the allocation was succeeded.";
    }
    else
    {
        throw->id = badAllocationException;
        throw->message = "the allocation wasn't succeed.";
        throws((int) throw->id);
    }
}

void objectWellFound(struct exception *throw, void *instanceGot, void *instanceWithMetadata)
{
    if(instanceGot == instanceWithMetadata)
    {
        throw->id = successException;
        throw->message = "This pointer points to a valid object.";
    }
    else
    {
        throw->id = objectMetadataNotFoundException;
        throw->message = "this pointer isn't returned by new or isn't valid.";
        throws((int) throw->id);
    }
}
