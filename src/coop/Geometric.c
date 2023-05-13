#define private_YPnOLrQT
#include MYSELF

#define namespace_vlDzoKUd
#include MYSPACE

CLASS_SETTER
(
    (INHERIT(ddUKsuMN, Derived),
    INHERIT(lbdtYEkR, Another)),NULL,NULL
)

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
        (this + i)->Derived.Object.protectedAttribute = "salut la compagnie !";
        (this + i)->Another.Object.protectedAttribute = "salut la compagnie 2 !";
    }
}

INTERNAL void destructor(bool freeParents)
{
    destructorOfDerived(freeParents);
    destructorOfAnother(freeParents);
    if(freeParents)
        free(self);
}
