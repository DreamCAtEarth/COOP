#define private_lbdtYEkR
#include MYSELF

#define namespace_vlDzoKUd
#include MYSPACE

CLASS_SETTER
(
    (INHERIT(kGAzHwmx, Object)),
    .absCustom = absCustom,
    .useCustom = useCustom,
    .testCustom = testCustom
)

INTERNAL void constructor(Id *this_)
{
    This *this = (This *) this_;
    struct object *metadata = findMetadata_;
    size_t numberOfElements = (metadata->settings[isArray])
        ? metadata->array->size
        : 1;
    for(size_t i=0; i < numberOfElements; ++i)
    {
        (this+i)->Object.protectedAttribute = "salut la compagnie 3 !";
        (this+i)->Object.protectedAttribute = "salut la compagnie 4 !";
    }
}

INTERNAL void destructor(bool freeParents)
{
    destructorOfObject(freeParents);
    if(freeParents)
        free(self);
}

static void absCustom(void)
{

}

static void useCustom(void)
{

}

static void testCustom(void)
{

}
