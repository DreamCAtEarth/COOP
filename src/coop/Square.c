#define private_UQZwMHfN
#include MYSELF

#define namespace_vlDzoKUd
#include MYSPACE

CLASS_SETTER((), area)

INTERNAL void constructor(Id *this_)
{
    This *this = (This *) this_;
    struct object *metadata = findMetadata_;
    size_t numberOfElements =
            (metadata->settings[isArray])
            ? metadata->array->size
            : 1;
    for(size_t i=0; i < numberOfElements; ++i)
    {
        (this+i)->length = 4;
        (this+i)->width = 4;
    }
}

INTERNAL void destructor(bool freeParents)
{
    if(freeParents)
        free(self);
}

static int area(This *this)
{
    return this->length * this->width;
}
